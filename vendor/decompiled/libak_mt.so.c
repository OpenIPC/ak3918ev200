typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    word;
typedef ulong size_t;

typedef uint __useconds_t;

typedef enum Elf32_DynTag_ARM {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf32_DynTag_ARM;

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_ARM {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482,
    PT_ARM_EXIDX=1879048192
} Elf_ProgramHeaderType_ARM;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_ARM p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

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

typedef struct Elf32_Dyn_ARM Elf32_Dyn_ARM, *PElf32_Dyn_ARM;

struct Elf32_Dyn_ARM {
    enum Elf32_DynTag_ARM d_tag;
    dword d_val;
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

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;



dword __FRAME_END__;
pointer __DT_PLTGOT;
undefined4 __dso_handle;
undefined1 completed.8817;
undefined4 __JCR_END__;
undefined1[24] object.8822;
undefined1 angle_time.6321;
undefined1[130] block_angle.6320;

int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = usleep(__useconds);
  return iVar1;
}



void mt_rect_optimization(void)

{
  mt_rect_optimization();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = malloc(__size);
  return pvVar1;
}



void mt_mrd_expand(void)

{
  mt_mrd_expand();
  return;
}



void mt_get_rotation_angle_v(void)

{
  mt_get_rotation_angle_v();
  return;
}



void __deregister_frame_info(void)

{
  __deregister_frame_info();
  return;
}



void mt_shadow_removal(void)

{
  mt_shadow_removal();
  return;
}



void ak_mt_mrd(void)

{
  ak_mt_mrd();
  return;
}



void mt_reset_tracking_param(void)

{
  mt_reset_tracking_param();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



void mt_get_rotation_angle(void)

{
  mt_get_rotation_angle();
  return;
}



void mt_mrd_Isoutofcenter(void)

{
  mt_mrd_Isoutofcenter();
  return;
}



void mt_quicksort(void)

{
  mt_quicksort();
  return;
}



void mt_member_copy(void)

{
  mt_member_copy();
  return;
}



void __register_frame_info(void)

{
  __register_frame_info();
  return;
}



void mt_tracking_max_distance(void)

{
  mt_tracking_max_distance();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = raise(__sig);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void free(void *__ptr)

{
  free(__ptr);
  return;
}



// WARNING: Removing unreachable block (ram,0x00010ca8)
// WARNING: Removing unreachable block (ram,0x00010cb4)
// WARNING: Removing unreachable block (ram,0x00010cb8)

void processEntry deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00010d00)
// WARNING: Removing unreachable block (ram,0x00010d0c)
// WARNING: Removing unreachable block (ram,0x00010d10)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &__DT_PLTGOT;
  if (completed_8817 == '\0') {
    __cxa_finalize(__dso_handle);
    deregister_tm_clones();
    if (ppuVar1[0x19] != (undefined *)0x0) {
      __deregister_frame_info(&__FRAME_END__);
    }
    completed_8817 = 1;
    return;
  }
  return;
}



void frame_dummy(void)

{
  __register_frame_info(&__FRAME_END__,object_8822);
  if (__JCR_END__ != 0) {
    _Jv_RegisterClasses();
  }
  register_tm_clones();
  return;
}



undefined4 ak_mt_destroy(void *param_1)

{
  if (param_1 == (void *)0x0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  free(param_1);
  return 0;
}



undefined4 ak_mt_set_fps(int param_1,int param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 < 1) {
    param_2 = 0x19;
  }
  *(short *)(param_1 + 0xa6a) = (short)param_2;
  return 0;
}



undefined4 ak_mt_set_max_invalid_frames(int param_1,uint param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 < 0x191) {
    if (param_2 < 0x14) {
      puts("input is out of capacity, now use the min accessible value instead");
      param_2 = 0x14;
    }
  }
  else {
    puts("input is out of capacity, now use the max accessible value instead");
    param_2 = 400;
  }
  *(short *)(param_1 + 0xa7c) = (short)param_2;
  return 0;
}



undefined4 ak_mt_set_max_decision_frames(int param_1,uint param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 < 0x15) {
    if (param_2 < 3) {
      puts("input is out of capacity, now use the min accessible value instead");
      param_2 = 3;
    }
  }
  else {
    puts("input is out of capacity, now use the max accessible value instead");
    param_2 = 0x14;
  }
  *(char *)(param_1 + 0xa7e) = (char)param_2;
  *(char *)(param_1 + 0xa7f) = (char)param_2;
  return 0;
}



undefined4 ak_mt_set_wait_time(int param_1,undefined2 param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(undefined2 *)(param_1 + 0xa82) = param_2;
  return 0;
}



undefined4 ak_mt_set_invalid_distance(int param_1,undefined1 param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(undefined1 *)(param_1 + 0xa9e) = param_2;
  return 0;
}



undefined4
ak_mt_set_camera_rotation_range(int param_1,int param_2,int param_3,int param_4,short param_5)

{
  int iVar1;
  int iVar2;
  int unaff_r4;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_5;
  if (param_1 != 0) {
    iVar2 = param_3;
    iVar1 = param_2;
    if (param_3 < param_2) {
      iVar2 = param_2;
      iVar1 = param_3;
      unaff_r4 = param_2;
    }
    if (iVar3 < param_4) {
      unaff_r4 = param_4;
    }
    iVar4 = iVar3;
    if (iVar3 < param_4) {
      iVar4 = unaff_r4;
      param_4 = iVar3;
    }
    *(ushort *)(param_1 + 0xa90) = (ushort)iVar1 & ~(ushort)(iVar1 >> 0x1f);
    if (0x167 < iVar2) {
      iVar2 = 0x168;
    }
    *(short *)(param_1 + 0xa92) = (short)iVar2;
    *(ushort *)(param_1 + 0xa94) = (ushort)param_4 & ~(ushort)(param_4 >> 0x1f);
    if (0x167 < iVar4) {
      iVar4 = 0x168;
    }
    *(short *)(param_1 + 0xa96) = (short)iVar4;
    return 0;
  }
  puts("mt_handle is NULL");
  return 0xffffffff;
}



undefined4 ak_mt_set_mrd_filters(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = param_3;
    if (param_2 < param_3) {
      uVar1 = param_2;
      param_2 = param_3;
    }
    *(short *)(param_1 + 0xa78) = (short)param_2;
    *(short *)(param_1 + 0xa7a) = (short)uVar1;
    return 0;
  }
  puts("mt_handle is NULL");
  return 0xffffffff;
}



undefined4 ak_mt_set_camera_init_angle(int param_1,int param_2,int param_3)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 < *(short *)(param_1 + 0xa90)) {
    param_2 = (int)*(short *)(param_1 + 0xa90);
  }
  if (*(short *)(param_1 + 0xa92) <= param_2) {
    param_2 = (int)*(short *)(param_1 + 0xa92);
  }
  if (param_3 < *(short *)(param_1 + 0xa94)) {
    param_3 = (int)*(short *)(param_1 + 0xa96);
  }
  *(short *)(param_1 + 0xa8c) = (short)param_2;
  if (*(short *)(param_1 + 0xa96) <= param_3) {
    param_3 = (int)*(short *)(param_1 + 0xa96);
  }
  *(short *)(param_1 + 0xa8e) = (short)param_3;
  return 0;
}



undefined4 ak_mt_set_camera_rotation_factor(int param_1,int param_2)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 == 0) {
    param_2 = 0x100;
  }
  *(int *)(param_1 + 0xa98) = param_2;
  return 0;
}



undefined4 ak_mt_update_camera_angle(int param_1,int param_2,int param_3)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  if (param_2 < *(short *)(param_1 + 0xa90)) {
    param_2 = (int)*(short *)(param_1 + 0xa90);
  }
  if (*(short *)(param_1 + 0xa92) <= param_2) {
    param_2 = (int)*(short *)(param_1 + 0xa92);
  }
  if (param_3 < *(short *)(param_1 + 0xa94)) {
    param_3 = (int)*(short *)(param_1 + 0xa96);
  }
  *(short *)(param_1 + 0xa64) = (short)param_2;
  if (*(short *)(param_1 + 0xa96) <= param_3) {
    param_3 = (int)*(short *)(param_1 + 0xa96);
  }
  *(short *)(param_1 + 0xa66) = (short)param_3;
  return 0;
}



undefined4 ak_mt_open_camera_rotation_switch_v(int param_1)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(undefined1 *)(param_1 + 0xa77) = 1;
  return 0;
}



undefined4 ak_mt_close_camera_rotation_switch_v(int param_1)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(undefined1 *)(param_1 + 0xa77) = 0;
  return 0;
}



undefined4 ak_mt_reverse_rotation_direction_h(int param_1)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(short *)(param_1 + 0xa88) = -*(short *)(param_1 + 0xa88);
  return 0;
}



undefined4 ak_mt_reverse_rotation_direction_v(int param_1)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  *(short *)(param_1 + 0xa8a) = -*(short *)(param_1 + 0xa8a);
  return 0;
}



undefined4
ak_mt_set_motion_region_params
          (int param_1,int param_2,int param_3,int param_4,short param_5,short param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)param_5;
  iVar2 = (int)param_6;
  if (param_1 == 0) {
    puts("mt_handle is NULL");
  }
  else {
    if ((uint)((param_2 + -1) * 0x10000) < 0x1f0001) {
      iVar1 = param_4;
      if (param_4 < param_3) {
        iVar1 = param_3;
        param_3 = param_4;
      }
      if (iVar1 < 1) {
        iVar1 = 1;
      }
      if (iVar3 < 0) {
        iVar3 = iVar3 * -0x10000 >> 0x10;
      }
      if (0x20 < iVar3 * 2) {
        iVar3 = 0x10;
      }
      if (iVar2 < 0) {
        iVar2 = iVar2 * -0x10000 >> 0x10;
      }
      if (param_2 < iVar2 * 2) {
        iVar2 = param_2 >> 1;
      }
      *(short *)(param_1 + 0xa6c) = (short)param_3;
      *(short *)(param_1 + 0xa6e) = (short)iVar1;
      *(short *)(param_1 + 0xa70) = (short)iVar3;
      *(short *)(param_1 + 0xa72) = (short)iVar2;
      return 0;
    }
    printf("Input is out of range ,the avaliable value of parameter len is 1 to %d\n",0x20,param_3,
           param_4,param_4);
  }
  return 0xffffffff;
}



void mt_reset_tracking_param(int param_1)

{
  *(undefined2 *)(param_1 + 0x9f8) = 0;
  *(undefined1 *)(param_1 + 0x9fa) = 0;
  *(undefined1 *)(param_1 + 0xa0f) = 0;
  *(undefined1 *)(param_1 + 0xa24) = 0;
  *(undefined1 *)(param_1 + 0xa39) = 0;
  *(undefined1 *)(param_1 + 0xa4e) = 0;
  *(undefined1 *)(param_1 + 0xa63) = 0;
  *(undefined1 *)(param_1 + 0xa68) = 0;
  *(undefined1 *)(param_1 + 0xa69) = 0;
  *(undefined1 *)(param_1 + 0xa75) = 0;
  *(undefined2 *)(param_1 + 0xa9c) = 0;
  *(undefined2 *)(param_1 + 0xa86) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  return;
}



void * ak_mt_init(void)

{
  void *__s;
  
  __s = malloc(0xaa0);
  if (__s == (void *)0x0) {
    puts("memory allocation failed!");
  }
  else {
    printf("########%s########\n","MT Lib V1.0.05");
    memset(__s,0,0xaa0);
    *(undefined2 *)((int)__s + 0xa90) = 0;
    *(undefined2 *)((int)__s + 0xa92) = 0x15e;
    *(undefined2 *)((int)__s + 0xa94) = 0;
    *(undefined2 *)((int)__s + 0xa96) = 0x82;
    *(undefined1 *)((int)__s + 0xa74) = 1;
    mt_reset_tracking_param(__s);
    *(undefined2 *)((int)__s + 0xa8c) = 0xb4;
    *(undefined2 *)((int)__s + 0xa8e) = 0x41;
    *(undefined2 *)((int)__s + 0xa64) = 0xb4;
    *(undefined2 *)((int)__s + 0xa66) = 0x41;
    *(undefined1 *)((int)__s + 0xa76) = 1;
    *(undefined1 *)((int)__s + 0xa77) = 0;
    *(undefined2 *)((int)__s + 0xa6c) = 1;
    *(undefined2 *)((int)__s + 0xa6e) = 0x300;
    *(undefined2 *)((int)__s + 0xa70) = 9;
    *(undefined2 *)((int)__s + 0xa72) = 8;
    *(undefined2 *)((int)__s + 0xa78) = 12000;
    *(undefined2 *)((int)__s + 0xa7a) = 6000;
    *(undefined2 *)((int)__s + 0xa6a) = 0x19;
    *(undefined2 *)((int)__s + 0xa7c) = 200;
    *(undefined1 *)((int)__s + 0xa7e) = 7;
    *(undefined1 *)((int)__s + 0xa7f) = 7;
    *(undefined1 *)((int)__s + 0xa80) = 0x14;
    *(undefined2 *)((int)__s + 0xa82) = 500;
    *(undefined2 *)((int)__s + 0xa84) = 0;
    *(undefined2 *)((int)__s + 0xa86) = 0;
    *(undefined2 *)((int)__s + 0xa88) = 1;
    *(undefined2 *)((int)__s + 0xa8a) = 1;
    *(undefined1 *)((int)__s + 0xa9e) = 8;
    *(undefined4 *)((int)__s + 0xa98) = 0x100;
    *(undefined2 *)((int)__s + 0xa9c) = 0;
  }
  return __s;
}



undefined4 ak_mt_wait_camera_rotation(int param_1)

{
  if (param_1 == 0) {
    puts("mt_handle is NULL");
    return 0xffffffff;
  }
  mt_reset_tracking_param();
  *(undefined1 *)(param_1 + 0xa74) = 0;
  return 0;
}



void mt_member_copy(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
  return;
}



void mt_mrd_expand(int param_1,int param_2,int param_3,ushort *param_4)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  short sVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  
  bVar5 = true;
  uVar14 = 1;
  bVar7 = true;
  bVar16 = true;
LAB_000115e4:
  do {
    uVar9 = (uint)*param_4;
    uVar10 = (uint)param_4[1];
    iVar11 = uVar9 + (byte)param_4[2];
    bVar15 = uVar9 != 0;
    sVar1 = (short)iVar11;
    uVar12 = iVar11 * 0x10000 - 0x10000;
    if (bVar15) {
      uVar9 = uVar9 - 1;
    }
    uVar3 = uVar12 >> 0x10;
    iVar11 = uVar10 + *(byte *)((int)param_4 + 5);
    if (bVar15) {
      uVar9 = uVar9 << 0x10;
    }
    uVar8 = uVar9;
    if (bVar15) {
      uVar9 = uVar9 >> 0x10;
      uVar8 = uVar14;
    }
    uVar14 = uVar8;
    if (uVar3 != 0x1e && 0x1dffff < (int)(uVar3 * 0x10000)) {
      bVar16 = false;
      sVar1 = (short)(uVar12 >> 0x10);
    }
    sVar2 = (short)((uint)(iVar11 * 0x10000 + -0x10000) >> 0x10);
    if (uVar10 == 0) {
      uVar10 = 0;
      bVar7 = false;
    }
    else {
      uVar10 = uVar10 - 1 & 0xffff;
    }
    sVar13 = sVar2;
    if ((int)sVar2 < param_3 + -1) {
      sVar13 = (short)iVar11;
    }
    if (param_3 + -1 <= (int)sVar2) {
      bVar5 = false;
    }
    iVar11 = (int)sVar1;
    for (uVar12 = uVar9; (short)uVar12 <= iVar11; uVar12 = uVar12 + 1 & 0xffff) {
      if (*(ushort *)(param_1 + 0xa7a) <
          *(ushort *)(param_2 + ((int)(uVar10 << 0x10) >> 10) + (short)uVar12 * 2)) {
        param_4[1] = (ushort)uVar10;
        goto LAB_000116d8;
      }
    }
    bVar7 = false;
LAB_000116d8:
    iVar4 = (int)sVar13;
    for (uVar12 = uVar9; (short)uVar12 <= iVar11; uVar12 = uVar12 + 1 & 0xffff) {
      if (*(ushort *)(param_1 + 0xa7a) < *(ushort *)(param_2 + iVar4 * 0x40 + (short)uVar12 * 2)) {
        *(char *)((int)param_4 + 5) = (char)sVar13 + ('\x01' - (char)param_4[1]);
        goto LAB_0001174c;
      }
    }
    bVar5 = false;
LAB_0001174c:
    for (uVar12 = uVar10; (short)uVar12 <= iVar4; uVar12 = uVar12 + 1 & 0xffff) {
      if (*(ushort *)(param_1 + 0xa7a) <
          *(ushort *)(param_2 + ((int)(uVar9 << 0x10) >> 0xf) + (short)uVar12 * 0x40)) {
        *param_4 = (ushort)uVar9;
        goto LAB_000117b0;
      }
    }
    uVar14 = 0;
LAB_000117b0:
    for (; (short)uVar10 <= iVar4; uVar10 = uVar10 + 1 & 0xffff) {
      if (*(ushort *)(param_1 + 0xa7a) < *(ushort *)(param_2 + iVar11 * 2 + (short)uVar10 * 0x40)) {
        *(char *)(param_4 + 2) = (char)sVar1 + ('\x01' - (char)*param_4);
        bVar15 = bVar16;
        if (uVar14 != 1) goto LAB_0001181c;
        goto LAB_000115e4;
      }
    }
    bVar16 = uVar14 == 1;
    bVar15 = false;
LAB_0001181c:
    bVar6 = !bVar16;
    bVar16 = bVar15;
    if (((bVar6) && (!bVar7)) && (!bVar5)) {
      return;
    }
  } while( true );
}



void mt_swap(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  return;
}



void mt_quicksort(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_4;
  while (param_3 < param_4) {
    uVar6 = param_3 + 1U & 0xffff;
    iVar7 = param_4;
    while( true ) {
      sVar5 = (short)uVar6;
      uVar3 = *(ushort *)(param_1 + param_3 * 2);
      iVar1 = sVar5 * 2;
      if (iVar7 <= sVar5) break;
      uVar4 = *(ushort *)(param_1 + iVar1);
      if (uVar3 < uVar4) {
        iVar2 = iVar7 * 2;
        *(undefined2 *)(param_1 + iVar1) = *(undefined2 *)(param_1 + iVar2);
        iVar7 = (iVar7 + -1) * 0x10000 >> 0x10;
        *(ushort *)(param_1 + iVar2) = uVar4;
      }
      else {
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
    if (uVar3 <= *(ushort *)(param_1 + iVar1)) {
      sVar5 = sVar5 + -1;
    }
    iVar1 = sVar5 * 2;
    *(undefined2 *)(param_1 + param_3 * 2) = *(undefined2 *)(param_1 + iVar1);
    *(ushort *)(param_1 + iVar1) = uVar3;
    mt_quicksort(param_1,param_2,param_3,(int)sVar5,iVar8);
    param_3 = iVar7;
  }
  return;
}



void mt_shadow_removal(int param_1,int param_2,int param_3,ushort *param_4)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  int iVar13;
  ushort local_828 [1026];
  
  memset(local_828,0,0x800);
  uVar11 = *(ushort *)(param_1 + 0xa78);
  uVar12 = *(ushort *)(param_1 + 0xa7a);
  iVar6 = param_2;
  for (uVar5 = 0; (short)uVar5 < param_3; uVar5 = uVar5 + 1 & 0xffff) {
    iVar8 = 0;
    do {
      iVar13 = ((uVar5 << 0x15) >> 0x10) + iVar8;
      iVar1 = iVar8 * 2;
      iVar8 = iVar8 + 1;
      *(undefined2 *)((int)local_828 + (iVar13 * 0x10000 >> 0xf)) = *(undefined2 *)(iVar6 + iVar1);
    } while (iVar8 != 0x20);
    iVar6 = iVar6 + 0x40;
  }
  uVar5 = param_3 * 0x200000;
  mt_quicksort(local_828,(int)uVar5 >> 0x10,0,(int)(uVar5 - 0x10000) >> 0x10);
  uVar9 = (uint)*(byte *)((int)param_4 + 5);
  if ((uint)((int)(short)(ushort)*(byte *)((int)param_4 + 5) * (int)(short)(ushort)(byte)param_4[2])
      < 0xb5) {
    iVar6 = (uVar5 >> 0x10) - 0x10;
  }
  else {
    iVar6 = (uVar5 >> 0x10) - 0x15;
  }
  uVar10 = *(ushort *)((int)local_828 + ((iVar6 << 0x10) >> 0xf));
  if (uVar10 <= *(ushort *)(param_1 + 0xa78)) {
    uVar10 = uVar11;
  }
  iVar6 = __divsi3(param_3 << 5,0xfffffffd);
  uVar11 = *(ushort *)
            ((int)local_828 + ((int)(((uVar5 - 0x10000 >> 0x10) + iVar6) * 0x10000) >> 0xf));
  if (uVar11 <= *(ushort *)(param_1 + 0xa7a)) {
    uVar11 = uVar12;
  }
  uVar12 = *param_4;
  iVar6 = __divsi3(uVar9 << 1,3);
  while( true ) {
    bVar2 = (byte)param_4[2];
    if ((int)((uint)bVar2 + (int)(short)*param_4) <= (int)(short)uVar12) break;
    uVar5 = 0;
    for (uVar4 = param_4[1]; (int)(short)uVar4 < (int)(uVar9 + (int)(short)param_4[1]);
        uVar4 = uVar4 + 1) {
      uVar3 = *(ushort *)(param_2 + (short)uVar12 * 2 + (short)uVar4 * 0x40);
      if (uVar3 < uVar10) {
        if (uVar11 < uVar3) {
          uVar5 = uVar5 + 1;
          goto LAB_00011adc;
        }
      }
      else {
        uVar5 = uVar9 + uVar5;
LAB_00011adc:
        uVar5 = uVar5 & 0xffff;
      }
    }
    if ((int)uVar9 <= (int)(short)uVar5) break;
    uVar12 = uVar12 + 1;
    if ((short)uVar5 < iVar6) {
      *param_4 = *param_4 + 1;
      *(byte *)(param_4 + 2) = bVar2 - 1;
    }
  }
  uVar5 = (uint)bVar2 + (uint)*param_4;
  do {
    uVar7 = uVar5 - 1;
    uVar5 = uVar7 & 0xffff;
    iVar8 = (int)(short)uVar7;
    if (iVar8 < (short)*param_4) {
      return;
    }
    uVar7 = 0;
    for (uVar12 = param_4[1]; (int)(short)uVar12 < (int)(uVar9 + (int)(short)param_4[1]);
        uVar12 = uVar12 + 1) {
      uVar4 = *(ushort *)(param_2 + iVar8 * 2 + (short)uVar12 * 0x40);
      if (uVar4 < uVar10) {
        if (uVar11 < uVar4) {
          uVar7 = uVar7 + 1;
          goto LAB_00011b44;
        }
      }
      else {
        uVar7 = uVar9 + uVar7;
LAB_00011b44:
        uVar7 = uVar7 & 0xffff;
      }
    }
    if ((int)uVar9 <= (int)(short)uVar7) {
      return;
    }
    if ((short)uVar7 < iVar6) {
      *(char *)(param_4 + 2) = (char)param_4[2] + -1;
    }
  } while( true );
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 ak_mt_mrd(int param_1,int param_2,int param_3,short *param_4)

{
  ushort uVar1;
  char *__s;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  short sStack_1030;
  short local_102e;
  undefined2 local_102c;
  short local_1028 [2050];
  
  if (param_1 == 0) {
    __s = "mt_handle is NULL";
  }
  else {
    if (param_4 != (short *)0x0) {
      if (param_3 < 1) {
        param_3 = 1;
      }
      else if (0x1f < param_3) {
        param_3 = 0x20;
      }
      memset(local_1028,0,0x1000);
      uVar3 = 0;
      sStack_1030 = 0;
      local_102e = 0;
      uVar1 = *(ushort *)(param_1 + 0xa78);
      uVar7 = 0;
      local_102c = 0;
      iVar2 = param_2;
      do {
        iVar6 = 0;
        uVar4 = uVar7;
        do {
          uVar7 = uVar4;
          if (uVar1 < *(ushort *)(iVar2 + iVar6 * 2)) {
            uVar7 = uVar4 + 1 & 0xffff;
            local_1028[uVar4 * 2] = (short)iVar6;
            local_1028[uVar4 * 2 + 1] = (short)uVar3;
          }
          iVar6 = iVar6 + 1;
          uVar4 = uVar7;
        } while (iVar6 != 0x20);
        uVar4 = uVar3 + 1;
        iVar2 = iVar2 + 0x40;
        uVar3 = uVar4 & 0xffff;
      } while ((int)(uVar4 * 0x10000) >> 0x10 < param_3);
      sVar8 = 0;
      *param_4 = 0;
      param_4[1] = 0;
      *(undefined1 *)((int)param_4 + 5) = 0;
      *(undefined1 *)(param_4 + 2) = 0;
      if (uVar7 == 0) {
        return 0;
      }
      for (; iVar2 = (int)sVar8, iVar2 < (int)uVar7; sVar8 = sVar8 + 1) {
        if (-1 < local_1028[iVar2 * 2]) {
          local_102e = local_1028[iVar2 * 2 + 1];
          local_102c = 0x101;
          sStack_1030 = local_1028[iVar2 * 2];
          mt_mrd_expand(param_1,param_2,param_3,&sStack_1030);
          sVar5 = sVar8;
          while( true ) {
            sVar5 = sVar5 + 1;
            iVar2 = (int)sVar5;
            if ((int)uVar7 <= iVar2) break;
            iVar6 = (int)local_1028[iVar2 * 2];
            if ((((sStack_1030 <= iVar6) &&
                 (iVar6 < (int)((int)sStack_1030 + (uint)(byte)local_102c))) &&
                ((int)local_102e <= (int)local_1028[iVar2 * 2 + 1])) &&
               ((int)local_1028[iVar2 * 2 + 1] < (int)((int)local_102e + (uint)local_102c._1_1_))) {
              local_1028[iVar2 * 2] = -1;
            }
          }
          uVar3 = (int)(short)(ushort)local_102c._1_1_ * (int)(short)(local_102c & 0xff);
          uVar4 = (int)(short)(ushort)*(byte *)((int)param_4 + 5) *
                  (int)(short)(ushort)*(byte *)(param_4 + 2);
          if (uVar3 - uVar4 != 0 && uVar4 <= uVar3) {
            mt_member_copy(param_4,&sStack_1030);
          }
        }
      }
      mt_shadow_removal(param_1,param_2,param_3,param_4);
      *param_4 = *param_4 + 1;
      param_4[1] = param_4[1] + 1;
      iVar2 = (int)(short)(ushort)*(byte *)((int)param_4 + 5) *
              (int)(short)(ushort)*(byte *)(param_4 + 2);
      if ((*(short *)(param_1 + 0xa6c) <= iVar2) &&
         (iVar2 - *(short *)(param_1 + 0xa6e) == 0 || iVar2 < *(short *)(param_1 + 0xa6e))) {
        return 1;
      }
      *param_4 = 0;
      param_4[1] = 0;
      *(undefined1 *)((int)param_4 + 5) = 0;
      *(undefined1 *)(param_4 + 2) = 0;
      return 0;
    }
    __s = "rect pointer is NULL";
  }
  puts(__s);
  return 0xffffffff;
}



bool mt_mrd_Isoutofcenter
               (undefined4 param_1,ushort *param_2,short *param_3,undefined4 param_4,short param_5)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_2 + (uint)(byte)((byte)param_2[2] >> 1) & 0xff;
  if (((int)param_5 < (int)uVar2) && ((int)uVar2 <= 0x20 - param_5)) {
    sVar1 = 0;
  }
  else {
    sVar1 = (short)uVar2 + -0x10;
  }
  *param_3 = sVar1;
  if (*param_3 < 0) {
    *param_3 = *param_3 + -1;
  }
  if (*param_3 != 0) {
    return true;
  }
  return param_3[1] != 0;
}



void mt_tracking_max_distance(int param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  
  for (uVar2 = 0; (int)uVar2 < (int)*(short *)(param_1 + 0x9f8); uVar2 = uVar2 + 1 & 0xffff) {
    iVar5 = uVar2 * 6 + param_1;
    uVar3 = 0;
    if (*(char *)(iVar5 + 0x24) != '\0') {
      sVar4 = *(short *)(iVar5 + 0x20) - *param_2;
      sVar1 = *(short *)(iVar5 + 0x22) - param_2[1];
      uVar3 = sVar1 * sVar1 + sVar4 * sVar4;
    }
    if (*(byte *)(param_1 + 0xa68) < uVar3) {
      *(char *)(param_1 + 0xa68) = (char)uVar3;
    }
  }
  return;
}



int mt_rect_optimization(int param_1)

{
  byte *pbVar1;
  short *psVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar4 = (uint)*(byte *)(param_1 + 0x9fa);
  iVar8 = (uVar4 - 2) * 6 + 0x980;
  iVar5 = (uVar4 - 1) * 6 + 0x980;
  iVar7 = (int)*(short *)(param_1 + iVar5);
  iVar6 = (int)*(short *)(param_1 + iVar8);
  iVar8 = param_1 + iVar8;
  iVar5 = param_1 + iVar5;
  if (iVar6 <= iVar7) {
    if ((int)(iVar7 + (uint)*(byte *)(iVar5 + 4)) <= (int)(iVar6 + (uint)*(byte *)(iVar8 + 4))) {
      if ((int)*(short *)(iVar8 + 2) <= (int)*(short *)(iVar5 + 2)) {
        if (((int)((int)*(short *)(iVar5 + 2) + (uint)*(byte *)(iVar5 + 5)) <=
             (int)((int)*(short *)(iVar8 + 2) + (uint)*(byte *)(iVar8 + 5))) &&
           ((uint)((int)(short)(ushort)*(byte *)(iVar5 + 5) *
                   (int)(short)(ushort)*(byte *)(iVar5 + 4) * 10) <
            (uint)((int)(short)(ushort)*(byte *)(iVar8 + 5) *
                   (int)(short)(ushort)*(byte *)(iVar8 + 4) * 5))) {
          return -1;
        }
      }
    }
  }
  param_1 = param_1 + uVar4 * 6;
  iVar5 = 1;
  while( true ) {
    if ((int)uVar4 <= iVar5) {
      return 0;
    }
    iVar8 = uVar4 - iVar5;
    if ((int)((int)*(short *)(param_1 + 0x974) + (uint)*(byte *)(param_1 + 0x978)) <=
        (int)*(short *)(param_1 + 0x97a)) {
      return iVar8;
    }
    if ((int)((int)*(short *)(param_1 + 0x97a) + (uint)*(byte *)(param_1 + 0x97e)) <=
        (int)*(short *)(param_1 + 0x974)) {
      return iVar8;
    }
    psVar2 = (short *)(param_1 + 0x97c);
    psVar3 = (short *)(param_1 + 0x976);
    if ((int)((int)*psVar3 + (uint)*(byte *)(param_1 + 0x979)) <= (int)*psVar2) break;
    pbVar1 = (byte *)(param_1 + 0x97f);
    param_1 = param_1 + -6;
    if ((int)((int)*psVar2 + (uint)*pbVar1) <= (int)*psVar3) {
      return iVar8;
    }
    iVar5 = iVar5 + 1;
  }
  return iVar8;
}



undefined4 mt_get_rotation_angle_v(int param_1,int param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)*(short *)(param_3 + 2);
  iVar3 = param_2 + 7;
  if (-1 < param_2) {
    iVar3 = param_2;
  }
  if (iVar3 >> 3 < iVar4) {
    sVar1 = __divsi3(param_2,3,param_3,iVar3,param_4);
    if ((iVar4 <= sVar1) || ((int)(iVar4 + (uint)*(byte *)(param_3 + 5)) < param_2 + -1)) {
      return 0;
    }
    uVar2 = 0xfffb;
  }
  else {
    uVar2 = 5;
  }
  *(undefined2 *)(param_1 + 0xa86) = uVar2;
  return 1;
}



undefined4 mt_get_rotation_angle(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  undefined4 local_30;
  undefined2 local_2c;
  
  uVar11 = (uint)*(byte *)(param_1 + 0x9fa);
  if (uVar11 < 2) {
    iVar9 = -1;
  }
  else {
    iVar9 = mt_rect_optimization();
    local_30 = 0;
    local_2c = 0;
    if (iVar9 == -1) {
      iVar4 = param_1;
      if (uVar11 != 2) {
        bVar12 = uVar11 == 3;
        goto LAB_000121b0;
      }
LAB_00012214:
      mt_member_copy(&local_30,iVar4 + 0x980);
    }
    else {
      if (iVar9 == uVar11 - 1) {
        iVar4 = iVar9 * 6 + param_1;
        goto LAB_00012214;
      }
      bVar12 = uVar11 == 2;
LAB_000121b0:
      if (bVar12) {
        uVar3 = __divsi3(*(short *)(param_1 + 0x982) * 4 + *(short *)(param_1 + 0x988) * 6,10);
        local_30 = CONCAT22(uVar3,(undefined2)local_30);
        iVar4 = (uint)*(byte *)(param_1 + 0x985) * 4 + (uint)*(byte *)(param_1 + 0x98b) * 6;
      }
      else {
        iVar7 = (uVar11 - 2) * 6 + param_1;
        iVar4 = (uVar11 - 3) * 6 + param_1;
        uVar3 = __divsi3(*(short *)((uVar11 - 4) * 6 + param_1 + 0x982) * 2 +
                         *(short *)(iVar7 + 0x982) * 5 + *(short *)(iVar4 + 0x982) * 3,10);
        local_30 = CONCAT22(uVar3,(undefined2)local_30);
        bVar1 = *(byte *)(iVar7 + 0x985);
        iVar4 = (uint)bVar1 * 2 + (short)(ushort)bVar1 * 5 + (uint)*(byte *)(iVar4 + 0x985) * 3;
      }
      uVar2 = __divsi3(iVar4,10);
      local_2c = CONCAT11(uVar2,(undefined1)local_2c);
    }
    mt_get_rotation_angle_v(param_1,param_2,&local_30);
  }
  uVar11 = (uint)*(byte *)(param_1 + 0xa0f);
  uVar8 = (uint)*(byte *)(param_1 + 0xa24);
  if (uVar8 < uVar11) {
    iVar4 = (uVar11 - 1) * 6 + param_1;
    bVar1 = *(byte *)(iVar4 + 0x984);
    iVar4 = (int)(short)(*(short *)(iVar4 + 0x980) + (ushort)(bVar1 >> 1));
    if ((bVar1 & 1) == 0) {
      uVar11 = (iVar4 + -0x11) * 0x20000;
    }
    else {
      uVar11 = iVar4 * 0x20000 - 0x210000;
    }
    uVar11 = uVar11 >> 0x10;
    if ((iVar9 == -1) || (iVar9 == *(byte *)(param_1 + 0x9fa) - 1)) {
LAB_000123d8:
      uVar8 = 0;
    }
    else {
      iVar7 = iVar9 * 6 + param_1;
      iVar4 = iVar4 - ((int)(((uint)*(ushort *)(iVar7 + 0x980) +
                             (uint)(*(byte *)(iVar7 + 0x984) >> 1)) * 0x10000) >> 0x10);
LAB_000123d0:
      uVar8 = iVar4 << 1;
    }
  }
  else {
    if (uVar11 < uVar8) {
      iVar4 = (uVar8 - 1) * 6 + param_1;
      bVar1 = *(byte *)(iVar4 + 0x984);
      iVar4 = (int)(short)(*(short *)(iVar4 + 0x980) + (ushort)(bVar1 >> 1));
      if ((bVar1 & 1) == 0) {
        uVar11 = (0x11 - iVar4) * 0x20000;
      }
      else {
        uVar11 = (0x10 - iVar4) * 0x20000 + 0x10000;
      }
      uVar11 = uVar11 >> 0x10;
      if ((iVar9 == -1) || (iVar9 == *(byte *)(param_1 + 0x9fa) - 1)) goto LAB_000123d8;
      iVar7 = iVar9 * 6 + param_1;
      iVar4 = ((int)(((uint)*(ushort *)(iVar7 + 0x980) + (uint)(*(byte *)(iVar7 + 0x984) >> 1)) *
                    0x10000) >> 0x10) - iVar4;
      goto LAB_000123d0;
    }
    uVar8 = 0;
    uVar11 = uVar8;
  }
  iVar7 = *(int *)(param_1 + 0xa98);
  iVar4 = (int)(short)uVar11;
  if ((iVar7 < 0) || (uVar8 == 0)) {
    iVar9 = iVar4;
    if ((iVar4 - 0xbU < 0x31) && (*(byte *)(param_1 + 0x9fa) < *(byte *)(param_1 + 0xa7e)))
    goto LAB_00012438;
  }
  else {
    uVar11 = (uint)*(byte *)(param_1 + 0x9fa);
    if ((int)uVar8 < 1) {
      if ((10 < iVar4) && (uVar11 < *(byte *)(param_1 + 0xa7e))) goto LAB_00012438;
      iVar5 = __divsi3(1000,(int)*(short *)(param_1 + 0xa6a));
      iVar6 = __divsi3(uVar8 * 0x100 *
                       (int)*(short *)(&angle_time_6321 +
                                      *(short *)(block_angle_6320 + iVar4 * 2) * 2),
                       iVar5 * (((uVar11 - 1) - iVar9) + (int)*(short *)(param_1 + 0xa9c)));
      iVar10 = 0;
      while ((iVar9 = iVar4 - iVar10, iVar4 < iVar9 - (iVar6 >> 8) &&
             (iVar10 = iVar10 + 1, 0 < (iVar4 + 1) - iVar10))) {
        iVar6 = __divsi3(uVar8 * 0x100 *
                         (int)*(short *)(&angle_time_6321 +
                                        *(short *)(block_angle_6320 + iVar10 * -2 + iVar4 * 2) * 2),
                         (uVar11 - 1) * iVar5);
      }
    }
    else {
      if ((iVar4 < 0x3c) && (uVar11 < *(byte *)(param_1 + 0xa7e))) {
LAB_00012438:
        *(undefined2 *)(param_1 + 0xa86) = 0;
        return 0;
      }
      iVar5 = __divsi3(1000,(int)*(short *)(param_1 + 0xa6a));
      iVar6 = __divsi3(uVar8 * 0x100 *
                       (int)*(short *)(&angle_time_6321 +
                                      *(short *)(block_angle_6320 + iVar4 * 2) * 2),
                       iVar5 * (((uVar11 - 1) - iVar9) + (int)*(short *)(param_1 + 0xa9c)));
      iVar10 = 0;
      while ((iVar9 = iVar10 + iVar4, iVar9 - (iVar6 >> 8) < iVar4 &&
             (iVar10 = iVar10 + 1, iVar4 + -1 + iVar10 < 0x40))) {
        iVar6 = __divsi3(uVar8 * 0x100 *
                         (int)*(short *)(&angle_time_6321 +
                                        *(short *)(block_angle_6320 + iVar10 * 2 + iVar4 * 2) * 2),
                         (uVar11 - 1) * iVar5);
      }
    }
  }
  iVar7 = iVar7 * iVar9;
  uVar11 = iVar7 >> 8;
  if ((int)uVar11 < 0x41) {
    uVar11 = uVar11 & ~(iVar7 >> 0x1f);
  }
  else {
    uVar11 = 0x40;
  }
  uVar3 = *(undefined2 *)(block_angle_6320 + uVar11 * 2);
  if (*(short *)(block_angle_6320 + uVar11 * 2) < 6) {
    uVar3 = 0;
  }
  *(undefined2 *)(param_1 + 0xa84) = uVar3;
  return 1;
}



undefined4
ak_mt_tracking(int param_1,undefined4 param_2,int param_3,undefined4 param_4,ushort *param_5)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  char *__s;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  int aiStack_34 [5];
  
  if (param_1 == 0) {
    __s = "mt_handle is NULL";
  }
  else {
    if (param_5 != (ushort *)0x0) {
      if (param_3 < 1) {
        param_3 = 1;
      }
      else if (0x1f < param_3) {
        param_3 = 0x20;
      }
      *param_5 = 0;
      param_5[1] = 0;
      if (*(char *)(param_1 + 0xa74) != '\x01') {
        usleep((uint)*(ushort *)(param_1 + 0xa82) * 1000);
        *(undefined1 *)(param_1 + 0xa74) = 1;
        return 0;
      }
      cVar2 = ak_mt_mrd(param_1,param_2,param_3,param_4);
      if (cVar2 == '\x01') {
        local_40 = 0;
        cVar2 = mt_mrd_Isoutofcenter
                          (param_1,param_4,&local_40,param_3,(int)*(short *)(param_1 + 0xa70),
                           (int)*(short *)(param_1 + 0xa72));
        if (cVar2 == '\x01') {
          *(undefined1 *)(param_1 + 0x1e) = 0;
          *(undefined1 *)(param_1 + 0xa75) = 1;
          if ((short)local_40 < 1) {
            if ((short)local_40 != 0) {
              if (*(char *)(param_1 + 0xa0f) != '\0') {
                *(undefined1 *)(param_1 + 0xa0f) = 0;
                *(undefined1 *)(param_1 + 0x9fa) = 0;
              }
              *(char *)(param_1 + 0xa24) = *(char *)(param_1 + 0xa24) + '\x01';
            }
          }
          else {
            if (*(char *)(param_1 + 0xa24) != '\0') {
              *(undefined1 *)(param_1 + 0xa24) = 0;
              *(undefined1 *)(param_1 + 0x9fa) = 0;
            }
            *(char *)(param_1 + 0xa0f) = *(char *)(param_1 + 0xa0f) + '\x01';
          }
          mt_member_copy((uint)*(byte *)(param_1 + 0x9fa) * 6 + param_1 + 0x980,param_4);
          *(char *)(param_1 + 0x9fa) = *(char *)(param_1 + 0x9fa) + '\x01';
          cVar2 = mt_get_rotation_angle(param_1,param_3);
          if (cVar2 == '\x01') {
            if ((*(byte *)(param_1 + 0xa24) < *(byte *)(param_1 + 0xa0f)) &&
               (*(byte *)(param_1 + 0xa63) < *(byte *)(param_1 + 0xa0f))) {
              *param_5 = *(ushort *)(param_1 + 0xa88);
            }
            if ((*(byte *)(param_1 + 0xa0f) < *(byte *)(param_1 + 0xa24)) &&
               (*(byte *)(param_1 + 0xa63) < *(byte *)(param_1 + 0xa24))) {
              *param_5 = -*(short *)(param_1 + 0xa88);
            }
            iVar10 = (int)(((uint)*param_5 * (uint)*(ushort *)(param_1 + 0xa84) +
                           (uint)*(ushort *)(param_1 + 0xa64)) * 0x10000) >> 0x10;
            if (iVar10 < *(short *)(param_1 + 0xa90)) {
              iVar10 = (int)*(short *)(param_1 + 0xa90);
            }
            iVar8 = (int)(((uint)*(ushort *)(param_1 + 0xa86) * (uint)*(ushort *)(param_1 + 0xa8a) +
                          (uint)*(ushort *)(param_1 + 0xa66)) * 0x10000) >> 0x10;
            if (iVar8 < *(short *)(param_1 + 0xa94)) {
              iVar8 = (int)*(short *)(param_1 + 0xa94);
            }
            if (*(short *)(param_1 + 0xa96) <= iVar8) {
              iVar8 = (int)*(short *)(param_1 + 0xa96);
            }
            if (*(short *)(param_1 + 0xa92) <= iVar10) {
              iVar10 = (int)*(short *)(param_1 + 0xa92);
            }
            *param_5 = (ushort)iVar10;
            param_5[1] = (ushort)iVar8;
            if (*(char *)(param_1 + 0xa77) == '\0') {
              param_5[1] = *(ushort *)(param_1 + 0xa66);
            }
            if (*(char *)(param_1 + 0xa76) == '\0') {
              *param_5 = *(ushort *)(param_1 + 0xa64);
            }
            if ((*param_5 == *(ushort *)(param_1 + 0xa64)) &&
               (param_5[1] == *(ushort *)(param_1 + 0xa66))) {
              *(undefined1 *)(param_1 + 0xa75) = 0;
              *(undefined1 *)(param_1 + 0x9fa) = 0;
              *(undefined1 *)(param_1 + 0xa0f) = 0;
              *(undefined1 *)(param_1 + 0xa24) = 0;
              *(undefined1 *)(param_1 + 0xa39) = 0;
              *(undefined1 *)(param_1 + 0xa4e) = 0;
              *(undefined1 *)(param_1 + 0xa63) = 0;
              return 0;
            }
            mt_reset_tracking_param(param_1);
            if (*(char *)(param_1 + 0xa7f) == *(char *)(param_1 + 0xa7e)) {
              *(char *)(param_1 + 0xa7e) = *(char *)(param_1 + 0xa7f) + -2;
            }
            return 1;
          }
        }
        else {
          if (*(char *)(param_1 + 0xa77) == '\x01') {
            memset(aiStack_34,0,0x14);
            aiStack_34[1] = 2;
            aiStack_34[2] = 3;
            aiStack_34[3] = 5;
            local_3c = 0;
            local_38 = 0;
            mt_member_copy((uint)*(byte *)(param_1 + 0x1e) * 6 + param_1,param_4);
            bVar3 = *(char *)(param_1 + 0x1e) + 1;
            *(byte *)(param_1 + 0x1e) = bVar3;
            if (4 < bVar3) {
              uVar6 = local_3c >> 0x10;
              uVar11 = (uint)local_38._1_1_;
              iVar8 = param_1;
              for (iVar10 = 1; iVar10 < (int)(bVar3 - 1); iVar10 = iVar10 + 1) {
                iVar12 = aiStack_34[iVar10];
                uVar6 = iVar12 * (uint)*(ushort *)(iVar8 + 8) + (uVar6 & 0xffff);
                pbVar1 = (byte *)(iVar8 + 0xb);
                iVar8 = iVar8 + 6;
                uVar11 = iVar12 * (uint)*pbVar1 + uVar11 & 0xff;
              }
              uVar5 = __divsi3((int)(short)uVar6,10);
              local_3c = CONCAT22(uVar5,(undefined2)local_3c);
              uVar4 = __aeabi_uidiv(uVar11,10);
              local_38 = CONCAT11(uVar4,(undefined1)local_38);
              cVar2 = mt_get_rotation_angle_v(param_1,param_3,&local_3c);
              if (cVar2 != '\0') {
                *param_5 = *(ushort *)(param_1 + 0xa64);
                uVar7 = *(short *)(param_1 + 0xa86) * *(short *)(param_1 + 0xa8a) +
                        *(short *)(param_1 + 0xa66);
                param_5[1] = uVar7;
                if ((short)uVar7 < *(short *)(param_1 + 0xa94)) {
                  param_5[1] = *(ushort *)(param_1 + 0xa94);
                }
                if (*(short *)(param_1 + 0xa96) < (short)param_5[1]) {
                  param_5[1] = *(ushort *)(param_1 + 0xa96);
                }
                if (param_5[1] != *(ushort *)(param_1 + 0xa66)) {
                  mt_reset_tracking_param(param_1);
                  return 1;
                }
              }
              *(undefined1 *)(param_1 + 0x1e) = 0;
            }
          }
          if (*(char *)(param_1 + 0xa75) == '\x01') {
            *(undefined1 *)(param_1 + 0xa75) = 0;
            *(undefined1 *)(param_1 + 0x9fa) = 0;
            *(undefined1 *)(param_1 + 0xa0f) = 0;
            *(undefined1 *)(param_1 + 0xa24) = 0;
            *(undefined1 *)(param_1 + 0xa39) = 0;
            *(undefined1 *)(param_1 + 0xa4e) = 0;
            *(undefined2 *)(param_1 + 0xa9c) = 0;
          }
          if (*(short *)(param_1 + 0x9f8) == 0) {
            mt_member_copy(param_1 + 0x20,param_4);
            *(short *)(param_1 + 0x9f8) = *(short *)(param_1 + 0x9f8) + 1;
          }
          else {
            mt_tracking_max_distance(param_1,param_4);
            mt_member_copy(*(short *)(param_1 + 0x9f8) * 6 + param_1 + 0x20,param_4);
            *(short *)(param_1 + 0x9f8) = *(short *)(param_1 + 0x9f8) + 1;
            if (*(byte *)(param_1 + 0xa9e) < *(byte *)(param_1 + 0xa68)) {
              *(undefined2 *)(param_1 + 0x9f8) = 0;
              *(undefined1 *)(param_1 + 0xa68) = 0;
            }
          }
          if ((int)(uint)*(ushort *)(param_1 + 0xa7c) <= (int)*(short *)(param_1 + 0x9f8))
          goto LAB_00012bc8;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x1e) = 0;
        if (*(char *)(param_1 + 0xa75) == '\x01') {
          if ((int)*(short *)(param_1 + 0xa9c) < (int)((uint)*(byte *)(param_1 + 0xa7e) * 2)) {
            *(short *)(param_1 + 0xa9c) = *(short *)(param_1 + 0xa9c) + 1;
          }
          else {
            *(undefined1 *)(param_1 + 0xa75) = 0;
            *(undefined1 *)(param_1 + 0x9fa) = 0;
            *(undefined1 *)(param_1 + 0xa0f) = 0;
            *(undefined1 *)(param_1 + 0xa24) = 0;
            *(undefined1 *)(param_1 + 0xa39) = 0;
            *(undefined1 *)(param_1 + 0xa4e) = 0;
            *(undefined2 *)(param_1 + 0xa9c) = 0;
          }
        }
        mt_member_copy(*(short *)(param_1 + 0x9f8) * 6 + param_1 + 0x20,param_4);
        sVar9 = *(short *)(param_1 + 0x9f8) + 1;
        *(short *)(param_1 + 0x9f8) = sVar9;
        if ((int)(uint)*(ushort *)(param_1 + 0xa7c) <= (int)sVar9) {
LAB_00012bc8:
          *param_5 = *(ushort *)(param_1 + 0xa8c);
          param_5[1] = *(ushort *)(param_1 + 0xa8e);
          mt_reset_tracking_param(param_1);
          if (*(char *)(param_1 + 0xa7e) != *(char *)(param_1 + 0xa7f)) {
            *(char *)(param_1 + 0xa7e) = *(char *)(param_1 + 0xa7f);
          }
          if (*(int *)(param_1 + 0xa64) != *(int *)(param_1 + 0xa8c)) {
            return 2;
          }
          return 0;
        }
      }
      return 0;
    }
    __s = "rt_angle pointer is NULL";
  }
  puts(__s);
  return 0xffffffff;
}



uint __aeabi_uidiv(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = 0xffffffff;
    }
    uVar2 = __aeabi_idiv0(uVar1);
    return uVar2;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
  uVar3 = param_2 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar2 = 1 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar4 = 0;
  while( true ) {
    if (uVar3 <= param_1) {
      param_1 = param_1 - uVar3;
      uVar4 = uVar4 | uVar2;
    }
    if (uVar3 >> 1 <= param_1) {
      param_1 = param_1 - (uVar3 >> 1);
      uVar4 = uVar4 | uVar2 >> 1;
    }
    if (uVar3 >> 2 <= param_1) {
      param_1 = param_1 - (uVar3 >> 2);
      uVar4 = uVar4 | uVar2 >> 2;
    }
    if (uVar3 >> 3 <= param_1) {
      param_1 = param_1 - (uVar3 >> 3);
      uVar4 = uVar4 | uVar2 >> 3;
    }
    bVar5 = param_1 == 0;
    if (!bVar5) {
      uVar2 = uVar2 >> 4;
      bVar5 = uVar2 == 0;
    }
    if (bVar5) break;
    uVar3 = uVar3 >> 4;
  }
  return uVar4;
}



void __aeabi_uidivmod(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    __aeabi_uidiv();
    return;
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0xffffffff;
  }
  __aeabi_idiv0(uVar1);
  return;
}



uint __divsi3(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 == 0) {
    bVar6 = (int)param_1 < 0;
    if (0 < (int)param_1) {
      param_1 = 0x7fffffff;
    }
    if (bVar6) {
      param_1 = 0x80000000;
    }
    uVar2 = __aeabi_idiv0(param_1);
    return uVar2;
  }
  uVar5 = param_1 ^ param_2;
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar4 = param_1;
  if ((int)param_1 < 0) {
    uVar4 = -param_1;
  }
  if (uVar4 <= uVar2) {
    if (uVar4 < uVar2) {
      param_1 = 0;
    }
    if (uVar4 == uVar2) {
      param_1 = (int)uVar5 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar2 & uVar2 - 1) == 0) {
    uVar4 = uVar4 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar5 < 0) {
      uVar4 = -uVar4;
    }
    return uVar4;
  }
  uVar3 = uVar2 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar2 = 1 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar1 = 0;
  while( true ) {
    if (uVar3 <= uVar4) {
      uVar4 = uVar4 - uVar3;
      uVar1 = uVar1 | uVar2;
    }
    if (uVar3 >> 1 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 1);
      uVar1 = uVar1 | uVar2 >> 1;
    }
    if (uVar3 >> 2 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 2);
      uVar1 = uVar1 | uVar2 >> 2;
    }
    if (uVar3 >> 3 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 3);
      uVar1 = uVar1 | uVar2 >> 3;
    }
    bVar6 = uVar4 == 0;
    if (!bVar6) {
      uVar2 = uVar2 >> 4;
      bVar6 = uVar2 == 0;
    }
    if (bVar6) break;
    uVar3 = uVar3 >> 4;
  }
  if ((int)uVar5 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



uint _divsi3_skip_div0_test(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool in_NG;
  bool bVar6;
  
  uVar5 = param_1 ^ param_2;
  uVar2 = param_2;
  if (in_NG) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar4 = param_1;
  if ((int)param_1 < 0) {
    uVar4 = -param_1;
  }
  if (uVar4 <= uVar2) {
    if (uVar4 < uVar2) {
      param_1 = 0;
    }
    if (uVar4 == uVar2) {
      param_1 = (int)uVar5 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar2 & uVar2 - 1) == 0) {
    uVar4 = uVar4 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar5 < 0) {
      uVar4 = -uVar4;
    }
    return uVar4;
  }
  uVar3 = uVar2 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar2 = 1 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar1 = 0;
  while( true ) {
    if (uVar3 <= uVar4) {
      uVar4 = uVar4 - uVar3;
      uVar1 = uVar1 | uVar2;
    }
    if (uVar3 >> 1 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 1);
      uVar1 = uVar1 | uVar2 >> 1;
    }
    if (uVar3 >> 2 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 2);
      uVar1 = uVar1 | uVar2 >> 2;
    }
    if (uVar3 >> 3 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 3);
      uVar1 = uVar1 | uVar2 >> 3;
    }
    bVar6 = uVar4 == 0;
    if (!bVar6) {
      uVar2 = uVar2 >> 4;
      bVar6 = uVar2 == 0;
    }
    if (bVar6) break;
    uVar3 = uVar3 >> 4;
  }
  if ((int)uVar5 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



void __aeabi_idivmod(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 != 0) {
    _divsi3_skip_div0_test();
    return;
  }
  bVar1 = param_1 < 0;
  if (0 < param_1) {
    param_1 = 0x7fffffff;
  }
  if (bVar1) {
    param_1 = -0x80000000;
  }
  __aeabi_idiv0(param_1);
  return;
}



void __aeabi_idiv0(void)

{
  raise(8);
  return;
}



void _fini(void)

{
  return;
}


