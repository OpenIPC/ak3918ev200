# AK391X Hardware Design Guide Notes

Source: `AK391X芯片硬件设计指南_V1.0.1.pdf`

## English summary
The guide provides reference hardware design rules for Anyka AK391X series (including AK3918). It focuses on PCB layout, power delivery, clock circuitry, and external peripheral connections.

## Design highlights
- **Power architecture**: Details recommended regulators for core (1.2 V), DDR (1.5 V), analog (2.8 V), and I/O (3.3 V). Emphasises sequencing (core → analog → IO) and ramp rates (<2 ms).
- **Clock sources**: Specifies crystal load capacitance (18 pF typical), routing guidelines (<20 mm, guard traces), and jitter tolerances for video-quality clocks.
- **DDR routing**: 16-bit bus impedance control (50 Ω single-ended / 100 Ω differential), length-matching within ±10 mil, and the need for VTT termination if bus length > 2 inches.
- **EMI/ESD**: Recommends common-mode chokes on sensor signals, TVS diodes on Ethernet/USB, layout keep-outs near RF modules.
- **Thermal**: Suggests 4-layer stack with dedicated ground plane and copper pour under SoC for heat dissipation.

## OpenIPC relevance
- Aligns with hardware bring-up checklists when validating third-party boards. We should verify voltage sequencing before enabling peripherals via the supervisor agent.
- Provides numeric constraints for `docs/reference/hardware/aimer39_board_design_notes.md` (mirrored there for AK3918-specific boards).
- Use recommended GPIO voltage domains to annotate `include/ak3918/gpio.h` constants (TODO: add comments referencing safe ranges).

## Follow-up tasks
- Create schematic checklist for community hardware projects referencing these limits.
- Add voltage/clock diagrams to the README hardware section.
