typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    word;
typedef enum Elf_SectionHeaderType_ARM {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_ARM_EXIDX=1879048193,
    SHT_ARM_PREEMPTMAP=1879048194,
    SHT_ARM_ATTRIBUTES=1879048195,
    SHT_ARM_DEBUGOVERLAY=1879048196,
    SHT_ARM_OVERLAYSECTION=1879048197
} Elf_SectionHeaderType_ARM;

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_ARM sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};



undefined4 ak_info_dump_obj;
undefined DAT_000101a8;
undefined1 ak_info_dump_group;

void sensor_id_read(undefined4 param_1,undefined4 param_2,char *param_3)

{
  undefined4 uVar1;
  
  uVar1 = aksensor_get_sensor_id();
  sprintf(param_3,"0x%x\n",uVar1);
  return;
}



void reserved_mem_size_read(undefined4 param_1,undefined4 param_2,char *param_3)

{
  sprintf(param_3,"0x%x\n",0x1800000);
  return;
}



undefined4
ak_info_dump_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  
  printk(&DAT_000101a8,"ak_info_dump_init",param_3,param_4,param_4);
  ak_info_dump_obj = kobject_create_and_add("ak_info_dump",0);
  if (ak_info_dump_obj == 0) {
    pcVar2 = "\nobject_create_and_add ERROR : %s\n";
  }
  else {
    iVar1 = sysfs_create_group(ak_info_dump_obj,&ak_info_dump_group);
    if (iVar1 == 0) {
      return 0;
    }
    kobject_put(ak_info_dump_obj);
    sysfs_remove_group(ak_info_dump_obj,&ak_info_dump_group);
    pcVar2 = "\nsysfs_create_group ERROR : %s\n";
  }
  printk(pcVar2,"ak_info_dump_init");
  return 0;
}



void ak_info_dump_exit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  printk(&DAT_000101a8,"ak_info_dump_exit",param_3,param_4,param_4);
  kobject_put(ak_info_dump_obj);
  sysfs_remove_group(ak_info_dump_obj,&ak_info_dump_group);
  return;
}


