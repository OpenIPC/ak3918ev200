"""Utilities for extracting C data type definitions and related macros.

This script scans a directory tree containing C/C++ source files and extracts
user-defined data types created through ``typedef`` statements or named
``struct``/``union``/``enum`` declarations. After collecting the data types, it
performs a second pass to discover ``#define`` macros whose replacement text
references one of the previously found types.  The resulting type and macro
information is written to a text file.

Example::

    python tools/type_extractor.py /path/to/source --output data_types.txt

The output file will contain two sections: the list of discovered data types
followed by the macros that expand to those types.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path
from typing import Iterable, List, Sequence, Set, Tuple

# Recognised file extensions to analyse.  The list focuses on common C and C++
# source/header files, but more can be added via the ``--extensions`` option if
# required.
DEFAULT_EXTENSIONS: Sequence[str] = (
    ".h",
    ".hpp",
    ".hh",
    ".hxx",
    ".c",
    ".cc",
    ".cpp",
    ".cxx",
)

# Regular expressions to capture type definitions.  They are intentionally
# conservative to avoid false positives while covering the most common
# idioms used to define types in C code bases.
TYPEDEF_REGEX = re.compile(r"\btypedef\b[^;]*?\b([A-Za-z_]\w*)\s*;", re.DOTALL)
STRUCT_REGEX = re.compile(r"\bstruct\s+([A-Za-z_]\w*)\s*(?:\{|;)", re.DOTALL)
UNION_REGEX = re.compile(r"\bunion\s+([A-Za-z_]\w*)\s*(?:\{|;)", re.DOTALL)
ENUM_REGEX = re.compile(r"\benum\s+([A-Za-z_]\w*)\s*(?:\{|;)", re.DOTALL)

DEFINE_REGEX = re.compile(
    r"^\s*#\s*define\s+([A-Za-z_]\w*)(?:\s*\((.*?)\))?\s+(.*)$"
)


def iter_source_files(root: Path, extensions: Sequence[str]) -> Iterable[Path]:
    """Yield all files under *root* whose suffix matches *extensions*."""

    for path in root.rglob("*"):
        if path.is_file() and path.suffix.lower() in extensions:
            yield path


def load_text(path: Path) -> str:
    """Read *path* as text, gracefully handling encoding issues."""

    try:
        return path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        return path.read_text(encoding="latin-1", errors="ignore")


def extract_types_from_text(text: str) -> Set[str]:
    """Return a set with all user defined type names found in *text*."""

    types: Set[str] = set()
    for regex in (TYPEDEF_REGEX, STRUCT_REGEX, UNION_REGEX, ENUM_REGEX):
        types.update(regex.findall(text))
    return types


def extract_types(paths: Iterable[Path]) -> Set[str]:
    """Collect data types from the provided *paths*."""

    discovered: Set[str] = set()
    for path in paths:
        text = load_text(path)
        discovered.update(extract_types_from_text(text))
    return discovered


def discover_macros(paths: Iterable[Path], type_names: Sequence[str]) -> List[Tuple[str, str, Path]]:
    """Return macros whose definitions reference any of *type_names*.

    Each entry is a tuple ``(macro_name, replacement, path)``.
    """

    macros: List[Tuple[str, str, Path]] = []
    if not type_names:
        return macros

    type_patterns = [re.compile(rf"\\b{re.escape(t)}\\b") for t in type_names]

    for path in paths:
        try:
            lines = path.read_text(encoding="utf-8").splitlines()
        except UnicodeDecodeError:
            lines = path.read_text(encoding="latin-1", errors="ignore").splitlines()

        for line in lines:
            match = DEFINE_REGEX.match(line)
            if not match:
                continue

            name, params, replacement = match.groups()
            # Ignore function-like macros by skipping definitions with parameters.
            if params is not None and params.strip():
                continue

            for pattern in type_patterns:
                if pattern.search(replacement):
                    macros.append((name, replacement.strip(), path))
                    break

    return macros


def write_report(
    output_path: Path,
    type_names: Sequence[str],
    macros: Sequence[Tuple[str, str, Path]],
) -> None:
    """Write the discovered information to *output_path*."""

    lines = []
    lines.append("# Data types discovered (typedef/struct/union/enum)\n")
    for name in sorted(type_names):
        lines.append(f"{name}\n")

    if macros:
        lines.append("\n# Macros referencing the discovered types\n")
        for macro_name, replacement, path in sorted(macros, key=lambda item: item[0]):
            rel_path = path.as_posix()
            lines.append(f"{macro_name} -> {replacement}    (from {rel_path})\n")

    output_path.write_text("".join(lines), encoding="utf-8")


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Extract data type definitions and related macros from a C/C++ "
            "code base."
        )
    )
    parser.add_argument(
        "source_root",
        type=Path,
        help="Path to the root of the source tree to analyse.",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("data_types.txt"),
        help="Output file for the resulting report (default: data_types.txt).",
    )
    parser.add_argument(
        "--extensions",
        nargs="*",
        default=DEFAULT_EXTENSIONS,
        help="File extensions to include in the scan (default: common C/C++ extensions).",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_arguments()
    source_root: Path = args.source_root
    extensions: Sequence[str] = tuple(ext.lower() if ext.startswith(".") else f".{ext.lower()}" for ext in args.extensions)

    if not source_root.exists() or not source_root.is_dir():
        raise SystemExit(f"Source root '{source_root}' does not exist or is not a directory")

    source_files = list(iter_source_files(source_root, extensions))

    type_names = sorted(extract_types(source_files))
    macros = discover_macros(source_files, type_names)

    # Augment the type list with macro names to reflect the aliases discovered.
    if macros:
        type_names = sorted(set(type_names) | {name for name, _, _ in macros})

    write_report(args.output, type_names, macros)

    print(f"Processed {len(source_files)} files.")
    print(f"Discovered {len(type_names)} data types (including macro aliases).")
    if macros:
        print(f"Found {len(macros)} macros referencing discovered types.")
    print(f"Report written to {args.output.resolve()}")


if __name__ == "__main__":
    main()
