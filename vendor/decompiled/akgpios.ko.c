typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    word;
typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

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

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
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

typedef ulong size_t;



undefined1 akgpio_dev;
undefined4 akgpios;
undefined4 pdata;
undefined4 gpio_num;
undefined akgpio_custom_irq;
undefined1[80] akgpio_custom_driver;

undefined4 akgpio_custom_release(void)

{
  return 0;
}



undefined4 akgpio_custom_remove(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = akgpios;
  pdata = 0;
  misc_deregister(&akgpio_dev);
  iVar1 = gpio_num;
  for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    *(undefined4 *)(iVar3 + 0xc) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x24) = 0;
    iVar3 = iVar3 + 0x28;
  }
  return 0;
}



undefined4 akgpio_custom_open(void)

{
  printk("<6>open akgpio device success.\n");
  return 0;
}



undefined4 akgpio_custom_irq(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = ak_gpio_to_irq(*param_2);
  if (param_1 != iVar2) {
                    // WARNING: Does not return
    pcVar1 = (code *)software_udf(0x12,0x100c4);
    (*pcVar1)();
  }
  iVar2 = ak_gpio_getpin(*param_2);
  uVar3 = (uint)*(byte *)(param_2 + 2);
  if (iVar2 == 0) {
    if (uVar3 == 0) goto LAB_00010100;
LAB_000100f0:
    if (*(char *)(param_2 + 2) == '\0') {
      return 1;
    }
  }
  else {
    if (uVar3 != 0) {
LAB_00010100:
      iVar4 = 1 - uVar3;
      if (1 < uVar3) {
        iVar4 = 0;
      }
      ak_gpio_intpol(*param_2,iVar4);
      if (iVar2 == 0) goto LAB_000100f0;
    }
    if (*(char *)(param_2 + 2) != '\0') {
      return 1;
    }
  }
  ak_gpio_intpol(*param_2,*(undefined1 *)(param_2 + 2));
  if (param_2[9] != 0) {
    up(param_2 + 6);
    param_2[9] = 0;
  }
  return 1;
}



undefined4 akgpio_custom_ioctl(undefined4 param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  bool bVar8;
  char *pcStack_30;
  void *pvStack_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  char local_1c;
  undefined4 uStack_4;
  
  uStack_4 = 0x10160;
  local_28 = pdata[1];
  if (param_2 == 0x4001662f) {
    uVar6 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
    uVar4 = param_3 + 0xc;
    uVar5 = uVar4;
    if (param_3 < 0xfffffff4) {
      uVar5 = uVar4 - (uVar6 + 1);
    }
    if (param_3 < 0xfffffff4 && uVar4 <= uVar6) {
      uVar6 = 0;
    }
    if (uVar6 == 0) {
      iVar2 = __copy_from_user(&local_24,param_3,0xc);
      if (iVar2 != 0) {
        return 0xffffffea;
      }
      ak_gpio_setpin(local_24,local_20._2_1_);
      return 0;
    }
  }
  else {
    if (0x4001662e < param_2) {
      if (param_2 == 0x80016628) {
        uVar5 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
        if (param_3 < 0xfffffffc && param_3 + 4 <= uVar5) {
          uVar5 = 0;
        }
        if (uVar5 != 0) {
          return 0xffffffea;
        }
        iVar2 = -0x24;
        uVar3 = 4;
      }
      else {
        if (param_2 < 0x80016628) {
          if (param_2 != 0x40016630) goto LAB_000105e0;
          uVar6 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
          uVar4 = param_3 + 8;
          uVar5 = uVar4;
          if (param_3 < 0xfffffff8) {
            uVar5 = uVar4 - (uVar6 + 1);
          }
          if (param_3 < 0xfffffff8 && uVar4 <= uVar6) {
            uVar6 = 0;
          }
          if (uVar6 == 0) {
            iVar2 = __copy_from_user(&local_24,param_3,8);
            if (iVar2 != 0) {
              return 0xffffffea;
            }
            for (iVar2 = 0; iVar2 < local_20; iVar2 = iVar2 + 1) {
              ak_gpio_setpin(*(undefined4 *)(local_24 + iVar2 * 8),
                             *(undefined4 *)(local_24 + iVar2 * 8 + 4));
            }
            return 0;
          }
          uVar3 = 8;
          goto LAB_00010374;
        }
        if (param_2 == 0x80016629) {
          uVar5 = local_28 * 4;
          uVar4 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
          if (!CARRY4(param_3,uVar5) && param_3 + uVar5 <= uVar4) {
            uVar4 = 0;
          }
          if (uVar4 == 0) {
            uVar5 = __copy_to_user(param_3,*pdata);
          }
          goto LAB_00010418;
        }
        if (param_2 != 0xc001662b) goto LAB_000105e0;
        uVar6 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
        uVar4 = param_3 + 0xc;
        uVar5 = uVar4;
        if (param_3 < 0xfffffff4) {
          uVar5 = uVar4 - (uVar6 + 1);
        }
        if (param_3 < 0xfffffff4 && uVar4 <= uVar6) {
          uVar6 = 0;
        }
        if (uVar6 != 0) goto LAB_000102f8;
        iVar2 = __copy_from_user(&local_24,param_3,0xc);
        if (iVar2 != 0) {
          return 0xffffffea;
        }
        uVar1 = ak_gpio_getpin(local_24);
        local_20._0_3_ = CONCAT12(uVar1,(undefined2)local_20);
        uVar5 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
        if (param_3 < 0xfffffff4 && param_3 + 0xc <= uVar5) {
          uVar5 = 0;
        }
        if (uVar5 != 0) {
          return 0xffffffea;
        }
        iVar2 = -0x20;
        uVar3 = 0xc;
      }
      uVar5 = __copy_to_user(param_3,(int)&uStack_4 + iVar2,uVar3);
LAB_00010418:
      if (uVar5 == 0) {
        return 0;
      }
      return 0xffffffea;
    }
    if (param_2 == 0x4001662c) {
      uVar6 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
      uVar4 = param_3 + 0xc;
      uVar5 = uVar4;
      if (param_3 < 0xfffffff4) {
        uVar5 = uVar4 - (uVar6 + 1);
      }
      if (param_3 < 0xfffffff4 && uVar4 <= uVar6) {
        uVar6 = 0;
      }
      if (uVar6 == 0) {
        iVar2 = __copy_from_user(&local_24,param_3,0xc);
        if (iVar2 != 0) {
          return 0xffffffea;
        }
        iVar2 = 0;
        pvVar7 = akgpios;
        do {
          if (iVar2 == local_28) {
LAB_000104ac:
            iVar2 = 0;
            pvVar7 = akgpios;
            while( true ) {
              if (iVar2 == local_28) {
                return 0;
              }
              if ((*(int *)((int)pvVar7 + 0x10) != 0) && (*(int *)((int)pvVar7 + 0xc) == local_24))
              break;
              iVar2 = iVar2 + 1;
              pvVar7 = (void *)((int)pvVar7 + 0x28);
            }
            memcpy(pvVar7,&local_24,0xc);
            ak_gpio_set(&local_24);
            if (*(int *)((int)pvVar7 + 0x14) != 0) {
              return 0;
            }
            uVar3 = ak_gpio_to_irq(local_24);
            bVar8 = local_1c == '\x01';
            if (bVar8) {
              local_1c = '\x04';
            }
            pcStack_30 = "akgpio";
            if (!bVar8) {
              local_1c = '\b';
            }
            pvStack_2c = pvVar7;
            iVar2 = request_threaded_irq(uVar3,akgpio_custom_irq,0,local_1c);
            if (iVar2 == 0) {
              *(undefined4 *)((int)pvVar7 + 0x14) = 1;
              return 0;
            }
            printk("Request irq failed. ret=%d\n");
            return 0xffffffea;
          }
          if (*(int *)((int)pvVar7 + 0x10) == 0) {
            *(undefined4 *)((int)pvVar7 + 0x10) = 1;
            *(int *)((int)pvVar7 + 0xc) = local_24;
            down((int)pvVar7 + 0x18);
            goto LAB_000104ac;
          }
          if (*(int *)((int)pvVar7 + 0xc) == local_24) goto LAB_000104ac;
          iVar2 = iVar2 + 1;
          pvVar7 = (void *)((int)pvVar7 + 0x28);
        } while( true );
      }
    }
    else {
      if (0x4001662b < param_2) {
        if (param_2 == 0x4001662d) {
          iVar2 = 0;
          pvVar7 = akgpios;
          while( true ) {
            if (iVar2 == local_28) {
              return 0;
            }
            if ((*(int *)((int)pvVar7 + 0x10) != 0) && (*(uint *)((int)pvVar7 + 0xc) == param_3))
            break;
            pvVar7 = (void *)((int)pvVar7 + 0x28);
            iVar2 = iVar2 + 1;
          }
          *(undefined4 *)((int)pvVar7 + 0x24) = 1;
          down((int)pvVar7 + 0x18);
          return 0;
        }
        if (param_2 == 0x4001662e) {
          iVar2 = 0;
          pvVar7 = akgpios;
          while( true ) {
            if (iVar2 == local_28) {
              return 0;
            }
            if ((*(int *)((int)pvVar7 + 0x10) != 0) && (*(uint *)((int)pvVar7 + 0xc) == param_3))
            break;
            pvVar7 = (void *)((int)pvVar7 + 0x28);
            iVar2 = iVar2 + 1;
          }
          uVar3 = ak_gpio_to_irq(param_3);
          free_irq(uVar3,pvVar7);
          *(undefined4 *)((int)pvVar7 + 0x14) = 0;
          return 0;
        }
LAB_000105e0:
        printk("akgpio: the ioctl is unknow.\n");
        return 0;
      }
      if (param_2 != 0x4001662a) goto LAB_000105e0;
      uVar6 = *(uint *)(((uint)&pcStack_30 & 0xffffe000) + 8);
      uVar4 = param_3 + 0xc;
      uVar5 = uVar4;
      if (param_3 < 0xfffffff4) {
        uVar5 = uVar4 - (uVar6 + 1);
      }
      if (param_3 < 0xfffffff4 && uVar4 <= uVar6) {
        uVar6 = 0;
      }
      if (uVar6 == 0) {
        iVar2 = __copy_from_user(&local_24,param_3,0xc);
        if (iVar2 == 0) {
          ak_gpio_set(&local_24);
          return 0;
        }
        return 0xffffffea;
      }
    }
  }
LAB_000102f8:
  uVar3 = 0xc;
LAB_00010374:
  __memzero(&local_24,uVar3,uVar5);
  return 0xffffffea;
}



undefined4 akgpio_custom_probe(int param_1)

{
  int iVar1;
  int iVar2;
  
  pdata = *(int *)(param_1 + 0x50);
  if ((pdata != 0) && (*(int *)(pdata + 4) != 0)) {
    iVar1 = misc_register(&akgpio_dev);
    if (iVar1 == 0) {
      gpio_num = *(int *)(pdata + 4);
      iVar1 = __kmalloc(gpio_num * 0x28,0x80d0);
      if (iVar1 == 0) {
        akgpios = iVar1;
        return 0xfffffff4;
      }
      akgpios = iVar1;
      for (iVar2 = 0; iVar2 < gpio_num; iVar2 = iVar2 + 1) {
        *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        memset((void *)(iVar1 + 0x18),0,0xc);
        *(undefined4 *)(iVar1 + 0x18) = 1;
        *(int *)(iVar1 + 0x1c) = iVar1 + 0x1c;
        *(int *)(iVar1 + 0x20) = iVar1 + 0x1c;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        iVar1 = iVar1 + 0x28;
      }
      printk("akgpio driver initialize.\n");
      return 0;
    }
    printk("<3>akgpio: Unable register misc device.\n");
  }
  return 0xffffffed;
}



void init_module(void)

{
  platform_driver_register(akgpio_custom_driver);
  return;
}



void cleanup_module(void)

{
  platform_driver_unregister(akgpio_custom_driver);
  return;
}


