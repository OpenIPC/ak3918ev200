typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    word;
typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

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

typedef struct Elf32_Dyn_ARM Elf32_Dyn_ARM, *PElf32_Dyn_ARM;

struct Elf32_Dyn_ARM {
    enum Elf32_DynTag_ARM d_tag;
    dword d_val;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
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



undefined1 completed.8817;
pointer __DT_PLTGOT;
dword __FRAME_END__;
undefined4 __dso_handle;
undefined1[24] object.8822;
undefined4 __JCR_END__;
undefined4 g_fd;

int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,__request);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = strerror(__errnum);
  return pcVar1;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void __deregister_frame_info(void)

{
  __deregister_frame_info();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int * __errno_location(void)

{
  int *piVar1;
  
  piVar1 = __errno_location();
  return piVar1;
}



void isp_sdk_ioctl(void)

{
  isp_sdk_ioctl();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fcntl(int __fd,int __cmd,...)

{
  int iVar1;
  
  iVar1 = fcntl(__fd,__cmd);
  return iVar1;
}



void __register_frame_info(void)

{
  __register_frame_info();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Removing unreachable block (ram,0x0001177c)
// WARNING: Removing unreachable block (ram,0x00011788)
// WARNING: Removing unreachable block (ram,0x0001178c)

void processEntry deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x000117d4)
// WARNING: Removing unreachable block (ram,0x000117e0)
// WARNING: Removing unreachable block (ram,0x000117e4)

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
    if (ppuVar1[0xf] != (undefined *)0x0) {
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



int isp_sdk_ioctl(ulong param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int __errnum;
  
  if (param_2 == 0) {
    return 1;
  }
  if (g_fd < 0) {
    return 2;
  }
  iVar1 = ioctl(g_fd,param_1);
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = __errno_location();
  __errnum = *piVar2;
  pcVar3 = strerror(__errnum);
  printf("ISP: cmd=0x%X, err:%d, estr:%s\n",param_1,__errnum,pcVar3);
  return iVar1;
}



undefined4 AK_ISP_sdk_init(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  
  printf("\nispsdk_lib version:%s \n","V3.1.00");
  iVar4 = 3;
  do {
    iVar1 = open("/dev/null",1);
    if (1 < iVar1) break;
    if (iVar1 < 0) {
      printf("%s open null fail\n","AK_ISP_sdk_init");
      return 0xffffffff;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  g_fd = open("/dev/isp_char",2);
  if (g_fd < 0) {
    piVar2 = __errno_location();
    uVar5 = 0xffffffff;
    iVar4 = *piVar2;
    pcVar3 = strerror(iVar4);
    printf("open %s fail, err:%d, estr:%s\n","/dev/isp_char",iVar4,pcVar3);
  }
  else {
    fcntl(g_fd,2,1);
    uVar5 = 0;
  }
  printf("--- %s g_fd=%d ---\n","AK_ISP_sdk_init",g_fd);
  return uVar5;
}



undefined4 AK_ISP_sdk_exit(void)

{
  printf("--- %s g_fd=%d closed ---\n","AK_ISP_sdk_exit",g_fd);
  if (g_fd != -1) {
    close(g_fd);
    g_fd = -1;
  }
  return 0;
}



void AK_ISP_set_raw_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044943,param_1);
  return;
}



void AK_ISP_get_raw_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044944,param_1);
  return;
}



void AK_ISP_get_raw_hist_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044945,param_1);
  return;
}



void AK_ISP_set_rgb_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044946,param_1);
  return;
}



void AK_ISP_get_rgb_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044947,param_1);
  return;
}



void AK_ISP_get_rgb_hist_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044948,param_1);
  return;
}



void AK_ISP_set_yuv_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044949,param_1);
  return;
}



void AK_ISP_get_yuv_hist_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004494a,param_1);
  return;
}



void AK_ISP_get_yuv_hist_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004494b,param_1);
  return;
}



void AK_ISP_set_exp_type(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004494c,param_1);
  return;
}



void AK_ISP_get_exp_type(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004494d,param_1);
  return;
}



void AK_ISP_set_ae_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044950,param_1);
  return;
}



void AK_ISP_get_ae_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044951,param_1);
  return;
}



void AK_ISP_get_ae_run_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044952,param_1);
  return;
}



void AK_ISP_set_wb_type(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044953,param_1);
  return;
}



void AK_ISP_get_wb_type(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044954,param_1);
  return;
}



void AK_ISP_set_mwb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044963,param_1);
  return;
}



void AK_ISP_get_mwb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044964,param_1);
  return;
}



void AK_ISP_set_awb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044955,param_1);
  return;
}



void AK_ISP_get_awb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044956,param_1);
  return;
}



void AK_ISP_set_awb_ex_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044973,param_1);
  return;
}



void AK_ISP_get_awb_ex_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044974,param_1);
  return;
}



void Ak_ISP_get_awb_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044959,param_1);
  return;
}



void AK_ISP_set_af_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044960,param_1);
  return;
}



void AK_ISP_get_af_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044961,param_1);
  return;
}



void AK_ISP_get_af_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044962,param_1);
  return;
}



void AK_ISP_set_weight_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004495e,param_1);
  return;
}



void AK_ISP_get_weight_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004495f,param_1);
  return;
}



void AK_ISP_set_blc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044902,param_1);
  return;
}



void AK_ISP_get_blc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044901,param_1);
  return;
}



void AK_ISP_set_dpc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044910,param_1);
  return;
}



void AK_ISP_get_dpc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004490f,param_1);
  return;
}



undefined4 AK_ISP_set_sdpc_attr(void)

{
  return 0;
}



undefined4 AK_ISP_get_sdpc_attr(void)

{
  return 0;
}



void AK_ISP_set_lsc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044904,param_1);
  return;
}



void AK_ISP_get_lsc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044903,param_1);
  return;
}



void AK_ISP_set_nr1_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004490c,param_1);
  return;
}



void AK_ISP_get_nr1_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004490b,param_1);
  return;
}



void AK_ISP_set_nr2_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004492b,param_1);
  return;
}



void AK_ISP_get_nr2_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004492c,param_1);
  return;
}



void AK_ISP_set_3d_nr_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004492f,param_1);
  return;
}



void AK_ISP_get_3d_nr_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044930,param_1);
  return;
}



void AK_ISP_set_3d_nr_ref_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044967,param_1);
  return;
}



void AK_ISP_get_3d_nr_ref_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044968,param_1);
  return;
}



void AK_ISP_get_3d_nr_stat_info(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044970,param_1);
  return;
}



void AK_ISP_set_gb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044906,param_1);
  return;
}



void AK_ISP_get_gb_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044905,param_1);
  return;
}



void AK_ISP_set_demo_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004490e,param_1);
  return;
}



void AK_ISP_get_demo_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004490d,param_1);
  return;
}



void AK_ISP_set_rgb_gamma_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004491a,param_1);
  return;
}



void AK_ISP_get_rgb_gamma_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044919,param_1);
  return;
}



void AK_ISP_set_raw_lut_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004490a,param_1);
  return;
}



void AK_ISP_get_raw_lut_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044909,param_1);
  return;
}



void AK_ISP_set_ccm_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044912,param_1);
  return;
}



void AK_ISP_get_ccm_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044911,param_1);
  return;
}



void AK_ISP_set_sharp_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044925,param_1);
  return;
}



void AK_ISP_get_sharp_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044926,param_1);
  return;
}



void AK_ISP_set_sharp_ex_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044927,param_1);
  return;
}



void AK_ISP_get_sharp_ex_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044928,param_1);
  return;
}



void AK_ISP_set_fcs_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044936,param_1);
  return;
}



void AK_ISP_get_fcs_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044935,param_1);
  return;
}



void AK_ISP_set_wdr_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004491b,param_1);
  return;
}



void AK_ISP_get_wdr_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004491c,param_1);
  return;
}



void AK_ISP_set_contrast_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044939,param_1);
  return;
}



void AK_ISP_get_contrast_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004493a,param_1);
  return;
}



void AK_ISP_set_saturation_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004493b,param_1);
  return;
}



void AK_ISP_get_saturation_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004493c,param_1);
  return;
}



void AK_ISP_set_rgb2yuv_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004493f,param_1);
  return;
}



void AK_ISP_get_rgb2yuv_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044940,param_1);
  return;
}



void AK_ISP_set_effect_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044941,param_1);
  return;
}



void AK_ISP_get_effect_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044942,param_1);
  return;
}



void AK_ISP_set_main_chan_mask_area(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004495a,param_1);
  return;
}



void AK_ISP_get_main_chan_mask_area(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004495b,param_1);
  return;
}



void AK_ISP_set_sub_chan_mask_area(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044965,param_1);
  return;
}



void AK_ISP_get_sub_chan_mask_area(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044966,param_1);
  return;
}



void AK_ISP_set_mask_color(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004495c,param_1);
  return;
}



void AK_ISP_get_mask_color(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004495d,param_1);
  return;
}



void Ak_ISP_Sensor_Load_Conf(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044969,param_1);
  return;
}



void Ak_ISP_Sensor_Set_Reg(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004496b,param_1);
  return;
}



void Ak_ISP_Sensor_Get_Reg(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004496c,param_1);
  return;
}



void Ak_ISP_Set_User_Params(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004496d,param_1);
  return;
}



void AK_ISP_set_misc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004496e,param_1);
  return;
}



void AK_ISP_get_misc_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004496f,param_1);
  return;
}



void AK_ISP_set_Y_gamma_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044975,param_1);
  return;
}



void AK_ISP_get_Y_gamma_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044976,param_1);
  return;
}



void AK_ISP_set_hue_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044977,param_1);
  return;
}



void AK_ISP_get_hue_attr(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044978,param_1);
  return;
}



void AK_ISP_set_frame_rate(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004494e,param_1);
  return;
}



void AK_ISP_get_frame_rate(undefined4 param_1)

{
  isp_sdk_ioctl(0x8004494f,param_1);
  return;
}



void AK_ISP_set_isp_capturing(void)

{
  isp_sdk_ioctl(0x40044972);
  return;
}



void Ak_ISP_Sensor_Get_Id(undefined4 param_1)

{
  isp_sdk_ioctl(0x80044971,param_1);
  return;
}



void Ak_ISP_Set_Flip_Mirror(undefined4 param_1)

{
  isp_sdk_ioctl(0x40044979,param_1);
  return;
}



void Ak_ISP_Set_Sensor_Fps(undefined4 param_1)

{
  isp_sdk_ioctl(0x4004497a,param_1);
  return;
}



undefined4 Ak_ISP_Get_Sensor_Fps(void)

{
  isp_sdk_ioctl(0x8004497b);
  return 0;
}



undefined4 Ak_ISP_Get_Work_Scene(void)

{
  isp_sdk_ioctl(0x8004497c);
  return 0;
}



void _fini(void)

{
  return;
}


