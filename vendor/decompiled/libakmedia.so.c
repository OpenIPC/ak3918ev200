typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef ulong size_t;

typedef uint sizetype;

typedef ulonglong UDItype;

typedef uint USItype;

typedef longlong DItype;

typedef qword complex float;

typedef undefined complex double[16];

typedef int SItype;

typedef union DWunion DWunion, *PDWunion;

typedef struct DWstruct DWstruct, *PDWstruct;

struct DWstruct {
    SItype low;
    SItype high;
};

union DWunion {
    struct DWstruct s;
    DItype ll;
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

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

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



pointer __DT_PLTGOT;
undefined4 __dso_handle;
undefined1 completed.8817;
dword __FRAME_END__;
undefined4 __JCR_END__;
undefined1[24] object.8822;
undefined info_print;
undefined4 g_medialib_printf;
undefined1 g_zero_aacframe_mono;
undefined1[9] g_zero_aacframe_stereo;
undefined1[14] g_zero_amrframe_5150;
undefined1[32] g_zero_amrframe_12200;
undefined DAT_00057564;
undefined DAT_000576e0;
undefined DAT_000579e8;
undefined DAT_00057a48;
undefined DAT_00057dd4;
undefined DAT_00057c24;
undefined DAT_0005817c;
undefined DAT_0005820c;
undefined DAT_00058390;
undefined DAT_00058a48;
undefined DAT_00058bc8;
undefined DAT_00058bd0;
undefined DAT_00058bd8;
undefined DAT_00058be0;
undefined DAT_00058be8;
undefined DAT_00058c20;
undefined DAT_00058c28;
undefined DAT_000587d0;
undefined DAT_000587d8;
undefined DAT_00058c60;
undefined DAT_000587e0;
undefined DAT_00058864;
undefined DAT_00058908;
undefined DAT_00058910;
undefined DAT_00058974;
undefined DAT_00059238;
undefined DAT_0005923c;
undefined DAT_00059240;
undefined DAT_00059248;
undefined DAT_0005924c;
undefined DAT_00059254;
undefined DAT_0005a358;
undefined DAT_0005a360;
undefined DAT_0005a368;
undefined DAT_0005a370;
undefined DAT_0005a378;
undefined DAT_0005a37c;
undefined DAT_0005a380;
undefined DAT_0005a388;
undefined DAT_0005a38c;
undefined DAT_0005a394;
undefined DAT_0005a3c0;
undefined DAT_0005a3c8;
undefined DAT_0005a3d0;
undefined DAT_0005a3d8;
undefined1 DAT_0005a0f4;
undefined DAT_0005a0fc;
undefined DAT_0005a104;
undefined DAT_0005a1d8;
undefined DAT_0005a274;
undefined DAT_0005a2b4;
undefined DAT_0005a3e0;
undefined DAT_0005a3e8;
undefined1 DAT_0005a4f0;
undefined1 DAT_0005a4f8;
undefined1 DAT_0005a500;
undefined1 DAT_0005a508;
undefined1 DAT_0005a510;
undefined DAT_0005a518;
undefined DAT_0005a520;
undefined DAT_0005a528;
undefined DAT_0005a544;
undefined1 DAT_0005a54c;
undefined1 DAT_0005a554;
undefined DAT_0005a55c;
undefined DAT_0005a564;
undefined1 DAT_0005a56c;
undefined DAT_0005a574;
undefined DAT_0005a57c;
undefined DAT_0005a584;
undefined1 DAT_0005a58c;
undefined DAT_0005a594;
undefined DAT_0005a59c;
undefined DAT_0005a5a4;
undefined DAT_0005a6c0;
undefined DAT_0005a6c4;
undefined DAT_0005a6cc;
undefined DAT_0005a6d4;
undefined DAT_0005a6dc;
undefined DAT_0005a75c;
undefined DAT_0005a764;
undefined DAT_0005a76c;
undefined DAT_0005a774;
undefined DAT_0005a77c;
undefined DAT_0005a784;
undefined DAT_0005a78c;
undefined1 DAT_0005b090;
undefined1 DAT_0005b098;
undefined DAT_0005b0a0;
undefined DAT_0005b0cc;
undefined DAT_0005b0d4;
undefined DAT_0005b0dc;
undefined DAT_0005b0e4;
undefined DAT_0005b10c;
undefined1 DAT_0005b374;
undefined1 DAT_0005b37c;
undefined DAT_0005b384;
undefined DAT_0005b38c;
undefined DAT_0005b394;
undefined DAT_0005b39c;
undefined DAT_0005b3a4;
undefined DAT_0005b3ac;
undefined DAT_0005b3b4;
undefined1 DAT_0005b3bc;
undefined1 DAT_0005b420;
undefined1 DAT_0005b444;
undefined DAT_0005b460;
undefined DAT_0005b468;
undefined DAT_0005b470;
undefined DAT_0005b478;
undefined DAT_0005b480;
undefined DAT_0005b488;
undefined DAT_0005b490;
undefined DAT_0005b498;
undefined DAT_0005b4a0;
undefined1 DAT_0005b4a8;
undefined1 DAT_0005b4b0;
undefined1 DAT_0005b4b8;
undefined1 DAT_0005b4c0;
undefined1 DAT_0005b4c8;
undefined DAT_0005b4d0;
undefined DAT_0005b4d8;
undefined DAT_0005baf4;
undefined DAT_0005bafc;
undefined DAT_0005bb04;
undefined DAT_0005bb0c;
undefined DAT_0005bb14;
undefined DAT_0005bb20;
undefined DAT_0005bb28;
undefined *g_sID3v1GenreList;
undefined DAT_0005bb30;
undefined DAT_0005bb38;
undefined DAT_0005bb40;
undefined DAT_0005bb48;
undefined DAT_0005bb50;
undefined DAT_0005bb58;
undefined DAT_0005bb60;
undefined1 DAT_0005bb68;
undefined1 Log_table;
undefined1[48] g_aac_sample_rates;
undefined1[36] g_mp3_freqs;
undefined1 msk;
undefined DAT_0005c32c;
undefined DAT_0005c35c;
undefined DAT_0005c364;
undefined DAT_0005c3b4;
undefined DAT_0005c3f4;
undefined DAT_0005c668;
undefined DAT_0005c790;
undefined DAT_0005c794;
undefined DAT_0005c798;
undefined DAT_0005c7fc;
undefined DAT_0005c8f8;
undefined DAT_0005c900;
undefined DAT_0005c910;
undefined DAT_0005c9a0;
undefined MP4Demuxer_SeekVideo;
undefined AACDemuxer_ReleaseInfoMem;
undefined AVIDemuxer_SeekPrevKeyframe;
undefined MP4Demuxer_Open;
undefined WAVDemuxer_Seek;
undefined AACDemuxer_Destroy;
undefined WAVDemuxer_Init;
undefined AVIDemuxer_GetFileInfo;
undefined MP4Demuxer_GetFileInfo;
undefined AACDemuxer_Seek;
undefined AACDemuxer_Init;
undefined WAVDemuxer_Close;
undefined AVIDemuxer_GetFirstKeyframeSize;
undefined AVIDemuxer_Open;
undefined MP4Demuxer_GetFirstKeyframe;
undefined AMRDemuxer_Destroy;
undefined MP4Demuxer_SeekPrevKeyframe;
undefined AVIDemuxer_GetAudioData;
undefined AVIDemuxer_Close;
undefined AVIDemuxer_Init;
undefined AVIDemuxer_SeekVideo;
undefined MP4Demuxer_GetAudioDataSize;
undefined MP4Demuxer_GetVideoFrame;
undefined AVIDemuxer_GetVideoFrameSize;
undefined MP4Demuxer_Init;
undefined AMRDemuxer_Init;
undefined MP4Demuxer_SeekAudio;
undefined AMRDemuxer_Close;
undefined AVIDemuxer_Destroy;
undefined AACDemuxer_GetFileInfo;
undefined MP4Demuxer_GetVideoFrameSize;
undefined AVIDemuxer_GetVideoFrame;
undefined AVIDemuxer_GetAudioDataSize;
undefined AVIDemuxer_SeekNextKeyframe;
undefined AVIDemuxer_SeekAudio;
undefined WAVDemuxer_GetFileInfo;
undefined AVIDemuxer_GetAudioPackPts;
undefined MP4Demuxer_ReleaseInfoMem;
undefined MP4Demuxer_Close;
undefined AMRDemuxer_GetFileInfo;
undefined WAVDemuxer_Open;
undefined AVIDemuxer_GetFirstKeyframe;
undefined MP4Demuxer_SeekNextKeyframe;
undefined AMRDemuxer_Seek;
undefined AACDemuxer_Open;
undefined WAVDemuxer_Destroy;
undefined AMRDemuxer_Open;
undefined MP4Demuxer_GetAudioData;
undefined AACDemuxer_Close;
undefined MP4Demuxer_SeekVideoSetDirection;
undefined MP4Demuxer_GetNextBlockInfo;
undefined AVIDemuxer_GetNextBlockInfo;
undefined MP4Demuxer_GetAudioPackPts;
undefined MP4Demuxer_GetFirstKeyframeSize;
undefined MP4Demuxer_Destroy;
undefined AVIMuxer_GetCurrFileSize;
undefined MP4Muxer_Close;
undefined MP4Muxer_GetHeaderSize;
undefined AVIMuxer_Start;
undefined MP4Muxer_ProcessAudio;
undefined MP4Muxer_ProcessVideo;
undefined AVIMuxer_ProcessAudio;
undefined MP4Muxer_GetCurrFileSize;
undefined MP4Muxer_Start;
undefined MP4Muxer_Stop;
undefined AVIMuxer_Init;
undefined AVIMuxer_GetHeaderSize;
undefined MP4Muxer_Open;
undefined MP4Muxer_Init;
undefined MP4Muxer_Restart;
undefined AVIMuxer_Restart;
undefined MP4Muxer_Destroy;
undefined AVIMuxer_Open;
undefined AVIMuxer_Stop;
undefined AVIMuxer_ProcessVideo;
undefined AVIMuxer_Destroy;
undefined AVIMuxer_Close;

int _init(EVP_PKEY_CTX *ctx)

{
  return (int)ctx;
}



void quicktime_minf_init_video(void)

{
  quicktime_minf_init_video();
  return;
}



void S_Demuxer_SeekVideo(void)

{
  S_Demuxer_SeekVideo();
  return;
}



void quicktime_stts_init_video(void)

{
  quicktime_stts_init_video();
  return;
}



void AVIDemuxer_GetFirstKeyframeSize(void)

{
  AVIDemuxer_GetFirstKeyframeSize();
  return;
}



void quicktime_mdat_init(void)

{
  quicktime_mdat_init();
  return;
}



void quicktime_file_write_status(void)

{
  quicktime_file_write_status();
  return;
}



void MP4_GetMetaInfo(void)

{
  MP4_GetMetaInfo();
  return;
}



void destroyAVIOutput(void)

{
  destroyAVIOutput();
  return;
}



void quicktime_get_mp4_audio_decoder_config_size(void)

{
  quicktime_get_mp4_audio_decoder_config_size();
  return;
}



void quicktime_write_stsz_opt_vide(void)

{
  quicktime_write_stsz_opt_vide();
  return;
}



void quicktime_read_audio_frame(void)

{
  quicktime_read_audio_frame();
  return;
}



void Bitstream_FillBuffer(void)

{
  Bitstream_FillBuffer();
  return;
}



void quicktime_stsd_delete(void)

{
  quicktime_stsd_delete();
  return;
}



void quicktime_init_video_map_rec(void)

{
  quicktime_init_video_map_rec();
  return;
}



void quicktime_get_mp4_audio_decoder_objcetTypeId(void)

{
  quicktime_get_mp4_audio_decoder_objcetTypeId();
  return;
}



void AVIOutput_closeList(void)

{
  AVIOutput_closeList();
  return;
}



void quicktime_write_esds_common(void)

{
  quicktime_write_esds_common();
  return;
}



void quicktime_open_rec(void)

{
  quicktime_open_rec();
  return;
}



void destroyAVIOutputStream(void)

{
  destroyAVIOutputStream();
  return;
}



void quicktime_read_co64(void)

{
  quicktime_read_co64();
  return;
}



void MediaFile_SetReadMode(void)

{
  MediaFile_SetReadMode();
  return;
}



void quicktime_trak_init(void)

{
  quicktime_trak_init();
  return;
}



void quicktime_write_int16(void)

{
  quicktime_write_int16();
  return;
}



void quicktime_update_tables_video(void)

{
  quicktime_update_tables_video();
  return;
}



void quicktime_init_audio_map(void)

{
  quicktime_init_audio_map();
  return;
}



void Demuxer_GetAudioData(void)

{
  Demuxer_GetAudioData();
  return;
}



void quicktime_stbl_init(void)

{
  quicktime_stbl_init();
  return;
}



void quicktime_esds_init(void)

{
  quicktime_esds_init();
  return;
}



void quicktime_stsz_init_video_opt(void)

{
  quicktime_stsz_init_video_opt();
  return;
}



void quicktime_write_tkhd(void)

{
  quicktime_write_tkhd();
  return;
}



void AACDemuxer_GetNextHeader(void)

{
  AACDemuxer_GetNextHeader();
  return;
}



void FIFO_Reset_Old(void)

{
  FIFO_Reset_Old();
  return;
}



void mov_str2ulong(void)

{
  mov_str2ulong();
  return;
}



void quicktime_dref_table_delete(void)

{
  quicktime_dref_table_delete();
  return;
}



void quicktime_read_moov(void)

{
  quicktime_read_moov();
  return;
}



void quicktime_atom_is(void)

{
  quicktime_atom_is();
  return;
}



void FIFO_Get_Outaddr(void)

{
  FIFO_Get_Outaddr();
  return;
}



void quicktime_stsc_init_video(void)

{
  quicktime_stsc_init_video();
  return;
}



void quicktime_set_audio_position(void)

{
  quicktime_set_audio_position();
  return;
}



void Bitstream_UsedBits(void)

{
  Bitstream_UsedBits();
  return;
}



void quicktime_write_stco_opt_vide(void)

{
  quicktime_write_stco_opt_vide();
  return;
}



void Demuxer_Close(void)

{
  Demuxer_Close();
  return;
}



void quicktime_stts_init(void)

{
  quicktime_stts_init();
  return;
}



void quicktime_mvhd_delete(void)

{
  quicktime_mvhd_delete();
  return;
}



void quicktime_mdat_delete(void)

{
  quicktime_mdat_delete();
  return;
}



void quicktime_update_stts_opt(void)

{
  quicktime_update_stts_opt();
  return;
}



void AVIIndex_DeleteChain(void)

{
  AVIIndex_DeleteChain();
  return;
}



void quicktime_write_ftyp(void)

{
  quicktime_write_ftyp();
  return;
}



void MediaLib_Dmx_CheckVideoEnd(void)

{
  MediaLib_Dmx_CheckVideoEnd();
  return;
}



void AVIDemuxer_SeekPrevKeyframe(void)

{
  AVIDemuxer_SeekPrevKeyframe();
  return;
}



void str2ushort(void)

{
  str2ushort();
  return;
}



void quicktime_write_stsd_video(void)

{
  quicktime_write_stsd_video();
  return;
}



void quicktime_video_height(void)

{
  quicktime_video_height();
  return;
}



void get_aacsamplerate(void)

{
  get_aacsamplerate();
  return;
}



void AVIOutput_closeXblock_extend(void)

{
  AVIOutput_closeXblock_extend();
  return;
}



void AVC_ParseDecConfigRecord(void)

{
  AVC_ParseDecConfigRecord();
  return;
}



void AVIMuxer_Destroy(void)

{
  AVIMuxer_Destroy();
  return;
}



void AVIMuxer_Close(void)

{
  AVIMuxer_Close();
  return;
}



void quicktime_audio_compressor(void)

{
  quicktime_audio_compressor();
  return;
}



void Muxer_Start(void)

{
  Muxer_Start();
  return;
}



void MP4Demuxer_GetAudioDataSize(void)

{
  MP4Demuxer_GetAudioDataSize();
  return;
}



void Muxer_ProcessVideo(void)

{
  Muxer_ProcessVideo();
  return;
}



void quicktime_stts_delete(void)

{
  quicktime_stts_delete();
  return;
}



void quicktime_video_tracks(void)

{
  quicktime_video_tracks();
  return;
}



void quicktime_seek_video(void)

{
  quicktime_seek_video();
  return;
}



void quicktime_add_track(void)

{
  quicktime_add_track();
  return;
}



void quicktime_get_video_total_frames(void)

{
  quicktime_get_video_total_frames();
  return;
}



void Muxer_GetHeaderSize(void)

{
  Muxer_GetHeaderSize();
  return;
}



void ZeroMemory(void)

{
  ZeroMemory();
  return;
}



void quicktime_read_char32(void)

{
  quicktime_read_char32();
  return;
}



void quicktime_get_mp4_hvcC(void)

{
  quicktime_get_mp4_hvcC();
  return;
}



void Demuxer_SetPos(void)

{
  Demuxer_SetPos();
  return;
}



void AVIDemuxer_GetVideoFrame(void)

{
  AVIDemuxer_GetVideoFrame();
  return;
}



void MP4Muxer_ProcessAudio(void)

{
  MP4Muxer_ProcessAudio();
  return;
}



void Demuxer_SetDataEnd(void)

{
  Demuxer_SetDataEnd();
  return;
}



void MediaFile_SetPosition(void)

{
  MediaFile_SetPosition();
  return;
}



void quicktime_chunk_to_offset(void)

{
  quicktime_chunk_to_offset();
  return;
}



void Demuxer_GetVideoFrame(void)

{
  Demuxer_GetVideoFrame();
  return;
}



void quicktime_stsd_table_delete(void)

{
  quicktime_stsd_table_delete();
  return;
}



void quicktime_delete_trak_rec(void)

{
  quicktime_delete_trak_rec();
  return;
}



void AVIOutput_writeIn(void)

{
  AVIOutput_writeIn();
  return;
}



void quicktime_write_stsc_opt(void)

{
  quicktime_write_stsc_opt();
  return;
}



void Demuxer_GetFirstVideoSize(void)

{
  Demuxer_GetFirstVideoSize();
  return;
}



void quicktime_write_video_frame(void)

{
  quicktime_write_video_frame();
  return;
}



void quicktime_mdhd_init(void)

{
  quicktime_mdhd_init();
  return;
}



void quicktime_write_stsz_opt(void)

{
  quicktime_write_stsz_opt();
  return;
}



void AVIIndex_MakeIndex(void)

{
  AVIIndex_MakeIndex();
  return;
}



void Muxer_Close(void)

{
  Muxer_Close();
  return;
}



void quicktime_write_char32(void)

{
  quicktime_write_char32();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memcpy(__dest,__src,__n);
  return pvVar1;
}



void quicktime_vmhd_delete(void)

{
  quicktime_vmhd_delete();
  return;
}



void newAVIIndex(void)

{
  newAVIIndex();
  return;
}



void quicktime_stsd_init(void)

{
  quicktime_stsd_init();
  return;
}



void quicktime_minf_init_audio(void)

{
  quicktime_minf_init_audio();
  return;
}



void quicktime_write_stts(void)

{
  quicktime_write_stts();
  return;
}



void quicktime_get_mp4_audio_decoder_config2(void)

{
  quicktime_get_mp4_audio_decoder_config2();
  return;
}



void quicktime_tkhd_init(void)

{
  quicktime_tkhd_init();
  return;
}



void quicktime_write_char(void)

{
  quicktime_write_char();
  return;
}



void quicktime_update_stsz_opt_vide(void)

{
  quicktime_update_stsz_opt_vide();
  return;
}



void h264_startcode2length(void)

{
  h264_startcode2length();
  return;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void AVIOutput_closeXblock(void)

{
  AVIOutput_closeXblock();
  return;
}



void Demuxer_GetAudioPackPts(void)

{
  Demuxer_GetAudioPackPts();
  return;
}



void quicktime_read_mdia(void)

{
  quicktime_read_mdia();
  return;
}



void MP4Demuxer_GetVideoPts(void)

{
  MP4Demuxer_GetVideoPts();
  return;
}



void quicktime_write_matrix(void)

{
  quicktime_write_matrix();
  return;
}



void MediaFile_CheckType(void)

{
  MediaFile_CheckType();
  return;
}



void check_id3_header(void)

{
  check_id3_header();
  return;
}



void quicktime_read_mdat(void)

{
  quicktime_read_mdat();
  return;
}



void quicktime_read_mvhd(void)

{
  quicktime_read_mvhd();
  return;
}



void MEML_Destroy(void)

{
  MEML_Destroy();
  return;
}



void quicktime_trak_fix_counts(void)

{
  quicktime_trak_fix_counts();
  return;
}



void quicktime_write_trak_soun(void)

{
  quicktime_write_trak_soun();
  return;
}



void quicktime_minf_init(void)

{
  quicktime_minf_init();
  return;
}



void AVIFilePerf_checkIndexfile(void)

{
  AVIFilePerf_checkIndexfile();
  return;
}



void quicktime_dref_init(void)

{
  quicktime_dref_init();
  return;
}



void quicktime_write_fixed32(void)

{
  quicktime_write_fixed32();
  return;
}



void Demuxer_FastRewind(void)

{
  Demuxer_FastRewind();
  return;
}



void AMRDemuxer_Close(void)

{
  AMRDemuxer_Close();
  return;
}



void quicktime_atom_skip(void)

{
  quicktime_atom_skip();
  return;
}



void quicktime_write_int24(void)

{
  quicktime_write_int24();
  return;
}



void quicktime_get_proper_audiotrack(void)

{
  quicktime_get_proper_audiotrack();
  return;
}



void quicktime_set_video(void)

{
  quicktime_set_video();
  return;
}



void AVIDemuxer_IsKeyframe(void)

{
  AVIDemuxer_IsKeyframe();
  return;
}



void quicktime_read_fixed16(void)

{
  quicktime_read_fixed16();
  return;
}



void quicktime_stsz_delete_opt(void)

{
  quicktime_stsz_delete_opt();
  return;
}



void MP4Demuxer_SeekNextKeyframe(void)

{
  MP4Demuxer_SeekNextKeyframe();
  return;
}



void Demuxer_Resume(void)

{
  Demuxer_Resume();
  return;
}



void MediaFile_GetPosition(void)

{
  MediaFile_GetPosition();
  return;
}



void AACDemuxer_Close(void)

{
  AACDemuxer_Close();
  return;
}



void quicktime_stco_init(void)

{
  quicktime_stco_init();
  return;
}



void AVIOutput_writeVideoIndex(void)

{
  AVIOutput_writeVideoIndex();
  return;
}



void quicktime_stsd_init_video(void)

{
  quicktime_stsd_init_video();
  return;
}



void quicktime_write_mdia(void)

{
  quicktime_write_mdia();
  return;
}



void AVIOutput_writeDirect(void)

{
  AVIOutput_writeDirect();
  return;
}



void Demuxer_Stop(void)

{
  Demuxer_Stop();
  return;
}



void AVIIndex_WriteIndexFromTemp(void)

{
  AVIIndex_WriteIndexFromTemp();
  return;
}



void quicktime_is_keyframe(void)

{
  quicktime_is_keyframe();
  return;
}



void newAVIIndexChainNode(void)

{
  newAVIIndexChainNode();
  return;
}



void quicktime_read_esds(void)

{
  quicktime_read_esds();
  return;
}



void AACDemuxer_ReleaseInfoMem(void)

{
  AACDemuxer_ReleaseInfoMem();
  return;
}



void destroyAVIIndex(void)

{
  destroyAVIIndex();
  return;
}



void quicktime_sample_range_size(void)

{
  quicktime_sample_range_size();
  return;
}



void quicktime_read_stco(void)

{
  quicktime_read_stco();
  return;
}



void Demuxer_GetNextBlockInfo(void)

{
  Demuxer_GetNextBlockInfo();
  return;
}



void quicktime_stsz_init_audio(void)

{
  quicktime_stsz_init_audio();
  return;
}



void quicktime_dinf_init_all(void)

{
  quicktime_dinf_init_all();
  return;
}



void MP4Demuxer_SeekPrevKeyframe(void)

{
  MP4Demuxer_SeekPrevKeyframe();
  return;
}



void quicktime_write_mdat(void)

{
  quicktime_write_mdat();
  return;
}



void quicktime_write_minf(void)

{
  quicktime_write_minf();
  return;
}



void quicktime_mdhd_init_audio(void)

{
  quicktime_mdhd_init_audio();
  return;
}



void AVIDemuxer_SeekVideo(void)

{
  AVIDemuxer_SeekVideo();
  return;
}



void MP4_ReleaseMetaInfo(void)

{
  MP4_ReleaseMetaInfo();
  return;
}



void quicktime_write_stsc(void)

{
  quicktime_write_stsc();
  return;
}



void FIFO_Get_Old(void)

{
  FIFO_Get_Old();
  return;
}



void Muxer_ProcessAudio(void)

{
  Muxer_ProcessAudio();
  return;
}



void quicktime_get_audio_total_bytes(void)

{
  quicktime_get_audio_total_bytes();
  return;
}



void Dnp_Crc(void)

{
  Dnp_Crc();
  return;
}



void quicktime_chunk_of_sample(void)

{
  quicktime_chunk_of_sample();
  return;
}



void quicktime_hdlr_init_video(void)

{
  quicktime_hdlr_init_video();
  return;
}



void quicktime_check_video_valid(void)

{
  quicktime_check_video_valid();
  return;
}



void quicktime_match_32(void)

{
  quicktime_match_32();
  return;
}



void quicktime_read_mdhd(void)

{
  quicktime_read_mdhd();
  return;
}



void ulong2str(void)

{
  ulong2str();
  return;
}



void quicktime_update_stss_opt(void)

{
  quicktime_update_stss_opt();
  return;
}



void AVIOutput_WriteHDR(void)

{
  AVIOutput_WriteHDR();
  return;
}



void quicktime_read_stsc(void)

{
  quicktime_read_stsc();
  return;
}



void quicktime_write_stbl(void)

{
  quicktime_write_stbl();
  return;
}



void Demuxer_ReleaseInfoMem(void)

{
  Demuxer_ReleaseInfoMem();
  return;
}



void AVIDemuxer_SeekAudio(void)

{
  AVIDemuxer_SeekAudio();
  return;
}



void quicktime_read_stsd_audio(void)

{
  quicktime_read_stsd_audio();
  return;
}



void quicktime_close(void)

{
  quicktime_close();
  return;
}



void quicktime_track_channels(void)

{
  quicktime_track_channels();
  return;
}



void MediaFile_Write(void)

{
  MediaFile_Write();
  return;
}



void AVIOutput_beginList(void)

{
  AVIOutput_beginList();
  return;
}



void MediaLib_Dmx_Close(void)

{
  MediaLib_Dmx_Close();
  return;
}



void quicktime_cal_video_pts(void)

{
  quicktime_cal_video_pts();
  return;
}



void Demuxer_DisableAudio(void)

{
  Demuxer_DisableAudio();
  return;
}



void quicktime_read_matrix(void)

{
  quicktime_read_matrix();
  return;
}



void quicktime_set_mp4_video_decoder_config2(void)

{
  quicktime_set_mp4_video_decoder_config2();
  return;
}



void quicktime_audio_totaltime(void)

{
  quicktime_audio_totaltime();
  return;
}



void quicktime_read_info(void)

{
  quicktime_read_info();
  return;
}



void quicktime_write_minf_soun(void)

{
  quicktime_write_minf_soun();
  return;
}



void Demuxer_InitFifo(void)

{
  Demuxer_InitFifo();
  return;
}



void quicktime_atom_read_size64(void)

{
  quicktime_atom_read_size64();
  return;
}



void quicktime_stss_delete(void)

{
  quicktime_stss_delete();
  return;
}



void quicktime_delete_audio_map(void)

{
  quicktime_delete_audio_map();
  return;
}



void MediaFile_SkipZeroBytes(void)

{
  MediaFile_SkipZeroBytes();
  return;
}



void quicktime_read_stts(void)

{
  quicktime_read_stts();
  return;
}



void quicktime_get_total_time(void)

{
  quicktime_get_total_time();
  return;
}



void AVIOutput_createNewIndices_extend(void)

{
  AVIOutput_createNewIndices_extend();
  return;
}



void quicktime_set_audio(void)

{
  quicktime_set_audio();
  return;
}



void quicktime_moov_size(void)

{
  quicktime_moov_size();
  return;
}



void quicktime_delete_video_map(void)

{
  quicktime_delete_video_map();
  return;
}



void __deregister_frame_info(void)

{
  __deregister_frame_info();
  return;
}



void quicktime_stsd_table_init(void)

{
  quicktime_stsd_table_init();
  return;
}



void quicktime_audio_frame_size(void)

{
  quicktime_audio_frame_size();
  return;
}



void quicktime_read_char(void)

{
  quicktime_read_char();
  return;
}



void FIFO_Drop(void)

{
  FIFO_Drop();
  return;
}



void quicktime_read_stsd_video(void)

{
  quicktime_read_stsd_video();
  return;
}



void newAVIOutput(void)

{
  newAVIOutput();
  return;
}



void AVIOutput_writeLegacyIndex(void)

{
  AVIOutput_writeLegacyIndex();
  return;
}



void Demuxer_ResetAudioPos(void)

{
  Demuxer_ResetAudioPos();
  return;
}



void Demuxer_Start(void)

{
  Demuxer_Start();
  return;
}



void AVIDemuxer_Close(void)

{
  AVIDemuxer_Close();
  return;
}



void FIFO_ItemNum_Old(void)

{
  FIFO_ItemNum_Old();
  return;
}



void MediaLib_Mux_Close(void)

{
  MediaLib_Mux_Close();
  return;
}



void quicktime_trak_duration(void)

{
  quicktime_trak_duration();
  return;
}



void quicktime_set_video_position(void)

{
  quicktime_set_video_position();
  return;
}



void quicktime_hdlr_init(void)

{
  quicktime_hdlr_init();
  return;
}



void quicktime_video_frame_rate(void)

{
  quicktime_video_frame_rate();
  return;
}



void quicktime_video_totaltime(void)

{
  quicktime_video_totaltime();
  return;
}



void quicktime_stts_init_table(void)

{
  quicktime_stts_init_table();
  return;
}



void quicktime_get_mp4_video_decoder_objcetTypeId(void)

{
  quicktime_get_mp4_video_decoder_objcetTypeId();
  return;
}



void FIFO_ItemNum(void)

{
  FIFO_ItemNum();
  return;
}



void AVIOutput_Reinit(void)

{
  AVIOutput_Reinit();
  return;
}



void quicktime_audio_tracks(void)

{
  quicktime_audio_tracks();
  return;
}



void quicktime_get_audio_bitrate(void)

{
  quicktime_get_audio_bitrate();
  return;
}



void quicktime_moov_delete_rec(void)

{
  quicktime_moov_delete_rec();
  return;
}



void Demuxer_GetKeyframeSize(void)

{
  Demuxer_GetKeyframeSize();
  return;
}



void MEML_GetElement(void)

{
  MEML_GetElement();
  return;
}



void quicktime_get_mp4_video_decoder_config2(void)

{
  quicktime_get_mp4_video_decoder_config2();
  return;
}



void FIFO_FreeSpace(void)

{
  FIFO_FreeSpace();
  return;
}



void MediaFile_CheckTypeForID3(void)

{
  MediaFile_CheckTypeForID3();
  return;
}



void quicktime_current_time(void)

{
  quicktime_current_time();
  return;
}



void quicktime_mdia_init_video(void)

{
  quicktime_mdia_init_video();
  return;
}



void quicktime_delete_rec(void)

{
  quicktime_delete_rec();
  return;
}



void quicktime_stsd_init_audio(void)

{
  quicktime_stsd_init_audio();
  return;
}



void quicktime_dinf_delete(void)

{
  quicktime_dinf_delete();
  return;
}



void FIFO_Init_Old(void)

{
  FIFO_Init_Old();
  return;
}



void quicktime_write_mvhd(void)

{
  quicktime_write_mvhd();
  return;
}



void quicktime_stbl_delete_rec(void)

{
  quicktime_stbl_delete_rec();
  return;
}



void get_bits64(void)

{
  get_bits64();
  return;
}



void quicktime_write_esds_audio(void)

{
  quicktime_write_esds_audio();
  return;
}



void quicktime_atom_read_size(void)

{
  quicktime_atom_read_size();
  return;
}



void quicktime_stts_init_audio(void)

{
  quicktime_stts_init_audio();
  return;
}



void MP4Demuxer_IsKeyframe(void)

{
  MP4Demuxer_IsKeyframe();
  return;
}



void quicktime_open(void)

{
  quicktime_open();
  return;
}



void Demuxer_GetAudioDataSize(void)

{
  Demuxer_GetAudioDataSize();
  return;
}



void quicktime_smhd_delete(void)

{
  quicktime_smhd_delete();
  return;
}



void quicktime_dref_table_init(void)

{
  quicktime_dref_table_init();
  return;
}



void FIFO_Get_Inaddr(void)

{
  FIFO_Get_Inaddr();
  return;
}



void Demuxer_FastForward(void)

{
  Demuxer_FastForward();
  return;
}



void quicktime_copy_char32(void)

{
  quicktime_copy_char32();
  return;
}



void MediaLib_Dmx_CheckAudioEnd(void)

{
  MediaLib_Dmx_CheckAudioEnd();
  return;
}



void quicktime_stsz_delete(void)

{
  quicktime_stsz_delete();
  return;
}



void ConvertUTF82Unicode(void)

{
  ConvertUTF82Unicode();
  return;
}



void check_mp3layer(void)

{
  check_mp3layer();
  return;
}



void str2ulong(void)

{
  str2ulong();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = memcmp(__s1,__s2,__n);
  return iVar1;
}



void quicktime_get_file_position_video(void)

{
  quicktime_get_file_position_video();
  return;
}



void WAVDemuxer_Close(void)

{
  WAVDemuxer_Close();
  return;
}



void quicktime_add_trak(void)

{
  quicktime_add_trak();
  return;
}



void Demuxer_GetAudioPTS(void)

{
  Demuxer_GetAudioPTS();
  return;
}



void quicktime_write_stss_opt(void)

{
  quicktime_write_stss_opt();
  return;
}



void Demuxer_DisableVideo(void)

{
  Demuxer_DisableVideo();
  return;
}



void quicktime_read_stsd(void)

{
  quicktime_read_stsd();
  return;
}



void quicktime_dref_delete(void)

{
  quicktime_dref_delete();
  return;
}



void quicktime_get_proper_videotrack(void)

{
  quicktime_get_proper_videotrack();
  return;
}



void quicktime_write_moov(void)

{
  quicktime_write_moov();
  return;
}



void quicktime_write_trak_video(void)

{
  quicktime_write_trak_video();
  return;
}



void quicktime_delete(void)

{
  quicktime_delete();
  return;
}



void quicktime_update_stsc_opt(void)

{
  quicktime_update_stsc_opt();
  return;
}



void quicktime_mdia_init(void)

{
  quicktime_mdia_init();
  return;
}



void quicktime_hdlr_delete(void)

{
  quicktime_hdlr_delete();
  return;
}



void MediaFile_Open(void)

{
  MediaFile_Open();
  return;
}



void quicktime_stsz_init(void)

{
  quicktime_stsz_init();
  return;
}



void MP4Demuxer_GetVideoFrameSize(void)

{
  MP4Demuxer_GetVideoFrameSize();
  return;
}



void Demuxer_CheckAudioEnd(void)

{
  Demuxer_CheckAudioEnd();
  return;
}



void Bitstream_Init(void)

{
  Bitstream_Init();
  return;
}



void AVIDemuxer_GetVideoPts(void)

{
  AVIDemuxer_GetVideoPts();
  return;
}



void quicktime_write_audio_frame(void)

{
  quicktime_write_audio_frame();
  return;
}



void Bitstream_FlushBits(void)

{
  Bitstream_FlushBits();
  return;
}



void quicktime_atom_write_header(void)

{
  quicktime_atom_write_header();
  return;
}



void quicktime_check_audio_valid(void)

{
  quicktime_check_audio_valid();
  return;
}



void quicktime_seek_audio(void)

{
  quicktime_seek_audio();
  return;
}



void quicktime_smhd_init(void)

{
  quicktime_smhd_init();
  return;
}



void quicktime_get_mp4_video_decoder_config_size(void)

{
  quicktime_get_mp4_video_decoder_config_size();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



void quicktime_write_mp4_descr_length(void)

{
  quicktime_write_mp4_descr_length();
  return;
}



void quicktime_init_audio_map_rec(void)

{
  quicktime_init_audio_map_rec();
  return;
}



void quicktime_stsc_init_table(void)

{
  quicktime_stsc_init_table();
  return;
}



void quicktime_delete_trak(void)

{
  quicktime_delete_trak();
  return;
}



void quicktime_audio_sample_rate(void)

{
  quicktime_audio_sample_rate();
  return;
}



void AVIOutput_seekHeader(void)

{
  AVIOutput_seekHeader();
  return;
}



void Demuxer_GetInfo(void)

{
  Demuxer_GetInfo();
  return;
}



void quicktime_write_stss(void)

{
  quicktime_write_stss();
  return;
}



void quicktime_trak_init_audio(void)

{
  quicktime_trak_init_audio();
  return;
}



void get_mp3samplerate(void)

{
  get_mp3samplerate();
  return;
}



void quicktime_stco_delete_opt(void)

{
  quicktime_stco_delete_opt();
  return;
}



void AVIOutput_writeAudioIndex(void)

{
  AVIOutput_writeAudioIndex();
  return;
}



void quicktime_update_stco_opt(void)

{
  quicktime_update_stco_opt();
  return;
}



void quicktime_write_stts_opt(void)

{
  quicktime_write_stts_opt();
  return;
}



void Muxer_Restart(void)

{
  Muxer_Restart();
  return;
}



void quicktime_hdlr_init_audio(void)

{
  quicktime_hdlr_init_audio();
  return;
}



void AVIOutput_SetCaptureMode(void)

{
  AVIOutput_SetCaptureMode();
  return;
}



void AVIIndex_PutEntry(void)

{
  AVIIndex_PutEntry();
  return;
}



void quicktime_minf_delete_rec(void)

{
  quicktime_minf_delete_rec();
  return;
}



void quicktime_mdhd_delete(void)

{
  quicktime_mdhd_delete();
  return;
}



void quicktime_write_stsd_table(void)

{
  quicktime_write_stsd_table();
  return;
}



void quicktime_write_dref_table(void)

{
  quicktime_write_dref_table();
  return;
}



void quicktime_read_mp4_descr_length(void)

{
  quicktime_read_mp4_descr_length();
  return;
}



void quicktime_read_data(void)

{
  quicktime_read_data();
  return;
}



void MediaLib_Dmx_Pause(void)

{
  MediaLib_Dmx_Pause();
  return;
}



void quicktime_mdia_delete(void)

{
  quicktime_mdia_delete();
  return;
}



void MP4Demuxer_GetVideoFrame(void)

{
  MP4Demuxer_GetVideoFrame();
  return;
}



void quicktime_atom_read_type(void)

{
  quicktime_atom_read_type();
  return;
}



void quicktime_stbl_init_audio(void)

{
  quicktime_stbl_init_audio();
  return;
}



void quicktime_minf_delete(void)

{
  quicktime_minf_delete();
  return;
}



void Bitstream_ReadBits(void)

{
  Bitstream_ReadBits();
  return;
}



void quicktime_moov_delete(void)

{
  quicktime_moov_delete();
  return;
}



void AVIIndex_AddEntry2(void)

{
  AVIIndex_AddEntry2();
  return;
}



void quicktime_set_mp4_audio_decoder_config2(void)

{
  quicktime_set_mp4_audio_decoder_config2();
  return;
}



void AVIFilePerf_checkMoviData(void)

{
  AVIFilePerf_checkMoviData();
  return;
}



void quicktime_read_stbl(void)

{
  quicktime_read_stbl();
  return;
}



void quicktime_write_smhd(void)

{
  quicktime_write_smhd();
  return;
}



void MediaFile_Read(void)

{
  MediaFile_Read();
  return;
}



void Bitstream_ShowBits(void)

{
  Bitstream_ShowBits();
  return;
}



void MediaFile_SkipID3(void)

{
  MediaFile_SkipID3();
  return;
}



void quicktime_tkhd_delete(void)

{
  quicktime_tkhd_delete();
  return;
}



void AVIDemuxer_SeekNextKeyframe(void)

{
  AVIDemuxer_SeekNextKeyframe();
  return;
}



void AVIOutput_SetAudioSamples(void)

{
  AVIOutput_SetAudioSamples();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = sprintf(__s,__format);
  return iVar1;
}



void MP4Demuxer_Close(void)

{
  MP4Demuxer_Close();
  return;
}



void MediaFile_Close(void)

{
  MediaFile_Close();
  return;
}



void quicktime_udta_init(void)

{
  quicktime_udta_init();
  return;
}



void quicktime_write_int64(void)

{
  quicktime_write_int64();
  return;
}



void quicktime_write_dinf(void)

{
  quicktime_write_dinf();
  return;
}



void quicktime_atom_read_header(void)

{
  quicktime_atom_read_header();
  return;
}



void Demuxer_GetAudioSeekInfo(void)

{
  Demuxer_GetAudioSeekInfo();
  return;
}



void quicktime_dref_init_all(void)

{
  quicktime_dref_init_all();
  return;
}



void AVIIndex_AddChain(void)

{
  AVIIndex_AddChain();
  return;
}



void AVIIndexChainNode_Add(void)

{
  AVIIndexChainNode_Add();
  return;
}



void quicktime_esds_delete(void)

{
  quicktime_esds_delete();
  return;
}



void Demuxer_CheckVideoEnd(void)

{
  Demuxer_CheckVideoEnd();
  return;
}



void quicktime_write_fixed16(void)

{
  quicktime_write_fixed16();
  return;
}



void quicktime_release_infomem(void)

{
  quicktime_release_infomem();
  return;
}



void quicktime_read_minf(void)

{
  quicktime_read_minf();
  return;
}



void quicktime_read_tkhd(void)

{
  quicktime_read_tkhd();
  return;
}



void AVIMuxer_Stop(void)

{
  AVIMuxer_Stop();
  return;
}



void quicktime_read_trak(void)

{
  quicktime_read_trak();
  return;
}



void AVIOutput_SetCompressed(void)

{
  AVIOutput_SetCompressed();
  return;
}



void Muxer_Stop(void)

{
  Muxer_Stop();
  return;
}



void quicktime_track_bitspersample(void)

{
  quicktime_track_bitspersample();
  return;
}



void quicktime_init(void)

{
  quicktime_init();
  return;
}



void quicktime_read_stsd_table(void)

{
  quicktime_read_stsd_table();
  return;
}



void quicktime_dinf_init(void)

{
  quicktime_dinf_init();
  return;
}



void MP4Muxer_Stop(void)

{
  MP4Muxer_Stop();
  return;
}



void quicktime_tkhd_init_video(void)

{
  quicktime_tkhd_init_video();
  return;
}



void FIFO_Add_Old(void)

{
  FIFO_Add_Old();
  return;
}



void quicktime_stsc_delete(void)

{
  quicktime_stsc_delete();
  return;
}



void quicktime_update_stsc(void)

{
  quicktime_update_stsc();
  return;
}



void quicktime_trak_init_video(void)

{
  quicktime_trak_init_video();
  return;
}



void AVIOutput_writeHeaderChunk(void)

{
  AVIOutput_writeHeaderChunk();
  return;
}



void quicktime_get_audio_total_samples(void)

{
  quicktime_get_audio_total_samples();
  return;
}



void quicktime_stsc_init_audio(void)

{
  quicktime_stsc_init_audio();
  return;
}



void quicktime_mdhd_init_video(void)

{
  quicktime_mdhd_init_video();
  return;
}



void quicktime_write_stsd(void)

{
  quicktime_write_stsd();
  return;
}



void quicktime_read_int16(void)

{
  quicktime_read_int16();
  return;
}



void quicktime_trak_delete_rec(void)

{
  quicktime_trak_delete_rec();
  return;
}



void quicktime_is_anka_3gp(void)

{
  quicktime_is_anka_3gp();
  return;
}



void AVIOutput_seekDirect(void)

{
  AVIOutput_seekDirect();
  return;
}



void mov_ulong2str(void)

{
  mov_ulong2str();
  return;
}



void Demuxer_GetStatus(void)

{
  Demuxer_GetStatus();
  return;
}



void quicktime_set_position(void)

{
  quicktime_set_position();
  return;
}



void quicktime_write_int32(void)

{
  quicktime_write_int32();
  return;
}



void FIFO_Destroy(void)

{
  FIFO_Destroy();
  return;
}



void quicktime_write_esds_video(void)

{
  quicktime_write_esds_video();
  return;
}



void quicktime_set_mp4_hvcC(void)

{
  quicktime_set_mp4_hvcC();
  return;
}



void quicktime_mdia_init_audio(void)

{
  quicktime_mdia_init_audio();
  return;
}



void quicktime_write_mdia_soun(void)

{
  quicktime_write_mdia_soun();
  return;
}



void quicktime_tkhd_init_audio(void)

{
  quicktime_tkhd_init_audio();
  return;
}



void quicktime_read_udta(void)

{
  quicktime_read_udta();
  return;
}



void quicktime_trak_delete(void)

{
  quicktime_trak_delete();
  return;
}



void quicktime_moov_init(void)

{
  quicktime_moov_init();
  return;
}



void Demuxer_Open(void)

{
  Demuxer_Open();
  return;
}



void quicktime_read_int32(void)

{
  quicktime_read_int32();
  return;
}



void AVIOutput_flushHeader(void)

{
  AVIOutput_flushHeader();
  return;
}



void MP4Demuxer_ReleaseInfoMem(void)

{
  MP4Demuxer_ReleaseInfoMem();
  return;
}



void FIFO_Add(void)

{
  FIFO_Add();
  return;
}



void quicktime_udta_delete(void)

{
  quicktime_udta_delete();
  return;
}



void AVIOutput_writeHeader(void)

{
  AVIOutput_writeHeader();
  return;
}



void quicktime_get_video_total_keyframes(void)

{
  quicktime_get_video_total_keyframes();
  return;
}



void quicktime_init_video_map(void)

{
  quicktime_init_video_map();
  return;
}



void quicktime_stsc_init(void)

{
  quicktime_stsc_init();
  return;
}



void quicktime_stbl_delete(void)

{
  quicktime_stbl_delete();
  return;
}



void quicktime_write_mdhd(void)

{
  quicktime_write_mdhd();
  return;
}



void Muxer_Open(void)

{
  Muxer_Open();
  return;
}



void quicktime_get_file_position_audio(void)

{
  quicktime_get_file_position_audio();
  return;
}



void quicktime_sample_to_offset(void)

{
  quicktime_sample_to_offset();
  return;
}



void quicktime_stsd_init_table(void)

{
  quicktime_stsd_init_table();
  return;
}



void Muxer_GetCurrFileSize(void)

{
  Muxer_GetCurrFileSize();
  return;
}



void quicktime_get_video_bitrate(void)

{
  quicktime_get_video_bitrate();
  return;
}



void quicktime_update_tables_audio(void)

{
  quicktime_update_tables_audio();
  return;
}



void quicktime_read_stss(void)

{
  quicktime_read_stss();
  return;
}



void quicktime_read_fixed32(void)

{
  quicktime_read_fixed32();
  return;
}



void AVIOutput_Finalize(void)

{
  AVIOutput_Finalize();
  return;
}



void Demuxer_GetFirstVideo(void)

{
  Demuxer_GetFirstVideo();
  return;
}



void FIFO_Get_Length(void)

{
  FIFO_Get_Length();
  return;
}



void quicktime_write_data(void)

{
  quicktime_write_data();
  return;
}



void MediaFile_GetTotalLen(void)

{
  MediaFile_GetTotalLen();
  return;
}



void MediaFile_ChangePosition(void)

{
  MediaFile_ChangePosition();
  return;
}



void quicktime_stbl_init_video(void)

{
  quicktime_stbl_init_video();
  return;
}



void quicktime_write_pascal(void)

{
  quicktime_write_pascal();
  return;
}



void quicktime_matrix_init(void)

{
  quicktime_matrix_init();
  return;
}



void AVIOutput_writeLegacyIndex_extend(void)

{
  AVIOutput_writeLegacyIndex_extend();
  return;
}



void quicktime_video_compressor(void)

{
  quicktime_video_compressor();
  return;
}



void get_aacFreqIndex(void)

{
  get_aacFreqIndex();
  return;
}



void quicktime_stco_delete(void)

{
  quicktime_stco_delete();
  return;
}



void quicktime_write_stsd_audio(void)

{
  quicktime_write_stsd_audio();
  return;
}



void quicktime_frame_size(void)

{
  quicktime_frame_size();
  return;
}



void quicktime_write_vmhd(void)

{
  quicktime_write_vmhd();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void MediaFile_CheckMediaType(void)

{
  MediaFile_CheckMediaType();
  return;
}



void quicktime_write_dref(void)

{
  quicktime_write_dref();
  return;
}



void MediaLib_Mux_Stop(void)

{
  MediaLib_Mux_Stop();
  return;
}



void quicktime_read_int24(void)

{
  quicktime_read_int24();
  return;
}



void AVIOutputStream_Finalize(void)

{
  AVIOutputStream_Finalize();
  return;
}



void quicktime_write_stbl_soun(void)

{
  quicktime_write_stbl_soun();
  return;
}



void quicktime_vmhd_init_video(void)

{
  quicktime_vmhd_init_video();
  return;
}



void quicktime_vmhd_init(void)

{
  quicktime_vmhd_init();
  return;
}



void AVIOutput_openXblock(void)

{
  AVIOutput_openXblock();
  return;
}



void quicktime_read_stsz(void)

{
  quicktime_read_stsz();
  return;
}



void quicktime_video_width(void)

{
  quicktime_video_width();
  return;
}



void quicktime_stss_init(void)

{
  quicktime_stss_init();
  return;
}



void quicktime_close_rec(void)

{
  quicktime_close_rec();
  return;
}



void quicktime_audio_position(void)

{
  quicktime_audio_position();
  return;
}



void quicktime_update_stsz_opt(void)

{
  quicktime_update_stsz_opt();
  return;
}



void quicktime_atom_reset(void)

{
  quicktime_atom_reset();
  return;
}



void FIFO_Destroy_Old(void)

{
  FIFO_Destroy_Old();
  return;
}



void quicktime_atom_write_footer(void)

{
  quicktime_atom_write_footer();
  return;
}



void quicktime_read_video_frame(void)

{
  quicktime_read_video_frame();
  return;
}



void MulDiv(void)

{
  MulDiv();
  return;
}



void __register_frame_info(void)

{
  __register_frame_info();
  return;
}



void MediaFile_ReOpen(void)

{
  MediaFile_ReOpen();
  return;
}



void Demuxer_GetVideoFrameSize(void)

{
  Demuxer_GetVideoFrameSize();
  return;
}



void FIFO_Init(void)

{
  FIFO_Init();
  return;
}



void quicktime_position(void)

{
  quicktime_position();
  return;
}



void MEML_StoreElement(void)

{
  MEML_StoreElement();
  return;
}



void AVIIndexChainNode_PutNodeEntry(void)

{
  AVIIndexChainNode_PutNodeEntry();
  return;
}



void FIFO_Reset(void)

{
  FIFO_Reset();
  return;
}



void mov_str2ushort(void)

{
  mov_str2ushort();
  return;
}



void quicktime_write_stco_opt(void)

{
  quicktime_write_stco_opt();
  return;
}



void newAVIOutputStream(void)

{
  newAVIOutputStream();
  return;
}



void Demuxer_Pause(void)

{
  Demuxer_Pause();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = raise(__sig);
  return iVar1;
}



void quicktime_write_hdlr(void)

{
  quicktime_write_hdlr();
  return;
}



void quicktime_mdia_delete_rec(void)

{
  quicktime_mdia_delete_rec();
  return;
}



void AVIOutput_getPosition(void)

{
  AVIOutput_getPosition();
  return;
}



void MP4Muxer_Close(void)

{
  MP4Muxer_Close();
  return;
}



void quicktime_mvhd_init(void)

{
  quicktime_mvhd_init();
  return;
}



// WARNING: Removing unreachable block (ram,0x000190a8)
// WARNING: Removing unreachable block (ram,0x000190b4)
// WARNING: Removing unreachable block (ram,0x000190b8)

void processEntry deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00019100)
// WARNING: Removing unreachable block (ram,0x0001910c)
// WARNING: Removing unreachable block (ram,0x00019110)

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
    if (ppuVar1[0x1ef] != (undefined *)0x0) {
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



undefined4 * MediaLib_Dmx_Open(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined1 local_1c;
  undefined4 *local_18;
  char *local_14;
  
  if (param_2 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)0x0;
  }
  else if (param_1 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)0x0;
  }
  else {
    local_14 = "Media Lib V1.19.00_svn5741";
    iVar1 = memcmp((void *)param_1[0x1b],"Media Lib V1.19.00_svn5741",0x10);
    if (iVar1 == 0) {
      *param_2 = 2;
      if ((param_1[0x11] == 0) || (iVar1 = (*(code *)param_1[0x11])(param_1[1]), iVar1 != 0)) {
        if (param_1[2] == 0) {
          g_medialib_printf = info_print;
        }
        else {
          g_medialib_printf = (code *)param_1[2];
        }
        if (param_1[2] != 0) {
          (*(code *)param_1[2])("\r\n--Demux %s--\r\n\r\n","Media Lib V1.19.00_svn5741");
        }
        local_18 = (undefined4 *)(*(code *)param_1[7])(0xec);
        if (local_18 == (undefined4 *)0x0) {
          if (param_1[2] != 0) {
            (*(code *)param_1[2])("##MediaLib_Dmx: ERROR--malloc##\r\n");
          }
          *param_2 = 3;
          local_18 = (undefined4 *)0x0;
        }
        else {
          ZeroMemory(local_18,0xec);
          memcpy(local_18 + 2,param_1,0x70);
          if (param_1[2] == 0) {
            local_18[4] = info_print;
          }
          ZeroMemory(local_28,0x10);
          local_28[0] = param_1[1];
          local_20 = *param_1;
          local_1c = 1;
          uVar2 = Demuxer_Open(local_28,local_18 + 4);
          local_18[0x1e] = uVar2;
          if (local_18[0x1e] == 0) {
            (*g_medialib_printf)("##MediaLib_Dmx: ERROR--open demuxer failed##\r\n");
            MediaLib_Dmx_Close(local_18);
            *param_2 = 1;
            local_18 = (undefined4 *)0x0;
          }
          else {
            local_18[0x1f] = local_20;
            iVar1 = Demuxer_GetInfo(local_18[0x1e],local_18 + 0x20);
            if (iVar1 == 0) {
              MediaLib_Dmx_Close(local_18);
              *param_2 = 3;
              local_18 = (undefined4 *)0x0;
            }
            else {
              if (local_18[0x23] != 0) {
                *(undefined1 *)(local_18 + 0x3a) = 1;
                *(byte *)((int)local_18 + 0xea) = *(byte *)((int)local_18 + 0xea) | 2;
              }
              if (local_18[0x22] != 0) {
                *(undefined1 *)((int)local_18 + 0xe9) = 1;
                *(byte *)((int)local_18 + 0xea) = *(byte *)((int)local_18 + 0xea) | 1;
              }
              Demuxer_InitFifo(local_18[0x1e],0,0);
              *local_18 = 0xec;
              local_18[1] = 3;
              *param_2 = 0;
            }
          }
        }
      }
      else {
        local_18 = (undefined4 *)0x0;
      }
    }
    else {
      (*(code *)param_1[2])("## ERROR: Wrong version input.\n","Media Lib V1.19.00_svn5741");
      local_18 = (undefined4 *)0x0;
    }
  }
  return local_18;
}



undefined4 MediaLib_Dmx_Close(void *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  code *pcVar3;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    pcVar2 = *(code **)((int)param_1 + 0x28);
    if (pcVar2 == (code *)0x0) {
      uVar1 = 0;
    }
    else {
      pcVar3 = *(code **)((int)param_1 + 0x10);
      Demuxer_Close(*(undefined4 *)((int)param_1 + 0x78));
      memset(param_1,0,0xec);
      (*pcVar2)(param_1);
      (*pcVar3)("\r\n--Leave Demux %s--\r\n\r\n","Media Lib V1.19.00_svn5741");
      uVar1 = 1;
    }
  }
  return uVar1;
}



int MediaLib_Dmx_Start(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return -1;
  }
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    goto LAB_00019724;
  case 1:
    break;
  case 2:
    break;
  case 3:
LAB_00019724:
    Demuxer_Stop(*(undefined4 *)(param_1 + 0x78));
    goto LAB_0001977c;
  case 4:
    break;
  case 5:
    goto LAB_00019738;
  case 6:
    goto LAB_00019738;
  case 7:
LAB_00019738:
    Demuxer_Pause(*(undefined4 *)(param_1 + 0x78));
LAB_0001977c:
    uVar1 = Demuxer_Start(*(undefined4 *)(param_1 + 0x78),param_2);
    switch(uVar1) {
    case 0:
      (*g_medialib_printf)("##MediaLib_Dmx: ERROR--Demuxer start failed##\r\n");
      *(undefined4 *)(param_1 + 4) = 4;
      return -1;
    case 1:
      if (*(int *)(param_1 + 0x8c) != 0) {
        (*g_medialib_printf)("##MediaLib_Dmx: WARNING--get audio error, disable audio##\r\n");
        Demuxer_DisableAudio(*(undefined4 *)(param_1 + 0x78));
      }
      break;
    case 2:
      break;
    case 3:
      (*g_medialib_printf)("##MediaLib_Dmx: WARNING--movie comes to end##\r\n");
      *(undefined4 *)(param_1 + 4) = 0;
      return -1;
    }
    iVar2 = Demuxer_GetAudioPTS(*(undefined4 *)(param_1 + 0x78));
    if (iVar2 < 0) {
      *(undefined4 *)(param_1 + 4) = 4;
      return -1;
    }
    iVar3 = MediaLib_Dmx_CheckAudioEnd(param_1);
    if ((iVar3 == 0) && ((*(byte *)(param_1 + 0xea) & 2) == 0)) {
      Demuxer_DisableAudio(*(undefined4 *)(param_1 + 0x78));
    }
    iVar3 = MediaLib_Dmx_CheckVideoEnd(param_1);
    if ((iVar3 == 0) && ((*(byte *)(param_1 + 0xea) & 1) == 0)) {
      Demuxer_DisableVideo(*(undefined4 *)(param_1 + 0x78));
    }
    *(undefined4 *)(param_1 + 4) = 1;
    return iVar2;
  }
  (*g_medialib_printf)("##MediaLib_Dmx: ERROR--start, status %d##\r\n",*(undefined4 *)(param_1 + 4))
  ;
  return -1;
}



char MediaLib_Dmx_Resume(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    cVar1 = Demuxer_Resume(*(undefined4 *)(param_1 + 0x78));
    if (cVar1 == '\x01') {
      *(undefined4 *)(param_1 + 4) = 1;
    }
  }
  return cVar1;
}



char MediaLib_Dmx_Stop(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    cVar1 = Demuxer_Stop(*(undefined4 *)(param_1 + 0x78));
    if (cVar1 == '\x01') {
      *(undefined4 *)(param_1 + 4) = 3;
    }
  }
  return cVar1;
}



char MediaLib_Dmx_Pause(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    cVar1 = '\0';
  }
  else {
    cVar1 = Demuxer_Pause(*(undefined4 *)(param_1 + 0x78));
    if (cVar1 == '\x01') {
      *(undefined4 *)(param_1 + 4) = 2;
    }
  }
  return cVar1;
}



undefined4 MediaLib_Dmx_GetInfo(int param_1,undefined4 *param_2)

{
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    return 0;
  }
  ZeroMemory(param_2,0x54);
  *param_2 = *(undefined4 *)(param_1 + 0x7c);
  *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 0xe9);
  *(undefined1 *)((int)param_2 + 5) = *(undefined1 *)(param_1 + 0xe8);
  *(undefined1 *)((int)param_2 + 6) = *(undefined1 *)(param_1 + 0xa1);
  *(undefined1 *)((int)param_2 + 7) = *(undefined1 *)(param_1 + 0xa0);
  param_2[2] = *(undefined4 *)(param_1 + 0xe0);
  switch(*(undefined4 *)(param_1 + 0xa4)) {
  case 1:
    param_2[3] = 1;
    break;
  case 2:
    param_2[3] = 2;
    break;
  case 3:
    goto LAB_00019bb4;
  case 4:
    goto LAB_00019bb4;
  case 5:
LAB_00019bb4:
    param_2[3] = 0;
    break;
  case 6:
    param_2[3] = 3;
    break;
  case 7:
    param_2[3] = 4;
    break;
  case 8:
    param_2[3] = 5;
    break;
  case 9:
    param_2[3] = 6;
    break;
  case 10:
    param_2[3] = 7;
    break;
  case 0xb:
    param_2[3] = 2;
    break;
  case 0xc:
    param_2[3] = 8;
    break;
  case 0xd:
  default:
    param_2[3] = 0;
    break;
  case 0xe:
    param_2[3] = 9;
    break;
  case 0xf:
    param_2[3] = 10;
    break;
  case 0x10:
    param_2[3] = 0xb;
  }
  if (*(char *)(param_2 + 1) != '\0') {
    *(short *)(param_2 + 5) = (short)(*(uint *)(param_1 + 0x9c) / 10);
    *(short *)(param_2 + 4) = (short)*(undefined4 *)(param_1 + 0xd8);
    *(short *)((int)param_2 + 0x12) = (short)*(undefined4 *)(param_1 + 0xdc);
    param_2[6] = *(undefined4 *)(param_1 + 0x94);
  }
  if (*(char *)((int)param_2 + 5) != '\0') {
    param_2[7] = *(undefined4 *)(param_1 + 0xa8);
    param_2[8] = *(undefined4 *)(param_1 + 0x98);
    *(undefined2 *)(param_2 + 9) = *(undefined2 *)(param_1 + 0xac);
    *(undefined2 *)((int)param_2 + 0x26) = *(undefined2 *)(param_1 + 0xae);
    param_2[10] = *(undefined4 *)(param_1 + 0xb0);
    param_2[0xb] = *(undefined4 *)(param_1 + 0xb4);
    *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(param_1 + 0xb8);
    *(undefined2 *)((int)param_2 + 0x32) = *(undefined2 *)(param_1 + 0xba);
    *(undefined2 *)(param_2 + 0x13) = *(undefined2 *)(param_1 + 0xbc);
    memcpy(param_2 + 0xd,(void *)(param_1 + 0xc0),0x18);
  }
  param_2[0x14] = *(undefined4 *)(param_1 + 0xe4);
  return 1;
}



undefined4 MediaLib_Dmx_ReleaseInfoMem(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_ReleaseInfoMem(*(undefined4 *)(param_1 + 0x78));
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetAudioSeekInfo(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_GetAudioSeekInfo(*(undefined4 *)(param_1 + 0x78));
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetStatus(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = Demuxer_GetStatus(*(undefined4 *)(param_1 + 0x78));
    if (iVar1 == 1) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else if (iVar1 == 8) {
      *(undefined4 *)(param_1 + 4) = 4;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  return uVar2;
}



int MediaLib_Dmx_SetPosition(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = -1;
  }
  else if (param_2 < *(uint *)(param_1 + 0xe0)) {
    switch(*(undefined4 *)(param_1 + 4)) {
    case 0:
      Demuxer_Stop(*(undefined4 *)(param_1 + 0x78));
      break;
    case 1:
      Demuxer_Pause(*(undefined4 *)(param_1 + 0x78));
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
    default:
      (*g_medialib_printf)
                ("##MediaLib_Dmx: ERROR--setpos, status %d##\r\n",*(undefined4 *)(param_1 + 4));
      return -1;
    case 5:
    }
    iVar1 = Demuxer_SetPos(*(undefined4 *)(param_1 + 0x78),param_2,param_3);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      Demuxer_Pause(*(undefined4 *)(param_1 + 0x78));
      *(undefined4 *)(param_1 + 4) = 5;
    }
  }
  else {
    (*g_medialib_printf)
              ("##MediaLib_Dmx: ERROR--Set pos invalid! msTime(%d) > totalTime(%d)##\r\n",param_2,
               *(undefined4 *)(param_1 + 0xe0));
    iVar1 = -1;
  }
  return iVar1;
}



undefined4 MediaLib_Dmx_ResetAudioPos(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 4) == 3) {
    uVar1 = Demuxer_ResetAudioPos(*(undefined4 *)(param_1 + 0x78));
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetAudioData(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 1) {
    uVar1 = Demuxer_GetAudioData(*(undefined4 *)(param_1 + 0x78),param_2,param_3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetAudioDataSize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 1) {
    uVar1 = Demuxer_GetAudioDataSize(*(undefined4 *)(param_1 + 0x78));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetAudioPts(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 1) {
    uVar1 = Demuxer_GetAudioPackPts(*(undefined4 *)(param_1 + 0x78),param_2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetVideoFrameSize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 1) {
      uVar1 = Demuxer_GetVideoFrameSize(*(undefined4 *)(param_1 + 0x78));
    }
    else if ((iVar2 == 0) || (1 < iVar2 - 6U)) {
      uVar1 = 0;
    }
    else {
      uVar1 = Demuxer_GetKeyframeSize(*(undefined4 *)(param_1 + 0x78));
    }
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetVideoFrame(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if ((iVar2 == 1) || ((iVar2 != 0 && (iVar2 - 6U < 2)))) {
      uVar1 = Demuxer_GetVideoFrame(*(undefined4 *)(param_1 + 0x78),param_2,param_3);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_CheckAudioEnd(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_CheckAudioEnd(*(undefined4 *)(param_1 + 0x78));
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_CheckVideoEnd(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_CheckVideoEnd(*(undefined4 *)(param_1 + 0x78));
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetFirstVideoSize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_GetFirstVideoSize(*(undefined4 *)(param_1 + 0x78));
  }
  return uVar1;
}



undefined1 MediaLib_Dmx_GetFirstVideo(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = Demuxer_GetFirstVideo(*(undefined4 *)(param_1 + 0x78),param_2,param_3);
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_DisableVideo(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 3) {
    *(byte *)(param_1 + 0xea) = *(byte *)(param_1 + 0xea) & 0xfe;
    uVar1 = 1;
  }
  else {
    (*g_medialib_printf)
              ("##MediaLib_Dmx: ERROR--disable video, status %d##\r\n",*(undefined4 *)(param_1 + 4))
    ;
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_DisableAudio(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 3) {
    *(byte *)(param_1 + 0xea) = *(byte *)(param_1 + 0xea) & 0xfd;
    uVar1 = 1;
  }
  else {
    (*g_medialib_printf)
              ("##MediaLib_Dmx: ERROR--disable audio, status %d##\r\n",*(undefined4 *)(param_1 + 4))
    ;
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_GetNextBlockInfo(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else if (*(int *)(param_1 + 4) == 1) {
    uVar1 = Demuxer_GetNextBlockInfo(*(undefined4 *)(param_1 + 0x78),param_2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 MediaLib_Dmx_FF_FR(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((param_3 != 6) && (param_3 != 7)) {
    (*g_medialib_printf)("##MediaLib_Dmx: ERROR--FF/FR, input##\r\n");
    return 0;
  }
  if ((*(char *)(param_1 + 0xe9) == '\0') || (*(uint *)(param_1 + 0x84) < 2)) {
    (*g_medialib_printf)
              ("##MediaLib_Dmx: WARNING--FF/FR, there is no video or only one key frame##\r\n");
    return 0;
  }
  switch(*(undefined4 *)(param_1 + 4)) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    return 0;
  case 4:
    return 0;
  case 5:
    break;
  case 6:
    goto LAB_0001a790;
  case 7:
LAB_0001a790:
    if (*(int *)(param_1 + 4) == param_3) {
      return 1;
    }
    break;
  default:
    return 0;
  }
  MediaLib_Dmx_Pause(param_1);
  if (param_3 == 6) {
    Demuxer_FastForward(*(undefined4 *)(param_1 + 0x78),param_2);
  }
  else {
    Demuxer_FastRewind(*(undefined4 *)(param_1 + 0x78),param_2);
  }
  *(int *)(param_1 + 4) = param_3;
  (*g_medialib_printf)("##MediaLib_Dmx: Enter FF/FR status(%d), start %d##\r\n",param_3,param_2);
  return 1;
}



char * MediaLib_GetVersion(void)

{
  return "Media Lib V1.19.00_svn5741";
}



undefined4 MediaLib_Init(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*param_2 == 0) {
      g_medialib_printf = info_print;
    }
    else {
      g_medialib_printf = (code *)*param_2;
    }
    (*g_medialib_printf)("\r\n##Media Lib: support: \r\n");
    (*g_medialib_printf)("demux\r\n");
    (*g_medialib_printf)(" avi ");
    (*g_medialib_printf)(" mp4 ");
    (*g_medialib_printf)(" audio ");
    (*g_medialib_printf)("mux\r\n");
    (*g_medialib_printf)(" avi ");
    (*g_medialib_printf)(" 3gp ");
    (*g_medialib_printf)("\r\n##############################\r\n");
    uVar1 = 1;
  }
  return uVar1;
}



void MediaLib_Destroy(void)

{
  return;
}



undefined4 MediaLib_CheckFile(int *param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_medialib_printf == (code *)0x0) {
    if (*param_1 == 0) {
      g_medialib_printf = info_print;
    }
    else {
      g_medialib_printf = (code *)*param_1;
    }
  }
  if ((param_1 == (int *)0x0) || (param_3 == (undefined1 *)0x0)) {
    return 0;
  }
  if ((param_1[0xf] != 0) && (iVar1 = (*(code *)param_1[0xf])(param_2), iVar1 == 0)) {
    return 0;
  }
  uVar2 = MediaFile_CheckType(param_2,param_1);
  ZeroMemory(param_3,2);
  switch(uVar2) {
  case 1:
    goto LAB_0001ab94;
  case 2:
    goto LAB_0001ab94;
  case 3:
    break;
  case 4:
    goto LAB_0001abc0;
  case 5:
    goto LAB_0001abc0;
  case 6:
    break;
  case 7:
    goto LAB_0001abc0;
  case 8:
    break;
  case 9:
    goto LAB_0001ab94;
  case 10:
    break;
  case 0xb:
    goto LAB_0001ab94;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    goto LAB_0001ab94;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    goto LAB_0001ab94;
  case 0x14:
    break;
  case 0x15:
LAB_0001ab94:
    *param_3 = 1;
    param_3[1] = 1;
    goto switchD_0001ab30_default;
  case 0x16:
LAB_0001abc0:
    *param_3 = 1;
    param_3[1] = 1;
    goto switchD_0001ab30_default;
  case 0x17:
    break;
  default:
    goto switchD_0001ab30_default;
  }
  param_3[1] = 1;
switchD_0001ab30_default:
  if (*param_1 != 0) {
    (*(code *)*param_1)("\r\n##%s##\r\n","Media Lib V1.19.00_svn5741");
    (*(code *)*param_1)("##MediaLib: CheckFile return %d##\r\n\r\n",uVar2);
  }
  return uVar2;
}



undefined4 MediaLib_GetPicMetaInfo(void)

{
  return 0;
}



void MediaLib_ReleasePicMetaInfo(void)

{
  return;
}



undefined4 * MediaLib_GetID3MetaInfo(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  undefined4 *local_14;
  
  local_14 = (undefined4 *)0x0;
  if (g_medialib_printf == (code *)0x0) {
    if (*param_1 == 0) {
      g_medialib_printf = info_print;
    }
    else {
      g_medialib_printf = (code *)*param_1;
    }
  }
  if ((param_1 == (int *)0x0) || (param_4 == 0)) {
    local_14 = (undefined4 *)0x0;
  }
  else if ((param_1[0xf] == 0) || (iVar1 = (*(code *)param_1[0xf])(param_2), iVar1 != 0)) {
    local_18 = param_3;
    if (param_3 == 0) {
      local_18 = MediaFile_CheckTypeForID3(param_2,param_1);
    }
    ZeroMemory(param_4,0x40);
    if ((3 < local_18) && ((local_18 < 9 || (local_18 == 0x16)))) {
      local_14 = (undefined4 *)(*(code *)param_1[5])(200);
      if (local_14 == (undefined4 *)0x0) {
        if (*param_1 != 0) {
          (*(code *)*param_1)("##MediaLib: ERROR--GetID3, malloc##\r\n");
        }
        return (undefined4 *)0x0;
      }
      ZeroMemory(local_14,200);
      memcpy(local_14 + 10,param_1,100);
      if (*param_1 == 0) {
        local_14[10] = info_print;
      }
    }
    if ((local_18 < 4) || ((7 < local_18 && (local_18 != 0x16)))) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      uVar2 = MP4_GetMetaInfo(param_4,param_2,local_14 + 10);
      local_14[0x31] = uVar2;
      if (local_14[0x31] == 0) {
        (*(code *)param_1[6])(local_14);
        local_14 = (undefined4 *)0x0;
      }
      else {
        local_14[3] = local_18;
        *local_14 = 200;
      }
    }
  }
  else {
    local_14 = (undefined4 *)0x0;
  }
  return local_14;
}



void MediaLib_ReleaseID3MetaInfo(int param_1,int *param_2)

{
  uint uVar1;
  
  if ((param_2 != (int *)0x0) && (*param_2 == 200)) {
    uVar1 = param_2[3];
    if ((3 < uVar1) && ((uVar1 < 8 || (uVar1 == 0x16)))) {
      MP4_ReleaseMetaInfo(param_2[0x31]);
    }
    (**(code **)(param_1 + 0x18))(param_2);
  }
  return;
}



undefined4 S_MediaLib_Mux_TransStatus(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 2) {
    uVar1 = 2;
  }
  else if (param_1 == 5) {
    uVar1 = 4;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



void S_MediaLib_Mux_VideoCntUpdate(int param_1)

{
  int extraout_r1;
  
  __aeabi_uidivmod(*(undefined4 *)(param_1 + 0xd0),*(undefined2 *)(param_1 + 0x94));
  if (extraout_r1 == 0) {
    MulDiv(param_1 + 0x11c,*(undefined4 *)(param_1 + 0xd0),1000,*(undefined2 *)(param_1 + 0x94));
  }
  else {
    *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + *(int *)(param_1 + 0xfc);
  }
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
  return;
}



void S_MediaLib_Mux_AudioCntUpdate(int param_1)

{
  if (*(uint *)(param_1 + 0xcc) % 10 == 0) {
    *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x100);
  }
  else {
    MulDiv(param_1 + 0x120,*(undefined4 *)(param_1 + 0xcc),*(int *)(param_1 + 0xa4) * 1000,
           *(int *)(param_1 + 0xa8) * (uint)*(ushort *)(param_1 + 0xac));
  }
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
  return;
}



undefined4 * MediaLib_Mux_Open(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_98;
  int local_94 [2];
  int local_8c;
  int local_88;
  undefined2 local_84;
  undefined2 local_82;
  undefined2 local_80;
  undefined2 local_7e;
  int local_7c;
  int local_78;
  undefined2 local_74;
  undefined2 local_72;
  undefined2 local_70;
  int local_6c;
  undefined2 local_68;
  undefined2 local_66;
  char local_60;
  char local_5f;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 *local_24;
  char *local_20;
  int *local_1c;
  undefined1 *local_18;
  char local_11;
  
  local_1c = (int *)0x0;
  local_11 = 0;
  local_98 = 0;
  if (param_2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_1 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  local_20 = "Media Lib V1.19.00_svn5741";
  iVar1 = memcmp((void *)param_1[0x2e],"Media Lib V1.19.00_svn5741",0x10);
  if (iVar1 != 0) {
    (*(code *)param_1[2])("## ERROR: Wrong version input.\n","Media Lib V1.19.00_svn5741");
    return (undefined4 *)0x0;
  }
  *param_2 = 2;
  if ((param_1[0x11] != 0) && (iVar1 = (*(code *)param_1[0x11])(param_1[1]), iVar1 == 0)) {
    return (undefined4 *)0x0;
  }
  if (param_1[2] == 0) {
    g_medialib_printf = info_print;
  }
  else {
    g_medialib_printf = (code *)param_1[2];
  }
  if (((short)param_1[0x22] == 0) || (*(short *)((int)param_1 + 0x8a) == 0)) {
    return (undefined4 *)0x0;
  }
  if (((short)param_1[0x23] == 0) || (0x3c < *(ushort *)(param_1 + 0x23))) {
    return (undefined4 *)0x0;
  }
  if ((*param_1 != 0) && (*param_1 != 2)) {
    return (undefined4 *)0x0;
  }
  if ((char)param_1[0x1b] != '\0') {
    MulDiv(&local_98,1000,param_1[0x27],param_1[0x28] * (uint)*(ushort *)(param_1 + 0x29));
    if (local_98 < 10) {
      if (param_1[2] != 0) {
        (*(code *)param_1[2])("##MediaLib_Mux: ERROR--audio samples(%d)\r\n",param_1[0x27]);
      }
      return (undefined4 *)0x0;
    }
    if (0x10 < *(ushort *)((int)param_1 + 0xb2)) {
      if (param_1[2] != 0) {
        (*(code *)param_1[2])
                  ("##MediaLib_Mux: ERROR--cbSize(%d)\r\n",*(undefined2 *)((int)param_1 + 0xb2));
      }
      return (undefined4 *)0x0;
    }
    if (param_1[0x25] == 1) {
      if (local_98 != 0x14) {
        if (param_1[2] != 0) {
          (*(code *)param_1[2])
                    ("##MediaLib_Mux: ERROR--audio duration(%d [%d]), must be 20ms##\r\n",local_98,
                     param_1[0x27]);
        }
        return (undefined4 *)0x0;
      }
    }
    else if ((((param_1[0x25] == 7) && ((short)param_1[0x2c] != 0x100)) &&
             ((short)param_1[0x2c] != 0x200)) && ((short)param_1[0x2c] != 0x400)) {
      if (param_1[2] != 0) {
        (*(code *)param_1[2])("##MediaLib_Mux: ERROR--m_nBlockAlign(%d)\r\n",(short)param_1[0x2c]);
      }
      return (undefined4 *)0x0;
    }
  }
  if (param_1[2] != 0) {
    (*(code *)param_1[2])("\r\n--Mux %s--\r\n\r\n","Media Lib V1.19.00_svn5741");
  }
  local_24 = (undefined4 *)(*(code *)param_1[7])(0x128);
  if (local_24 == (undefined4 *)0x0) {
    if (param_1[2] != 0) {
      (*(code *)param_1[2])("##MediaLib_Mux: ERROR--malloc##\r\n");
    }
    *param_2 = 3;
    return (undefined4 *)0x0;
  }
  ZeroMemory(local_24,0x128);
  local_1c = local_24 + 2;
  memcpy(local_1c,param_1,0xbc);
  if (param_1[2] == 0) {
    local_1c[2] = (int)info_print;
  }
  (*(code *)local_24[4])("\r\n#####################################\r\n");
  (*(code *)local_24[4])("##Mux Info: file type is %d (0:AVI; 2:3GP;)\r\n",*param_1);
  (*(code *)local_24[4])
            ("##\tmovie--width: %d, height: %d\r\n",(short)param_1[0x22],
             *(undefined2 *)((int)param_1 + 0x8a));
  (*(code *)local_24[4])
            ("##\tkeyframe interval is %d, capture audio is %d, bIdxInMem %d(%d)\r\n",
             *(undefined2 *)((int)param_1 + 0x8e),(char)param_1[0x1b],
             *(undefined1 *)((int)param_1 + 0x6f),param_1[0x1c]);
  (*(code *)local_24[4])
            ("##\tfps: %d; samplerate: %d; SamplesPerPack: %d; channels: %d\r\n",
             (short)param_1[0x23],param_1[0x28],param_1[0x27],(short)param_1[0x29]);
  (*(code *)local_24[4])
            ("##\tvideo codec: %d, audio codec: %d(cbSize %d);\r\n",param_1[0x21],param_1[0x25],
             *(undefined2 *)((int)param_1 + 0xb2));
  (*(code *)local_24[4])("##\tm_ulTimeScale: %d\r\n",param_1[0x20]);
  (*(code *)local_24[4])("#####################################\r\n\r\n");
  if (*local_1c != 0) {
    if (*local_1c != 2) goto LAB_0001b7bc;
    switch(local_1c[0x21]) {
    case 1:
      goto LAB_0001b7bc;
    case 2:
      goto LAB_0001b7bc;
    case 3:
      break;
    case 4:
      break;
    case 5:
      goto LAB_0001b7bc;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      goto LAB_0001b7bc;
    }
    local_1c[0x21] = 0;
    goto LAB_0001b7bc;
  }
  switch(local_1c[0x21]) {
  case 1:
    break;
  case 2:
    break;
  case 3:
  default:
switchD_0001b714_default:
    local_1c[0x21] = 0;
    break;
  case 4:
    goto switchD_0001b714_default;
  case 5:
    break;
  case 6:
    goto switchD_0001b714_default;
  case 7:
    *(undefined2 *)((int)local_1c + 0x8e) = 0;
    break;
  case 8:
    goto switchD_0001b714_default;
  case 9:
  }
LAB_0001b7bc:
  if (local_1c[0x21] == 0) {
    (*(code *)local_24[4])("##MediaLib_Mux: ERROR--video(%d) is not supported##\r\n",param_1[0x21]);
    MediaLib_Mux_Close(local_24);
    return (undefined4 *)0x0;
  }
  ZeroMemory(local_94,0x70);
  if ((char)local_1c[0x1b] == '\0') goto LAB_0001b9b8;
  local_4c = local_1c[0x26];
  if (*local_1c != 0) {
    if (((*local_1c == 2) && (iVar1 = local_1c[0x25], iVar1 != 3)) && (iVar1 != 0xd)) {
      if (iVar1 == 1) {
        if (local_4c == 0x2fa8) {
          local_5f = '\x01';
        }
        else if (local_4c == 0x141e) {
          local_5f = '\0';
        }
        else {
          local_1c[0x25] = 0;
        }
      }
      else {
        local_1c[0x25] = 0;
      }
    }
    goto LAB_0001b974;
  }
  switch(local_1c[0x25]) {
  case 2:
    goto LAB_0001b974;
  case 3:
    goto LAB_0001b974;
  case 4:
    goto LAB_0001b890;
  case 5:
    break;
  case 6:
    break;
  case 7:
LAB_0001b890:
    if (local_1c[0x26] == 0) {
      local_1c[0x26] = local_1c[0x28] * (uint)*(ushort *)((int)local_1c + 0xa6);
      local_4c = local_1c[0x26];
    }
    goto LAB_0001b974;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    goto LAB_0001b974;
  }
  local_1c[0x25] = 0;
LAB_0001b974:
  if (local_1c[0x25] == 0) {
    (*(code *)local_24[4])("##MediaLib_Mux: ERROR--audio(%d) is not supported##\r\n",param_1[0x25]);
    MediaLib_Mux_Close(local_24);
    return (undefined4 *)0x0;
  }
LAB_0001b9b8:
  local_24[1] = 0;
  uVar2 = __divsi3(1000,(short)param_1[0x23]);
  local_24[0x3f] = uVar2;
  if (local_1c[0x20] == 0) {
    local_1c[0x20] = 1000;
  }
  local_11 = *(char *)((int)param_1 + 0x6f);
  if (((local_11 == '\0') && (local_1c[0x11] != 0)) &&
     (iVar1 = (*(code *)local_1c[0x11])(param_1[0x1d]), iVar1 == 0)) {
    local_11 = '\x01';
  }
  if (local_11 == '\x01') {
    local_1c[0x1d] = -1;
    local_58 = param_1[0x1c];
    if ((param_1[0x1c] == 0) || (param_1[0x1c] == -1)) {
      if (*local_1c == 2) {
        local_58 = 0x200000;
      }
      else {
        local_5d = 1;
      }
    }
  }
  *(char *)((int)local_1c + 0x6f) = local_11;
  if (local_1c[0x1e] == 0) goto LAB_0001be58;
  if ((char)local_1c[0x1b] == '\0') goto LAB_0001be24;
  *(undefined2 *)((int)local_24 + 0xee) = 8;
  if (local_1c[0x1f] != 0) {
    uVar2 = FIFO_Init(local_1c[0x1f],local_1c + 2);
    local_24[0x37] = uVar2;
  }
  if (local_24[0x37] == 0) {
    (*(code *)local_24[4])
              ("##MediaLib_Mux: ERROR--malloc audio fifo failed(%d)##\r\n",local_1c[0x1f]);
    MediaLib_Mux_Close(local_24);
    *param_2 = 3;
    return (undefined4 *)0x0;
  }
  local_24[0x40] = local_98;
  if (*(char *)((int)local_24 + 0x75) != '\x01') goto LAB_0001be24;
  local_18 = (undefined1 *)0x0;
  switch(local_1c[0x25]) {
  case 1:
    if (local_5f == '\0') {
      local_24[0x3d] = 0xe;
      local_18 = g_zero_amrframe_5150;
    }
    else {
      local_24[0x3d] = 0x20;
      local_18 = g_zero_amrframe_12200;
    }
    local_24[0x3d] = local_24[0x3d] * (local_98 / 0x14);
    break;
  case 2:
    goto LAB_0001bc34;
  case 3:
    if (*(short *)(local_24 + 0x2b) == 1) {
      local_24[0x3d] = 6;
      local_18 = &g_zero_aacframe_mono;
    }
    else if (*(short *)(local_24 + 0x2b) == 2) {
      local_24[0x3d] = 9;
      local_18 = g_zero_aacframe_stereo;
    }
    break;
  case 4:
    local_24[0x3d] = (uint)*(ushort *)((int)local_1c + 0xa6) * local_1c[0x27] >> 3;
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    local_24[0x3d] = (uint)*(ushort *)(local_1c + 0x2c);
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
LAB_0001bc34:
    local_24[0x3d] = (uint)*(ushort *)((int)local_1c + 0xa6) * local_1c[0x27] >> 3;
  }
  if (local_24[0x3d] != 0) {
    uVar2 = (*(code *)local_24[9])(local_24[0x3d] + (uint)*(ushort *)((int)local_24 + 0xee));
    local_24[0x3c] = uVar2;
  }
  if (local_24[0x3c] == 0) {
    (*(code *)local_24[4])
              ("##MediaLib_Mux: ERROR--malloc audio buf failed(%d)##\r\n",local_24[0x3d]);
    MediaLib_Mux_Close(local_24);
    *param_2 = 3;
    local_24 = (undefined4 *)0x0;
  }
  else {
    ZeroMemory(local_24[0x3c],local_24[0x3d] + (uint)*(ushort *)((int)local_24 + 0xee));
    if ((local_1c[0x25] == 3) || (local_1c[0x25] == 1)) {
      memcpy((void *)(local_24[0x3c] + (uint)*(ushort *)((int)local_24 + 0xee)),local_18,
             local_24[0x3d]);
    }
LAB_0001be24:
    *(undefined2 *)(local_24 + 0x3b) = 8;
    uVar2 = FIFO_Init(local_1c[0x1e],local_1c + 2);
    local_24[0x38] = uVar2;
LAB_0001be58:
    if (local_24[0x38] == 0) {
      (*(code *)local_24[4])
                ("##MediaLib_Mux: ERROR--malloc video fifo failed(%d)##\r\n",local_1c[0x1e]);
      MediaLib_Mux_Close(local_24);
      *param_2 = 3;
      local_24 = (undefined4 *)0x0;
    }
    else {
      local_94[0] = local_1c[1];
      local_88 = local_1c[0x1d];
      local_8c = *local_1c;
      local_68 = (undefined2)local_1c[0x23];
      local_60 = local_11;
      local_5e = (undefined1)local_1c[0x1b];
      local_5c = 1;
      local_84 = (undefined2)local_1c[0x22];
      local_82 = *(undefined2 *)((int)local_1c + 0x8a);
      local_66 = *(undefined2 *)((int)local_1c + 0x8e);
      local_54 = local_1c[0x21];
      if ((char)local_1c[0x1b] != '\0') {
        local_50 = local_1c[0x25];
        local_48 = __aeabi_uidiv(local_1c[0x27],(short)local_1c[0x29]);
        local_44 = (undefined2)local_1c[0x24];
        local_7e = (undefined2)local_1c[0x29];
        local_7c = local_1c[0x28];
        local_72 = *(undefined2 *)((int)local_1c + 0xa6);
        local_80 = (undefined2)local_1c[0x2a];
        local_78 = local_1c[0x2b];
        local_74 = (undefined2)local_1c[0x2c];
        local_70 = *(undefined2 *)((int)local_1c + 0xb2);
        local_6c = local_1c[0x2d];
      }
      local_28 = *(undefined2 *)(local_24 + 0x3b);
      local_26 = *(undefined2 *)((int)local_24 + 0xee);
      local_5b = *(undefined1 *)((int)local_1c + 0x6d);
      uVar2 = Muxer_Open(local_94,local_1c + 2);
      local_24[0x31] = uVar2;
      if (local_24[0x31] == 0) {
        (*g_medialib_printf)("##MediaLib_Mux: ERROR--open muxer failed##\r\n");
        MediaLib_Mux_Close(local_24);
        local_24 = (undefined4 *)0x0;
      }
      else {
        local_24[0x46] = 0xffffffff;
        local_24[0x45] = 0xffffffff;
        *local_24 = 0x128;
        *param_2 = 0;
      }
    }
  }
  return local_24;
}



undefined4 MediaLib_Mux_Close(void *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  code *pcVar3;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    pcVar2 = *(code **)((int)param_1 + 0x28);
    if (pcVar2 == (code *)0x0) {
      uVar1 = 0;
    }
    else {
      pcVar3 = *(code **)((int)param_1 + 0x10);
      MediaLib_Mux_Stop(param_1);
      Muxer_Close(*(undefined4 *)((int)param_1 + 0xc4));
      FIFO_Destroy(*(undefined4 *)((int)param_1 + 0xdc));
      FIFO_Destroy(*(undefined4 *)((int)param_1 + 0xe0));
      (*pcVar2)(*(undefined4 *)((int)param_1 + 0xf0));
      memset(param_1,0,0x128);
      (*pcVar2)(param_1);
      (*pcVar3)("\r\n--Leave Mux %s--\r\n\r\n","Media Lib V1.19.00_svn5741");
      uVar1 = 1;
    }
  }
  return uVar1;
}



undefined4 MediaLib_Mux_Start(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    iVar1 = Muxer_Start(*(undefined4 *)(param_1 + 0xc4));
    if (iVar1 == 0) {
      (**(code **)(param_1 + 0x10))("##MediaLib_Mux: ERROR--Start, Muxer_start##\r\n");
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 2;
      uVar2 = 1;
    }
  }
  else {
    (**(code **)(param_1 + 0x10))
              ("##MediaLib_Mux: ERROR--Start, status %d##\r\n",*(undefined4 *)(param_1 + 4));
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MediaLib_Mux_Restart(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_80 [3];
  undefined4 local_74;
  undefined2 local_52;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    local_c = param_1;
    if (*(int *)(param_1 + 4) == 1) {
      ZeroMemory(local_80,0x70);
      local_52 = *(undefined2 *)(local_c + 0x96);
      local_74 = *(undefined4 *)(local_c + 0x7c);
      local_80[0] = param_2;
      iVar1 = Muxer_Restart(*(undefined4 *)(local_c + 0xc4),local_80);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        FIFO_Reset(*(undefined4 *)(local_c + 0xe0));
        FIFO_Reset(*(undefined4 *)(local_c + 0xdc));
        *(undefined1 *)(local_c + 0xf9) = 0;
        *(undefined1 *)(local_c + 0xfa) = 0;
        *(undefined1 *)(local_c + 0xfb) = 0;
        *(undefined4 *)(local_c + 0x104) = 0;
        *(undefined4 *)(local_c + 0x108) = 0;
        *(undefined4 *)(local_c + 0x124) = 0;
        *(undefined4 *)(local_c + 0x10c) = 0;
        *(undefined4 *)(local_c + 0x110) = 0;
        *(undefined4 *)(local_c + 0x114) = 0xffffffff;
        *(undefined4 *)(local_c + 0x118) = 0xffffffff;
        *(undefined4 *)(local_c + 200) = 0;
        *(undefined4 *)(local_c + 0xcc) = 0;
        *(undefined4 *)(local_c + 0xd0) = 0;
        *(undefined4 *)(local_c + 0xd4) = 0;
        *(undefined4 *)(local_c + 0xd8) = 0;
        *(undefined4 *)(local_c + 0xc) = param_2;
        *(undefined4 *)(local_c + 4) = 2;
        uVar2 = 1;
      }
    }
    else {
      (**(code **)(param_1 + 0x10))
                ("##MediaLib_Mux: ERROR--Restart, status %d##\r\n",*(undefined4 *)(param_1 + 4));
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined4 MediaLib_Mux_Stop(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_1c;
  
  local_1c = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else if (*(int *)(param_1 + 4) == 1) {
    uVar4 = 1;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    uVar4 = 0;
  }
  else {
    local_20 = param_1;
    if (*(int *)(param_1 + 0xdc) == 0) {
      pcVar5 = *(code **)(param_1 + 0x10);
      uVar4 = FIFO_ItemNum(*(undefined4 *)(param_1 + 0xe0));
      (*pcVar5)("##MediaLib_Mux: Stop, video remain %d##\r\n",uVar4);
    }
    else {
      pcVar5 = *(code **)(param_1 + 0x10);
      uVar4 = FIFO_ItemNum(*(undefined4 *)(param_1 + 0xe0));
      uVar2 = FIFO_ItemNum(*(undefined4 *)(local_20 + 0xdc));
      (*pcVar5)("##MediaLib_Mux: Stop, video remain %d, audio remain %d##\r\n",uVar4,uVar2);
    }
    iVar3 = Muxer_Stop(*(undefined4 *)(local_20 + 0xc4));
    if (iVar3 == 1) {
      if (*(int *)(local_20 + 0x50) == 0) {
        (**(code **)(local_20 + 0x1c))(*(undefined4 *)(local_20 + 0xc),0,2);
        local_1c = (**(code **)(local_20 + 0x20))(*(undefined4 *)(local_20 + 0xc));
      }
      else {
        local_1c = (**(code **)(local_20 + 0x50))(*(undefined4 *)(local_20 + 0xc));
      }
      if ((*(int *)(local_20 + 0xd0) != 0) &&
         (MulDiv(&local_24,*(int *)(local_20 + 0xd0) - *(int *)(local_20 + 0xd4),
                 *(undefined2 *)(local_20 + 0x94),*(undefined4 *)(local_20 + 0xd0)), local_24 == 0))
      {
        local_24 = 1;
      }
      MulDiv(&local_28,*(undefined4 *)(local_20 + 0xd0),1000,*(undefined2 *)(local_20 + 0x94));
      if (*(char *)(local_20 + 0x74) != '\0') {
        MulDiv(&local_2c,*(undefined4 *)(local_20 + 0xcc),*(int *)(local_20 + 0xa4) * 1000,
               *(int *)(local_20 + 0xa8) * (uint)*(ushort *)(local_20 + 0xac));
      }
      (**(code **)(local_20 + 0x10))
                ("\r\n##MediaLib_Mux: %d packets, filelen %dKB##\r\n",
                 *(undefined4 *)(local_20 + 200),local_1c >> 10);
      (**(code **)(local_20 + 0x10))
                ("##MediaLib_Mux: %d video frames, insert %d, real fr %d##\r\n",
                 *(undefined4 *)(local_20 + 0xd0),*(undefined4 *)(local_20 + 0xd4),local_24);
      (**(code **)(local_20 + 0x10))
                ("##MediaLib_Mux: %d audio packets, insert %d##\r\n",
                 *(undefined4 *)(local_20 + 0xcc),*(undefined4 *)(local_20 + 0xd8));
      uVar4 = local_2c;
      pcVar5 = *(code **)(local_20 + 0x10);
      uVar1 = local_28 / 1000;
      uVar6 = local_28 % 1000;
      if (local_28 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = __aeabi_uidiv(local_1c,local_28);
        iVar3 = iVar3 << 3;
      }
      (*pcVar5)("##MediaLib_Mux: time %d.%03ds(%d), about %dkbps##\r\n\r\n",uVar1,uVar6,uVar4,iVar3)
      ;
      *(undefined4 *)(local_20 + 4) = 1;
      uVar4 = 1;
    }
    else {
      *(undefined4 *)(local_20 + 4) = 3;
      (**(code **)(local_20 + 0x10))("##MediaLib_Mux: ERROR--Muxer Stop##\r\n");
      uVar4 = 0;
    }
  }
  return uVar4;
}



undefined4 MediaLib_Mux_GetInfo(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 4);
    param_2[1] = *(undefined4 *)(param_1 + 200);
    param_2[2] = *(undefined4 *)(param_1 + 0xd0);
    param_2[3] = *(undefined4 *)(param_1 + 0xcc);
    MulDiv(param_2 + 6,*(undefined4 *)(param_1 + 0xd0),1000,*(undefined2 *)(param_1 + 0x94));
    uVar1 = Muxer_GetHeaderSize(*(undefined4 *)(param_1 + 0xc4));
    param_2[4] = uVar1;
    uVar1 = Muxer_GetCurrFileSize(*(undefined4 *)(param_1 + 0xc4));
    param_2[5] = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 MediaLib_Mux_GetStatus(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}



undefined4 MediaLib_Mux_InsertVideo(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 *local_30;
  undefined4 local_2c;
  undefined1 local_24;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  int local_18;
  uint local_14;
  
  local_20 = 0;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  local_1c = 0;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_2c = 0;
  local_30 = &local_20;
  local_24 = 0;
  local_14 = 0;
  while( true ) {
    if (param_2 <= local_14) {
      return *(undefined4 *)(param_1 + 0x11c);
    }
    ulong2str(local_30,*(undefined4 *)(param_1 + 0xd0));
    local_18 = Muxer_ProcessVideo(*(undefined4 *)(param_1 + 0xc4),&local_30);
    if (local_18 != 2) break;
    S_MediaLib_Mux_VideoCntUpdate(param_1);
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
    local_14 = local_14 + 1;
  }
  (*g_medialib_printf)("##MediaLib_Mux: ERROR--insert video##\r\n");
  uVar1 = S_MediaLib_Mux_TransStatus(local_18);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return 0xffffffff;
}



undefined4 MediaLib_Mux_InsertAudio(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  int local_18;
  uint local_14;
  
  if (*(int *)(param_1 + 0xf0) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    local_24 = *(undefined4 *)(param_1 + 0xf4);
    local_28 = *(undefined4 *)(param_1 + 0xf0);
    for (local_14 = 0; local_14 < param_2; local_14 = local_14 + 1) {
      local_18 = Muxer_ProcessAudio(*(undefined4 *)(param_1 + 0xc4),&local_28);
      if (local_18 != 2) {
        (*g_medialib_printf)("##MediaLib_Mux: ERROR--insert audio##\r\n");
        uVar1 = S_MediaLib_Mux_TransStatus(local_18);
        *(undefined4 *)(param_1 + 4) = uVar1;
        return 0xffffffff;
      }
      S_MediaLib_Mux_AudioCntUpdate(param_1);
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x120);
  }
  return uVar1;
}



void S_MediaLib_Mux_VideoAdjust(int param_1)

{
  int local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  MulDiv(&local_10,*(int *)(param_1 + 0xd0) - *(int *)(param_1 + 0x124),1000,
         *(undefined2 *)(param_1 + 0x94));
  local_c = *(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104);
  if (local_10 + 0x96U < local_c) {
    MediaLib_Mux_InsertVideo(param_1,1);
  }
  return;
}



undefined4 MediaLib_Mux_ReSYN(int param_1)

{
  undefined4 uVar1;
  uint local_1c;
  uint local_18 [2];
  int local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  local_18[0] = 0;
  local_1c = 0;
  *(undefined1 *)(param_1 + 0xf9) = 0;
  *(undefined1 *)(param_1 + 0xfa) = 0;
  *(undefined1 *)(param_1 + 0xfb) = 0;
  FIFO_Reset(*(undefined4 *)(param_1 + 0xe0));
  if (*(char *)(param_1 + 0x74) == '\0') {
    uVar1 = 6;
  }
  else {
    FIFO_Reset(*(undefined4 *)(param_1 + 0xdc));
    MulDiv(&local_1c,*(undefined4 *)(param_1 + 0xd0),1000,*(undefined2 *)(param_1 + 0x94));
    MulDiv(local_18,*(undefined4 *)(param_1 + 0xcc),*(int *)(param_1 + 0xa4) * 1000,
           *(int *)(param_1 + 0xa8) * (uint)*(ushort *)(param_1 + 0xac));
    local_c = local_18[0] - local_1c;
    if ((int)local_c < 0) {
      local_c = -local_c;
    }
    if ((int)local_c < 0xea61) {
      if (*(uint *)(param_1 + 0x100) < local_c) {
        if (local_18[0] < local_1c) {
          local_10 = __aeabi_uidiv(local_c,*(undefined4 *)(param_1 + 0x100));
          if (local_10 != 0) {
            MediaLib_Mux_InsertAudio(param_1,local_10);
          }
        }
        else {
          local_10 = __aeabi_uidiv(local_c,*(undefined4 *)(param_1 + 0xfc));
          if (local_10 != 0) {
            MediaLib_Mux_InsertVideo(param_1,local_10);
          }
        }
      }
      *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0xd0);
      uVar1 = 6;
    }
    else {
      (**(code **)(param_1 + 0x10))
                ("## diff_pts=%d, a_absolut_time=%d, v_absolut_time=%d\n",local_c,local_18[0],
                 local_1c);
      (**(code **)(param_1 + 0x10))
                ("##MediaLib_Mux: ERROR--resyn v %d, a %d, diff %d ms##\r\n",
                 *(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xcc),local_c);
      (**(code **)(param_1 + 0x10))
                ("## V_nFPS=%d, A_SamplesPerPack=%d, A_channel=%d, A_sr=%d\n",
                 *(undefined2 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0xa4),
                 *(undefined2 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0xa8));
      *(undefined4 *)(param_1 + 4) = 5;
      uVar1 = 5;
    }
  }
  return uVar1;
}



undefined4 MediaLib_Mux_AddAudioData(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_14 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar3 = 0;
  }
  else {
    local_18 = param_1;
    if ((*param_2 == 0) || (param_2[1] == 0)) {
      (**(code **)(param_1 + 0x10))
                ("##MediaLib_Mux: ERROR--AddAudio, addr(0x%x) and size(%d)##\r\n",*param_2,
                 param_2[1]);
      uVar3 = 0;
    }
    else if (*(int *)(param_1 + 0xdc) == 0) {
      uVar3 = 0;
    }
    else {
      MulDiv(&local_20,param_2[2],1000,*(undefined4 *)(param_1 + 0x88));
      if (*(char *)(local_18 + 0x75) == '\x01') {
        if ((local_20 <= *(uint *)(local_18 + 0x118)) &&
           (*(int *)(local_18 + 0x118) - local_20 < 1000)) {
          (**(code **)(local_18 + 0x10))
                    ("##MediaLib_Mux: ERROR--AddAudio, pts 0x%x 0x%x##\r\n",
                     *(undefined4 *)(local_18 + 0x118),local_20);
          return 0;
        }
        if ((*(char *)(local_18 + 0x76) == '\0') &&
           (((*(char *)(local_18 + 0xf9) == '\0' || (local_20 + 0x96 < *(uint *)(local_18 + 0x104)))
            || ((*(char *)(local_18 + 0xfb) == '\0' &&
                (*(int *)(local_18 + 0x114) + 10000U < local_20)))))) {
          return 0;
        }
      }
      local_1c = param_2[1] + (uint)*(ushort *)(local_18 + 0xee);
      uVar1 = FIFO_FreeSpace(*(undefined4 *)(local_18 + 0xdc));
      if (uVar1 < local_1c) {
        pcVar4 = *(code **)(local_18 + 0x10);
        uVar5 = *(undefined4 *)(*(int *)(local_18 + 0xdc) + 4);
        uVar3 = FIFO_FreeSpace(*(undefined4 *)(local_18 + 0xdc));
        (*pcVar4)("##MediaLib_Mux: ERROR--audio fifo overflow, data size(%d), fifo size(%d), fifo free(%d)\n"
                  ,local_1c,uVar5,uVar3);
        uVar3 = 0;
      }
      else {
        local_14 = FIFO_Get_Inaddr(*(undefined4 *)(local_18 + 0xdc),local_1c);
        if (local_14 == 0) {
          (**(code **)(local_18 + 0x10))("##MediaLib_Mux: ERROR--AddAudio, FIFO_Get_Inaddr##\r\n");
          uVar3 = 0;
        }
        else {
          ulong2str(local_14 + 4,local_20);
          memcpy((void *)(local_14 + (uint)*(ushort *)(local_18 + 0xee)),(void *)*param_2,param_2[1]
                );
          iVar2 = FIFO_Add(*(undefined4 *)(local_18 + 0xdc),local_14,local_1c);
          if (iVar2 == 0) {
            (**(code **)(local_18 + 0x10))("##MediaLib_Mux: ERROR--AddAudio, ADD FIFO##\r\n");
            uVar3 = 0;
          }
          else {
            if (*(char *)(local_18 + 0xfa) == '\0') {
              (**(code **)(local_18 + 0x10))("#FA#\r\n");
              *(undefined1 *)(local_18 + 0xfa) = 1;
              *(uint *)(local_18 + 0x108) = local_20;
            }
            *(uint *)(local_18 + 0x118) = local_20;
            uVar3 = 1;
          }
        }
      }
    }
  }
  return uVar3;
}



undefined4 MediaLib_Mux_AddVideoData(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_18 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar3 = 0;
  }
  else {
    local_14 = param_1;
    if ((*param_2 == 0) || (param_2[1] == 0)) {
      (**(code **)(param_1 + 0x10))
                ("##MediaLib_Mux: ERROR--AddVideo, addr(0x%x) and size(%d)##\r\n",*param_2,
                 param_2[1]);
      uVar3 = 0;
    }
    else if (*(int *)(param_1 + 0xe0) == 0) {
      uVar3 = 0;
    }
    else {
      MulDiv(&local_20,param_2[2],1000,*(undefined4 *)(param_1 + 0x88));
      if (*(char *)(local_14 + 0x75) == '\x01') {
        if (*(char *)(local_14 + 0xf9) == '\0') {
          if ((char)param_2[3] == '\0') {
            return 0;
          }
        }
        else if ((local_20 <= *(uint *)(local_14 + 0x114)) &&
                (*(int *)(local_14 + 0x114) - local_20 < 1000)) {
          (**(code **)(local_14 + 0x10))
                    ("##MediaLib_Mux: ERROR--AddVideo, pts 0x%x 0x%x##\r\n",
                     *(undefined4 *)(local_14 + 0x114),local_20);
          return 0;
        }
      }
      local_1c = param_2[1] + (uint)*(ushort *)(local_14 + 0xec);
      uVar1 = FIFO_FreeSpace(*(undefined4 *)(local_14 + 0xe0));
      if (uVar1 < local_1c) {
        pcVar4 = *(code **)(local_14 + 0x10);
        uVar5 = *(undefined4 *)(*(int *)(local_14 + 0xe0) + 4);
        uVar3 = FIFO_FreeSpace(*(undefined4 *)(local_14 + 0xe0));
        (*pcVar4)("##MediaLib_Mux: ERROR--video fifo overflow, data size(%d), fifo size(%d), fifo free(%d)\n"
                  ,local_1c,uVar5,uVar3);
        uVar3 = 0;
      }
      else {
        local_18 = FIFO_Get_Inaddr(*(undefined4 *)(local_14 + 0xe0),local_1c);
        if (local_18 == 0) {
          (**(code **)(local_14 + 0x10))("##MediaLib_Mux: ERROR--AddVideo, FIFO_Get_Inaddr##\r\n");
          uVar3 = 0;
        }
        else {
          ulong2str(local_18,(char)param_2[3]);
          ulong2str(local_18 + 4,local_20);
          memcpy((void *)(local_18 + (uint)*(ushort *)(local_14 + 0xec)),(void *)*param_2,param_2[1]
                );
          iVar2 = FIFO_Add(*(undefined4 *)(local_14 + 0xe0),local_18,local_1c);
          if (iVar2 == 0) {
            (**(code **)(local_14 + 0x10))("##MediaLib_Mux: ERROR--AddVideo, ADD FIFO##\r\n");
            uVar3 = 0;
          }
          else {
            if (*(char *)(local_14 + 0xf9) == '\0') {
              (**(code **)(local_14 + 0x10))("#IDR#\r\n");
              *(undefined1 *)(local_14 + 0xf9) = 1;
              *(uint *)(local_14 + 0x104) = local_20;
            }
            *(uint *)(local_14 + 0x114) = local_20;
            uVar3 = 1;
          }
        }
      }
    }
  }
  return uVar3;
}



undefined4 MediaLib_Mux_NormalAudio(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_24;
  int local_20;
  undefined1 local_18;
  int local_14;
  
  if ((uint)param_2[1] < (uint)*(ushort *)(param_1 + 0xee)) {
    uVar1 = 0xffffffff;
  }
  else {
    local_24 = *param_2;
    local_20 = param_2[1] - (uint)*(ushort *)(param_1 + 0xee);
    local_18 = 0;
    local_14 = Muxer_ProcessAudio(*(undefined4 *)(param_1 + 0xc4),&local_24);
    if (local_14 == 2) {
      *(undefined4 *)(param_1 + 0x110) = param_2[2];
      S_MediaLib_Mux_AudioCntUpdate(param_1);
      uVar1 = *(undefined4 *)(param_1 + 0x120);
    }
    else {
      (*g_medialib_printf)("##MediaLib_Mux: ERROR--normal audio##\r\n");
      uVar1 = S_MediaLib_Mux_TransStatus(local_14);
      *(undefined4 *)(param_1 + 4) = uVar1;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}



undefined4 MediaLib_Mux_NormalVideo(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined1 local_18;
  int local_14;
  
  if ((uint)param_2[1] < (uint)*(ushort *)(param_1 + 0xec)) {
    uVar1 = 0xffffffff;
  }
  else {
    local_24 = *param_2;
    local_20 = param_2[1] - (uint)*(ushort *)(param_1 + 0xec);
    local_18 = *(undefined1 *)(param_2 + 3);
    local_1c = param_2[2];
    ulong2str(local_24,*(undefined4 *)(param_1 + 0xd0));
    local_14 = Muxer_ProcessVideo(*(undefined4 *)(param_1 + 0xc4),&local_24);
    if (local_14 == 2) {
      *(undefined4 *)(param_1 + 0x10c) = param_2[2];
      S_MediaLib_Mux_VideoCntUpdate(param_1);
      if (*(char *)(param_1 + 0x75) == '\x01') {
        S_MediaLib_Mux_VideoAdjust(param_1);
      }
      uVar1 = *(undefined4 *)(param_1 + 0x11c);
    }
    else {
      (*g_medialib_printf)("##MediaLib_Mux: ERROR--normal video, %d##\r\n",local_14);
      uVar1 = S_MediaLib_Mux_TransStatus(local_14);
      *(undefined4 *)(param_1 + 4) = uVar1;
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}



undefined4 MediaLib_Mux_Handle(int param_1)

{
  undefined4 uVar1;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_1c = 0;
  local_20 = 0;
  local_c = 0;
  local_10 = 0;
  local_24 = 0;
  local_28 = 0;
  local_14 = 0;
  local_2c = 0;
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    local_18 = param_1;
    if (*(int *)(param_1 + 0xe0) != 0) {
      local_c = FIFO_ItemNum(*(undefined4 *)(param_1 + 0xe0));
    }
    if (*(int *)(local_18 + 0xdc) != 0) {
      local_10 = FIFO_ItemNum(*(undefined4 *)(local_18 + 0xdc));
    }
    if ((local_c == 0) && (local_10 == 0)) {
      uVar1 = 6;
    }
    else if ((*(char *)(local_18 + 0x75) == '\x01') &&
            ((*(char *)(local_18 + 0xf9) == '\0' && (*(char *)(local_18 + 0xfa) == '\0')))) {
      uVar1 = 6;
    }
    else {
      if (*(int *)(local_18 + 4) == 2) {
        do {
          if ((local_c == 0) && (local_10 == 0)) break;
          if ((*(char *)(local_18 + 0x75) == '\x01') &&
             (((*(char *)(local_18 + 0xfb) == '\0' && (*(char *)(local_18 + 0xf9) != '\0')) &&
              (*(char *)(local_18 + 0xfa) != '\0')))) {
            local_14 = *(int *)(local_18 + 0x108) - *(int *)(local_18 + 0x104);
            if (local_14 < 0) {
              local_14 = -local_14;
            }
            if (60000 < local_14) {
              (**(code **)(local_18 + 0x10))
                        ("## diff_pts=%d, firstAudioTimeStamp=%d, firstTimeStamp=%d\n",local_14,
                         *(undefined4 *)(local_18 + 0x108),*(undefined4 *)(local_18 + 0x104));
              uVar1 = MediaLib_Mux_ReSYN(local_18);
              return uVar1;
            }
            if (local_14 < 0x33) {
              local_2c = 0;
            }
            else if (*(uint *)(local_18 + 0x104) < *(uint *)(local_18 + 0x108)) {
              local_2c = __aeabi_uidiv(local_14,*(undefined4 *)(local_18 + 0x100));
              if (local_2c != 0) {
                local_30 = MediaLib_Mux_InsertAudio(local_18,local_2c);
                local_2c = 0;
              }
            }
            else {
              local_2c = __aeabi_uidiv(local_14,*(undefined4 *)(local_18 + 0xfc));
              if (local_2c != 0) {
                local_34 = MediaLib_Mux_InsertVideo(local_18,local_2c);
                local_2c = 0;
                *(undefined4 *)(local_18 + 0x124) = *(undefined4 *)(local_18 + 0xd0);
              }
            }
            *(undefined1 *)(local_18 + 0xfb) = 1;
          }
          if (local_c != 0) {
            uVar1 = FIFO_Get_Outaddr(*(undefined4 *)(local_18 + 0xe0));
            *(undefined4 *)(local_18 + 0xe4) = uVar1;
            local_20 = FIFO_Get_Length(*(undefined4 *)(local_18 + 0xe0));
            local_3c = str2ulong(*(int *)(local_18 + 0xe4) + 4);
            local_44 = *(undefined4 *)(local_18 + 0xe4);
            local_40 = local_20;
            local_38 = **(undefined1 **)(local_18 + 0xe4);
            local_28 = local_3c;
            if ((*(char *)(local_18 + 0x75) == '\x01') && (*(uint *)(local_18 + 0x104) != local_3c))
            {
              local_14 = (local_3c - *(int *)(local_18 + 0x10c)) - *(int *)(local_18 + 0xfc);
              if ((local_3c < *(uint *)(local_18 + 0x10c)) || (10000 < local_14)) {
                (**(code **)(local_18 + 0x10))
                          ("## diff_pts=%d, v_time_stamp=%d, video_pre_pts=%d, v_frame_interval=%d\n"
                           ,local_14,local_3c,*(undefined4 *)(local_18 + 0x10c),
                           *(undefined4 *)(local_18 + 0xfc));
                uVar1 = MediaLib_Mux_ReSYN(local_18);
                return uVar1;
              }
              if ((0 < local_14) &&
                 (local_2c = __aeabi_uidiv(local_14,*(undefined4 *)(local_18 + 0xfc)), local_2c != 0
                 )) {
                local_34 = MediaLib_Mux_InsertVideo(local_18,local_2c);
              }
            }
            local_34 = MediaLib_Mux_NormalVideo(local_18,&local_44);
            if (local_34 < 0) break;
            FIFO_Drop(*(undefined4 *)(local_18 + 0xe0));
            local_c = FIFO_ItemNum(*(undefined4 *)(local_18 + 0xe0));
          }
          if (local_10 != 0) {
            uVar1 = FIFO_Get_Outaddr(*(undefined4 *)(local_18 + 0xdc));
            *(undefined4 *)(local_18 + 0xe8) = uVar1;
            local_1c = FIFO_Get_Length(*(undefined4 *)(local_18 + 0xdc));
            local_3c = str2ulong(*(int *)(local_18 + 0xe8) + 4);
            local_44 = *(undefined4 *)(local_18 + 0xe8);
            local_40 = local_1c;
            local_38 = 1;
            local_24 = local_3c;
            if ((*(char *)(local_18 + 0x75) == '\x01') && (*(uint *)(local_18 + 0x108) != local_3c))
            {
              local_14 = (local_3c - *(int *)(local_18 + 0x110)) - *(int *)(local_18 + 0x100);
              if ((local_3c < *(uint *)(local_18 + 0x110)) || (1000 < local_14)) {
                (**(code **)(local_18 + 0x10))
                          ("## diff_pts=%d, a_time_stamp=%d, audio_pre_pts=%d, a_packet_interval=%d\n"
                           ,local_14,local_3c,*(undefined4 *)(local_18 + 0x110),
                           *(undefined4 *)(local_18 + 0x100));
                uVar1 = MediaLib_Mux_ReSYN(local_18);
                return uVar1;
              }
              if ((0 < local_14) &&
                 (local_2c = __aeabi_uidiv(local_14,*(undefined4 *)(local_18 + 0x100)),
                 local_2c != 0)) {
                local_30 = MediaLib_Mux_InsertAudio(local_18,local_2c);
              }
            }
            local_30 = MediaLib_Mux_NormalAudio(local_18,&local_44);
            if (local_30 < 0) break;
            FIFO_Drop(*(undefined4 *)(local_18 + 0xdc));
            local_10 = FIFO_ItemNum(*(undefined4 *)(local_18 + 0xdc));
          }
        } while (*(int *)(local_18 + 4) == 2);
      }
      else {
        (**(code **)(local_18 + 0x10))
                  ("##MediaLib_Mux: in Handle, status: %d##\r\n",*(undefined4 *)(local_18 + 4));
      }
      uVar1 = *(undefined4 *)(local_18 + 4);
    }
  }
  return uVar1;
}



int AAC_ProgramConfigElement(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  byte local_11;
  
  ZeroMemory(param_2,0xa5);
  param_2[0x80] = 0;
  uVar1 = Bitstream_ReadBits(param_1,4,"element_instance_tag");
  *param_2 = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,2,"object_type");
  param_2[1] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,4,"sf_index");
  param_2[2] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,4,"num_front_channel_elements");
  param_2[3] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
  param_2[4] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
  param_2[5] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,2,&DAT_00057564);
  param_2[6] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,3,&DAT_00057564);
  param_2[7] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
  param_2[8] = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
  param_2[9] = uVar1;
  if (param_2[9] == '\x01') {
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[10] = uVar1;
  }
  uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
  param_2[0xb] = uVar1;
  if (param_2[0xb] == '\x01') {
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[0xc] = uVar1;
  }
  uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
  param_2[0xd] = uVar1;
  if (param_2[0xd] == '\x01') {
    uVar1 = Bitstream_ReadBits(param_1,2,&DAT_00057564);
    param_2[0xf] = uVar1;
    uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
    param_2[0xe] = uVar1;
  }
  for (local_11 = 0; local_11 < (byte)param_2[3]; local_11 = local_11 + 1) {
    uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
    param_2[local_11 + 0x10] = uVar1;
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[local_11 + 0x20] = uVar1;
    if ((param_2[local_11 + 0x10] & 1) == 0) {
      param_2[(byte)param_2[local_11 + 0x20] + 0x85] = param_2[0x80];
      param_2[0x81] = param_2[0x81] + '\x01';
      param_2[0x80] = param_2[0x80] + '\x01';
    }
    else {
      param_2[(byte)param_2[local_11 + 0x20] + 0x95] = param_2[0x80];
      param_2[0x81] = param_2[0x81] + '\x02';
      param_2[0x80] = param_2[0x80] + '\x02';
    }
  }
  for (local_11 = 0; local_11 < (byte)param_2[4]; local_11 = local_11 + 1) {
    uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
    param_2[local_11 + 0x30] = uVar1;
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[local_11 + 0x40] = uVar1;
    if ((param_2[local_11 + 0x30] & 1) == 0) {
      param_2[(byte)param_2[local_11 + 0x40] + 0x85] = param_2[0x80];
      param_2[0x82] = param_2[0x82] + '\x01';
      param_2[0x80] = param_2[0x80] + '\x01';
    }
    else {
      param_2[(byte)param_2[local_11 + 0x40] + 0x95] = param_2[0x80];
      param_2[0x82] = param_2[0x82] + '\x02';
      param_2[0x80] = param_2[0x80] + '\x02';
    }
  }
  for (local_11 = 0; local_11 < (byte)param_2[5]; local_11 = local_11 + 1) {
    uVar1 = Bitstream_ReadBits(param_1,1,&DAT_00057564);
    param_2[local_11 + 0x50] = uVar1;
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[local_11 + 0x60] = uVar1;
    if ((param_2[local_11 + 0x50] & 1) == 0) {
      param_2[(byte)param_2[local_11 + 0x60] + 0x85] = param_2[0x80];
      param_2[0x83] = param_2[0x83] + '\x01';
      param_2[0x80] = param_2[0x80] + '\x01';
    }
    else {
      param_2[(byte)param_2[local_11 + 0x60] + 0x95] = param_2[0x80];
      param_2[0x80] = param_2[0x80] + '\x02';
      param_2[0x83] = param_2[0x83] + '\x02';
    }
  }
  for (local_11 = 0; local_11 < (byte)param_2[6]; local_11 = local_11 + 1) {
    uVar1 = Bitstream_ReadBits(param_1,4,&DAT_00057564);
    param_2[local_11 + 0x70] = uVar1;
    param_2[(byte)param_2[local_11 + 0x70] + 0x85] = param_2[0x80];
    param_2[0x84] = param_2[0x84] + '\x01';
    param_2[0x80] = param_2[0x80] + '\x01';
  }
  for (local_11 = 0; local_11 < (byte)param_2[7]; local_11 = local_11 + 1) {
    Bitstream_ReadBits(param_1,4,&DAT_00057564);
  }
  for (local_11 = 0; local_11 < (byte)param_2[8]; local_11 = local_11 + 1) {
    Bitstream_ReadBits(param_1,5,&DAT_00057564);
  }
  if ((byte)param_2[0x80] < 3) {
    cVar2 = '\0';
  }
  else {
    (*g_medialib_printf)("##AAC Demuxer: ERROR--channels exceed the max num##\r\n");
    cVar2 = -1;
  }
  return (int)cVar2;
}



bool AACDemuxer_GetAdifHeader(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_d7 [9];
  char acStack_ce [6];
  undefined4 local_c8;
  undefined1 local_c4;
  undefined4 local_c0;
  char acStack_bc [128];
  byte local_3c;
  byte local_11;
  
  local_11 = 0;
  Bitstream_Init(param_1 + 0x28,param_2,0,0x24);
  Bitstream_ReadBits(param_1 + 0x28,0x20,&DAT_00057564);
  cVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  if (cVar1 != '\0') {
    for (local_11 = 0; local_11 < 9; local_11 = local_11 + 1) {
      uVar5 = (uint)local_11;
      uVar2 = Bitstream_ReadBits(param_1 + 0x28,8,&DAT_00057564);
      auStack_d7[uVar5] = uVar2;
    }
    auStack_d7[local_11] = 0;
  }
  acStack_ce[1] = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  acStack_ce[2] = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  acStack_ce[3] = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  local_c8 = Bitstream_ReadBits(param_1 + 0x28,0x17,&DAT_00057564);
  local_c4 = Bitstream_ReadBits(param_1 + 0x28,4,&DAT_00057564);
  if (acStack_ce[3] == '\0') {
    local_c0 = Bitstream_ReadBits(param_1 + 0x28,0x14,&DAT_00057564);
  }
  else {
    local_c0 = 0;
  }
  iVar3 = AAC_ProgramConfigElement(param_1 + 0x28,acStack_bc + (uint)local_11 * 0xa5);
  if (-1 < iVar3) {
    *(char *)(param_1 + 1) = acStack_bc[1] + '\x01';
    uVar4 = get_aacsamplerate(acStack_bc[2]);
    *(undefined4 *)(param_1 + 0xc) = uVar4;
    *(ushort *)(param_1 + 2) = (ushort)local_3c;
    *(undefined4 *)(param_1 + 8) = local_c8;
  }
  return -1 < iVar3;
}



int AACDemuxer_AdtsFixedHeader(int param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  
  uVar2 = Bitstream_ShowBits(param_1 + 0x28,0x10);
  if (((uVar2 & 0xfff6) == 0xfff0) && (uVar2 != 0xfff0)) {
    uVar3 = Bitstream_ReadBits(param_1 + 0x28,0xc,&DAT_00057564);
    *param_2 = uVar3;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
    *(undefined1 *)(param_2 + 1) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,2,&DAT_00057564);
    *(undefined1 *)((int)param_2 + 3) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
    *(undefined1 *)(param_2 + 2) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,2,&DAT_00057564);
    *(undefined1 *)((int)param_2 + 5) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,4,&DAT_00057564);
    *(undefined1 *)(param_2 + 3) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
    *(undefined1 *)((int)param_2 + 7) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,3,&DAT_00057564);
    *(undefined1 *)(param_2 + 4) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
    *(undefined1 *)((int)param_2 + 9) = uVar1;
    uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
    *(undefined1 *)(param_2 + 5) = uVar1;
    cVar4 = '\0';
  }
  else {
    cVar4 = -1;
  }
  return (int)cVar4;
}



void AACDemuxer_AdtsVariableHeader(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  *(undefined1 *)(param_2 + 0xc) = uVar1;
  uVar1 = Bitstream_ReadBits(param_1 + 0x28,1,&DAT_00057564);
  *(undefined1 *)(param_2 + 0xd) = uVar1;
  uVar2 = Bitstream_ReadBits(param_1 + 0x28,0xd,&DAT_00057564);
  *(undefined2 *)(param_2 + 0xe) = uVar2;
  uVar2 = Bitstream_ReadBits(param_1 + 0x28,0xb,&DAT_00057564);
  *(undefined2 *)(param_2 + 0x10) = uVar2;
  uVar1 = Bitstream_ReadBits(param_1 + 0x28,2,&DAT_00057564);
  *(undefined1 *)(param_2 + 0x12) = uVar1;
  return;
}



int AACDemuxer_AdtsFrame(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  ushort uVar4;
  undefined1 auStack_20 [4];
  char local_1c;
  char local_1b;
  undefined1 local_1a;
  byte local_18;
  undefined2 local_c;
  
  Bitstream_Init(param_1 + 0x28,param_2,0,0x24);
  iVar1 = AACDemuxer_AdtsFixedHeader(param_1,auStack_20);
  if (iVar1 == 0) {
    AACDemuxer_AdtsVariableHeader(param_1,auStack_20);
    if (local_1c == '\0') {
      local_c = Bitstream_ReadBits(param_1 + 0x28,0x10,&DAT_00057564);
    }
    param_1[1] = local_1b + '\x01';
    uVar2 = get_aacsamplerate(local_1a);
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    if (local_18 < 7) {
      uVar4 = (ushort)local_18;
    }
    else {
      uVar4 = 2;
    }
    *(ushort *)(param_1 + 2) = uVar4;
    *param_1 = 1;
    cVar3 = '\0';
  }
  else {
    cVar3 = -1;
  }
  return (int)cVar3;
}



int AACDemuxer_GetNextHeader(int param_1)

{
  int iVar1;
  byte local_68 [4];
  byte local_64;
  byte local_63;
  undefined1 auStack_62 [58];
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  ushort local_12;
  
  local_12 = 0;
  local_18 = 2;
  local_1c = 0;
  local_24 = MediaFile_GetPosition(param_1);
  local_28 = 0;
  local_20 = 0;
  iVar1 = MediaFile_Read(param_1,local_68,6);
  if (iVar1 == 6) {
    if (*(int *)(param_1 + 0x10) == 1) {
      (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while getting next header 1##\r\n");
      local_20 = -1;
    }
    else {
      local_12 = CONCAT11(local_68[0],local_68[1]);
      if (((local_12 & 0xfff6) == 0xfff0) && (local_12 != 0xfff0)) {
        local_20 = (local_68[3] & 3) * 0x800 + (uint)local_64 * 8 + (uint)(local_63 >> 5);
        MediaFile_SetPosition(param_1,local_24);
      }
      else {
        iVar1 = MediaFile_Read(param_1,auStack_62,0x3a);
        local_28 = iVar1 + 6;
        if (*(int *)(param_1 + 0x10) == 1) {
          (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while getting next header 2##\r\n")
          ;
          local_20 = -1;
        }
        else {
          if (local_28 < 0x40) {
            ZeroMemory(auStack_62 + iVar1,0x40 - local_28);
          }
          do {
            if (((local_12 & 0xfff6) == 0xfff0) && (local_12 != 0xfff0)) {
              MediaFile_SetPosition(param_1,local_24 + local_1c);
              iVar1 = MediaFile_Read(param_1,local_68,6);
              if (iVar1 != 6) {
                return -1;
              }
              if (((CONCAT11(local_68[0],local_68[1]) & 0xfff6) == 0xfff0) &&
                 (CONCAT11(local_68[0],local_68[1]) != 0xfff0)) {
                local_20 = (local_68[3] & 3) * 0x800 + (uint)local_64 * 8 + (uint)(local_63 >> 5);
              }
              MediaFile_SetPosition(param_1,local_24 + local_1c);
              return local_20;
            }
            local_12 = local_12 << 8 | (ushort)local_68[local_18];
            local_18 = local_18 + 1;
            local_1c = local_1c + 1;
            if (local_18 == 0x40) {
              local_28 = MediaFile_Read(param_1,local_68,0x40);
              if (local_28 == 0) {
                return 0;
              }
              if (local_28 < 0x40) {
                ZeroMemory(local_68 + local_28,0x40 - local_28);
              }
              local_18 = 0;
            }
          } while (local_1c < 0x1200);
          local_20 = -1;
        }
      }
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}



undefined4 AACDemuxer_GetTotalFrameNum(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_1c = 0;
  uVar1 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 0x1c));
  local_20 = 1000;
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(ushort *)(param_1 + 2) < 3) {
    if (uVar1 < 0x400001) {
      uVar2 = (**(code **)(*(int *)(param_1 + 0x24) + 0x14))(0xcc);
      *(undefined4 *)(param_1 + 0x20) = uVar2;
      if (*(int *)(param_1 + 0x20) == 0) {
        return 0;
      }
      local_1c = *(int *)(param_1 + 0x20);
      *(undefined4 *)(local_1c + 200) = 0;
      local_20 = 0x1194;
    }
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10));
    local_18 = AACDemuxer_GetNextHeader(*(undefined4 *)(param_1 + 0x1c));
    do {
      if ((local_1c != 0) && (*(uint *)(param_1 + 0x14) % 0x1e == 0)) {
        if (local_14 == 0x32) {
          uVar2 = (**(code **)(*(int *)(param_1 + 0x24) + 0x14))(0xcc);
          *(undefined4 *)(local_1c + 200) = uVar2;
          if (*(int *)(local_1c + 200) == 0) {
            return 0;
          }
          local_1c = *(int *)(local_1c + 200);
          *(undefined4 *)(local_1c + 200) = 0;
          local_14 = 0;
        }
        uVar2 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x1c));
        *(undefined4 *)(local_1c + local_14 * 4) = uVar2;
        local_14 = local_14 + 1;
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      if (*(int *)(param_1 + 0x14) == local_20) {
        return 0;
      }
      MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x1c),local_18);
      local_18 = AACDemuxer_GetNextHeader(*(undefined4 *)(param_1 + 0x1c));
    } while (0 < local_18);
    if ((local_1c != 0) && (local_14 < 0x32)) {
      ZeroMemory(local_1c + local_14 * 4,local_14 * -4 + 200);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AACDemuxer_GetTotalTime(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_14;
  
  if (*param_1 == '\0') {
    MulDiv(param_1 + 4,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 4),8000,
           *(undefined4 *)(param_1 + 8));
  }
  else {
    uVar1 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 0x1c));
    iVar2 = AACDemuxer_GetTotalFrameNum(param_1);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x20) != 0) {
        local_14 = *(int *)(param_1 + 0x20);
        while (local_14 != 0) {
          iVar2 = *(int *)(local_14 + 200);
          (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(local_14);
          local_14 = iVar2;
        }
        param_1[0x20] = '\0';
        param_1[0x21] = '\0';
        param_1[0x22] = '\0';
        param_1[0x23] = '\0';
      }
      if ((3 < *(uint *)(param_1 + 0x14)) &&
         (uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x1c)),
         *(uint *)(param_1 + 0x10) < uVar3)) {
        iVar2 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x1c));
        uVar4 = __aeabi_uidiv(iVar2 - *(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
        *(undefined4 *)(param_1 + 0x18) = uVar4;
      }
      MulDiv(param_1 + 4,uVar1,0xfa000,*(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x18));
      MulDiv(param_1 + 8,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc),0x80);
      (*g_medialib_printf)("##AAC Demuxer: WARNING--total time is not accurate##\r\n");
    }
    else {
      MulDiv(param_1 + 4,*(undefined4 *)(param_1 + 0x14),0xfa000,*(undefined4 *)(param_1 + 0xc));
      MulDiv(param_1 + 8,uVar1,8000,*(undefined4 *)(param_1 + 4));
    }
  }
  return 1;
}



undefined4 AACDemuxer_FillHeader(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_44;
  undefined1 auStack_40 [36];
  int local_1c;
  int local_18;
  int local_14;
  
  local_44 = 10;
  iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x1c),auStack_40,10);
  if (iVar1 == local_44) {
    check_id3_header(auStack_40,&local_44);
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),local_44);
    iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x1c),auStack_40,0x24);
    if (iVar1 == 0x24) {
      *(undefined2 *)(param_1 + 2) = 1;
      *(int *)(param_1 + 0x10) = local_44;
      iVar1 = memcmp(auStack_40,&DAT_000576e0,4);
      if (iVar1 == 0) {
        *param_1 = 0;
        iVar1 = AACDemuxer_GetAdifHeader(param_1,auStack_40);
        if (iVar1 == 0) {
          (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while getting adif header##\r\n");
          return 0;
        }
      }
      else {
        local_14 = 3;
        local_18 = 10;
        local_1c = 0;
        MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),local_44);
        *(undefined4 *)(param_1 + 0x18) = 0;
        for (; local_18 != 0; local_18 = local_18 + -1) {
          local_1c = AACDemuxer_GetNextHeader(*(undefined4 *)(param_1 + 0x1c));
          if (local_1c < 1) {
            (*g_medialib_printf)
                      ("##AAC Demuxer: ERROR--Length error while reading adts header##\r\n");
            return 0;
          }
          MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x1c),local_1c);
          iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x1c),auStack_40,2);
          if (iVar1 != 2) {
            (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while reading adts header##\r\n")
            ;
            return 0;
          }
          uVar2 = mov_str2ushort(auStack_40);
          if (((uVar2 & 0xfff6) == 0xfff0) && (iVar1 = mov_str2ushort(auStack_40), iVar1 != 0xfff0))
          {
            if (local_14 == 3) {
              iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x1c));
              *(int *)(param_1 + 0x10) = (iVar1 - local_1c) + -2;
            }
            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + local_1c;
            local_14 = local_14 + -1;
            if (local_14 == 0) break;
          }
          else {
            local_14 = 3;
            *(int *)(param_1 + 0x10) = local_44;
            *(undefined4 *)(param_1 + 0x18) = 0;
          }
          MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x1c),0xfffffffe);
        }
        if (local_18 == 0) {
          (*g_medialib_printf)("##AAC Demuxer: ERROR--check adts header error##\r\n");
          return 0;
        }
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) / 3;
        MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10));
        iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x1c),auStack_40,0x24);
        if (iVar1 != 0x24) {
          (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while reading aac header 2##\r\n");
          return 0;
        }
        iVar1 = AACDemuxer_AdtsFrame(param_1,auStack_40);
        if (iVar1 < 0) {
          (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while getting adts header##\r\n");
          return 0;
        }
      }
      if (*(int *)(param_1 + 0xc) == 0) {
        (*g_medialib_printf)("##AAC Demuxer: ERROR--sample rate is zero##\r\n");
        uVar3 = 0;
      }
      else if (param_1[1] == '\x02') {
        iVar1 = AACDemuxer_GetTotalTime(param_1);
        if (iVar1 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        (*g_medialib_printf)("##AAC Demuxer: ERROR--Unsupported--LC ONLY##\r\n");
        uVar3 = 0;
      }
    }
    else {
      (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while reading aac header 2##\r\n");
      uVar3 = 0;
    }
  }
  else {
    (*g_medialib_printf)("##AAC Demuxer: ERROR--Read error while reading aac header 1##\r\n");
    uVar3 = 0;
  }
  return uVar3;
}



int AACDemuxer_Init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[5])(0x44);
  if (iVar1 == 0) {
    if (*param_1 != 0) {
      (*(code *)*param_1)("##AAC Demuxer: ERROR--Init return FALSE, malloc demuxer failed\r\n");
    }
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x44);
    *(int **)(iVar1 + 0x24) = param_1;
  }
  return iVar1;
}



undefined4 AACDemuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    AACDemuxer_Close(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 AACDemuxer_Open(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 4);
    iVar1 = AACDemuxer_FillHeader(param_1);
    if (iVar1 == 0) {
      AACDemuxer_Close(param_1);
      (*g_medialib_printf)("##AAC Demuxer: ERROR--Fill header failed##\r\n");
      uVar2 = 0;
    }
    else {
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10));
      uVar2 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##AAC Demuxer: ERROR--AAC demxer has been opened already##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AACDemuxer_Close(char *param_1)

{
  int iVar1;
  int local_c;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    if (*param_1 != '\0') {
      local_c = *(int *)(param_1 + 0x20);
      while (local_c != 0) {
        iVar1 = *(int *)(local_c + 200);
        (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(local_c);
        local_c = iVar1;
      }
      param_1[0x20] = '\0';
      param_1[0x21] = '\0';
      param_1[0x22] = '\0';
      param_1[0x23] = '\0';
    }
    AACDemuxer_ReleaseInfoMem(param_1);
    param_1[0x1c] = '\0';
    param_1[0x1d] = '\0';
    param_1[0x1e] = '\0';
    param_1[0x1f] = '\0';
  }
  return 1;
}



undefined4 AACDemuxer_GetFileInfo(undefined1 *param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0xc);
  *(undefined2 *)(param_2 + 0x2e) = *(undefined2 *)(param_1 + 2);
  *(undefined4 *)(param_2 + 0x28) = 4;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4);
  *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(param_2 + 0x21) = *param_1;
  return 1;
}



uint AACDemuxer_Seek(char *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint local_30;
  char *local_2c;
  undefined1 auStack_24 [4];
  uint local_20;
  uint local_1c;
  int local_18;
  char *local_14;
  int local_10;
  uint local_c;
  
  local_1c = 0;
  local_c = 0;
  local_10 = *(int *)(param_1 + 0x20);
  local_30 = param_2;
  local_2c = param_1;
  local_20 = param_2;
  local_14 = param_1;
  if (*(uint *)(param_1 + 4) < param_2) {
    (*g_medialib_printf)("##AAC Demuxer: ERROR--Seek time over the song length ##\r\n");
    local_30 = 0xffffffff;
  }
  else if (param_2 == 0) {
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10));
    local_30 = 0;
  }
  else if (*param_1 == '\0') {
    local_30 = 0xffffffff;
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    local_18 = 0;
    MulDiv(&local_1c,param_2,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 4),
           *(undefined4 *)(param_1 + 4));
    if (*(uint *)(local_14 + 0x18) <= local_1c) {
      local_1c = local_1c - *(int *)(local_14 + 0x18);
    }
    MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x1c),local_1c);
    while (local_18 = AACDemuxer_GetNextHeader(*(undefined4 *)(local_14 + 0x1c)), 0 < local_18) {
      local_1c = MediaFile_GetPosition(*(undefined4 *)(local_14 + 0x1c));
      MediaFile_ChangePosition(*(undefined4 *)(local_14 + 0x1c),local_18);
      iVar1 = MediaFile_Read(*(undefined4 *)(local_14 + 0x1c),auStack_24,2);
      if (iVar1 != 2) {
        return 0xffffffff;
      }
      uVar2 = mov_str2ushort(auStack_24);
      if (((uVar2 & 0xfff6) == 0xfff0) && (iVar1 = mov_str2ushort(auStack_24), iVar1 != 0xfff0)) {
        MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x1c),local_1c);
        return local_20;
      }
      MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x1c),local_1c + 1);
    }
    local_30 = 0xffffffff;
  }
  else {
    MulDiv(&local_1c,param_2,*(undefined4 *)(param_1 + 0xc),0xfa000);
    MulDiv(&local_30,local_1c,0xfa000,*(undefined4 *)(local_14 + 0xc));
    for (local_c = local_1c / 0x5dc; local_c != 0; local_c = local_c - 1) {
      local_10 = *(int *)(local_10 + 200);
      local_1c = local_1c - 0x5dc;
    }
    local_c = local_1c / 0x1e;
    MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x1c),*(undefined4 *)(local_10 + local_c * 4));
    local_c = local_1c % 0x1e;
    MulDiv(&local_20,local_c,0xfa000,*(undefined4 *)(local_14 + 0xc));
    local_30 = local_30 - local_20;
  }
  return local_30;
}



undefined4 AACDemuxer_ReleaseInfoMem(void)

{
  return 1;
}



undefined4 AMRDemuxer_GetTotalTime(byte *param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  short asStack_38 [16];
  byte *local_18;
  int local_14;
  
  local_18 = param_1 + 0x18;
  local_14 = 0;
  memcpy(asStack_38,&DAT_000579e8,0x20);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x30),*(int *)(*(int *)(param_1 + 0x30) + 4) + -0x18);
  iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x30),local_18,0x18);
  if (iVar1 == 0x18) {
    iVar1 = memcmp(local_18 + 0x11,"ANYKA",5);
    if ((iVar1 == 0) && (local_18[0x10] == 0)) {
      if (local_18[0x17] == 1) {
        bVar2 = 2;
      }
      else {
        bVar2 = 1;
      }
      param_1[1] = bVar2;
      if (param_1[1] == 2) {
        uVar3 = str2ulong(local_18);
        *(undefined4 *)(param_1 + 8) = uVar3;
        return 1;
      }
      local_14 = (*(int *)(*(int *)(param_1 + 0x30) + 4) - *(int *)(param_1 + 0x14)) + -8;
    }
    else {
      local_14 = *(int *)(*(int *)(param_1 + 0x30) + 4) - *(int *)(param_1 + 0x14);
    }
    if (asStack_38[*param_1] == 0) {
      (*g_medialib_printf)("##AMR Demuxer: ERROR--frame size is zero##\r\n");
      uVar3 = 0;
    }
    else {
      *(short *)(param_1 + 4) = asStack_38[*param_1];
      MulDiv(param_1 + 8,local_14,0x14,*(undefined2 *)(param_1 + 4));
      uVar3 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##AMR Demuxer: ERROR--Read error while getting total time##\r\n");
    uVar3 = 0;
  }
  return uVar3;
}



undefined4 AMRDemuxer_FillHeader(byte *param_1)

{
  int iVar1;
  undefined4 uVar2;
  ushort auStack_34 [17];
  byte local_11 [5];
  
  local_11[0] = 0;
  memcpy(auStack_34,&DAT_00057a48,0x20);
  param_1[2] = 1;
  param_1[3] = 0;
  param_1[0x10] = 0x40;
  param_1[0x11] = 0x1f;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 6;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x14));
  iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x30),local_11,1);
  if (iVar1 == 1) {
    *param_1 = local_11[0] >> 3 & 0xf;
    *(uint *)(param_1 + 0xc) = (uint)auStack_34[*param_1];
    iVar1 = AMRDemuxer_GetTotalTime(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##AMR Demuxer: ERROR--Read error while checking amr header##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



int AMRDemuxer_Init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[5])(0x38);
  if (iVar1 == 0) {
    if (*param_1 != 0) {
      (*(code *)*param_1)("##AMR Demuxer: ERROR--Init return FALSE, malloc demuxer failed\r\n");
    }
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x38);
    *(int **)(iVar1 + 0x34) = param_1;
  }
  return iVar1;
}



undefined4 AMRDemuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    AMRDemuxer_Close(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 0x34) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 AMRDemuxer_Open(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 4);
    iVar1 = AMRDemuxer_FillHeader(param_1);
    if (iVar1 == 0) {
      AMRDemuxer_Close(param_1);
      (*g_medialib_printf)("##AMR Demuxer: ERROR--Fill header failed##\r\n");
      uVar2 = 0;
    }
    else {
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x14));
      uVar2 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##AMR Demuxer: ERROR--AMR demxer has been opened already##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AMRDemuxer_Close(int param_1)

{
  if (*(int *)(param_1 + 0x30) != 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return 1;
}



undefined4 AMRDemuxer_GetFileInfo(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(param_2 + 0x2e) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_2 + 0x3a) = 0x10;
  *(undefined4 *)(param_2 + 0x28) = 3;
  uVar1 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_1 + 8);
  if (*(char *)(param_1 + 1) == '\0') {
    *(undefined1 *)(param_2 + 0x21) = 0;
  }
  else {
    *(undefined1 *)(param_2 + 0x21) = 1;
  }
  return 1;
}



uint AMRDemuxer_Seek(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_14;
  
  if (*(int *)(param_1 + 8) == 0) {
    param_2 = 0xffffffff;
  }
  else if (*(uint *)(param_1 + 8) < param_2) {
    (*g_medialib_printf)("##AMR Demuxer: ERROR--Seek time over the song length ##\r\n");
    param_2 = 0xffffffff;
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    if (param_2 == 0) {
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x14));
      param_2 = 0;
    }
    else {
      param_2 = 0xffffffff;
    }
  }
  else {
    if (*(char *)(param_1 + 1) == '\x01') {
      local_14 = (uint)*(ushort *)(param_1 + 4) * (param_2 / 0x14) + *(int *)(param_1 + 0x14);
      if (*(uint *)(*(int *)(param_1 + 0x30) + 4) < local_14) {
        return 0xffffffff;
      }
    }
    else {
      uVar1 = str2ulong(param_1 + 0x24);
      iVar2 = __aeabi_uidiv(param_2,uVar1);
      iVar3 = str2ulong(param_1 + 0x20);
      uVar4 = iVar3 + iVar2 * -4;
      if (((int)uVar4 < 3) || (*(uint *)(*(int *)(param_1 + 0x30) + 4) < uVar4)) {
        (*g_medialib_printf)("##AMR Demuxer: ERROR--index error##\r\n");
        return 0xffffffff;
      }
      MediaFile_SetPosition
                (*(undefined4 *)(param_1 + 0x30),*(int *)(*(int *)(param_1 + 0x30) + 4) - uVar4);
      iVar2 = MediaFile_Read(*(undefined4 *)(param_1 + 0x30),param_1 + 0x18,3);
      if (iVar2 != 3) {
        (*g_medialib_printf)("##AMR Demuxer: ERROR--Read error while reading amr data##\r\n");
        return 0xffffffff;
      }
      local_14 = str2ulong(param_1 + 0x18);
    }
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x30),local_14);
  }
  return param_2;
}



int ConvertUTF82Unicode(byte *param_1,int param_2)

{
  int local_10;
  byte *local_c;
  
  local_10 = 0;
  if (param_1 == (byte *)0x0) {
    local_10 = 1;
  }
  else {
    local_c = param_1;
    if (param_2 == 0) {
      while (*local_c != 0) {
        if ((*local_c & 0xe0) == 0xe0) {
          local_c = local_c + 3;
        }
        else if ((*local_c & 0xc0) == 0xc0) {
          local_c = local_c + 2;
        }
        else {
          local_c = local_c + 1;
        }
        local_10 = local_10 + 1;
      }
    }
    else {
      while (*local_c != 0) {
        if ((*local_c & 0xe0) == 0xe0) {
          *(ushort *)(param_2 + local_10 * 2) =
               (ushort)*local_c * 0x1000 + (local_c[1] & 0x3f) * 0x40 + (local_c[2] & 0x3f);
          local_c = local_c + 3;
        }
        else if ((*local_c & 0xc0) == 0xc0) {
          *(ushort *)(param_2 + local_10 * 2) = (*local_c & 0x1f) * 0x40 + (local_c[1] & 0x3f);
          local_c = local_c + 2;
        }
        else {
          *(ushort *)(param_2 + local_10 * 2) = (ushort)*local_c;
          local_c = local_c + 1;
        }
        local_10 = local_10 + 1;
      }
      *(undefined2 *)(param_2 + local_10 * 2) = 0;
    }
    local_10 = local_10 + 1;
  }
  return local_10;
}



undefined4 WAVDemuxer_FillHeader(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_3c;
  uint local_38;
  char local_34 [4];
  byte local_30;
  byte local_2f;
  undefined1 auStack_2e [10];
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_3c = 0;
  local_38 = 0;
  ZeroMemory(param_1 + 0x18,0x14);
  *(undefined4 *)(param_1 + 4) = 0;
  local_14 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 0x10));
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x10),0xc);
  local_14 = local_14 - 0xc;
  do {
    if (local_14 == 0) {
LAB_00021674:
      *(int *)(param_1 + 8) = *(int *)(param_1 + 0x20) << 3;
      if (*(short *)(param_1 + 0x18) == -0x7778) {
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) >> 2;
      }
      if ((((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x1c) == 0)) ||
          (*(short *)(param_1 + 0x1a) == 0)) ||
         ((*(short *)(param_1 + 0x26) == 0 || (*(int *)(param_1 + 8) == 0)))) {
        (*g_medialib_printf)("##WAV Demuxer: ERROR--Fill header FALSE, some param is zero##\r\n");
        uVar4 = 0;
      }
      else {
        if (((*(short *)(param_1 + 0x18) == 1) && (*(short *)(param_1 + 0x1a) == 2)) &&
           (*(int *)(param_1 + 0x1c) == 0xac44)) {
          local_24 = 0;
          MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc));
          MediaFile_Read(*(undefined4 *)(param_1 + 0x10),local_34,8);
          if (local_34[0] == '\0') {
            local_1c = 0;
            MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc));
            local_1c = MediaFile_SkipZeroBytes
                                 (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc));
            if (local_1c == -1) {
              (*g_medialib_printf)("##WAV Demuxer: WARNING--SkipZeroBytes##\r\n");
              local_1c = *(int *)(param_1 + 0xc);
            }
            MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x10),local_1c);
            MediaFile_Read(*(undefined4 *)(param_1 + 0x10),local_34,8);
          }
          local_24 = mov_str2ulong(local_34);
          if (((((local_24 == -0xe0ff18) && ((local_30 & 0xfe) == 0xf0)) && (local_2f == 7)) ||
              (((local_24 == 0x1fffe800 && (local_30 == 7)) && ((local_2f & 0xfe) == 0xf0)))) ||
             ((local_24 == 0x7ffe8001 || (local_24 == -0x180fe80)))) {
            (*g_medialib_printf)("##WAV Demuxer: ERROR--DTS Unsupported##\r\n");
            return 0;
          }
        }
        if ((*(short *)(param_1 + 0x18) == 2) || (*(short *)(param_1 + 0x18) == 0x11)) {
          MulDiv(param_1,*(undefined4 *)(param_1 + 4),(uint)*(ushort *)(param_1 + 0x2c) * 1000,
                 *(int *)(param_1 + 0x1c) * (uint)*(ushort *)(param_1 + 0x24));
        }
        else {
          if ((*(ushort *)(param_1 + 0x26) & 7) != 0) {
            (*g_medialib_printf)
                      ("##WAV Demuxer: ERROR--BitsPerSample %d(%d)##\r\n",
                       *(undefined2 *)(param_1 + 0x26),*(undefined2 *)(param_1 + 0x18));
            return 0;
          }
          MulDiv(param_1,*(undefined4 *)(param_1 + 4),8000,*(undefined4 *)(param_1 + 8));
        }
        uVar4 = 1;
      }
      return uVar4;
    }
    iVar3 = MediaFile_Read(*(undefined4 *)(param_1 + 0x10),&local_3c,8);
    if (iVar3 != 8) {
      (*g_medialib_printf)("##WAV Demuxer: ERROR--Read error while checking wav header ##\r\n");
      return 0;
    }
    if (local_14 < 8) {
      (*g_medialib_printf)("##WAV Demuxer: ERROR--length error##\r\n");
      return 0;
    }
    local_14 = local_14 - 8;
    iVar3 = memcmp(&local_3c,&DAT_00057c24,4);
    if (iVar3 == 0) {
      local_18 = 0;
      if (local_38 < 0x10) {
        (*g_medialib_printf)("##WAV Demuxer: ERROR--fmt length, less than 16##\r\n");
        return 0;
      }
      iVar3 = MediaFile_Read(*(undefined4 *)(param_1 + 0x10),local_34,0x10);
      if (iVar3 != 0x10) {
        (*g_medialib_printf)("##WAV Demuxer: ERROR--Read wav header##\r\n");
        return 0;
      }
      local_18 = 0x10;
      memcpy((void *)(param_1 + 0x18),local_34,0x10);
      if (0x11 < local_38) {
        iVar3 = MediaFile_Read(*(undefined4 *)(param_1 + 0x10),local_34,2);
        if (iVar3 != 2) {
          (*g_medialib_printf)("##WAV Demuxer: ERROR--Read wav header 2##\r\n");
          return 0;
        }
        local_18 = local_18 + 2;
        uVar2 = str2ushort(local_34);
        *(undefined2 *)(param_1 + 0x28) = uVar2;
        if ((0x15 < *(ushort *)(param_1 + 0x28)) && (*(short *)(param_1 + 0x18) == -2)) {
          local_20 = 0;
          iVar3 = MediaFile_Read(*(undefined4 *)(param_1 + 0x10),local_34,10);
          if (iVar3 != 10) {
            (*g_medialib_printf)("##WAV Demuxer: ERROR--Read wav header 3##\r\n");
            return 0;
          }
          local_18 = local_18 + 10;
          uVar2 = str2ushort(local_34);
          *(undefined2 *)(param_1 + 0x26) = uVar2;
          local_20 = str2ulong(auStack_2e);
          if ((local_20 & 0xffff0000) != 0) {
            (*g_medialib_printf)("##WAV Demuxer: ERROR--Unknown Tag##\r\n");
            return 0;
          }
          *(short *)(param_1 + 0x18) = (short)local_20;
        }
      }
      uVar1 = *(ushort *)(param_1 + 0x18);
      if (uVar1 < 8) {
        if ((uVar1 < 6) && (uVar1 != 1)) {
          if (uVar1 != 2) {
LAB_000214dc:
            (*g_medialib_printf)("##WAV Demuxer: ERROR--unknown wav format##\r\n");
            return 0;
          }
LAB_00021404:
          if ((int)(local_38 - local_18) < 2) {
            (*g_medialib_printf)("##WAV Demuxer: ERROR--ADPCM fmt length##\r\n");
            return 0;
          }
          iVar3 = MediaFile_Read(*(undefined4 *)(param_1 + 0x10),param_1 + 0x2e,2);
          if (iVar3 != 2) {
            (*g_medialib_printf)("##WAV Demuxer: ERROR--Read ADPCM header##\r\n");
            return 0;
          }
          local_18 = local_18 + 2;
          uVar2 = str2ushort(param_1 + 0x2e);
          *(undefined2 *)(param_1 + 0x2c) = uVar2;
          memcpy((void *)(param_1 + 0x30),(void *)(param_1 + 0x24),2);
        }
      }
      else {
        if (uVar1 == 0x11) goto LAB_00021404;
        if (uVar1 != 0x8888) goto LAB_000214dc;
      }
      if ((*(short *)(param_1 + 0x1a) == 0) || (2 < *(ushort *)(param_1 + 0x1a))) {
        (*g_medialib_printf)("##WAV Demuxer: ERROR--channel num exceeds the normal range##\r\n");
        return 0;
      }
      MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x10),local_38 - local_18);
    }
    else {
      iVar3 = memcmp(&local_3c,&DAT_00057dd4,4);
      if (iVar3 == 0) {
        if ((local_38 == 0) || (local_14 < local_38)) {
          *(uint *)(param_1 + 4) = local_14;
        }
        else {
          *(uint *)(param_1 + 4) = local_38;
        }
        uVar4 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x10));
        *(undefined4 *)(param_1 + 0xc) = uVar4;
        *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
        goto LAB_00021674;
      }
      MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x10),local_38);
    }
    if (local_14 < local_38) {
      (*g_medialib_printf)("##WAV Demuxer: ERROR--chunk length error##\r\n");
      return 0;
    }
    local_14 = local_14 - local_38;
  } while( true );
}



int WAVDemuxer_Init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[5])(0x34);
  if (iVar1 == 0) {
    if (*param_1 != 0) {
      (*(code *)*param_1)("##WAV Demuxer: ERROR--Init return FALSE, malloc demuxer failed\r\n");
    }
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x34);
    *(int **)(iVar1 + 0x14) = param_1;
  }
  return iVar1;
}



undefined4 WAVDemuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    WAVDemuxer_Close(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 0x14) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 WAVDemuxer_Open(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 4);
    iVar1 = WAVDemuxer_FillHeader(param_1);
    if (iVar1 == 0) {
      WAVDemuxer_Close(param_1);
      (*g_medialib_printf)("##WAV Demuxer: ERROR--Fill header failed##\r\n");
      uVar2 = 0;
    }
    else {
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc));
      uVar2 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##WAV Demuxer: ERROR--WAV demxer has been opened already##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 WAVDemuxer_Close(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 1;
}



undefined4 WAVDemuxer_GetFileInfo(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 0x18) = param_1[2];
  memcpy((void *)(param_2 + 0x2c),param_1 + 6,0x14);
  switch(*(undefined2 *)(param_1 + 6)) {
  case 2:
    *(undefined4 *)(param_2 + 0x28) = 8;
    memcpy((void *)(param_2 + 0x40),(void *)((int)param_1 + 0x2e),4);
    *(undefined2 *)(param_2 + 0x3c) = 4;
    goto LAB_00021da4;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    *(undefined4 *)(param_2 + 0x28) = 0x11;
    goto LAB_00021da4;
  case 7:
    *(undefined4 *)(param_2 + 0x28) = 0x12;
    goto LAB_00021da4;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    *(undefined4 *)(param_2 + 0x28) = 7;
    memcpy((void *)(param_2 + 0x40),(void *)((int)param_1 + 0x2e),4);
    *(undefined2 *)(param_2 + 0x3c) = 4;
    goto LAB_00021da4;
  }
  *(undefined4 *)(param_2 + 0x28) = 6;
LAB_00021da4:
  uVar1 = MediaFile_GetTotalLen(param_1[4]);
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  *(undefined4 *)(param_2 + 0x60) = *param_1;
  *(undefined1 *)(param_2 + 0x21) = 1;
  return 1;
}



uint WAVDemuxer_Seek(uint *param_1,uint param_2)

{
  int iVar1;
  uint local_20;
  uint *local_1c;
  int local_14;
  uint local_10;
  uint *local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_20 = param_2;
  local_1c = param_1;
  local_c = param_1;
  if (param_2 < *param_1) {
    if (((short)param_1[6] == 2) || ((short)param_1[6] == 0x11)) {
      MulDiv(&local_14,param_2,param_1[7],(uint)(ushort)param_1[0xb] * 1000);
      local_10 = local_14 * (uint)(ushort)local_c[9];
      MulDiv(&local_20,local_14,(uint)(ushort)local_c[0xb] * 1000,local_c[7]);
    }
    else {
      MulDiv(&local_10,param_2,param_1[2],8000);
      local_14 = (uint)*(ushort *)((int)local_c + 0x1a) *
                 (uint)(*(ushort *)((int)local_c + 0x26) >> 3);
      iVar1 = __aeabi_uidiv(local_10,local_14);
      local_10 = local_14 * iVar1;
    }
    if (local_10 < local_c[1]) {
      MediaFile_SetPosition(local_c[4],local_c[3] + local_10);
    }
    else {
      local_20 = 0xffffffff;
    }
  }
  else {
    (*g_medialib_printf)("##WAV Demuxer: ERROR--Seek position ERROR##\r\n");
    local_20 = 0xffffffff;
  }
  return local_20;
}



undefined4
AVIDemuxer_FillIndex
          (int param_1,uint param_2,undefined4 param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_424 [8];
  undefined1 auStack_41c [4];
  undefined1 auStack_418 [1012];
  int local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  
  local_18 = 0;
  local_20 = 0x400;
  local_10 = 0;
  local_14 = 0;
  local_1c = auStack_424;
  local_24 = *(int *)(param_1 + 0xb8);
  ZeroMemory(auStack_424,0x400);
  if (param_6 == 2) {
    ZeroMemory(param_1 + 200,0xc);
    local_20 = 0x400;
    local_14 = param_4;
    local_10 = param_2;
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),param_3);
    do {
      local_18 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),local_1c,local_20);
      if ((local_18 == 0) || (*(int *)(*(int *)(param_1 + 0xa0) + 0x10) != 0)) {
        return 0;
      }
      for (local_c = 0; local_c < local_18 >> 4; local_c = local_c + 1) {
        iVar1 = str2ulong(auStack_424 + local_c * 0x10);
        if (iVar1 == *(int *)(param_1 + 0x38)) {
          if (local_10 == param_5) break;
          iVar1 = str2ulong(auStack_418 + local_c * 0x10);
          local_14 = local_14 + iVar1;
          local_10 = local_10 + 1;
        }
      }
    } while ((local_10 < param_5) || (local_18 >> 4 <= local_c));
    if (local_10 == param_5) {
      iVar1 = str2ulong(auStack_41c + local_c * 0x10);
      *(int *)(param_1 + 200) = iVar1 + local_24;
      uVar2 = str2ulong(auStack_418 + local_c * 0x10);
      *(undefined4 *)(param_1 + 0xcc) = uVar2;
      *(int *)(param_1 + 0xd0) = local_14;
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AVIDemuxer_FindIndexFrom(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_c;
  
  (*g_medialib_printf)("#AVIDemuxer_FindIndexFrom frame = %d#\r\n",param_2);
  if (param_3 == 2) {
    if (param_2 < *(uint *)(param_1 + 0x7c)) {
      if (param_2 < *(uint *)(*(int *)(param_1 + 0xc4) + 0x17f4)) {
        for (local_c = 0; local_c < 0x1ff; local_c = local_c + 1) {
          if ((*(uint *)(*(int *)(param_1 + 0xc4) + local_c * 0xc) <= param_2) &&
             (param_2 < *(uint *)(*(int *)(param_1 + 0xc4) + (local_c + 1) * 0xc))) {
            puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc4) + local_c * 0xc);
            uVar1 = AVIDemuxer_FillIndex(param_1,*puVar3,puVar3[1],puVar3[2],param_2,2);
            return uVar1;
          }
        }
        uVar1 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0xc4);
        uVar1 = AVIDemuxer_FillIndex
                          (param_1,*(undefined4 *)(iVar2 + 0x17f4),*(undefined4 *)(iVar2 + 0x17f8),
                           *(undefined4 *)(iVar2 + 0x17fc),param_2,2);
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 AVIDemuxer_GetAudioIndex(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  uint local_14;
  
  if (param_3 == (int *)0x0) {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--get audio index pEntry is NULL##\r\n");
    uVar3 = 0;
  }
  else if (param_2 < *(uint *)(param_1 + 0x7c)) {
    if (*(char *)(param_1 + 0x10d) == '\0') {
      iVar1 = AVIDemuxer_FindIndexFrom(param_1,param_2,2);
      if (iVar1 == 0) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--Audio FindIndexFrom, frame invalid!##\r\n");
        uVar3 = 0;
      }
      else {
        memcpy(param_3,(void *)(param_1 + 200),0xc);
        if (*param_3 == 0) {
          *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x7c);
          (*g_medialib_printf)
                    ("##AVI Demuxer: ERROR--a pos is zero, len = 0x%x, tot = 0x%x, frame = %d##\r\n"
                     ,param_3[1],param_3[2],param_2);
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
    }
    else {
      local_14 = 0;
      while ((local_14 < *(uint *)(param_1 + 0x114) &&
             (*(uint *)(*(int *)(param_1 + 0x124) + local_14 * 0x10 + 4) <= param_2))) {
        *(uint *)(param_1 + 0x11c) = local_14;
        local_14 = local_14 + 1;
      }
      MediaFile_SetPosition
                (*(undefined4 *)(param_1 + 0xa0),
                 *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10) +
                 (param_2 -
                 *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4)) * 8);
      iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_1c,8);
      if (iVar1 == 8) {
        iVar1 = str2ulong(auStack_1c);
        *param_3 = iVar1;
        if (*param_3 == 0) {
          param_3[1] = 0;
        }
        else {
          uVar2 = str2ulong(auStack_18);
          param_3[1] = uVar2 & 0x7fffffff;
        }
        *param_3 = *param_3 +
                   *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 0xc);
        param_3[2] = 0;
        uVar3 = 1;
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read audio index, frame invalid!##\r\n");
        uVar3 = 0;
      }
    }
  }
  else {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--audio chunk number is out of range##\r\n");
    uVar3 = 0;
  }
  return uVar3;
}



undefined4 AVIDemuxer_FillODMLIndex(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_207c [4];
  undefined1 auStack_2078 [8188];
  undefined1 auStack_7c [8];
  undefined1 auStack_74 [2];
  undefined1 auStack_72 [2];
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [16];
  uint local_54;
  undefined1 *local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int *local_34;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_20 = 0;
  local_24 = 0;
  local_48 = 0;
  local_28 = 0;
  local_4c = 0;
  local_2c = 0;
  local_50 = (undefined1 *)0x0;
  local_30 = 0;
  local_34 = (int *)0x0;
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  (*g_medialib_printf)("##AVI Demuxer: FillODMLIndex##\r\n");
  if (*(int *)(param_1 + 0x120) != 0) {
    local_28 = 0;
    for (local_18 = 0; local_18 < *(uint *)(param_1 + 0x110); local_18 = local_18 + 1) {
      MediaFile_SetPosition
                (*(undefined4 *)(param_1 + 0xa0),
                 *(undefined4 *)(*(int *)(param_1 + 0x120) + local_18 * 0x10));
      iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_7c,0x28);
      if (iVar1 != 0x28) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read video index failed##\r\n");
        return 0;
      }
      iVar1 = memcmp(auStack_7c,&DAT_0005817c,2);
      if ((((iVar1 != 0) || (iVar1 = str2ushort(auStack_74), iVar1 != 2)) ||
          (iVar1 = str2ushort(auStack_72), iVar1 != 0x100)) ||
         ((iVar1 = str2ulong(auStack_6c), iVar1 * 0x100 != *(int *)(param_1 + 0x34) ||
          (iVar1 = str2ulong(auStack_64), iVar1 != 0)))) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--video index error##\r\n");
        return 0;
      }
      *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10 + 4) = local_28;
      iVar2 = *(int *)(param_1 + 0x120);
      iVar1 = local_18 * 0x10;
      uVar4 = str2ulong(auStack_70);
      *(undefined4 *)(iVar2 + iVar1 + 8) = uVar4;
      iVar2 = *(int *)(param_1 + 0x120);
      iVar1 = local_18 * 0x10;
      uVar4 = str2ulong(auStack_68);
      *(undefined4 *)(iVar2 + iVar1 + 0xc) = uVar4;
      *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10) =
           *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10) + 0x20;
      local_28 = local_28 + *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10 + 8);
    }
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    local_28 = 0;
    for (local_18 = 0; local_18 < *(uint *)(param_1 + 0x114); local_18 = local_18 + 1) {
      MediaFile_SetPosition
                (*(undefined4 *)(param_1 + 0xa0),
                 *(undefined4 *)(*(int *)(param_1 + 0x124) + local_18 * 0x10));
      iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_7c,0x28);
      if (iVar1 != 0x28) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read audio index failed##\r\n");
        return 0;
      }
      iVar1 = memcmp(auStack_7c,&DAT_0005817c,2);
      if (((iVar1 != 0) || (iVar1 = str2ushort(auStack_74), iVar1 != 2)) ||
         ((iVar1 = str2ushort(auStack_72), iVar1 != 0x100 ||
          ((iVar1 = str2ulong(auStack_6c), iVar1 != *(int *)(param_1 + 0x38) ||
           (iVar1 = str2ulong(auStack_64), iVar1 != 0)))))) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--audio index error##\r\n");
        return 0;
      }
      *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10 + 4) = local_28;
      iVar2 = *(int *)(param_1 + 0x124);
      iVar1 = local_18 * 0x10;
      uVar4 = str2ulong(auStack_70);
      *(undefined4 *)(iVar2 + iVar1 + 8) = uVar4;
      iVar2 = *(int *)(param_1 + 0x124);
      iVar1 = local_18 * 0x10;
      uVar4 = str2ulong(auStack_68);
      *(undefined4 *)(iVar2 + iVar1 + 0xc) = uVar4;
      *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10) =
           *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10) + 0x20;
      local_28 = local_28 + *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10 + 8);
    }
    *(int *)(param_1 + 0x7c) = local_28;
  }
  local_50 = auStack_207c;
  local_34 = (int *)(param_1 + 0xd4);
  iVar1 = memcmp(&DAT_0005820c,(void *)(param_1 + 0x2c),4);
  if (iVar1 == 0) {
    local_3c = *(uint *)(param_1 + 0x48) >> 1;
  }
  local_18 = 0;
  do {
    if (*(uint *)(param_1 + 0x110) <= local_18) {
      if ((local_38 != 0x100) && (*(int *)(param_1 + 0xc0) != 0)) {
        ZeroMemory(*(int *)(param_1 + 0xc0) + local_38 * 8,local_38 * -8 + 0x800);
      }
      if (*(int *)(*(int *)(param_1 + 0xa0) + 0x10) == 0) {
        if ((*(int *)(param_1 + 100) == local_20) || (*(int *)(param_1 + 100) == local_20 + 1)) {
          *(int *)(param_1 + 100) = local_20;
          *(int *)(param_1 + 0x60) = local_30;
          local_28 = 0;
          for (local_18 = 0; local_18 < *(uint *)(param_1 + 0x114); local_18 = local_18 + 1) {
            local_2c = 0;
            local_48 = *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10 + 0xc);
            MediaFile_SetPosition
                      (*(undefined4 *)(param_1 + 0xa0),
                       *(undefined4 *)(*(int *)(param_1 + 0x124) + local_18 * 0x10));
            while (local_2c < *(uint *)(*(int *)(param_1 + 0x124) + local_18 * 0x10 + 8)) {
              local_4c = *(int *)(*(int *)(param_1 + 0x124) + local_18 * 0x10 + 8) - local_2c;
              if (0x3ff < local_4c) {
                local_4c = 0x400;
              }
              local_4c = local_4c << 3;
              local_54 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),local_50,local_4c);
              if (local_54 != local_4c) {
                (*g_medialib_printf)
                          ("##AVI Demuxer: ERROR--read video index failed, n != to_read##\r\n");
                return 0;
              }
              local_54 = local_54 >> 3;
              local_2c = local_2c + local_54;
              if (local_54 < 0x400) {
                ZeroMemory(local_50 + local_4c,(0x400 - local_54) * 8);
              }
              for (local_14 = 0; local_14 < local_54; local_14 = local_14 + 1) {
                local_1c = str2ulong(auStack_2078 + local_14 * 8);
                local_28 = local_28 + (local_1c & 0x7fffffff);
                local_24 = local_24 + 1;
              }
            }
          }
          if (*(int *)(*(int *)(param_1 + 0xa0) + 0x10) == 0) {
            if ((*(int *)(param_1 + 0x7c) == local_24) || (*(int *)(param_1 + 0x7c) == local_24 + 1)
               ) {
              *(int *)(param_1 + 0x78) = local_28;
              *(int *)(param_1 + 0x7c) = local_24;
              MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa8))
              ;
              *(undefined4 *)(param_1 + 0x88) = 0;
              *(int *)(param_1 + 0xac) = (*(int *)(param_1 + 100) + *(int *)(param_1 + 0x7c)) * 0x10
              ;
              uVar4 = 1;
            }
            else {
              (*g_medialib_printf)
                        (
                        "##AVI Demuxer: WARNING--File is likely to be damaged -- audio_chunks != nai##\r\n"
                        );
              uVar4 = 0;
            }
          }
          else {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read error##\r\n");
            uVar4 = 0;
          }
        }
        else {
          (*g_medialib_printf)
                    (
                    "##AVI Demuxer: WARNING--File is likely to be damaged -- video_frames != nvi##\r\n"
                    );
          uVar4 = 0;
        }
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read error##\r\n");
        uVar4 = 0;
      }
      return uVar4;
    }
    local_2c = 0;
    local_48 = *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10 + 0xc);
    MediaFile_SetPosition
              (*(undefined4 *)(param_1 + 0xa0),
               *(undefined4 *)(*(int *)(param_1 + 0x120) + local_18 * 0x10));
    while (local_2c < *(uint *)(*(int *)(param_1 + 0x120) + local_18 * 0x10 + 8)) {
      local_4c = *(int *)(*(int *)(param_1 + 0x120) + local_18 * 0x10 + 8) - local_2c;
      if (0x3ff < local_4c) {
        local_4c = 0x400;
      }
      local_4c = local_4c << 3;
      local_54 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),local_50,local_4c);
      if (local_54 != local_4c) {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read video index failed, n != to_read##\r\n");
        return 0;
      }
      local_54 = local_54 >> 3;
      local_2c = local_2c + local_54;
      if (local_54 < 0x400) {
        ZeroMemory(local_50 + local_4c,(0x400 - local_54) * 8);
      }
      for (local_14 = 0; local_14 < local_54; local_14 = local_14 + 1) {
        local_1c = str2ulong(auStack_2078 + local_14 * 8);
        if ((int)local_1c < 0) {
          local_1c = local_1c & 0x7fffffff;
        }
        else {
          if ((local_1c != 0) && (local_44 == 0)) {
            if (local_38 == 0x100) {
              iVar1 = (**(code **)(*(int *)(param_1 + 0x108) + 0x14))(8);
              local_34[1] = iVar1;
              if (local_34[1] == 0) {
                (*g_medialib_printf)("##AVI Demuxer: ERROR--malloc key frame node failed##\r\n");
                return 0;
              }
              local_34 = (int *)local_34[1];
              local_34[1] = 0;
              iVar1 = (**(code **)(*(int *)(param_1 + 0x108) + 0x14))(0x800);
              *local_34 = iVar1;
              if (*local_34 == 0) {
                (*g_medialib_printf)("##AVI Demuxer: ERROR--malloc key frame buffer failed##\r\n");
                return 0;
              }
              *(int *)(param_1 + 0xc0) = *local_34;
              local_38 = 0;
              if (local_20 == local_40) {
                local_3c = *(uint *)(param_1 + 0x48) >> 1;
              }
            }
            iVar3 = *(int *)(param_1 + 0xc0);
            iVar1 = local_38 * 8;
            iVar2 = str2ulong(auStack_207c + local_14 * 8);
            *(int *)(iVar3 + iVar1 + 4) = iVar2 + local_48;
            *(int *)(*(int *)(param_1 + 0xc0) + local_38 * 8) = local_20;
            local_30 = local_30 + 1;
            local_38 = local_38 + 1;
            local_44 = local_3c;
          }
          local_40 = local_40 + 1;
          if (local_44 != 0) {
            local_44 = local_44 - 1;
          }
        }
        *(uint *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + local_1c;
        local_20 = local_20 + 1;
      }
    }
    local_18 = local_18 + 1;
  } while( true );
}



undefined4 AVIDemuxer_FillHeaderIndex(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_407c [4];
  undefined1 auStack_4078 [4];
  undefined1 auStack_4074 [4];
  undefined1 auStack_4070 [16372];
  undefined1 auStack_7c [4];
  undefined1 auStack_78 [4];
  uint local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  undefined1 *local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_18 = 0;
  local_1c = 0;
  local_50 = 0;
  local_20 = 0;
  local_54 = 0;
  local_24 = 0;
  local_58 = auStack_407c;
  local_5c = 0x4000;
  local_28 = 0;
  local_60 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = (int *)0x0;
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  local_64 = str2ulong(&DAT_00058390);
  local_68 = 0;
  local_4c = 0;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xb0));
  local_54 = local_5c;
  if (*(uint *)(param_1 + 0xac) < local_5c) {
    local_54 = *(uint *)(param_1 + 0xac);
  }
  uVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),local_58,local_54);
  if (uVar1 == local_54) {
    *(undefined4 *)(param_1 + 0xb4) = 0;
    local_14 = 0;
    while (((local_14 < local_54 >> 4 &&
            (local_68 = str2ulong(auStack_407c + local_14 * 0x10),
            local_68 * 0x100 != *(int *)(param_1 + 0x34))) && (*(int *)(param_1 + 0x38) != local_68)
           )) {
      local_14 = local_14 + 1;
    }
    if (local_14 < local_54 >> 4) {
      local_6c = str2ulong(auStack_4074 + local_14 * 0x10);
      local_70 = str2ulong(auStack_4070 + local_14 * 0x10);
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),local_6c);
      iVar2 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_7c,8);
      if (iVar2 == 8) {
        iVar2 = memcmp(auStack_7c,auStack_407c + local_14 * 0x10,4);
        if ((iVar2 == 0) && (iVar2 = str2ulong(auStack_78), iVar2 == local_70)) {
          *(undefined4 *)(param_1 + 0xb4) = 1;
        }
        else {
          MediaFile_SetPosition
                    (*(undefined4 *)(param_1 + 0xa0),*(int *)(param_1 + 0xa8) + local_6c + -4);
          iVar2 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_7c,8);
          if (iVar2 != 8) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read index failed 2##\r\n");
            return 0;
          }
          iVar2 = memcmp(auStack_7c,auStack_407c + local_14 * 0x10,4);
          if ((iVar2 == 0) && (iVar2 = str2ulong(auStack_78), iVar2 == local_70)) {
            *(undefined4 *)(param_1 + 0xb4) = 2;
          }
        }
        if (*(int *)(param_1 + 0xb4) == 0) {
          (*g_medialib_printf)
                    ("##AVI Demuxer: ERROR--we do NOT support AVI without idx1 chunk##\r\n");
          uVar5 = 0;
        }
        else {
          local_24 = 0;
          if (*(int *)(param_1 + 0xb4) == 1) {
            iVar2 = 8;
          }
          else {
            iVar2 = *(int *)(param_1 + 0xa8) + 4;
          }
          *(int *)(param_1 + 0xb8) = iVar2;
          MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xb0));
          local_28 = 0;
          local_34 = (int *)(param_1 + 0xd4);
          local_60 = ((*(uint *)(param_1 + 0xac) >> 4) + 0x1ff >> 9) << 4;
          iVar2 = memcmp(&DAT_0005820c,(void *)(param_1 + 0x2c),4);
          if (iVar2 == 0) {
            local_44 = *(uint *)(param_1 + 0x48) >> 1;
          }
          local_50 = *(int *)(param_1 + 0xb8);
          while (local_24 < *(uint *)(param_1 + 0xac)) {
            uVar1 = *(int *)(param_1 + 0xac) - local_24;
            local_54 = local_5c;
            if (uVar1 < local_5c) {
              local_54 = uVar1;
            }
            local_74 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),local_58,local_54);
            if (local_74 != local_54) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--read index failed, n != to_read##\r\n");
              return 0;
            }
            local_24 = local_24 + local_74;
            if (local_74 < local_5c) {
              ZeroMemory(local_58 + local_74,local_5c - local_74);
            }
            local_74 = local_74 >> 4;
            for (local_14 = 0; local_14 < local_74; local_14 = local_14 + 1) {
              if ((local_2c < 0x200) &&
                 (local_60 * local_2c < local_28 || local_60 * local_2c - local_28 == 0)) {
                *(uint *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc + 4) =
                     *(int *)(param_1 + 0xb0) + local_28;
                *(int *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc) = local_1c;
                *(uint *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc + 8) = local_20;
                local_2c = local_2c + 1;
              }
              local_28 = local_28 + 0x10;
              local_68 = str2ulong(auStack_407c + local_14 * 0x10);
              if (local_68 * 0x100 == *(int *)(param_1 + 0x34)) {
                local_70 = str2ulong(auStack_4070 + local_14 * 0x10);
                uVar1 = str2ulong(auStack_4078 + local_14 * 0x10);
                if ((uVar1 & 0x10) != 0) {
                  if ((local_70 != 0) && (local_4c == 0)) {
                    if (local_38 == 0x100) {
                      iVar2 = (**(code **)(*(int *)(param_1 + 0x108) + 0x14))(8);
                      local_34[1] = iVar2;
                      if (local_34[1] == 0) {
                        (*g_medialib_printf)
                                  ("##AVI Demuxer: ERROR--malloc key frame node failed##\r\n");
                        return 0;
                      }
                      local_34 = (int *)local_34[1];
                      local_34[1] = 0;
                      iVar2 = (**(code **)(*(int *)(param_1 + 0x108) + 0x14))(0x800);
                      *local_34 = iVar2;
                      if (*local_34 == 0) {
                        (*g_medialib_printf)
                                  ("##AVI Demuxer: ERROR--malloc key frame buffer failed##\r\n");
                        return 0;
                      }
                      *(int *)(param_1 + 0xc0) = *local_34;
                      local_38 = 0;
                      if (local_18 == local_48) {
                        local_44 = *(uint *)(param_1 + 0x48) >> 1;
                      }
                    }
                    iVar4 = *(int *)(param_1 + 0xc0);
                    iVar2 = local_38 * 8;
                    iVar3 = str2ulong(auStack_4074 + local_14 * 0x10);
                    *(int *)(iVar4 + iVar2 + 4) = iVar3 + local_50;
                    *(int *)(*(int *)(param_1 + 0xc0) + local_38 * 8) = local_18;
                    local_30 = local_30 + 1;
                    local_38 = local_38 + 1;
                    local_4c = local_44;
                  }
                  local_48 = local_48 + 1;
                  if (local_4c != 0) {
                    local_4c = local_4c - 1;
                  }
                }
                *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + local_70;
                local_18 = local_18 + 1;
              }
              else if (*(int *)(param_1 + 0x38) == local_68) {
                local_70 = str2ulong(auStack_4070 + local_14 * 0x10);
                local_20 = local_20 + local_70;
                local_1c = local_1c + 1;
              }
              else if (local_68 == local_64) {
                local_3c = local_3c + 1;
              }
              else {
                if (local_40 == 0) {
                  (*g_medialib_printf)("##AVI Demuxer: WARNING--first index error##\r\n");
                }
                local_40 = local_40 + 1;
                if (0x200 < local_40) {
                  (*g_medialib_printf)("##AVI Demuxer: WARNING--index error##\r\n");
                  return 0;
                }
              }
            }
          }
          if ((local_38 != 0x100) && (*(int *)(param_1 + 0xc0) != 0)) {
            ZeroMemory(*(int *)(param_1 + 0xc0) + local_38 * 8,local_38 * -8 + 0x800);
          }
          if (*(int *)(*(int *)(param_1 + 0xa0) + 0x10) == 0) {
            if ((*(int *)(param_1 + 100) == local_18) || (*(int *)(param_1 + 100) == local_18 + 1))
            {
              *(uint *)(param_1 + 0x78) = local_20;
              *(int *)(param_1 + 100) = local_18;
              *(int *)(param_1 + 0x7c) = local_1c;
              *(int *)(param_1 + 0x60) = local_30;
              local_28 = local_28 + *(int *)(param_1 + 0xb0);
              for (; local_2c < 0x200; local_2c = local_2c + 1) {
                *(uint *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc + 4) = local_28;
                *(int *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc) = local_1c;
                *(uint *)(*(int *)(param_1 + 0xc4) + local_2c * 0xc + 8) = local_20;
              }
              MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa8))
              ;
              *(undefined4 *)(param_1 + 0x88) = 0;
              uVar5 = 1;
            }
            else {
              (*g_medialib_printf)
                        (
                        "##AVI Demuxer: WARNING--File is likely to be damaged -- video_frames != nvi##\r\n"
                        );
              if (*(uint *)(param_1 + 0x78) < local_20) {
                *(uint *)(param_1 + 0x78) = local_20;
              }
              *(undefined4 *)(param_1 + 0xac) = 0;
              uVar5 = 1;
            }
          }
          else {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read error##\r\n");
            uVar5 = 0;
          }
        }
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--read index failed##\r\n");
        uVar5 = 0;
      }
    }
    else {
      (*g_medialib_printf)("##AVI Demuxer: ERROR--can\'t find the first video or audio index##\r\n")
      ;
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



undefined4 AVIDemuxer_HeaderHandle(ushort *param_1)

{
  int extraout_r1;
  int extraout_r1_00;
  int iVar1;
  uint uVar2;
  uint local_30;
  undefined1 auStack_2c [4];
  int local_28;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_18 = 0;
  local_1c = 0;
  if (*(int *)(param_1 + 0x32) != 0) {
    MulDiv(param_1 + 0x22,*(int *)(param_1 + 0x34) * 1000,*(undefined4 *)(param_1 + 0x32),
           *(undefined4 *)(param_1 + 0x36));
    (*g_medialib_printf)
              ("##AVI Demuxer: video_scale = %d, audio_scale = %d##\r\n",
               *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x40));
  }
  if (*(int *)(param_1 + 0x56) == 0) {
    *(undefined1 *)((int)param_1 + 0xa7) = 0;
    if (*(int *)(param_1 + 0x32) != 0) {
      param_1[0x30] = 1;
      param_1[0x31] = 0;
    }
  }
  else if (*(uint *)(param_1 + 0x56) >> 4 <
           (uint)(*(int *)(param_1 + 0x32) + *(int *)(param_1 + 0x3e))) {
    (*g_medialib_printf)
              ("##AVI Demuxer: ERROR--File is likely to be damaged -- index err, idx_len = 0x%x, video_frames = %d, audio_chunks = %d##\r\n"
               ,*(undefined4 *)(param_1 + 0x56),*(undefined4 *)(param_1 + 0x32),
               *(undefined4 *)(param_1 + 0x3e));
    return 0;
  }
  if (*(int *)(param_1 + 0x3e) != 0) {
    if (*(int *)(param_1 + 0x40) == 1) {
      uVar2 = (uint)*param_1;
      if (uVar2 == 1) {
        *(uint *)(param_1 + 0x42) = *(int *)(param_1 + 2) * (uint)param_1[1];
        *(uint *)(param_1 + 0x42) = *(int *)(param_1 + 0x42) * (uint)(param_1[7] >> 3);
      }
      else if (((uVar2 != 0) && (uVar2 - 6 < 2)) &&
              (*(int *)(param_1 + 0x3c) == (uint)param_1[6] * *(int *)(param_1 + 0x4e))) {
        *(uint *)(param_1 + 0x42) = *(int *)(param_1 + 0x42) * (uint)param_1[6];
        *(uint *)(param_1 + 0x4e) = *(int *)(param_1 + 0x4e) * (uint)param_1[6];
      }
      MulDiv(param_1 + 0x38,1000,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x42));
    }
    else {
      MulDiv(param_1 + 0x38,*(int *)(param_1 + 0x40) * 1000,*(undefined4 *)(param_1 + 0x4e),
             *(undefined4 *)(param_1 + 0x42));
    }
    iVar1 = *(uint *)(param_1 + 0x38) * 0x10624dd3;
    local_18 = *(uint *)(param_1 + 0x38) / 1000;
    if (*(int *)(param_1 + 0x22) == 0) {
      *(undefined4 *)(param_1 + 0x22) = *(undefined4 *)(param_1 + 0x38);
    }
    else {
      local_1c = *(uint *)(param_1 + 0x22) / 1000;
      if ((local_18 < local_1c - 1) || (local_1c + 1 < local_18)) {
        (*g_medialib_printf)
                  ("##AVI Demuxer: WARNING--audio time (%d) is not equal to video time (%d)##\r\n",
                   local_18,local_1c);
        iVar1 = extraout_r1;
      }
      else {
        (*g_medialib_printf)
                  ("##AVI Demuxer: audio total time is %d seconds; video total time %d seconds##\r\n"
                   ,local_18,local_1c);
        iVar1 = extraout_r1_00;
      }
      if ((*(uint *)(param_1 + 0x22) < *(uint *)(param_1 + 0x38)) &&
         (*(uint *)(param_1 + 0x38) < *(int *)(param_1 + 0x22) + 10000U)) {
        *(undefined4 *)(param_1 + 0x22) = *(undefined4 *)(param_1 + 0x38);
      }
    }
    if (*(char *)((int)param_1 + 0xa7) == '\0') {
      if (*(char *)((int)param_1 + 0x10d) == '\0') {
        if (*(int *)(param_1 + 0x40) == 1) {
          if ((*(int *)(param_1 + 0x4e) != *(int *)(param_1 + 0x3e)) &&
             (*(int *)(param_1 + 0x4e) != *(int *)(param_1 + 0x3c))) {
            (*g_medialib_printf)
                      ("##AVI Demuxer: WARNING--audio data may be damaged, dwAudioLength != audio bytes or audio chunks##\r\n"
                       ,iVar1);
          }
          MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x38),1000,*(undefined4 *)(param_1 + 0x3e)
                );
          (*g_medialib_printf)("##AVI Demuxer: audio in this file is likely to be CBR##\r\n");
        }
        else {
          MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x38),1000,*(undefined4 *)(param_1 + 0x3e)
                );
          (*g_medialib_printf)("##AVI Demuxer: audio in this file is likely to be VBR##\r\n");
        }
      }
      else {
        if (4 < *(uint *)(param_1 + 0x3e)) {
          local_20 = 0;
          AVIDemuxer_GetAudioIndex(param_1,1,auStack_2c);
          local_20 = local_28;
          AVIDemuxer_GetAudioIndex(param_1,*(int *)(param_1 + 0x3e) + -2,auStack_2c);
          if (local_28 == local_20) {
            MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x38),local_20 * 1000,
                   *(undefined4 *)(param_1 + 0x3c));
          }
        }
        if (*(int *)(param_1 + 0x4c) == 0) {
          MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x38),1000,*(undefined4 *)(param_1 + 0x3e)
                );
        }
      }
    }
    else if (*param_1 == 0xff) {
      MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x40),1000000,*(undefined4 *)(param_1 + 0x42))
      ;
    }
    else {
      MulDiv(param_1 + 0x4c,*(undefined4 *)(param_1 + 0x38),1000,*(undefined4 *)(param_1 + 0x3e));
    }
  }
  (*g_medialib_printf)
            ("##AVI Demuxer: dwMicroSecPerFrame = %d, dwMicroSecPerChunk = %d, dwAudioLength is %d##\r\n"
             ,*(undefined4 *)(param_1 + 0x4a),*(undefined4 *)(param_1 + 0x4c),
             *(undefined4 *)(param_1 + 0x4e));
  local_30 = 0;
  local_14 = 0;
  MulDiv(&local_30,*(undefined4 *)(param_1 + 0x34),1000000,*(undefined4 *)(param_1 + 0x36));
  if (*(uint *)(param_1 + 0x4a) < local_30) {
    local_14 = local_30 - *(int *)(param_1 + 0x4a);
  }
  else {
    local_14 = *(int *)(param_1 + 0x4a) - local_30;
  }
  if (1000 < local_14) {
    (*g_medialib_printf)("##AVI Demuxer: WARNING--dwMicroSecPerFrame maybe %d##\r\n",local_30);
    *(uint *)(param_1 + 0x4a) = local_30;
  }
  return 1;
}



undefined4 AVIDemuxer_FillHeader(void *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char local_144;
  char local_143;
  undefined1 local_142;
  undefined1 local_141;
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [4];
  undefined1 auStack_138 [248];
  byte *local_40;
  uint local_3c;
  undefined1 *local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  short local_1c;
  char local_1a;
  char local_19;
  uint local_18;
  uint local_14;
  
  local_18 = 0;
  local_1a = '\0';
  local_1c = 0;
  local_1d = '\0';
  local_1e = '\0';
  local_1f = '\0';
  local_20 = '\0';
  local_2c = 0;
  local_30 = 0;
  if (*(int *)((int)param_1 + 0xa0) == 0) {
    uVar3 = 0;
  }
  else {
    local_28 = 0;
    local_38 = (undefined1 *)0x0;
    local_19 = '\0';
    local_24 = 0;
    MediaFile_SetPosition(*(undefined4 *)((int)param_1 + 0xa0),0);
    iVar1 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),auStack_140,0xc);
    if (iVar1 == 0xc) {
      iVar1 = memcmp(auStack_140,&DAT_000587d0,4);
      if (((iVar1 == 0) || (iVar1 = memcmp(auStack_140,&DAT_000587d8,4), iVar1 == 0)) &&
         ((iVar1 = memcmp(auStack_138,&DAT_000587e0,4), iVar1 == 0 ||
          (iVar1 = memcmp(auStack_138,&DAT_000587d8,4), iVar1 == 0)))) {
        iVar1 = MediaFile_GetTotalLen(*(undefined4 *)((int)param_1 + 0xa0));
        if (iVar1 == -1) {
          iVar4 = *(int *)((int)param_1 + 0xa0);
          iVar1 = str2ulong(auStack_13c);
          *(int *)(iVar4 + 4) = iVar1 + 8;
        }
        while (iVar1 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),auStack_140,8),
              iVar1 == 8) {
          iVar1 = str2ulong(auStack_13c);
          local_3c = iVar1 + 1U & 0xfffffffe;
          iVar1 = MediaFile_GetPosition(*(undefined4 *)((int)param_1 + 0xa0));
          if (iVar1 + local_3c < local_3c) {
            if (*(int *)((int)param_1 + 0xac) == 0) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--length of chunk is too large##\r\n");
              (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
              return 0;
            }
            break;
          }
          uVar2 = str2ulong(auStack_140);
          if (uVar2 == 0x46464952) {
            if ((local_3c < 0xc) ||
               (iVar1 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),auStack_140,0xc),
               iVar1 != 0xc)) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--Fill header, Read RIFF error##\r\n");
              (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
              return 0;
            }
            iVar1 = memcmp(auStack_140,&DAT_00058a48,4);
            if ((iVar1 == 0) && (iVar1 = str2ulong(auStack_138), iVar1 + 0xcU == local_3c)) {
              uVar5 = *(undefined4 *)((int)param_1 + 0xa0);
              uVar3 = str2ulong(auStack_138);
              MediaFile_ChangePosition(uVar5,uVar3);
              local_30 = MediaFile_GetPosition(*(undefined4 *)((int)param_1 + 0xa0));
            }
            else {
              MediaFile_ChangePosition(*(undefined4 *)((int)param_1 + 0xa0),local_3c - 0xc);
            }
          }
          else if (uVar2 < 0x46464953) {
            if (uVar2 == 0x31786469) {
              local_24 = 0;
              *(undefined4 *)((int)param_1 + 0xb0) =
                   *(undefined4 *)(*(int *)((int)param_1 + 0xa0) + 8);
              *(uint *)((int)param_1 + 0xac) = local_3c;
              MediaFile_SetPosition
                        (*(undefined4 *)((int)param_1 + 0xa0),
                         *(int *)((int)param_1 + 0xb0) + *(int *)((int)param_1 + 0xac));
              local_30 = MediaFile_GetPosition(*(undefined4 *)((int)param_1 + 0xa0));
            }
            else {
LAB_00025400:
              MediaFile_ChangePosition(*(undefined4 *)((int)param_1 + 0xa0),local_3c);
              local_24 = local_24 + local_3c;
              if (0x1000 < local_24) {
                if ((*(int *)((int)param_1 + 0xac) == 0) && (*(int *)((int)param_1 + 0xa8) == 0)) {
                  (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
                  (*g_medialib_printf)
                            (
                            "##AVI Demuxer: ERROR--file corruption, this file is altered by somebody!##\r\n"
                            );
                  return 0;
                }
                (*g_medialib_printf)
                          (
                          "##AVI Demuxer: WARNING--file corruption, this file is altered by somebody!##\r\n"
                          );
              }
            }
          }
          else if (uVar2 == 0x4b4e554a) {
            MediaFile_ChangePosition(*(undefined4 *)((int)param_1 + 0xa0),local_3c);
          }
          else {
            if (uVar2 != 0x5453494c) goto LAB_00025400;
            local_24 = 0;
            iVar1 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),auStack_140,4);
            if (iVar1 != 4) {
              (*g_medialib_printf)
                        ("##AVI Demuxer: ERROR--Fill header, Read(aviFile, data, 4) != 4##\r\n");
              (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
              return 0;
            }
            local_3c = local_3c - 4;
            iVar1 = memcmp(auStack_140,&DAT_00058864,4);
            if (iVar1 == 0) {
              local_18 = local_3c;
              if (local_28 != 0) {
                (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
              }
              local_28 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))(local_3c);
              if (local_28 == 0) {
                (*g_medialib_printf)("##AVI Demuxer: ERROR--Fill header, hdrl_data is NULL##\r\n");
                return 0;
              }
              uVar2 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),local_28,local_3c);
              if (uVar2 != local_3c) {
                (*g_medialib_printf)
                          (
                          "##AVI Demuxer: ERROR--Fill header, MediaFile_Read(aviDemuxer->->aviFile, hdrl_data, n) != n##\r\n"
                          );
                (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
                return 0;
              }
            }
            else {
              iVar1 = memcmp(auStack_140,&DAT_00058908,4);
              if (iVar1 == 0) {
                uVar3 = MediaFile_GetPosition(*(undefined4 *)((int)param_1 + 0xa0));
                *(undefined4 *)((int)param_1 + 0xa8) = uVar3;
                MediaFile_ChangePosition(*(undefined4 *)((int)param_1 + 0xa0),local_3c);
              }
              else {
                iVar1 = memcmp(auStack_140,&DAT_00058910,4);
                if ((iVar1 == 0) && (local_3c < 0x21)) {
                  local_38 = auStack_140;
                  uVar2 = MediaFile_Read(*(undefined4 *)((int)param_1 + 0xa0),local_38,local_3c);
                  if (uVar2 != local_3c) {
                    (*g_medialib_printf)
                              (
                              "##AVI Demuxer: ERROR--Fill header, MediaFile_Read(aviDemuxer->->aviFile, datai, n) != n##\r\n"
                              );
                    (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
                    return 0;
                  }
                  iVar1 = memcmp(local_38,&DAT_00058974,4);
                  if (iVar1 == 0) {
                    iVar1 = memcmp(local_38 + 8,"ankarec ",8);
                    if (iVar1 == 0) {
                      (*g_medialib_printf)
                                (
                                "##AVI Demuxer: The avi file is recorded by the library itself##\r\n"
                                );
                      *(undefined1 *)((int)param_1 + 0xa7) = 1;
                      local_19 = '\x01';
                    }
                    else {
                      iVar1 = memcmp(local_38 + 8,"D-1.2.2",6);
                      if (iVar1 == 0) {
                        (*g_medialib_printf)
                                  ("##AVI Demuxer: The avi file is converted by mp4 tool##\r\n");
                        local_19 = '\x01';
                      }
                    }
                  }
                }
                else {
                  MediaFile_ChangePosition(*(undefined4 *)((int)param_1 + 0xa0),local_3c);
                }
              }
            }
            local_30 = MediaFile_GetPosition(*(undefined4 *)((int)param_1 + 0xa0));
          }
        }
        if (local_28 == 0) {
          (*g_medialib_printf)("##AVI Demuxer: ERROR-hdrl_data is NULL##\r\n");
          uVar3 = 0;
        }
        else if (*(int *)(*(int *)((int)param_1 + 0xa0) + 0x10) == 0) {
          if (*(int *)((int)param_1 + 0xa8) == 0) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--!movi_start##\r\n");
            (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
            uVar3 = 0;
          }
          else if ((*(char *)((int)param_1 + 0xa6) == '\0') || (local_19 != '\0')) {
            if (*(int *)(*(int *)((int)param_1 + 0xa0) + 4) != local_30) {
              *(int *)(*(int *)((int)param_1 + 0xa0) + 4) = local_30;
              (*g_medialib_printf)
                        ("##AVI Demuxer: file length changed to 0x%x##\r\n",
                         *(undefined4 *)(*(int *)((int)param_1 + 0xa0) + 4));
            }
            local_14 = 0;
            while (local_14 < local_18) {
              iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058bc8,4);
              if (iVar1 == 0) {
                local_14 = local_14 + 0xc;
              }
              else {
                iVar1 = str2ulong(local_28 + local_14 + 4);
                local_3c = iVar1 + 1U & 0xfffffffe;
                iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058bd0,4);
                if (iVar1 == 0) {
                  local_14 = local_14 + 8;
                  uVar3 = str2ulong(local_28 + local_14);
                  *(undefined4 *)((int)param_1 + 0x94) = uVar3;
                }
                else {
                  iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058bd8,4);
                  if (iVar1 == 0) {
                    local_14 = local_14 + 8;
                    iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058be0,4);
                    if ((iVar1 == 0) && (local_1d == '\0')) {
                      memcpy((void *)((int)param_1 + 0x2c),(void *)(local_28 + local_14 + 4),4);
                      if ((0x60 < *(byte *)((int)param_1 + 0x2c)) &&
                         (*(byte *)((int)param_1 + 0x2c) < 0x7b)) {
                        *(char *)((int)param_1 + 0x2c) = *(char *)((int)param_1 + 0x2c) + -0x20;
                      }
                      if ((0x60 < *(byte *)((int)param_1 + 0x2d)) &&
                         (*(byte *)((int)param_1 + 0x2d) < 0x7b)) {
                        *(char *)((int)param_1 + 0x2d) = *(char *)((int)param_1 + 0x2d) + -0x20;
                      }
                      if ((0x60 < *(byte *)((int)param_1 + 0x2e)) &&
                         (*(byte *)((int)param_1 + 0x2e) < 0x7b)) {
                        *(char *)((int)param_1 + 0x2e) = *(char *)((int)param_1 + 0x2e) + -0x20;
                      }
                      if ((0x60 < *(byte *)((int)param_1 + 0x2f)) &&
                         (*(byte *)((int)param_1 + 0x2f) < 0x7b)) {
                        *(char *)((int)param_1 + 0x2f) = *(char *)((int)param_1 + 0x2f) + -0x20;
                      }
                      uVar3 = str2ulong(local_28 + local_14 + 0x14);
                      *(undefined4 *)((int)param_1 + 0x68) = uVar3;
                      uVar3 = str2ulong(local_28 + local_14 + 0x18);
                      *(undefined4 *)((int)param_1 + 0x6c) = uVar3;
                      if (*(int *)((int)param_1 + 0x68) != 0) {
                        uVar3 = __aeabi_uidiv(*(int *)((int)param_1 + 0x6c) +
                                              (*(uint *)((int)param_1 + 0x68) >> 1),
                                              *(undefined4 *)((int)param_1 + 0x68));
                        *(undefined4 *)((int)param_1 + 0x48) = uVar3;
                      }
                      uVar3 = str2ulong(local_28 + local_14 + 0x20);
                      *(undefined4 *)((int)param_1 + 100) = uVar3;
                      *(int *)((int)param_1 + 0x54) = (int)local_1c;
                      local_1d = '\x01';
                      local_1a = '\x01';
                    }
                    else {
                      iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058be8,4);
                      if ((iVar1 == 0) && (local_1f == '\0')) {
                        uVar3 = str2ulong(local_28 + local_14 + 0x20);
                        *(undefined4 *)((int)param_1 + 0x78) = uVar3;
                        *(undefined4 *)((int)param_1 + 0x9c) = *(undefined4 *)((int)param_1 + 0x78);
                        *(int *)((int)param_1 + 0x74) = (int)local_1c;
                        uVar3 = str2ulong(local_28 + local_14 + 0x14);
                        *(undefined4 *)((int)param_1 + 0x80) = uVar3;
                        uVar3 = str2ulong(local_28 + local_14 + 0x18);
                        *(undefined4 *)((int)param_1 + 0x84) = uVar3;
                        if (*(int *)((int)param_1 + 0x84) == 0) {
                          (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
                          (*g_medialib_printf)("##AVI Demuxer: ERROR--audio rate is zero##\r\n");
                          return 0;
                        }
                        local_1f = '\x01';
                        local_1a = '\x02';
                      }
                      else {
                        local_1a = '\0';
                      }
                    }
                    local_1c = local_1c + 1;
                  }
                  else {
                    iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058c20,4);
                    if (iVar1 == 0) {
                      iVar1 = local_14 + 8;
                      if (local_1a == '\x01') {
                        local_40 = (byte *)((int)param_1 + 0x30);
                        iVar4 = local_14 + 0x18;
                        local_14 = iVar1;
                        memcpy(local_40,(void *)(local_28 + iVar4),4);
                        if ((0x60 < *local_40) && (*local_40 < 0x7b)) {
                          *local_40 = *local_40 - 0x20;
                        }
                        if ((0x60 < local_40[1]) && (local_40[1] < 0x7b)) {
                          local_40[1] = local_40[1] - 0x20;
                        }
                        if ((0x60 < local_40[2]) && (local_40[2] < 0x7b)) {
                          local_40[2] = local_40[2] - 0x20;
                        }
                        if ((0x60 < local_40[3]) && (local_40[3] < 0x7b)) {
                          local_40[3] = local_40[3] - 0x20;
                        }
                        uVar3 = str2ulong(local_28 + local_14 + 4);
                        *(undefined4 *)((int)param_1 + 0x4c) = uVar3;
                        uVar3 = str2ulong(local_28 + local_14 + 8);
                        *(undefined4 *)((int)param_1 + 0x50) = uVar3;
                        if ((0x28 < local_3c) &&
                           (iVar1 = memcmp(local_40,&DAT_00058c28,4), iVar1 == 0)) {
                          *(uint *)((int)param_1 + 0x28) = local_3c - 0x28;
                          uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))
                                            (*(undefined4 *)((int)param_1 + 0x28));
                          *(undefined4 *)((int)param_1 + 0x24) = uVar3;
                          if (*(int *)((int)param_1 + 0x24) == 0) {
                            (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
                            (*g_medialib_printf)("##AVI Demuxer: ERROR--p_vheader_data NULL##\r\n");
                            return 0;
                          }
                          memcpy(*(void **)((int)param_1 + 0x24),
                                 (void *)(local_28 + local_14 + 0x28),
                                 *(size_t *)((int)param_1 + 0x28));
                        }
                        local_1e = '\x01';
                      }
                      else {
                        local_14 = iVar1;
                        if (local_1a == '\x02') {
                          memcpy(param_1,(void *)(local_28 + iVar1),0x24);
                          local_2c = str2ushort(local_28 + local_14 + 2);
                          if (*(short *)((int)param_1 + 0x10) != 0) {
                            if (0x18 < *(ushort *)((int)param_1 + 0x10)) {
                              *(undefined2 *)((int)param_1 + 0x10) = 0x18;
                            }
                            memcpy((void *)((int)param_1 + 0xf0),
                                   (void *)(local_28 + local_14 + 0x12),
                                   (uint)*(ushort *)((int)param_1 + 0x10));
                          }
                          local_20 = '\x01';
                        }
                      }
                      local_1a = '\0';
                    }
                    else {
                      iVar1 = memcmp((void *)(local_28 + local_14),&DAT_00058c60,4);
                      if (((iVar1 == 0) && (iVar1 = str2ushort(local_28 + local_14 + 8), iVar1 == 4)
                          ) && (iVar1 = str2ushort(local_28 + local_14 + 10), iVar1 == 0)) {
                        iVar1 = local_14 + 0x24;
                        local_14 = local_14 + 8;
                        iVar1 = str2ulong(local_28 + iVar1);
                        if (iVar1 == 0) {
                          if ((*(char *)(local_28 + local_14 + 10) == 'd') &&
                             (*(int *)((int)param_1 + 0x120) == 0)) {
                            uVar3 = str2ulong(local_28 + local_14 + 4);
                            *(undefined4 *)((int)param_1 + 0x110) = uVar3;
                            uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))
                                              (*(int *)((int)param_1 + 0x110) << 4);
                            *(undefined4 *)((int)param_1 + 0x120) = uVar3;
                            if (*(int *)((int)param_1 + 0x120) != 0) {
                              *(undefined1 *)((int)param_1 + 0x10d) = 1;
                              for (local_34 = 0; local_34 < *(uint *)((int)param_1 + 0x110);
                                  local_34 = local_34 + 1) {
                                iVar1 = str2ulong(local_28 + local_34 * 0x10 + local_14 + 0x1c);
                                if (iVar1 != 0) {
                                  (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))
                                            (*(undefined4 *)((int)param_1 + 0x120));
                                  *(undefined4 *)((int)param_1 + 0x120) = 0;
                                  *(undefined1 *)((int)param_1 + 0x10d) = 0;
                                  break;
                                }
                                iVar4 = *(int *)((int)param_1 + 0x120);
                                iVar1 = local_34 * 0x10;
                                uVar3 = str2ulong(local_28 + local_34 * 0x10 + local_14 + 0x18);
                                *(undefined4 *)(iVar4 + iVar1) = uVar3;
                              }
                            }
                          }
                          else if ((*(char *)(local_28 + local_14 + 10) == 'w') &&
                                  (*(int *)((int)param_1 + 0x124) == 0)) {
                            uVar3 = str2ulong(local_28 + local_14 + 4);
                            *(undefined4 *)((int)param_1 + 0x114) = uVar3;
                            uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))
                                              (*(int *)((int)param_1 + 0x114) << 4);
                            *(undefined4 *)((int)param_1 + 0x124) = uVar3;
                            if (*(int *)((int)param_1 + 0x124) != 0) {
                              *(undefined1 *)((int)param_1 + 0x10d) = 1;
                              for (local_34 = 0; local_34 < *(uint *)((int)param_1 + 0x114);
                                  local_34 = local_34 + 1) {
                                iVar1 = str2ulong(local_28 + local_34 * 0x10 + local_14 + 0x1c);
                                if (iVar1 != 0) {
                                  (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))
                                            (*(undefined4 *)((int)param_1 + 0x124));
                                  *(undefined4 *)((int)param_1 + 0x124) = 0;
                                  *(undefined1 *)((int)param_1 + 0x10d) = 0;
                                  break;
                                }
                                iVar4 = *(int *)((int)param_1 + 0x124);
                                iVar1 = local_34 * 0x10;
                                uVar3 = str2ulong(local_28 + local_34 * 0x10 + local_14 + 0x18);
                                *(undefined4 *)(iVar4 + iVar1) = uVar3;
                              }
                            }
                          }
                        }
                        else {
                          *(undefined1 *)((int)param_1 + 0x10d) = 0;
                        }
                      }
                      else {
                        local_14 = local_14 + 8;
                        local_1a = '\0';
                      }
                    }
                  }
                }
                local_14 = local_14 + local_3c;
              }
            }
            (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
            local_28 = 0;
            if ((((local_1d == '\0') || (local_1e == '\0')) || (*(int *)((int)param_1 + 100) == 0))
               && (((local_1f == '\0' || (local_20 == '\0')) || (*(int *)((int)param_1 + 0x78) == 0)
                   ))) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--no video and no audio##\r\n");
              uVar3 = 0;
            }
            else {
              if (*(int *)((int)param_1 + 100) != 0) {
                local_144 = (char)(*(int *)((int)param_1 + 0x54) / 10) + '0';
                local_143 = (char)*(int *)((int)param_1 + 0x54) +
                            (char)(*(int *)((int)param_1 + 0x54) / 10) * -10 + '0';
                local_142 = 100;
                local_141 = 0x62;
                uVar3 = str2ulong(&local_144);
                *(undefined4 *)((int)param_1 + 0x34) = uVar3;
                *(int *)((int)param_1 + 0x34) = *(int *)((int)param_1 + 0x34) << 8;
              }
              if (local_2c == 0) {
                *(undefined4 *)((int)param_1 + 0x74) = 99;
              }
              if (*(int *)((int)param_1 + 0x78) != 0) {
                local_144 = (char)(*(int *)((int)param_1 + 0x74) / 10) + '0';
                local_143 = (char)*(int *)((int)param_1 + 0x74) +
                            (char)(*(int *)((int)param_1 + 0x74) / 10) * -10 + '0';
                local_142 = 0x77;
                local_141 = 0x62;
                *(undefined4 *)((int)param_1 + 0x7c) = 1;
                uVar3 = str2ulong(&local_144);
                *(undefined4 *)((int)param_1 + 0x38) = uVar3;
              }
              MediaFile_SetPosition
                        (*(undefined4 *)((int)param_1 + 0xa0),*(undefined4 *)((int)param_1 + 0xa8));
              if (*(char *)((int)param_1 + 0x10d) != '\0') {
                if (((*(int *)((int)param_1 + 100) == 0) || (*(int *)((int)param_1 + 0x120) != 0))
                   && ((*(int *)((int)param_1 + 0x7c) == 0 || (*(int *)((int)param_1 + 0x124) != 0))
                      )) {
                  uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))(0x800);
                  *(undefined4 *)((int)param_1 + 0xd4) = uVar3;
                  if (*(int *)((int)param_1 + 0xd4) == 0) {
                    (*g_medialib_printf)
                              (
                              "##AVI Demuxer: WARNING--Fill header, malloc key frame buffer failed##\r\n"
                              );
                    *(undefined4 *)((int)param_1 + 0xac) = 0;
                    *(undefined1 *)((int)param_1 + 0x10d) = 0;
                  }
                  else {
                    ZeroMemory(*(undefined4 *)((int)param_1 + 0xd4),0x800);
                    *(undefined4 *)((int)param_1 + 0xc0) = *(undefined4 *)((int)param_1 + 0xd4);
                    iVar1 = AVIDemuxer_FillODMLIndex(param_1);
                    if (iVar1 == 0) {
                      *(undefined4 *)((int)param_1 + 0xac) = 0;
                      *(undefined1 *)((int)param_1 + 0x10d) = 0;
                      (*g_medialib_printf)("##AVI Demuxer: WARNING--odmlidx_len is 0##\r\n");
                    }
                  }
                  uVar3 = AVIDemuxer_HeaderHandle(param_1);
                  return uVar3;
                }
                if (*(int *)((int)param_1 + 0xac) == 0) {
                  (*g_medialib_printf)("##AVI Demuxer: WARNING--we do NOT support such index##\r\n")
                  ;
                  *(undefined4 *)((int)param_1 + 0xac) = 0;
                  *(undefined1 *)((int)param_1 + 0x10d) = 0;
                  uVar3 = AVIDemuxer_HeaderHandle(param_1);
                  return uVar3;
                }
                (*g_medialib_printf)("##AVI Demuxer: WARNING--odml has idx1##\r\n");
                *(undefined1 *)((int)param_1 + 0x10d) = 0;
              }
              if ((param_2 != 0) && (*(int *)((int)param_1 + 0xac) != 0)) {
                uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))(0x1800);
                *(undefined4 *)((int)param_1 + 0xc4) = uVar3;
                uVar3 = (**(code **)(*(int *)((int)param_1 + 0x108) + 0x14))(0x800);
                *(undefined4 *)((int)param_1 + 0xd4) = uVar3;
                if ((*(int *)((int)param_1 + 0xc4) == 0) || (*(int *)((int)param_1 + 0xd4) == 0)) {
                  (*g_medialib_printf)
                            (
                            "##AVI Demuxer: WARNING--Fill header, malloc index_pos or key frame buffer failed##\r\n"
                            );
                  (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))
                            (*(undefined4 *)((int)param_1 + 0xc4));
                  (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))
                            (*(undefined4 *)((int)param_1 + 0xd4));
                  *(undefined4 *)((int)param_1 + 0xd4) = 0;
                  *(undefined4 *)((int)param_1 + 0xc4) = 0;
                  *(undefined4 *)((int)param_1 + 0xac) = 0;
                }
                else {
                  ZeroMemory(*(undefined4 *)((int)param_1 + 0xd4),0x800);
                  *(undefined4 *)((int)param_1 + 0xc0) = *(undefined4 *)((int)param_1 + 0xd4);
                }
              }
              if ((param_2 == 0) || (*(int *)((int)param_1 + 0xac) == 0)) {
                *(undefined4 *)((int)param_1 + 0xac) = 0;
                (*g_medialib_printf)("##AVI Demuxer: WARNING--idx_len is 0##\r\n");
                uVar3 = AVIDemuxer_HeaderHandle(param_1);
              }
              else {
                iVar1 = AVIDemuxer_FillHeaderIndex(param_1);
                if (iVar1 == 0) {
                  *(undefined4 *)((int)param_1 + 0xac) = 0;
                  (*g_medialib_printf)("##AVI Demuxer: WARNING--Fill index failed##\r\n");
                }
                uVar3 = AVIDemuxer_HeaderHandle(param_1);
              }
            }
          }
          else {
            (*g_medialib_printf)
                      (
                      "##AVI Demuxer: ERROR--It\'s not valid AVI file, please convert it with mp4 tool!##\r\n"
                      );
            (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
            uVar3 = 0;
          }
        }
        else {
          (**(code **)(*(int *)((int)param_1 + 0x108) + 0x18))(local_28);
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



int AVIDemuxer_GetSize(int param_1,int param_2,ushort param_3)

{
  int iVar1;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  do {
    MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0xa0),local_14);
    if ((*(uint *)(param_1 + 0xa8) < *(uint *)(param_1 + 0xb0)) &&
       (*(int *)(param_1 + 0xb0) - 8U <= *(uint *)(*(int *)(param_1 + 0xa0) + 8))) {
      return -1;
    }
    iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),auStack_30,8);
    if (iVar1 != 8) {
      return -1;
    }
    local_1c = str2ulong(auStack_30);
    if (local_1c == 0x5453494c) {
      local_14 = 4;
    }
    else {
      local_18 = str2ulong(auStack_2c);
      if (((local_1c == 0x63643030) || (local_1c == 0x62773130)) && (-1 < local_18)) {
        local_14 = local_18 + 1U & 0xfffffffe;
      }
      else {
        local_20 = *(uint *)(*(int *)(param_1 + 0xa0) + 8);
        (*g_medialib_printf)
                  ("##AVI Demuxer: GetSize WARN--data invalid, filepos(0x%x)##\r\n",local_20);
        do {
          local_24 = AVIDemuxer_SeekNextKeyframe(param_1);
          if (*(uint *)(param_1 + 0xdc) < local_20) {
            *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
          }
        } while ((*(uint *)(param_1 + 0xdc) < local_20) &&
                (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100)));
        local_28 = AVIDemuxer_GetVideoPts(param_1,*(undefined4 *)(param_1 + 0x88));
        MulDiv(param_1 + 0x8c,local_28,1000,*(undefined4 *)(param_1 + 0x98));
        local_14 = *(int *)(param_1 + 0xdc) - local_20;
        if ((int)local_14 < 8) {
          return -1;
        }
      }
    }
    if (local_1c << (param_3 & 0xff) == param_2) {
      return local_18;
    }
  } while( true );
}



bool AVIDemuxer_GetData(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0xa0),param_2,param_3);
  return iVar1 == param_3;
}



int AVIDemuxer_Init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[5])(0x128);
  if (iVar1 == 0) {
    if (*param_1 != 0) {
      (*(code *)*param_1)("##AVI Demuxer: ERROR--Init return FALSE, malloc demuxer failed##\r\n");
    }
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x128);
    *(int **)(iVar1 + 0x108) = param_1;
    *(undefined1 *)(iVar1 + 0xa6) = 0;
    *(undefined4 *)(iVar1 + 0xd8) = 0;
    *(undefined4 *)(iVar1 + 0xe4) = 0;
  }
  return iVar1;
}



undefined4 AVIDemuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    AVIDemuxer_Close(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 AVIDemuxer_Open(ushort *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  ushort *local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  ushort *local_1c;
  int local_18;
  int local_14;
  
  local_1c = param_1;
  if (*(int *)(param_1 + 0x50) != 0) {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--AVI demxer has been opened already##\r\n");
    return 0;
  }
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 4);
  iVar2 = AVIDemuxer_FillHeader(param_1,1);
  if (iVar2 == 0) {
    AVIDemuxer_Close(local_1c);
    (*g_medialib_printf)("##AVI Demuxer: ERROR--Fill header failed##\r\n");
    return 0;
  }
  if ((*(int *)(local_1c + 0x3e) == 0) && (*(int *)(local_1c + 0x32) == 0)) {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--no audio and no video, error avi file##\r\n");
    AVIDemuxer_Close(local_1c);
    return 0;
  }
  if (*(int *)(local_1c + 0x3e) != 0) {
    *(undefined1 *)((int)local_1c + 0xa5) = 1;
    uVar1 = *local_1c;
    if (uVar1 == 0x11) {
      local_1c[0x20] = 7;
      local_1c[0x21] = 0;
    }
    else if (uVar1 < 0x12) {
      if (uVar1 == 2) {
        local_1c[0x20] = 8;
        local_1c[0x21] = 0;
      }
      else if (uVar1 < 3) {
        if (uVar1 == 1) {
          local_1c[0x20] = 6;
          local_1c[0x21] = 0;
        }
        else {
LAB_00026e60:
          iVar2 = memcmp(local_1c + 0x16,&DAT_000587d8,4);
          if (iVar2 == 0) {
            local_1c[0x20] = 2;
            local_1c[0x21] = 0;
          }
          else {
            (*g_medialib_printf)("##AVI Demuxer: WARNING--UNKNOWN audio type, disable audio##\r\n");
            *(undefined1 *)((int)local_1c + 0xa5) = 0;
            local_1c[0x20] = 0;
            local_1c[0x21] = 0;
          }
        }
      }
      else if (uVar1 == 6) {
        local_1c[0x20] = 0x11;
        local_1c[0x21] = 0;
      }
      else {
        if (uVar1 != 7) goto LAB_00026e60;
        local_1c[0x20] = 0x12;
        local_1c[0x21] = 0;
      }
    }
    else if (uVar1 == 0xff) {
      local_1c[0x20] = 4;
      local_1c[0x21] = 0;
    }
    else if (uVar1 < 0x100) {
      if (uVar1 == 0x50) {
        local_1c[0x20] = 2;
        local_1c[0x21] = 0;
      }
      else {
        if (uVar1 != 0x55) goto LAB_00026e60;
        local_1c[0x20] = 2;
        local_1c[0x21] = 0;
      }
    }
    else if (uVar1 == 0x2000) {
      local_1c[0x20] = 0x10;
      local_1c[0x21] = 0;
    }
    else {
      if (uVar1 != 0x5169) goto LAB_00026e60;
      local_1c[0x20] = 2;
      local_1c[0x21] = 0;
    }
    if (*(int *)(local_1c + 0x20) == 2) {
      local_14 = 4;
      local_20 = 0;
      local_18 = 3;
      AVIDemuxer_SeekAudio(param_1,0);
      MediaFile_SetPosition(*(undefined4 *)(local_1c + 0x50),*(undefined4 *)(local_1c + 0x70));
      local_20 = AVIDemuxer_GetSize(local_1c,*(undefined4 *)(local_1c + 0x1c),0);
      iVar2 = local_14;
      do {
        local_14 = iVar2;
        iVar2 = AVIDemuxer_GetData(param_1,&local_30,4);
        if (iVar2 == 0) {
          (*g_medialib_printf)
                    ("##AVI Demuxer: ERROR--read audio header failed when checking audio##\r\n");
          return 0;
        }
        local_18 = local_18 + 4;
        local_14 = check_mp3layer(&local_30);
      } while ((local_14 == 4) && (iVar2 = 4, local_18 < local_20));
      if (local_18 <= local_20) {
        if (local_14 == 6) {
          local_30 = local_2e;
          local_2f = local_2d;
          (*g_medialib_printf)("##AVI Demuxer: 2 zeros##\r\n");
          iVar2 = AVIDemuxer_GetData(param_1,&local_2e,2);
          if (iVar2 == 0) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read audio header failed 6##\r\n");
            return 0;
          }
          local_14 = check_mp3layer(&local_30);
        }
        else if (local_14 == 7) {
          local_30 = local_2f;
          local_2f = local_2e;
          local_2e = local_2d;
          (*g_medialib_printf)("##AVI Demuxer: 1 zeros##\r\n");
          iVar2 = AVIDemuxer_GetData(param_1,&local_2d,1);
          if (iVar2 == 0) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read audio header failed 7##\r\n");
            return 0;
          }
          local_14 = check_mp3layer(&local_30);
        }
        else if (local_14 == 5) {
          local_30 = local_2d;
          (*g_medialib_printf)("##AVI Demuxer: 3 zeros##\r\n");
          iVar2 = AVIDemuxer_GetData(param_1,&local_2f,3);
          if (iVar2 == 0) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--read audio header failed 5##\r\n");
            return 0;
          }
          local_14 = check_mp3layer(&local_30);
        }
        if (local_14 == 2) {
          local_1c[0x20] = 2;
          local_1c[0x21] = 0;
          (*g_medialib_printf)("##AVI Demuxer: MP3 layer 2 ##\r\n");
        }
        else if (local_14 == 3) {
          local_1c[0x20] = 2;
          local_1c[0x21] = 0;
          (*g_medialib_printf)("##AVI Demuxer: MP3 layer 3 ##\r\n");
        }
        else if (local_14 == 1) {
          local_1c[0x20] = 2;
          local_1c[0x21] = 0;
          (*g_medialib_printf)("##AVI Demuxer: MP3 layer 1 ##\r\n");
        }
        else {
          (*g_medialib_printf)
                    (
                    "##AVI Demuxer: WARNING--check_mp3layer failed, maybe not support this audio##\r\n"
                    );
        }
        uVar3 = mov_str2ulong(&local_30);
        uVar3 = get_mp3samplerate(uVar3);
        *(undefined4 *)(local_1c + 2) = uVar3;
      }
    }
    else if ((*(int *)(local_1c + 0x20) == 4) && (local_1c[8] != 0)) {
      local_28 = 0;
      local_24 = ((byte)local_1c[0x78] & 7) << 1 | (uint)(*(byte *)((int)local_1c + 0xf1) >> 7);
      local_24 = get_aacsamplerate(local_24);
      local_28 = *(byte *)((int)local_1c + 0xf1) >> 3 & 0xf;
      if ((*(int *)(local_1c + 2) != local_24) && (local_24 != 0)) {
        (*g_medialib_printf)("##AVI Demuxer: WARNING--samplerate is different!##\r\n");
        *(uint *)(local_1c + 2) = local_24;
      }
      if (((local_28 & 0xffff) != (uint)local_1c[1]) && (local_28 != 0)) {
        (*g_medialib_printf)("##AVI Demuxer: WARNING--channels is different!##\r\n");
        local_1c[1] = (ushort)local_28;
      }
    }
  }
  if (*(int *)(local_1c + 0x32) == 0) goto LAB_000276e0;
  local_2c = local_1c + 0x16;
  *(undefined1 *)(local_1c + 0x52) = 1;
  if ((*(int *)(local_1c + 0x24) == 0) &&
     (MulDiv(local_1c + 0x24,*(undefined4 *)(local_1c + 0x32),1000,*(undefined4 *)(local_1c + 0x22))
     , *(int *)(local_1c + 0x24) == 0)) {
    local_1c[0x24] = 1;
    local_1c[0x25] = 0;
    (*g_medialib_printf)("##AVI Demuxer: WARNING--fps is zero, change it to 1##\r\n");
  }
  iVar2 = memcmp((void *)((int)local_2c + 1),&DAT_00059238,3);
  if (iVar2 == 0) {
    local_1c[0x1e] = 1;
    local_1c[0x1f] = 0;
    goto LAB_000276e0;
  }
  iVar2 = memcmp((void *)((int)local_2c + 1),&DAT_0005923c,3);
  if ((iVar2 == 0) || (iVar2 = memcmp(local_2c,&DAT_00059240,4), iVar2 == 0)) {
    local_1c[0x1e] = 7;
    local_1c[0x1f] = 0;
    goto LAB_000276e0;
  }
  iVar2 = memcmp((void *)((int)local_2c + 1),&DAT_00059248,3);
  if ((iVar2 == 0) || (iVar2 = memcmp(local_2c,&DAT_0005924c,4), iVar2 == 0)) {
    local_1c[0x1e] = 0xf;
    local_1c[0x1f] = 0;
    goto LAB_000276e0;
  }
  iVar2 = str2ulong(local_2c);
  if (iVar2 == 0) {
    memcpy(local_2c,local_1c + 0x18,4);
  }
  uVar4 = str2ulong(local_2c);
  if (uVar4 != 0x44495658) {
    if (uVar4 < 0x44495659) {
      if (uVar4 != 0x32564933) {
        if (uVar4 < 0x32564934) {
          if (((uVar4 != 0x31585644) && (uVar4 != 0x3253344d)) && (uVar4 != 0x30355844))
          goto LAB_000276b8;
        }
        else if (uVar4 != 0x414b4e41) {
          if (uVar4 == 0x4356534d) {
            iVar2 = memcmp(local_1c + 0x18,&DAT_00059254,4);
            if (iVar2 == 0) {
              local_1c[0x1e] = 2;
              local_1c[0x1f] = 0;
            }
            goto LAB_000276e0;
          }
          if (uVar4 != 0x34504d46) goto LAB_000276b8;
        }
      }
    }
    else if (uVar4 != 0x5334504d) {
      if (uVar4 < 0x5334504e) {
        if (uVar4 == 0x47504a4d) {
          local_1c[0x1e] = 10;
          local_1c[0x1f] = 0;
          goto LAB_000276e0;
        }
        if (uVar4 != 0x4d475844) {
          if (uVar4 == 0x4745504d) {
            local_1c[0x1e] = 0xc;
            local_1c[0x1f] = 0;
            goto LAB_000276e0;
          }
          goto LAB_000276b8;
        }
      }
      else if (((uVar4 != 0x58495658) && (uVar4 != 0x58564944)) && (uVar4 != 0x5634504d)) {
LAB_000276b8:
        (*g_medialib_printf)("##AVI Demuxer: WARNING--video UNKNOWN##\r\n");
        local_1c[0x1e] = 0;
        local_1c[0x1f] = 0;
        goto LAB_000276e0;
      }
    }
  }
  local_1c[0x1e] = 2;
  local_1c[0x1f] = 0;
LAB_000276e0:
  if ((char)local_1c[0x52] != '\0') {
    local_1c[0x2e] = 0;
    local_1c[0x2f] = 0;
    while ((*(uint *)(local_1c + 0x2e) < *(uint *)(local_1c + 0x32) &&
           ((iVar2 = AVIDemuxer_IsKeyframe(local_1c,*(undefined4 *)(local_1c + 0x2e)), iVar2 != 1 ||
            (iVar2 = AVIDemuxer_GetFirstKeyframeSize(param_1), iVar2 == 0))))) {
      *(int *)(local_1c + 0x2e) = *(int *)(local_1c + 0x2e) + 1;
      if ((uint)(*(int *)(local_1c + 0x24) * 10) < *(uint *)(local_1c + 0x2e)) {
        *(undefined4 *)(local_1c + 0x2e) = *(undefined4 *)(local_1c + 0x32);
      }
    }
    if (*(uint *)(local_1c + 0x32) <= *(uint *)(local_1c + 0x2e)) {
      (*g_medialib_printf)("##AVI Demuxer: WARNING--first key frame not found, disable video##\r\n")
      ;
      local_1c[0x32] = 0;
      local_1c[0x33] = 0;
      *(undefined1 *)(local_1c + 0x52) = 0;
    }
  }
  local_1c[0x74] = 0xffff;
  local_1c[0x75] = 0xffff;
  local_1c[0x76] = 0xffff;
  local_1c[0x77] = 0xffff;
  *(undefined4 *)(local_1c + 0x72) = *(undefined4 *)(local_1c + 0x54);
  return 1;
}



undefined4 AVIDemuxer_Close(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    local_c = *(undefined4 **)(param_1 + 0xd8);
    while (local_c != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)local_c[1];
      (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*local_c);
      (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(local_c);
      local_c = puVar1;
    }
    *(undefined4 *)(param_1 + 0xd8) = 0;
    (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*(undefined4 *)(param_1 + 0xd4));
    (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*(undefined4 *)(param_1 + 0xc4));
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    if (*(int *)(param_1 + 0x120) != 0) {
      (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*(undefined4 *)(param_1 + 0x120));
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    if (*(int *)(param_1 + 0x124) != 0) {
      (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*(undefined4 *)(param_1 + 0x124));
      *(undefined4 *)(param_1 + 0x124) = 0;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      (**(code **)(*(int *)(param_1 + 0x108) + 0x18))(*(undefined4 *)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  return 1;
}



undefined4 AVIDemuxer_GetFileInfo(void *param_1,undefined4 *param_2)

{
  if (*(char *)((int)param_1 + 0xa4) != '\0') {
    *param_2 = *(undefined4 *)((int)param_1 + 0x5c);
    param_2[1] = *(undefined4 *)((int)param_1 + 0x60);
    param_2[2] = *(undefined4 *)((int)param_1 + 0x44);
    MulDiv(param_2 + 5,*(undefined4 *)((int)param_1 + 0x58),8000,
           *(undefined4 *)((int)param_1 + 0x44));
    param_2[7] = *(int *)((int)param_1 + 0x48) * 10;
    param_2[9] = *(undefined4 *)((int)param_1 + 0x3c);
    param_2[0x16] = *(undefined4 *)((int)param_1 + 0x4c);
    param_2[0x17] = *(undefined4 *)((int)param_1 + 0x50);
    if (param_2[7] == 0) {
      param_2[7] = 1;
    }
  }
  if (*(char *)((int)param_1 + 0xa5) != '\0') {
    param_2[3] = *(undefined4 *)((int)param_1 + 0x7c);
    param_2[4] = *(undefined4 *)((int)param_1 + 0x78);
    MulDiv(param_2 + 6,*(undefined4 *)((int)param_1 + 0x78),8000,
           *(undefined4 *)((int)param_1 + 0x44));
    memcpy(param_2 + 0xb,param_1,0x14);
    memcpy(param_2 + 0x10,(void *)((int)param_1 + 0xf0),2);
    param_2[10] = *(undefined4 *)((int)param_1 + 0x40);
  }
  param_2[0x18] = *(undefined4 *)((int)param_1 + 0x44);
  *(undefined1 *)(param_2 + 8) = *(undefined1 *)((int)param_1 + 0xa7);
  if ((*(int *)((int)param_1 + 0xac) == 0) || (*(uint *)((int)param_1 + 0x60) < 2)) {
    *(undefined1 *)((int)param_2 + 0x21) = 0;
  }
  else {
    *(undefined1 *)((int)param_2 + 0x21) = 1;
  }
  return 1;
}



undefined4 AVIDemuxer_GetVideoFrame(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 0xe8) = 0xffffffff;
  uVar2 = *param_3 - 8;
  if ((int)uVar2 < 0) {
    *param_3 = 0;
    uVar3 = 0;
  }
  else {
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xdc));
    iVar1 = AVIDemuxer_GetData(param_1,param_2 + 8,uVar2);
    if (iVar1 == 0) {
      *param_3 = 0;
      uVar3 = 0;
    }
    else {
      ulong2str(param_2,*(undefined4 *)(param_1 + 0x88));
      uVar3 = AVIDemuxer_GetVideoPts(param_1,*(undefined4 *)(param_1 + 0x88));
      ulong2str(param_2 + 4,uVar3);
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
      if ((uVar2 & 1) == 0) {
        uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0xa0));
        *(undefined4 *)(param_1 + 0xdc) = uVar3;
      }
      else {
        uVar3 = MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0xa0),1);
        *(undefined4 *)(param_1 + 0xdc) = uVar3;
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}



int AVIDemuxer_GetVideoFrameSize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  int local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_14 = param_1;
  if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100)) {
    if (*(int *)(param_1 + 0xe8) == -1) {
      if (*(char *)(param_1 + 0x10d) == '\0') {
        MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xdc));
        local_c = AVIDemuxer_GetSize(local_14,*(undefined4 *)(local_14 + 0x34),8);
        if ((int)local_c < 0) {
          iVar2 = 0;
        }
        else {
          uVar1 = MediaFile_GetPosition(*(undefined4 *)(local_14 + 0xa0));
          *(undefined4 *)(local_14 + 0xdc) = uVar1;
          *(uint *)(local_14 + 0xe8) = local_c;
          iVar2 = local_c + 8;
        }
      }
      else if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100)) {
        if ((*(uint *)(param_1 + 0x88) <
             *(uint *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) ||
           ((uint)(*(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4) +
                  *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 8)) <=
            *(uint *)(param_1 + 0x88))) {
          local_10 = 0;
          while ((local_10 < *(uint *)(param_1 + 0x110) &&
                 (*(uint *)(*(int *)(param_1 + 0x120) + local_10 * 0x10 + 4) <=
                  *(uint *)(param_1 + 0x88)))) {
            *(uint *)(param_1 + 0x118) = local_10;
            local_10 = local_10 + 1;
          }
          if ((*(uint *)(param_1 + 0x88) <
               *(uint *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) ||
             ((uint)(*(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4) +
                    *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 8)) <=
              *(uint *)(param_1 + 0x88))) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR--find v index failed##\r\n");
            return 0;
          }
        }
        MediaFile_SetPosition
                  (*(undefined4 *)(param_1 + 0xa0),
                   *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10) +
                   (*(int *)(param_1 + 0x88) -
                   *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) * 8);
        iVar2 = MediaFile_Read(*(undefined4 *)(local_14 + 0xa0),auStack_1c,8);
        if (iVar2 == 8) {
          uVar1 = str2ulong(auStack_1c);
          *(undefined4 *)(local_14 + 0xdc) = uVar1;
          if (*(int *)(local_14 + 0xdc) != 0) {
            local_c = str2ulong(auStack_18);
            local_c = local_c & 0x7fffffff;
          }
          *(int *)(local_14 + 0xdc) =
               *(int *)(local_14 + 0xdc) +
               *(int *)(*(int *)(local_14 + 0x120) + *(int *)(local_14 + 0x118) * 0x10 + 0xc);
          iVar2 = local_c + 8;
        }
        else {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0xe8) + 8;
    }
  }
  else {
    (*g_medialib_printf)("##AVI Demuxer: video_pos >= video_frames##\r\n");
    iVar2 = 0;
  }
  return iVar2;
}



uint AVIDemuxer_GetAudioData(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = param_3;
  local_18 = param_2;
  if (*(int *)(param_1 + 0x40) == 4) {
    local_1c = param_3 - 7;
    local_18 = param_2 + 7;
  }
  *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xe0));
  iVar2 = AVIDemuxer_GetData(param_1,local_18,local_1c);
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
    if ((local_1c & 1) == 0) {
      uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0xe0) = uVar3;
    }
    else {
      uVar3 = MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0xa0),1);
      *(undefined4 *)(param_1 + 0xe0) = uVar3;
    }
    if (*(int *)(param_1 + 0x40) == 4) {
      bVar1 = get_aacFreqIndex(*(undefined4 *)(param_1 + 4));
      local_1c = local_1c + 7;
      *(undefined1 *)(local_18 + -7) = 0xff;
      *(undefined1 *)(local_18 + -6) = 0xf9;
      *(byte *)(local_18 + -5) = (bVar1 & 0xf) << 2 | 0x40;
      *(char *)(local_18 + -4) = (char)*(undefined2 *)(param_1 + 2) << 6;
      *(char *)(local_18 + -3) = (char)(local_1c >> 3);
      *(byte *)(local_18 + -2) = (byte)((local_1c & 7) << 5) | 0x1f;
      *(undefined1 *)(local_18 + -1) = 0xfc;
    }
  }
  return local_1c;
}



uint AVIDemuxer_GetAudioDataSize(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 100;
  if (*(int *)(param_1 + 0xec) == -1) {
    local_20 = param_1;
    if (*(char *)(param_1 + 0x10d) == '\0') {
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xe0));
      uVar1 = local_14;
      do {
        local_14 = uVar1;
        local_14 = AVIDemuxer_GetSize(local_20,*(undefined4 *)(local_20 + 0x38),0);
        if ((int)local_14 < 0) {
          return 0;
        }
        local_18 = local_18 + -1;
      } while ((local_14 == 0) && (uVar1 = 0, local_18 != 0));
      if (*(int *)(local_20 + 0x90) != 0) {
        if (*(uint *)(local_20 + 0x90) < local_14) {
          local_14 = local_14 - *(int *)(local_20 + 0x90);
          MediaFile_ChangePosition
                    (*(undefined4 *)(local_20 + 0xa0),*(undefined4 *)(local_20 + 0x90));
        }
        else {
          (*g_medialib_printf)("##AVI Demuxer: WARNING--posb error##\r\n");
        }
        *(undefined4 *)(local_20 + 0x90) = 0;
      }
      uVar3 = MediaFile_GetPosition(*(undefined4 *)(local_20 + 0xa0));
      *(undefined4 *)(local_20 + 0xe0) = uVar3;
      *(uint *)(local_20 + 0xec) = local_14;
      if ((*(int *)(local_20 + 0x40) == 4) && (local_14 != 0)) {
        local_14 = local_14 + 7;
        *(uint *)(local_20 + 0xec) = local_14;
      }
    }
    else if (*(uint *)(param_1 + 0x8c) < *(uint *)(param_1 + 0x7c)) {
      if ((*(uint *)(param_1 + 0x8c) <
           *(uint *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4)) ||
         ((uint)(*(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4) +
                *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 8)) <=
          *(uint *)(param_1 + 0x8c))) {
        local_1c = 0;
        while ((local_1c < *(uint *)(param_1 + 0x114) &&
               (*(uint *)(*(int *)(param_1 + 0x124) + local_1c * 0x10 + 4) <=
                *(uint *)(param_1 + 0x8c)))) {
          *(uint *)(param_1 + 0x11c) = local_1c;
          local_1c = local_1c + 1;
        }
        if ((*(uint *)(param_1 + 0x8c) <
             *(uint *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4)) ||
           ((uint)(*(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4) +
                  *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 8)) <=
            *(uint *)(param_1 + 0x8c))) {
          (*g_medialib_printf)("##AVI Demuxer: ERROR--find a index failed##\r\n");
          return 0;
        }
      }
      MediaFile_SetPosition
                (*(undefined4 *)(param_1 + 0xa0),
                 *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10) +
                 (*(int *)(param_1 + 0x8c) -
                 *(int *)(*(int *)(param_1 + 0x124) + *(int *)(param_1 + 0x11c) * 0x10 + 4)) * 8);
      iVar2 = MediaFile_Read(*(undefined4 *)(local_20 + 0xa0),auStack_28,8);
      if (iVar2 == 8) {
        uVar3 = str2ulong(auStack_28);
        *(undefined4 *)(local_20 + 0xe0) = uVar3;
        if (*(int *)(local_20 + 0xe0) != 0) {
          local_14 = str2ulong(auStack_24);
          local_14 = local_14 & 0x7fffffff;
        }
        *(int *)(local_20 + 0xe0) =
             *(int *)(local_20 + 0xe0) +
             *(int *)(*(int *)(local_20 + 0x124) + *(int *)(local_20 + 0x11c) * 0x10 + 0xc);
      }
      else {
        local_14 = 0;
      }
    }
    else {
      local_14 = 0;
    }
  }
  else {
    local_14 = *(uint *)(param_1 + 0xec);
  }
  return local_14;
}



undefined4 AVIDemuxer_GetNextBlockInfo(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = param_1;
  if (*(int *)(*(int *)(param_1 + 0xa0) + 0x10) == 0) {
    if (*(char *)(param_1 + 0x10d) == '\0') {
      if ((*(uint *)(param_1 + 0xe4) < *(uint *)(param_1 + 0xe0)) ||
         (*(uint *)(param_1 + 0xe4) < *(uint *)(param_1 + 0xdc))) {
        if (*(uint *)(param_1 + 0xdc) < *(uint *)(param_1 + 0xe0)) {
          if (*(int *)(param_1 + 0xe8) != -1) {
            *param_2 = 1;
            param_2[1] = *(int *)(param_1 + 0xe8) + 8;
            return 1;
          }
          if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100)) {
            *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xdc);
          }
          else {
            if (*(int *)(param_1 + 0xec) != -1) {
              *param_2 = 2;
              param_2[1] = *(undefined4 *)(param_1 + 0xec);
              return 1;
            }
            *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe0);
          }
        }
        else {
          if (*(int *)(param_1 + 0xec) != -1) {
            *param_2 = 2;
            param_2[1] = *(undefined4 *)(param_1 + 0xec);
            return 1;
          }
          if (*(uint *)(param_1 + 0x8c) < *(uint *)(param_1 + 0x7c)) {
            *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe0);
          }
          else {
            if (*(int *)(param_1 + 0xe8) != -1) {
              *param_2 = 1;
              param_2[1] = *(int *)(param_1 + 0xe8) + 8;
              return 1;
            }
            *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xdc);
          }
        }
      }
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xe4));
      while( true ) {
        MediaFile_ChangePosition(*(undefined4 *)(local_30 + 0xa0),local_18);
        iVar1 = MediaFile_Read(*(undefined4 *)(local_30 + 0xa0),auStack_4c,8);
        if (iVar1 != 8) break;
        local_34 = str2ulong(auStack_4c);
        if (local_34 == 0x5453494c) {
          local_18 = 4;
          *(int *)(local_30 + 0xe4) = *(int *)(local_30 + 0xe4) + 4;
        }
        else {
          local_14 = str2ulong(auStack_48);
          if (((local_34 == 0x63643030) || (local_34 == 0x62773130)) && (-1 < (int)local_14)) {
            local_18 = local_14 + 1 & 0xfffffffe;
            *(int *)(local_30 + 0xe4) = *(int *)(local_30 + 0xe4) + 8;
            if (((local_34 * 0x100 == *(int *)(local_30 + 0x34)) &&
                ((*(uint *)(local_30 + 0xdc) < *(uint *)(local_30 + 0xe4) ||
                 ((*(int *)(local_30 + 0xe4) == *(int *)(local_30 + 0xdc) && (local_14 != 0)))))) ||
               ((*(int *)(local_30 + 0x38) == local_34 &&
                (*(uint *)(local_30 + 0xe0) <= *(uint *)(local_30 + 0xe4))))) {
              if ((int)local_14 < 0) {
                *param_2 = 0;
                param_2[1] = 0;
                (*g_medialib_printf)("##AVI Demuxer: error streamLen < 0##\r\n");
                return 0;
              }
              if (*(int *)(local_30 + 0x38) == local_34) {
                if (*(int *)(local_30 + 0xec) != -1) {
                  *param_2 = 2;
                  param_2[1] = *(undefined4 *)(local_30 + 0xec);
                  return 1;
                }
                if (*(int *)(local_30 + 0x90) != 0) {
                  if (*(uint *)(local_30 + 0x90) < local_14) {
                    local_14 = local_14 - *(int *)(local_30 + 0x90);
                    MediaFile_ChangePosition
                              (*(undefined4 *)(local_30 + 0xa0),*(undefined4 *)(local_30 + 0x90));
                  }
                  else {
                    (*g_medialib_printf)("##AVI Demuxer: WARNING--posb error##\r\n");
                  }
                  *(undefined4 *)(local_30 + 0x90) = 0;
                }
                uVar2 = MediaFile_GetPosition(*(undefined4 *)(local_30 + 0xa0));
                *(undefined4 *)(local_30 + 0xe0) = uVar2;
                *(uint *)(local_30 + 0xec) = local_14;
                if ((*(int *)(local_30 + 0x40) == 4) && (local_14 != 0)) {
                  *(uint *)(local_30 + 0xec) = local_14 + 7;
                }
                *param_2 = 2;
                param_2[1] = *(undefined4 *)(local_30 + 0xec);
              }
              else if (local_34 * 0x100 == *(int *)(local_30 + 0x34)) {
                if (*(int *)(local_30 + 0xe8) != -1) {
                  *param_2 = 1;
                  param_2[1] = *(int *)(local_30 + 0xe8) + 8;
                  return 1;
                }
                uVar2 = MediaFile_GetPosition(*(undefined4 *)(local_30 + 0xa0));
                *(undefined4 *)(local_30 + 0xdc) = uVar2;
                *(uint *)(local_30 + 0xe8) = local_14;
                *param_2 = 1;
                param_2[1] = local_14 + 8;
              }
              if ((local_14 & 1) == 0) {
                iVar1 = MediaFile_GetPosition(*(undefined4 *)(local_30 + 0xa0));
                *(uint *)(local_30 + 0xe4) = iVar1 + local_14;
              }
              else {
                iVar1 = MediaFile_GetPosition(*(undefined4 *)(local_30 + 0xa0));
                *(uint *)(local_30 + 0xe4) = iVar1 + local_14 + 1;
              }
              return 1;
            }
            *(uint *)(local_30 + 0xe4) = *(int *)(local_30 + 0xe4) + local_18;
          }
          else {
            local_3c = *(uint *)(*(int *)(local_30 + 0xa0) + 8);
            (*g_medialib_printf)
                      ("##AVI Demuxer: getNextBlocInfo WARN - data invalid, pos(0x%x)##\r\n",
                       local_3c);
            do {
              local_40 = AVIDemuxer_SeekNextKeyframe(local_30);
              if (*(uint *)(local_30 + 0xdc) < local_3c) {
                *(int *)(local_30 + 0x88) = *(int *)(local_30 + 0x88) + 1;
              }
            } while ((*(uint *)(local_30 + 0xdc) < local_3c) &&
                    (*(uint *)(local_30 + 0x88) < *(uint *)(local_30 + 100)));
            local_44 = AVIDemuxer_GetVideoPts(local_30,*(undefined4 *)(local_30 + 100));
            MulDiv(local_30 + 0x8c,local_44,1000,*(undefined4 *)(local_30 + 0x98));
            local_18 = *(int *)(local_30 + 0xdc) - local_3c;
            if ((int)local_18 < 8) {
              return 0;
            }
            *(undefined4 *)(local_30 + 0xe4) = *(undefined4 *)(local_30 + 0xdc);
          }
        }
      }
      (*g_medialib_printf)("##AVI Demuxer: read data error ##\r\n");
      uVar2 = 0;
    }
    else {
      local_38 = 0;
      local_1c = 0;
      local_20 = 0;
      local_24 = 0;
      if ((*(uint *)(param_1 + 0x8c) < *(uint *)(param_1 + 0x7c)) ||
         (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100))) {
        if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 100)) {
          if ((*(uint *)(param_1 + 0x88) <
               *(uint *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) ||
             ((uint)(*(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4) +
                    *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 8)) <=
              *(uint *)(param_1 + 0x88))) {
            local_28 = 0;
            while ((local_28 < *(uint *)(param_1 + 0x110) &&
                   (*(uint *)(*(int *)(param_1 + 0x120) + local_28 * 0x10 + 4) <=
                    *(uint *)(param_1 + 0x88)))) {
              *(uint *)(param_1 + 0x118) = local_28;
              local_28 = local_28 + 1;
            }
            if ((*(uint *)(param_1 + 0x88) <
                 *(uint *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) ||
               ((uint)(*(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4) +
                      *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 8)) <=
                *(uint *)(param_1 + 0x88))) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--find v index failed##\r\n");
              return 0;
            }
          }
          local_1c = *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10) +
                     (*(int *)(param_1 + 0x88) -
                     *(int *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x118) * 0x10 + 4)) * 8
          ;
          MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),local_1c);
          iVar1 = MediaFile_Read(*(undefined4 *)(local_30 + 0xa0),auStack_4c,8);
          if (iVar1 != 8) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR-- in ODML read##\r\n");
            return 0;
          }
          uVar2 = str2ulong(auStack_4c);
          *(undefined4 *)(local_30 + 0xdc) = uVar2;
          if (*(int *)(local_30 + 0xdc) != 0) {
            local_24 = str2ulong(auStack_48);
            local_24 = local_24 & 0x7fffffff;
          }
          *(int *)(local_30 + 0xdc) =
               *(int *)(local_30 + 0xdc) +
               *(int *)(*(int *)(local_30 + 0x120) + *(int *)(local_30 + 0x118) * 0x10 + 0xc);
        }
        if (*(uint *)(local_30 + 0x8c) < *(uint *)(local_30 + 0x7c)) {
          if ((*(uint *)(local_30 + 0x8c) <
               *(uint *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 4)) ||
             ((uint)(*(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 4) +
                    *(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 8)) <=
              *(uint *)(local_30 + 0x8c))) {
            local_2c = 0;
            while ((local_2c < *(uint *)(local_30 + 0x114) &&
                   (*(uint *)(*(int *)(local_30 + 0x124) + local_2c * 0x10 + 4) <=
                    *(uint *)(local_30 + 0x8c)))) {
              *(uint *)(local_30 + 0x11c) = local_2c;
              local_2c = local_2c + 1;
            }
            if ((*(uint *)(local_30 + 0x8c) <
                 *(uint *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 4)) ||
               ((uint)(*(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 4)
                      + *(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 8)
                      ) <= *(uint *)(local_30 + 0x8c))) {
              (*g_medialib_printf)("##AVI Demuxer: ERROR--find a index failed##\r\n");
              return 0;
            }
          }
          local_38 = *(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10) +
                     (*(int *)(local_30 + 0x8c) -
                     *(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 4)) *
                     8;
          MediaFile_SetPosition(*(undefined4 *)(local_30 + 0xa0),local_38);
          iVar1 = MediaFile_Read(*(undefined4 *)(local_30 + 0xa0),auStack_4c,8);
          if (iVar1 != 8) {
            (*g_medialib_printf)("##AVI Demuxer: ERROR-- in ODML read##\r\n");
            return 0;
          }
          uVar2 = str2ulong(auStack_4c);
          *(undefined4 *)(local_30 + 0xe0) = uVar2;
          if (*(int *)(local_30 + 0xe0) != 0) {
            local_20 = str2ulong(auStack_48);
            local_20 = local_20 & 0x7fffffff;
          }
          *(int *)(local_30 + 0xe0) =
               *(int *)(local_30 + 0xe0) +
               *(int *)(*(int *)(local_30 + 0x124) + *(int *)(local_30 + 0x11c) * 0x10 + 0xc);
        }
        if ((*(uint *)(local_30 + 0xe0) < *(uint *)(local_30 + 0xdc)) || (local_1c == 0)) {
          *param_2 = 2;
          param_2[1] = local_20;
          uVar2 = 1;
        }
        else {
          *param_2 = 1;
          param_2[1] = local_24 + 8;
          uVar2 = 1;
        }
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--no more video and audio frame##\r\n");
        uVar2 = 0;
      }
    }
  }
  else {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--read_status is not zero##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AVIDemuxer_SeekNextKeyframe(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(uint *)(param_1 + 0x88) < *(int *)(param_1 + 100) - 1U) {
    if (*(char *)(param_1 + 0x10c) != '\0') {
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
    }
    while (iVar1 = AVIDemuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x88)), iVar1 == 0) {
      if (*(int *)(param_1 + 100) - 1U <= *(uint *)(param_1 + 0x88)) {
        return 0;
      }
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
    }
    *(undefined4 *)(param_1 + 0x88) =
         *(undefined4 *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8);
    *(int *)(param_1 + 0xdc) =
         *(int *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8 + 4) + -8;
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xdc);
    *(undefined4 *)(param_1 + 0xe8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AVIDemuxer_SeekPrevKeyframe(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(uint *)(param_1 + 100) < *(uint *)(param_1 + 0x88)) {
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 100);
  }
  if ((uint)(*(char *)(param_1 + 0x10c) == '\0') < *(uint *)(param_1 + 0x88)) {
    if (*(char *)(param_1 + 0x10c) == '\0') {
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
    }
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
    while (iVar1 = AVIDemuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x88)), iVar1 == 0) {
      if (*(int *)(param_1 + 0x88) == 0) {
        return 0;
      }
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
    }
    *(undefined4 *)(param_1 + 0x88) =
         *(undefined4 *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8);
    *(int *)(param_1 + 0xdc) =
         *(int *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8 + 4) + -8;
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xdc);
    *(undefined4 *)(param_1 + 0xe8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



int AVIDemuxer_GetFirstKeyframeSize(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_18;
  int local_14;
  
  iVar1 = AVIDemuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x5c));
  if (iVar1 == 0) {
    (*g_medialib_printf)("##AVI Demuxer: ERROR--GetFirstKeyframeSize return failed##\r\n");
    local_14 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0xac) == 0) || (*(int *)(param_1 + 0x60) == 0)) {
      local_18 = 0;
      AVIDemuxer_SeekVideo(param_1,0);
      MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xdc));
      for (; local_18 < *(uint *)(param_1 + 0x5c); local_18 = local_18 + 1) {
        uVar2 = AVIDemuxer_GetSize(param_1,*(undefined4 *)(param_1 + 0x34),8);
        if ((uVar2 & 1) == 0) {
          MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0xa0),uVar2);
        }
        else {
          MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0xa0),uVar2 + 1);
        }
      }
      uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0xdc) = uVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) =
           *(undefined4 *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8);
      *(int *)(param_1 + 0xdc) =
           *(int *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xbc) * 8 + 4) + -8;
    }
    MediaFile_SetPosition(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xdc));
    local_14 = AVIDemuxer_GetSize(param_1,*(undefined4 *)(param_1 + 0x34),8);
    if (local_14 < 1) {
      local_14 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x28) != 0) {
        local_14 = *(int *)(param_1 + 0x28) + local_14;
      }
      uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0xa0));
      *(undefined4 *)(param_1 + 0xdc) = uVar3;
      *(int *)(param_1 + 0xe8) = local_14;
      local_14 = local_14 + 8;
    }
  }
  return local_14;
}



undefined4 AVIDemuxer_GetFirstKeyframe(int param_1,void *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = AVIDemuxer_GetVideoFrame(param_1,(int)param_2 + *(int *)(param_1 + 0x28),param_3);
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x28) != 0) {
      memcpy(param_2,(void *)((int)param_2 + *(int *)(param_1 + 0x28)),8);
      memcpy((void *)((int)param_2 + 8),*(void **)(param_1 + 0x24),*(size_t *)(param_1 + 0x28));
    }
    uVar2 = 1;
  }
  return uVar2;
}



undefined4 AVIDemuxer_SeekVideo(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_18;
  int local_14;
  
  local_18 = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0xe8) = 0xffffffff;
    uVar3 = 0;
  }
  else {
    local_14 = param_1;
    if (*(int *)(param_1 + 0xac) == 0) {
      (*g_medialib_printf)("##AVI Demuxer: no idx, can\'t seek video##\r\n");
      uVar3 = 0xffffffff;
    }
    else {
      MulDiv(&local_18,param_2,1000,*(undefined4 *)(param_1 + 0x94));
      if (local_18 < *(uint *)(local_14 + 100)) {
        if ((local_18 < *(int *)(local_14 + 100) - 1U) &&
           (uVar1 = AVIDemuxer_GetVideoPts(local_14,local_18 + 1), uVar1 <= param_2)) {
          local_18 = local_18 + 1;
        }
        if (local_18 < *(uint *)(local_14 + 0x5c)) {
          local_18 = *(uint *)(local_14 + 0x5c);
        }
        iVar2 = AVIDemuxer_IsKeyframe(local_14,local_18);
        if (iVar2 == 0) {
          *(uint *)(local_14 + 0x88) = local_18;
          *(undefined1 *)(local_14 + 0x10c) = 1;
          iVar2 = AVIDemuxer_SeekPrevKeyframe(param_1);
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          *(undefined1 *)(local_14 + 0x10c) = 0;
        }
        else {
          *(undefined4 *)(local_14 + 0x88) =
               *(undefined4 *)(*(int *)(local_14 + 0xc0) + *(int *)(local_14 + 0xbc) * 8);
          *(int *)(local_14 + 0xdc) =
               *(int *)(*(int *)(local_14 + 0xc0) + *(int *)(local_14 + 0xbc) * 8 + 4) + -8;
          *(undefined4 *)(local_14 + 0xe0) = *(undefined4 *)(local_14 + 0xdc);
        }
        *(undefined4 *)(local_14 + 0xe8) = 0xffffffff;
        *(undefined4 *)(local_14 + 0xe4) = *(undefined4 *)(local_14 + 0xa8);
        uVar3 = AVIDemuxer_GetVideoPts(param_1,*(undefined4 *)(local_14 + 0x88));
      }
      else {
        (*g_medialib_printf)
                  ("##AVI Demuxer: can\'t seek that far, video total frame is %d##\r\n",
                   *(undefined4 *)(local_14 + 100));
        uVar3 = 0xffffffff;
      }
    }
  }
  return uVar3;
}



uint AVIDemuxer_SeekAudio(int param_1,uint param_2)

{
  int iVar1;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_24 = 0;
  local_34 = 0;
  local_14 = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
    local_24 = 0;
  }
  else {
    local_18 = param_1;
    if (*(int *)(param_1 + 0xac) == 0) {
      (*g_medialib_printf)("##AVI Demuxer: no idx, can\'t seek audio##\r\n");
      local_24 = 0xffffffff;
    }
    else if (*(char *)(param_1 + 0xa4) == '\0') {
      if (param_2 < *(uint *)(param_1 + 0x44)) {
        MulDiv(param_1 + 0x8c,param_2,1000,*(undefined4 *)(param_1 + 0x98));
        iVar1 = AVIDemuxer_GetAudioIndex(local_18,*(undefined4 *)(local_18 + 0x8c),&local_30);
        if (iVar1 == 1) {
          *(undefined4 *)(local_18 + 0x90) = 0;
          MulDiv(&local_24,*(undefined4 *)(local_18 + 0x98),*(undefined4 *)(local_18 + 0x8c),1000);
          *(int *)(local_18 + 0xe0) = local_30 + -8;
          *(undefined4 *)(local_18 + 0xec) = 0xffffffff;
        }
        else {
          (*g_medialib_printf)("##AVI Demuxer: ERROR--GetAudioIndex return FALSE 5##\r\n");
          local_24 = 0xffffffff;
        }
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--seek pts is out of range##\r\n");
        local_24 = 0xffffffff;
      }
    }
    else {
      MulDiv(&local_1c,param_2,1000,*(undefined4 *)(param_1 + 0x94));
      if (local_1c < *(uint *)(local_18 + 100)) {
        MulDiv(local_18 + 0x8c,param_2,1000,*(undefined4 *)(local_18 + 0x98));
        iVar1 = AVIDemuxer_GetAudioIndex(local_18,*(undefined4 *)(local_18 + 0x8c),&local_30);
        if (iVar1 == 1) {
          MulDiv(&local_20,param_2,1000,10);
          if ((*(char *)(local_18 + 0xa7) == '\0') && (*(char *)(local_18 + 0x10d) == '\0')) {
            if (*(int *)(local_18 + 0x80) == 1) {
              MulDiv(&local_24,local_28,100000,*(undefined4 *)(local_18 + 0x84));
              if (local_20 < local_24) {
                while (*(int *)(local_18 + 0x8c) != 0) {
                  iVar1 = AVIDemuxer_GetAudioIndex
                                    (local_18,*(int *)(local_18 + 0x8c) + -1,&local_30);
                  if (iVar1 != 1) {
                    (*g_medialib_printf)("##AVI Demuxer: ERROR--GetAudioIndex return FALSE 2##\r\n")
                    ;
                    return 0xffffffff;
                  }
                  MulDiv(&local_34,local_28,100000,*(undefined4 *)(local_18 + 0x84));
                  *(int *)(local_18 + 0x8c) = *(int *)(local_18 + 0x8c) + -1;
                  if (local_34 < local_20) {
                    local_14 = local_24 - local_34;
                    local_24 = local_34;
                    break;
                  }
                  local_24 = local_34;
                }
              }
              else if (local_24 < local_20) {
                while (*(uint *)(local_18 + 0x8c) < *(uint *)(local_18 + 0x7c)) {
                  iVar1 = AVIDemuxer_GetAudioIndex(local_18,*(int *)(local_18 + 0x8c) + 1,&local_30)
                  ;
                  if (iVar1 != 1) {
                    (*g_medialib_printf)("##AVI Demuxer: ERROR--GetAudioIndex return FALSE 3##\r\n")
                    ;
                    return 0xffffffff;
                  }
                  MulDiv(&local_34,local_28,100000,*(undefined4 *)(local_18 + 0x84));
                  if (local_20 < local_34) {
                    local_14 = local_34 - local_24;
                    break;
                  }
                  local_24 = local_34;
                  *(int *)(local_18 + 0x8c) = *(int *)(local_18 + 0x8c) + 1;
                }
                iVar1 = AVIDemuxer_GetAudioIndex
                                  (local_18,*(undefined4 *)(local_18 + 0x8c),&local_30);
                if (iVar1 != 1) {
                  (*g_medialib_printf)("##AVI Demuxer: ERROR--GetAudioIndex return FALSE 4##\r\n");
                  return 0xffffffff;
                }
              }
            }
            else {
              MulDiv(&local_24,*(undefined4 *)(local_18 + 0x8c),*(undefined4 *)(local_18 + 0x98),10)
              ;
            }
          }
          else {
            MulDiv(&local_24,*(undefined4 *)(local_18 + 0x8c),*(undefined4 *)(local_18 + 0x98),10);
          }
          (*g_medialib_printf)
                    ("#video_pts = %d, audio_pts = %d, audio_diff_pts = %d#\r\n",local_20,local_24,
                     local_14);
          if (local_20 < local_24) {
            *(undefined4 *)(local_18 + 0x90) = 0;
            (*g_medialib_printf)
                      ("##AVI Demuxer: WARNING--calc err, audio pts is large than video pts##\r\n");
          }
          else if (*(int *)(local_18 + 0x40) == 6) {
            if (local_14 == 0) {
              MulDiv(local_18 + 0x90,local_2c,(local_20 - local_24) * 10,
                     *(undefined4 *)(local_18 + 0x98));
            }
            else {
              MulDiv(local_18 + 0x90,local_2c,local_20 - local_24,local_14);
            }
            if (local_2c <= *(uint *)(local_18 + 0x90)) {
              *(uint *)(local_18 + 0x90) = local_2c - 1;
            }
            if ((*(uint *)(local_18 + 0x90) & 1) != 0) {
              *(int *)(local_18 + 0x90) = *(int *)(local_18 + 0x90) + -1;
            }
            if (*(int *)(local_18 + 0x80) == 1) {
              MulDiv(&local_34,local_28 + *(int *)(local_18 + 0x90),100000,
                     *(undefined4 *)(local_18 + 0x84));
              (*g_medialib_printf)
                        ("#final audio_pts = %d, posc = %d, %d/%d#\r\n",local_34,
                         *(undefined4 *)(local_18 + 0x8c),*(undefined4 *)(local_18 + 0x90),local_2c)
              ;
              local_24 = local_34;
            }
            else {
              MulDiv(&local_34,*(undefined4 *)(local_18 + 0x90),*(undefined4 *)(local_18 + 0x98),
                     local_2c * 10);
              local_24 = local_24 + local_34;
              (*g_medialib_printf)
                        ("#%d final audio_pts = %d, posc = %d, %d/%d#\r\n",
                         *(undefined4 *)(local_18 + 0x80),local_24,*(undefined4 *)(local_18 + 0x8c),
                         *(undefined4 *)(local_18 + 0x90),local_2c);
            }
          }
          else {
            *(undefined4 *)(local_18 + 0x90) = 0;
          }
          *(int *)(local_18 + 0xe0) = local_30 + -8;
          *(undefined4 *)(local_18 + 0xec) = 0xffffffff;
          *(undefined4 *)(local_18 + 0xe4) = *(undefined4 *)(local_18 + 0xa8);
          MulDiv(&local_34,local_24,10,1000);
          local_24 = local_34;
        }
        else {
          (*g_medialib_printf)("##AVI Demuxer: ERROR--GetAudioIndex return FALSE 1##\r\n");
          local_24 = 0xffffffff;
        }
      }
      else {
        (*g_medialib_printf)("##AVI Demuxer: ERROR--seek pos is out of range##\r\n");
        local_24 = 0xffffffff;
      }
    }
  }
  return local_24;
}



undefined4 AVIDemuxer_GetVideoPts(int param_1,undefined4 param_2)

{
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = param_1;
  MulDiv(&local_10,*(undefined4 *)(param_1 + 0x94),param_2,1000);
  return local_10;
}



undefined4 AVIDemuxer_GetAudioPackPts(int param_1)

{
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = param_1;
  MulDiv(&local_10,*(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0x8c),1000);
  return local_10;
}



undefined4 AVIDemuxer_IsKeyframe(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_28;
  undefined4 *local_14;
  uint local_10;
  int local_c;
  
  if ((*(int *)(param_1 + 0xac) == 0) || (*(int *)(param_1 + 0x60) == 0)) {
    if (*(uint *)(param_1 + 0x5c) == param_2) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    local_28 = param_2;
    if (*(uint *)(param_1 + 100) <= param_2) {
      local_28 = 0;
    }
    local_c = 0;
    local_14 = (undefined4 *)(param_1 + 0xd4);
    *(undefined4 *)(param_1 + 0xc0) = *local_14;
    while ((local_14[1] != 0 && (**(uint **)local_14[1] <= local_28))) {
      local_14 = (undefined4 *)local_14[1];
      *(undefined4 *)(param_1 + 0xc0) = *local_14;
    }
    if (*(int *)(*(int *)(param_1 + 0xc0) + 0x7f8) == 0) {
      local_10 = *(int *)(param_1 + 0x60) - 1U & 0xff;
    }
    else {
      local_10 = 0xff;
    }
    do {
      if ((int)local_10 < local_c) {
        *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
        return 0;
      }
      iVar1 = (int)(local_c + local_10) / 2;
      if (local_28 < *(uint *)(*(int *)(param_1 + 0xc0) + iVar1 * 8)) {
        local_10 = iVar1 - 1;
      }
      else if (*(uint *)(*(int *)(param_1 + 0xc0) + iVar1 * 8) < local_28) {
        local_c = iVar1 + 1;
      }
    } while (*(uint *)(*(int *)(param_1 + 0xc0) + iVar1 * 8) != local_28);
    *(int *)(param_1 + 0xbc) = iVar1;
    uVar2 = 1;
  }
  return uVar2;
}



int GetAudioFormatSize(undefined4 param_1,int param_2)

{
  int local_10;
  
  switch(param_1) {
  case 2:
    local_10 = param_2;
    if (param_2 != 0) {
      local_10 = 0xc;
    }
    param_2 = local_10 + 0x12;
    break;
  case 3:
    param_2 = param_2 + 0x12;
    break;
  case 4:
    param_2 = 0x12;
    break;
  case 5:
  default:
switchD_0002a9f0_default:
    param_2 = 0x12;
    break;
  case 6:
    goto switchD_0002a9f0_default;
  case 7:
    param_2 = param_2 + 0x12;
  }
  return param_2;
}



int GetAudioFormat(undefined2 *param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  
  *param_1 = 1;
  param_1[1] = *(undefined2 *)(param_2 + 2);
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 4);
  param_1[7] = *(undefined2 *)(param_2 + 0xe);
  iVar2 = (uint)(ushort)param_1[7] * (uint)(ushort)param_1[1];
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  param_1[6] = (short)(iVar2 >> 3);
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 2) * (uint)(ushort)param_1[6];
  if (param_3 < 0x13) {
    sVar1 = 0;
  }
  else {
    sVar1 = (short)param_3 + -0x12;
  }
  param_1[8] = sVar1;
  return param_3;
}



undefined4 GetVideoFormatSize(void)

{
  return 0x28;
}



undefined4 GetVideoFormat(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  *(undefined2 *)(param_1 + 3) = 1;
  *(undefined2 *)((int)param_1 + 0xe) = 0x18;
  param_1[4] = 0x33363248;
  param_1[5] = param_3 * param_4 * 3;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return param_2;
}



undefined4 allocVideoFormat(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(*(int *)(param_2 + 4) + 0x44) == 0) ||
     (*(int *)(*(int *)(param_2 + 4) + 0x40) != param_1)) {
    (**(code **)(*(int *)(param_2 + 0x4cc) + 0x18))(*(undefined4 *)(*(int *)(param_2 + 4) + 0x44));
    iVar2 = *(int *)(param_2 + 4);
    uVar1 = (**(code **)(*(int *)(param_2 + 0x4cc) + 0x14))(param_1);
    *(undefined4 *)(iVar2 + 0x44) = uVar1;
    *(int *)(*(int *)(param_2 + 4) + 0x40) = param_1;
    uVar1 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x44);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x44);
  }
  return uVar1;
}



undefined4 allocAudioFormat(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(*param_2 + 0x44) == 0) || (*(int *)(*param_2 + 0x40) != param_1)) {
    (**(code **)(param_2[0x133] + 0x18))(*(undefined4 *)(*param_2 + 0x44));
    iVar2 = *param_2;
    uVar1 = (**(code **)(param_2[0x133] + 0x14))(param_1);
    *(undefined4 *)(iVar2 + 0x44) = uVar1;
    *(int *)(*param_2 + 0x40) = param_1;
    uVar1 = *(undefined4 *)(*param_2 + 0x44);
  }
  else {
    uVar1 = *(undefined4 *)(*param_2 + 0x44);
  }
  return uVar1;
}



// WARNING: Removing unreachable block (ram,0x0002b4bc)

undefined4 AVIMuxer_SetParam(void *param_1)

{
  undefined4 uVar1;
  size_t __n;
  byte local_80;
  byte local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  undefined4 local_70;
  int local_6c;
  int local_68;
  ushort local_62;
  undefined4 local_60;
  undefined2 local_44;
  ushort local_42;
  uint local_40;
  uint local_3c;
  ushort local_38;
  ushort local_34;
  undefined4 *local_30;
  byte local_29;
  undefined4 *local_28;
  size_t local_24;
  undefined4 local_20;
  size_t local_1c;
  void *local_18;
  ushort *local_14;
  
  local_14 = (ushort *)0x0;
  local_18 = (void *)0x0;
  ZeroMemory(&local_80,0x10);
  *(undefined4 *)((int)param_1 + 0x50) = 1000000;
  uVar1 = __aeabi_uidiv(*(undefined4 *)((int)param_1 + 0x50),*(undefined4 *)((int)param_1 + 0x54));
  *(undefined4 *)((int)param_1 + 0x4c) = uVar1;
  *(int *)((int)param_1 + 0x50) = *(int *)((int)param_1 + 0x54) * *(int *)((int)param_1 + 0x4c);
  AVIOutput_SetCaptureMode(*(undefined4 *)((int)param_1 + 0x40),0);
  local_1c = GetAudioFormatSize(*(undefined4 *)((int)param_1 + 0x9c),
                                *(undefined2 *)((int)param_1 + 0x70));
  GetAudioFormat(&local_44,(int)param_1 + 0x60,local_1c);
  local_20 = GetVideoFormatSize();
  GetVideoFormat(&local_70,local_20,*(undefined4 *)((int)param_1 + 0x58),
                 *(undefined4 *)((int)param_1 + 0x5c));
  switch(*(undefined4 *)((int)param_1 + 0x98)) {
  case 1:
    local_60 = 0x44495658;
    break;
  case 2:
    local_60 = 0x33363248;
    break;
  case 3:
    return 0;
  case 4:
    return 0;
  case 5:
    local_60 = 0x34363248;
    break;
  case 6:
    return 0;
  case 7:
    local_60 = 0x47504a4d;
    break;
  case 8:
    return 0;
  case 9:
    local_60 = 0x35363248;
    break;
  default:
    return 0;
  }
  local_70 = 0x28;
  memcpy((void *)((int)param_1 + 0x14),&local_70,0x28);
  local_24 = *(size_t *)((int)param_1 + 0x14);
  local_18 = (void *)allocVideoFormat(local_24,*(undefined4 *)((int)param_1 + 0x40));
  if (local_18 == (void *)0x0) {
    (*g_medialib_printf)("##AVI muxer: ERROR--can\'t malloc bmi##\r\n");
    return 0;
  }
  memcpy(local_18,(void *)((int)param_1 + 0x14),local_24);
  local_28 = (undefined4 *)(*(int *)(*(int *)((int)param_1 + 0x40) + 4) + 8);
  ZeroMemory(local_28,0x38);
  *local_28 = 0x73646976;
  local_28[1] = *(undefined4 *)((int)param_1 + 0x24);
  local_28[5] = *(undefined4 *)((int)param_1 + 0x4c);
  local_28[6] = *(undefined4 *)((int)param_1 + 0x50);
  local_28[9] = 0;
  local_28[10] = 0xffffffff;
  *(undefined2 *)(local_28 + 0xc) = 0;
  *(undefined2 *)((int)local_28 + 0x32) = 0;
  *(short *)(local_28 + 0xd) = (short)*(undefined4 *)((int)param_1 + 0x18);
  *(short *)((int)local_28 + 0x36) = (short)*(undefined4 *)((int)param_1 + 0x1c);
  AVIOutput_SetCompressed(*(undefined4 *)((int)param_1 + 0x40),*(int *)((int)param_1 + 0x24) != 0);
  if (*(char *)((int)param_1 + 0x7c) == '\0') goto LAB_0002b444;
  switch(*(undefined4 *)((int)param_1 + 0x9c)) {
  case 2:
    local_44 = 0x55;
    if (*(int *)((int)param_1 + 0xa0) == 0) {
      if (local_40 < 32000) {
        local_38 = 0x240;
      }
      else {
        local_38 = 0x480;
      }
      local_3c = local_40;
    }
    else {
      local_3c = *(uint *)((int)param_1 + 0xa0) >> 3;
      local_38 = 1;
    }
    if (local_34 == 0xc) {
      local_80 = 1;
      local_7f = 0;
      local_7e = 2;
      local_7d = 0;
      local_7c = 0;
      local_7b = 0;
      if (local_40 < 32000) {
        local_7a = 0x40;
        local_79 = 2;
      }
      else {
        local_7a = 0x80;
        local_79 = 4;
      }
      local_78 = 1;
      local_77 = 0;
      local_76 = 0;
      local_75 = 0;
    }
    goto LAB_0002b318;
  case 3:
    local_44 = 0xff;
    local_38 = 0x400;
    local_3c = local_40;
    if (local_34 == 2) {
      local_29 = get_aacFreqIndex(local_40);
      if (0xb < local_29) {
        return 0;
      }
      local_80 = local_29 >> 1 | 0x10;
      local_7f = local_29 << 7 | (byte)((local_42 & 0x1f) << 3);
    }
    goto LAB_0002b318;
  case 4:
    local_44 = 1;
    goto LAB_0002b318;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto LAB_0002b2a4;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
LAB_0002b2a4:
    local_44 = *(undefined2 *)((int)param_1 + 0x60);
    local_3c = *(uint *)((int)param_1 + 0x68);
    local_38 = *(ushort *)((int)param_1 + 0x6c);
    if ((local_34 != 0) && (*(int *)((int)param_1 + 0x74) != 0)) {
      memcpy(&local_80,*(void **)((int)param_1 + 0x74),(uint)local_34);
    }
LAB_0002b318:
    local_14 = (ushort *)allocAudioFormat(local_1c,*(undefined4 *)((int)param_1 + 0x40));
    if (local_14 == (ushort *)0x0) {
      return 0;
    }
    memcpy(local_14,&local_44,local_1c);
    if (local_34 != 0) {
      memcpy(local_14 + 9,&local_80,(uint)local_34);
    }
    local_30 = (undefined4 *)(**(int **)((int)param_1 + 0x40) + 8);
    ZeroMemory(local_30,4);
    *local_30 = 0x73647561;
    local_30[1] = (uint)*local_14;
    local_30[5] = (uint)local_14[6];
    local_30[6] = *(undefined4 *)(local_14 + 4);
    local_30[10] = 0xffffffff;
    local_30[0xb] = (uint)local_14[6];
    if ((*(int *)((int)param_1 + 0x9c) != 4) && (*(int *)((int)param_1 + 0xa0) == 0)) {
      local_30[6] = local_40;
      local_30[0xb] = 0;
    }
LAB_0002b444:
    __n = local_1c;
    if (0x13 < local_1c) {
      __n = 0x14;
    }
    memcpy(param_1,&local_44,__n);
    *(uint *)((int)param_1 + 0x48) = (uint)local_38;
    if (local_62 == 0) {
      *(uint *)((int)param_1 + 0x44) = (local_6c * 2 + 3U & 0xfffffffd) * local_68;
    }
    else {
      *(uint *)((int)param_1 + 0x44) =
           (local_6c * ((int)(local_62 + 7) >> 3) + 3U & 0xfffffffd) * local_68;
    }
    return 1;
  }
  return 0;
}



int AVIMuxer_Init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_1 + 0x14))(0xf0);
  if (iVar1 == 0) {
    (*g_medialib_printf)("##AVI Muxer: ERROR--Init return FALSE, muxer malloc failed##\r\n");
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0xf0);
    *(int *)(iVar1 + 0x94) = param_1;
    uVar2 = newAVIOutput(param_1);
    *(undefined4 *)(iVar1 + 0x40) = uVar2;
    if (*(int *)(iVar1 + 0x40) == 0) {
      AVIMuxer_Destroy(iVar1);
      (*g_medialib_printf)("##AVI Muxer: ERROR--can\'t malloc aoFile##\r\n");
      iVar1 = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x88) = 0;
    }
  }
  return iVar1;
}



undefined4 AVIMuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    AVIMuxer_Close(param_1);
    destroyAVIOutput(*(undefined4 *)(param_1 + 0x40));
    uVar1 = (**(code **)(*(int *)(param_1 + 0x94) + 0x18))(param_1);
  }
  return uVar1;
}



bool AVIMuxer_Open(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x88) != 0) {
    return false;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  *(undefined1 *)(param_1 + 0x7d) = *(undefined1 *)(param_2 + 0x34);
  *(uint *)(param_1 + 0x54) = (uint)*(ushort *)(param_2 + 0x2c);
  *(uint *)(param_1 + 0x58) = (uint)*(ushort *)(param_2 + 0x10);
  *(uint *)(param_1 + 0x5c) = (uint)*(ushort *)(param_2 + 0x12);
  *(undefined1 *)(param_1 + 0x7c) = *(undefined1 *)(param_2 + 0x36);
  *(uint *)(param_1 + 0xb0) = (uint)*(ushort *)(param_2 + 0x2e);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x44);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0x48);
  *(undefined2 *)(*(int *)(param_1 + 0x40) + 0x4c8) = *(undefined2 *)(param_2 + 0x3a);
  *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x15) =
       *(undefined1 *)(param_2 + 0x37);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_2 + 0x68);
  *(undefined2 *)(param_1 + 0xec) = *(undefined2 *)(param_2 + 0x6c);
  *(undefined2 *)(param_1 + 0xee) = *(undefined2 *)(param_2 + 0x6e);
  *(undefined2 *)(*(int *)(param_1 + 0x40) + 0x4d4) = *(undefined2 *)(param_2 + 0x6c);
  *(undefined2 *)(*(int *)(param_1 + 0x40) + 0x4d6) = *(undefined2 *)(param_2 + 0x6e);
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x15) == '\0') {
    if (*(char *)(param_1 + 0x7d) == '\0') {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0xc) =
           *(undefined4 *)(param_2 + 0xc);
    }
    else {
      *(uint *)(param_1 + 0x78) = *(uint *)(param_2 + 0x3c) >> 4;
      if (*(uint *)(param_1 + 0x78) < *(uint *)(param_1 + 0x54)) {
        (*g_medialib_printf)("##AVI Muxer: ERROR--index memory is too small##\r\n");
        AVIMuxer_Close(param_1);
        return false;
      }
      if (*(int *)(param_2 + 0x68) == 0) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x40) + 0x440);
        uVar1 = (**(code **)(*(int *)(param_1 + 0x94) + 0x14))(*(undefined4 *)(param_2 + 0x3c));
        *(undefined4 *)(iVar2 + 0x10) = uVar1;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x10) =
             *(undefined4 *)(param_2 + 0x68);
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x10) == 0) {
        (*g_medialib_printf)("##AVI Muxer: ERROR--can\'t malloc entryBuffer##\r\n");
        AVIMuxer_Close(param_1);
        return false;
      }
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x1c) =
           *(undefined4 *)(param_1 + 0x78);
    }
  }
  if (*(char *)(param_1 + 0x7c) != '\0') {
    memcpy((void *)(param_1 + 0x60),(void *)(param_2 + 0x14),0x18);
  }
  *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x14) =
       *(undefined1 *)(param_1 + 0x7d);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x18) =
       *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 8) = *(undefined4 *)(param_2 + 4);
  iVar2 = AVIMuxer_SetParam(param_1);
  if (iVar2 == 0) {
    (*g_medialib_printf)("##AVI Muxer: ERROR--SetParam failed##\r\n");
    AVIMuxer_Close(param_1);
  }
  return iVar2 != 0;
}



undefined4 AVIMuxer_Close(int param_1)

{
  if (*(int *)(param_1 + 0x88) != 0) {
    AVIMuxer_Stop(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x40) + 8) = 0;
    (**(code **)(*(int *)(param_1 + 0x94) + 0x18))(*(undefined4 *)(param_1 + 0x8c));
    if (*(int *)(param_1 + 0xe8) == 0) {
      (**(code **)(*(int *)(param_1 + 0x94) + 0x18))
                (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x10));
    }
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  return 1;
}



undefined1 AVIMuxer_Start(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  if (*(int *)(param_1 + 0x88) == 1) {
    MediaFile_SetPosition(*(undefined4 *)(*(int *)(param_1 + 0x40) + 8),0);
    cVar1 = AVIOutput_WriteHDR(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x18),
                               *(undefined4 *)(param_1 + 0x1c),*(undefined1 *)(param_1 + 0x7c),1);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = 2;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined1 AVIMuxer_Restart(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  if (*(int *)(param_1 + 0x88) == 3) {
    *(undefined4 *)(param_1 + 0x80) = 0;
    AVIOutput_Reinit(*(undefined4 *)(param_1 + 0x40));
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 4) != 0) {
      *(undefined4 *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 4) + 0xc04) = 0;
    }
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 8) = 0;
    if (*(char *)(param_1 + 0x7d) == '\0') {
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0xc) != *(int *)(param_2 + 0xc)) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0xc) =
             *(undefined4 *)(param_2 + 0xc);
      }
      (**(code **)(*(int *)(param_1 + 0x94) + 0xc))
                (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0xc),0,0);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x40) + 8) = *(undefined4 *)(param_2 + 4);
    MediaFile_SetPosition(*(undefined4 *)(*(int *)(param_1 + 0x40) + 8),0);
    cVar1 = AVIOutput_WriteHDR(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x18),
                               *(undefined4 *)(param_1 + 0x1c),*(undefined1 *)(param_1 + 0x7c),1);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x88) = 2;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined1 AVIMuxer_Stop(int param_1)

{
  undefined1 uVar1;
  undefined4 local_10;
  undefined1 local_9;
  
  local_9 = 0;
  if ((*(int *)(param_1 + 0x88) == 2) || (*(int *)(param_1 + 0x88) == 5)) {
    *(undefined4 *)(param_1 + 0x88) = 3;
    if ((*(char *)(param_1 + 0x7c) != '\0') && (*(int *)(param_1 + 0xa0) == 0)) {
      local_10 = 0;
      MulDiv(&local_10,**(undefined4 **)(*(int *)(param_1 + 0x40) + 4),1000,
             *(undefined4 *)(param_1 + 0x54));
      AVIOutput_SetAudioSamples(*(undefined4 *)(param_1 + 0x40),local_10);
    }
    uVar1 = AVIOutput_Finalize(*(undefined4 *)(param_1 + 0x40));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 AVIMuxer_ProcessAudio(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*(char *)(param_1 + 0x7c) == '\0') {
    (*g_medialib_printf)("##AVI Muxer: WARNING--no capture audio##\r\n");
    uVar2 = *(undefined4 *)(param_1 + 0x88);
  }
  else if (*(int *)(param_1 + 0x88) == 2) {
    if ((*(int *)(param_1 + 0x9c) == 4) || (*(int *)(param_1 + 0x9c) == 7)) {
      local_c = __aeabi_uidiv(param_2[1],*(undefined4 *)(param_1 + 0x48));
    }
    else {
      local_c = 1;
    }
    iVar1 = AVIOutput_writeAudioIndex(*(undefined4 *)(param_1 + 0x40),0,*param_2,param_2[1],local_c)
    ;
    if (iVar1 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x4c6) == '\0') {
        *(undefined4 *)(param_1 + 0x88) = 4;
      }
      else {
        *(undefined4 *)(param_1 + 0x88) = 5;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x88);
    }
    else {
      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x4c6) == '\0') {
        *(undefined4 *)(param_1 + 0x88) = 4;
        uVar2 = *(undefined4 *)(param_1 + 0x88);
      }
      else {
        if (*(char *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x15) == '\0') {
          if (*(char *)(param_1 + 0x7d) == '\0') {
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x80) * 0x20 + 100;
          }
          else {
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x80) * 0x10 + 100;
          }
        }
        uVar2 = 2;
      }
    }
  }
  else {
    (*g_medialib_printf)
              ("##AVI Muxer: ERROR--Process audio status %d##\r\n",*(undefined4 *)(param_1 + 0x88));
    uVar2 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar2;
}



undefined4 AVIMuxer_ProcessVideo(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x88) == 2) {
    if (*(char *)(param_2 + 3) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x10;
    }
    iVar1 = AVIOutput_writeVideoIndex(*(undefined4 *)(param_1 + 0x40),uVar2,*param_2,param_2[1],1);
    if (iVar1 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x4c6) == '\0') {
        *(undefined4 *)(param_1 + 0x88) = 4;
      }
      else {
        *(undefined4 *)(param_1 + 0x88) = 5;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x88);
    }
    else {
      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x4c6) == '\0') {
        *(undefined4 *)(param_1 + 0x88) = 4;
        uVar2 = *(undefined4 *)(param_1 + 0x88);
      }
      else {
        if (*(char *)(*(int *)(*(int *)(param_1 + 0x40) + 0x440) + 0x15) == '\0') {
          if (*(char *)(param_1 + 0x7d) == '\0') {
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x80) * 0x20 + 100;
          }
          else {
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x80) * 0x10 + 100;
          }
        }
        uVar2 = 2;
      }
    }
  }
  else {
    (*g_medialib_printf)
              ("##AVI Muxer: ERROR--Process video status %d##\r\n",*(undefined4 *)(param_1 + 0x88));
    uVar2 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar2;
}



undefined4 AVIMuxer_GetHeaderSize(int param_1)

{
  return *(undefined4 *)(param_1 + 0x84);
}



undefined4 AVIMuxer_GetCurrFileSize(int param_1)

{
  return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 8) + 4);
}



int newAVIIndex(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x14))(0x28);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x28);
    *(int *)(iVar1 + 0x24) = param_1;
    *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
  }
  return iVar1;
}



undefined4 destroyAVIIndex(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    AVIIndex_DeleteChain(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 * newAVIIndexChainNode(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x24) + 0x14))(0xc08);
  if (puVar1 == (undefined4 *)0x0) {
    (*g_medialib_printf)("##AVI index: ERROR--add chain error##\r\n");
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[0x301] = 0;
    *puVar1 = 0;
  }
  return puVar1;
}



undefined4
AVIIndexChainNode_Add(int param_1,undefined4 param_2,undefined4 param_3,int param_4,char param_5)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc04) < 0x100) {
    *(undefined4 *)(param_1 + *(int *)(param_1 + 0xc04) * 0xc + 8) = param_2;
    *(undefined4 *)(param_1 + *(int *)(param_1 + 0xc04) * 0xc + 4) = param_3;
    if (param_5 == '\0') {
      param_4 = param_4 + -0x80000000;
    }
    *(int *)(param_1 + *(int *)(param_1 + 0xc04) * 0xc + 0xc) = param_4;
    *(int *)(param_1 + 0xc04) = *(int *)(param_1 + 0xc04) + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



void AVIIndex_DeleteChain(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_c;
  
  local_c = (undefined4 *)*param_1;
  while (local_c != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*local_c;
    (**(code **)(param_1[9] + 0x18))(local_c);
    local_c = puVar1;
  }
  param_1[1] = 0;
  *param_1 = param_1[1];
  return;
}



void AVIIndexChainNode_PutNodeEntry(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *local_18;
  int local_c;
  
  local_18 = param_2;
  for (local_c = 0; local_c < *(int *)(param_1 + 0xc04); local_c = local_c + 1) {
    *local_18 = *(undefined4 *)(param_1 + local_c * 0xc + 8);
    if (*(int *)(param_1 + local_c * 0xc + 0xc) < 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x10;
    }
    local_18[1] = uVar1;
    local_18[2] = *(undefined4 *)(param_1 + local_c * 0xc + 4);
    local_18[3] = *(uint *)(param_1 + local_c * 0xc + 0xc) & 0x7fffffff;
    local_18 = local_18 + 4;
  }
  return;
}



undefined4 AVIIndex_PutEntry(int *param_1,void *param_2)

{
  size_t __n;
  size_t sVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    AVIIndexChainNode_PutNodeEntry(iVar2,param_2);
    __n = *(int *)(iVar2 + 0xc04) * 0x10;
    if ((char)param_1[5] == '\0') {
      sVar1 = (**(code **)(param_1[9] + 8))(param_1[3],param_2,__n);
      if (sVar1 != __n) {
        (*g_medialib_printf)("##AVI Index: WARNING--write index file failed##\r\n");
        *(byte *)(param_1[6] + 0x4c7) = *(byte *)(param_1[6] + 0x4c7) | 1;
        return 0;
      }
    }
    else {
      if (param_1[7] < param_1[2]) {
        (*g_medialib_printf)
                  ("##AVI Index: WARNING--save index failed, %d %d##\r\n",param_1[2],param_1[7]);
        *(byte *)(param_1[6] + 0x4c7) = *(byte *)(param_1[6] + 0x4c7) | 1;
        return 0;
      }
      memcpy((void *)(param_1[4] + param_1[8]),param_2,__n);
      param_1[8] = param_1[8] + __n;
    }
  }
  return 1;
}



undefined4 AVIIndex_MakeIndex(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1008 [4096];
  
  uVar1 = AVIIndex_PutEntry(param_1,auStack_1008);
  return uVar1;
}



bool AVIIndex_AddChain(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined1 param_5)

{
  int iVar1;
  
  if ((param_1[1] != 0) &&
     (iVar1 = AVIIndexChainNode_Add(param_1[1],param_2,param_3,param_4,param_5), iVar1 != 0)) {
    param_1[2] = param_1[2] + 1;
    return true;
  }
  if (param_1[1] == 0) {
    iVar1 = newAVIIndexChainNode(param_1);
    if (iVar1 == 0) {
      return false;
    }
    *param_1 = iVar1;
    param_1[1] = iVar1;
  }
  else {
    iVar1 = AVIIndex_MakeIndex(param_1);
    if (iVar1 == 0) {
      (*g_medialib_printf)("##AVI Output: WARNING--AddChain, make Index error##\r\n");
      return false;
    }
    *(undefined4 *)(param_1[1] + 0xc04) = 0;
  }
  iVar1 = AVIIndexChainNode_Add(param_1[1],param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  return iVar1 != 0;
}



undefined4 AVIIndex_AddEntry2(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x15) == '\0') {
    uVar1 = AVIIndex_AddChain(param_1,param_2[1],*param_2,param_2[2] & 0x7fffffff,
                              (uint)param_2[2] >> 0x1f);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 AVIIndex_WriteIndexFromTemp(int *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1028 [4096];
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = param_1[6];
  local_24 = *param_1;
  local_28 = param_1[2];
  if ((param_1[2] == 0) || (local_24 == 0)) {
    (*g_medialib_printf)("##AVI Index: WARNING--no frame is record##\r\n");
    uVar1 = 1;
  }
  else {
    local_28 = local_28 - *(int *)(local_24 + 0xc04);
    if ((char)param_1[5] == '\0') {
      if (0 < local_28) {
        (**(code **)(param_1[9] + 0xc))(param_1[3],0,0);
        local_1c = 0x1000;
        local_18 = (**(code **)(param_1[9] + 4))(param_1[3],auStack_1028,0x1000);
        local_14 = local_18 >> 4;
      }
      (*g_medialib_printf)
                ("##AVI Index: FileRead successed and loop %d, %d##\r\n",param_1[2],local_18);
      while (0 < local_18) {
        if (local_28 < local_14) {
          local_18 = local_18 + (local_14 - local_28) * -0x10;
          AVIOutput_writeIn(local_20,auStack_1028,local_18);
          break;
        }
        AVIOutput_writeIn(local_20,auStack_1028,local_18);
        if (*(char *)(local_20 + 0x4c6) == '\0') {
          (*g_medialib_printf)("##AVI Index: ERROR--Writing index is not valid##\r\n");
          return 0;
        }
        local_18 = (**(code **)(param_1[9] + 4))(param_1[3],auStack_1028,local_1c);
        local_14 = local_14 + (local_18 >> 4);
      }
      (**(code **)(param_1[9] + 0xc))(param_1[3],0,0);
LAB_0002ce2c:
      (*g_medialib_printf)("##AVI Index: exit loop %d##\r\n",*(undefined4 *)(local_24 + 0xc04));
      if (*(int *)(local_24 + 0xc04) != 0) {
        AVIIndexChainNode_PutNodeEntry(local_24,auStack_1028);
        local_18 = *(int *)(local_24 + 0xc04) << 4;
        local_14 = local_14 + (local_18 >> 4);
        AVIOutput_writeIn(local_20,auStack_1028,local_18);
        if (*(char *)(local_20 + 0x4c6) == '\0') {
          (*g_medialib_printf)("##AVI Index: ERROR--Writing index is not valid 2##\r\n");
          return 0;
        }
      }
      uVar1 = 1;
    }
    else {
      (*g_medialib_printf)
                ("##AVI Index: total_ents %d, entryBuffer 0x%x##\r\n",param_1[2],param_1[4]);
      do {
        if (local_28 - local_14 < 1) {
          param_1[8] = 0;
          goto LAB_0002ce2c;
        }
        if (local_28 - local_14 < 0x101) {
          AVIOutput_writeIn(local_20,param_1[4] + local_14 * 0x10,(local_28 - local_14) * 0x10);
          local_14 = param_1[2];
        }
        else {
          AVIOutput_writeIn(local_20,param_1[4] + local_14 * 0x10,0x1000);
          local_14 = local_14 + 0x100;
        }
      } while (*(char *)(local_20 + 0x4c6) != '\0');
      (*g_medialib_printf)("##AVI Index: ERROR--Writing index is not valid##\r\n");
      uVar1 = 0;
    }
  }
  return uVar1;
}



int * newAVIOutput(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(param_1 + 0x14))(0x4d8);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    ZeroMemory(piVar1,0x4d8);
    piVar1[0x133] = param_1;
    iVar2 = (**(code **)(piVar1[0x133] + 0x14))(0x3000);
    piVar1[0x111] = iVar2;
    if (piVar1[0x111] == 0) {
      destroyAVIOutput(piVar1);
      (*g_medialib_printf)("##AVI Output: ERROR--can\'t malloc pHeaderBlock!##\r\n");
      piVar1 = (int *)0x0;
    }
    else {
      iVar2 = newAVIOutputStream(piVar1);
      piVar1[1] = iVar2;
      iVar2 = newAVIOutputStream(piVar1);
      *piVar1 = iVar2;
      if ((piVar1[1] == 0) || (*piVar1 == 0)) {
        destroyAVIOutput(piVar1);
        (*g_medialib_printf)("##AVI Output: ERROR--can\'t malloc videoOut or audioOut!##\r\n");
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = newAVIIndex(param_1);
        piVar1[0x110] = iVar2;
        if (piVar1[0x110] == 0) {
          destroyAVIOutput(piVar1);
          (*g_medialib_printf)("##AVI Output: ERROR--can\'t malloc index!##\r\n");
          piVar1 = (int *)0x0;
        }
        else {
          piVar1[2] = 0;
          piVar1[3] = 0;
          piVar1[4] = 0;
          piVar1[0x105] = 0;
          *(undefined1 *)(piVar1 + 0x123) = 1;
          piVar1[0x121] = 0x7f000000;
          *(undefined1 *)((int)piVar1 + 0x48d) = 0;
          piVar1[0x122] = 0;
          piVar1[0x124] = 0;
          piVar1[0x125] = 0;
          *(undefined1 *)((int)piVar1 + 0x48e) = 0;
          piVar1[0x112] = 0;
          piVar1[0x127] = 0;
          piVar1[0x128] = 0;
          piVar1[0x129] = 0;
          piVar1[0x12a] = 0;
          piVar1[299] = 0;
          piVar1[300] = 0;
          piVar1[0x12d] = 0;
          piVar1[0x12e] = 0;
          piVar1[0x12f] = 0;
          piVar1[0x130] = 0;
          *(undefined1 *)(piVar1 + 0x131) = 0;
          *(undefined1 *)((int)piVar1 + 0x4c5) = 0;
          *(undefined1 *)((int)piVar1 + 0x4c6) = 1;
          *(undefined1 *)((int)piVar1 + 0x4c7) = 0;
        }
      }
    }
  }
  return piVar1;
}



void destroyAVIOutput(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    destroyAVIIndex(param_1[0x110]);
    destroyAVIOutputStream(param_1[1],param_1);
    destroyAVIOutputStream(*param_1,param_1);
    (**(code **)(param_1[0x133] + 0x18))(param_1[0x111]);
    (**(code **)(param_1[0x133] + 0x18))(param_1);
  }
  return;
}



bool AVIOutput_Reinit(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *(undefined4 *)param_1[1] = 0;
    *(undefined4 *)*param_1 = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[0x105] = 0;
    param_1[0x122] = 0;
    param_1[0x124] = 0;
    param_1[0x125] = 0;
    *(undefined1 *)((int)param_1 + 0x48e) = 0;
    param_1[0x112] = 0;
    param_1[0x127] = 0;
    param_1[0x128] = 0;
    param_1[0x129] = 0;
    param_1[0x12a] = 0;
    param_1[299] = 0;
    param_1[300] = 0;
    param_1[0x12d] = 0;
    param_1[0x12e] = 0;
    param_1[0x12f] = 0;
    param_1[0x130] = 0;
    *(undefined1 *)(param_1 + 0x131) = 0;
    *(undefined1 *)((int)param_1 + 0x4c6) = 1;
    *(undefined1 *)((int)param_1 + 0x4c7) = 0;
  }
  return param_1 != (undefined4 *)0x0;
}



undefined4 * newAVIOutputStream(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + 0x4cc) + 0x14))(0x48);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    ZeroMemory(puVar1,0x48);
    puVar1[0x11] = 0;
    *puVar1 = 0;
    ZeroMemory(puVar1 + 2,0x38);
  }
  return puVar1;
}



void destroyAVIOutputStream(int param_1,int param_2)

{
  if (param_1 != 0) {
    (**(code **)(*(int *)(param_2 + 0x4cc) + 0x18))(*(undefined4 *)(param_1 + 0x44));
    (**(code **)(*(int *)(param_2 + 0x4cc) + 0x18))(param_1);
  }
  return;
}



undefined4 AVIOutput_WriteHDR(int *param_1,int param_2,int param_3,char param_4,char param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_2248 [8192];
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined1 auStack_148 [256];
  undefined4 local_48;
  undefined4 local_44;
  uint local_24;
  size_t local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  *(undefined1 *)((int)param_1 + 0x48f) = 1;
  if ((param_4 == '\0') || (*param_1 != 0)) {
    if (param_1[1] == 0) {
      uVar2 = 0;
    }
    else if (param_1[2] == 0) {
      uVar2 = 0;
    }
    else {
      ZeroMemory(param_1 + 0x113,0x38);
      param_1[0x113] = *(int *)(param_1[1] + 0x1c);
      param_1[0x114] = 0;
      param_1[0x115] = 0;
      if (param_5 == '\0') {
        iVar3 = 0x10;
      }
      else {
        iVar3 = 0x110;
      }
      param_1[0x116] = iVar3;
      param_1[0x117] = *(int *)(param_1[1] + 0x28);
      param_1[0x118] = 0;
      if (param_4 == '\0') {
        iVar3 = 1;
      }
      else {
        iVar3 = 2;
      }
      param_1[0x119] = iVar3;
      param_1[0x11a] = 0;
      param_1[0x11b] = param_2;
      param_1[0x11c] = param_3;
      param_1[3] = 0;
      local_248 = 0x46464952;
      local_244 = 0;
      local_240 = 0x20495641;
      AVIOutput_writeHeader(param_1,&local_248,0xc);
      local_14 = AVIOutput_beginList(param_1,0x6c726468);
      iVar3 = AVIOutput_writeHeaderChunk(param_1,0x68697661,param_1 + 0x113,0x38);
      param_1[0x107] = iVar3;
      iVar3 = AVIOutput_beginList(param_1,0x6c727473);
      param_1[0x106] = iVar3;
      iVar3 = AVIOutput_writeHeaderChunk(param_1,0x68727473,param_1[1] + 8,0x38);
      param_1[0x10a] = iVar3;
      AVIOutput_writeHeaderChunk
                (param_1,0x66727473,*(undefined4 *)(param_1[1] + 0x44),
                 *(undefined4 *)(param_1[1] + 0x40));
      if ((char)param_1[0x123] != '\0') {
        ZeroMemory(&local_48,0x20);
        ZeroMemory(auStack_148,0x100);
        iVar3 = AVIOutput_getPosition(param_1);
        param_1[0x10c] = iVar3;
        local_48 = 0x4b4e554a;
        local_44 = 0x118;
        AVIOutput_writeHeader(param_1,&local_48,0x20);
        AVIOutput_writeHeader(param_1,auStack_148,0x100);
      }
      AVIOutput_closeList(param_1,param_1[0x106]);
      *(undefined4 *)(param_1[1] + 0x2c) = 0;
      *(char *)((int)param_1 + 0x4c5) = param_4;
      if (param_4 != '\0') {
        iVar3 = AVIOutput_beginList(param_1,0x6c727473);
        param_1[0x106] = iVar3;
        iVar3 = AVIOutput_writeHeaderChunk(param_1,0x68727473,*param_1 + 8,0x38);
        param_1[0x108] = iVar3;
        iVar3 = AVIOutput_writeHeaderChunk
                          (param_1,0x66727473,*(undefined4 *)(*param_1 + 0x44),
                           *(undefined4 *)(*param_1 + 0x40));
        param_1[0x109] = iVar3;
        if ((char)param_1[0x123] != '\0') {
          iVar3 = AVIOutput_getPosition(param_1);
          param_1[0x10b] = iVar3;
          local_48 = 0x4b4e554a;
          local_44 = 0x118;
          AVIOutput_writeHeader(param_1,&local_48,0x20);
          AVIOutput_writeHeader(param_1,auStack_148,0x100);
        }
        AVIOutput_closeList(param_1,param_1[0x106]);
        *(undefined4 *)(*param_1 + 0x2c) = 0;
      }
      if ((char)param_1[0x123] != '\0') {
        local_18 = AVIOutput_beginList(param_1,0x6c6d646f);
        ZeroMemory(&local_248,0x100);
        iVar3 = AVIOutput_writeHeaderChunk(param_1,0x686c6d64,&local_248,0xf8);
        param_1[0x10d] = iVar3;
        AVIOutput_closeList(param_1,local_18);
      }
      if (param_1[0x124] != 0) {
        iVar3 = AVIOutput_writeHeaderChunk(param_1,0x6d676573,param_1[0x124],param_1[0x125]);
        param_1[0x10e] = iVar3;
      }
      AVIOutput_closeList(param_1,local_14);
      local_1c = AVIOutput_beginList(param_1,0x4f464e49);
      memcpy(&local_248,"ankarec ",8);
      iVar3 = AVIOutput_writeHeaderChunk(param_1,0x54465349,&local_248,8);
      param_1[0x10f] = iVar3;
      AVIOutput_closeList(param_1,local_1c);
      uVar1 = *(ushort *)(param_1 + 0x132);
      iVar3 = AVIOutput_getPosition(param_1);
      if ((iVar3 + 0x14U < (uint)uVar1) && (*(ushort *)(param_1 + 0x132) < 0x2001)) {
        uVar1 = *(ushort *)(param_1 + 0x132);
        iVar3 = AVIOutput_getPosition(param_1);
        local_20 = ((uint)uVar1 - iVar3) - 0x14;
        if (local_20 != 0) {
          memset(auStack_2248,0,local_20);
          AVIOutput_writeHeaderChunk(param_1,0x4b4e554a,auStack_2248,local_20);
        }
      }
      else {
        iVar3 = AVIOutput_getPosition(param_1);
        local_24 = -iVar3 - 8U & 0x7ff;
        if (local_24 != 0) {
          ZeroMemory(auStack_2248,local_24);
          AVIOutput_writeHeaderChunk(param_1,0x4b4e554a,auStack_2248,local_24);
        }
      }
      AVIOutput_flushHeader(param_1);
      AVIOutput_openXblock(param_1);
      iVar3 = MediaFile_GetPosition(param_1[2]);
      if (iVar3 == 0) {
        param_1[0x126] = 0;
      }
      else {
        param_1[0x126] = iVar3;
      }
      if (*(int *)(param_1[2] + 0x14) == 0) {
        *(undefined1 *)((int)param_1 + 0x48e) = 1;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 AVIOutput_Finalize(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_25c;
  undefined4 local_258;
  undefined1 auStack_254 [256];
  undefined1 auStack_154 [256];
  undefined1 auStack_54 [32];
  undefined1 auStack_34 [32];
  int local_14;
  
  if ((*(char *)((int)param_1 + 0x4c6) == '\0') && ((*(byte *)((int)param_1 + 0x4c7) & 0x10) != 0))
  {
    (*g_medialib_printf)("##AVI output: ERROR--Finalize, Writing file is not valid##\r\n");
    uVar2 = 0;
  }
  else {
    (*g_medialib_printf)("#in finalize#\r\n");
    if (*(char *)((int)param_1 + 0x48e) == '\0') {
      uVar2 = 1;
    }
    else if ((param_1[1] == 0) || (iVar1 = AVIOutputStream_Finalize(param_1[1]), iVar1 != 0)) {
      if ((*(char *)((int)param_1 + 0x4c5) == '\0') ||
         ((*param_1 == 0 || (iVar1 = AVIOutputStream_Finalize(*param_1), iVar1 != 0)))) {
        if (((char)param_1[0x123] != '\0') && (param_1[0x105] != 0)) {
          AVIOutput_createNewIndices_extend(param_1,param_1[0x110],auStack_34,auStack_154,0);
          if ((*(char *)((int)param_1 + 0x4c5) != '\0') && (*param_1 != 0)) {
            AVIOutput_createNewIndices_extend(param_1,param_1[0x110],auStack_54,auStack_254,1);
          }
        }
        AVIOutput_closeXblock(param_1);
        if (*(char *)((int)param_1 + 0x4c6) == '\0') {
          uVar2 = 0;
        }
        else {
          (*g_medialib_printf)("##AVI Output: Writing main AVI header...##\r\n");
          AVIOutput_seekHeader(param_1,param_1[0x107] + 8);
          AVIOutput_writeHeader(param_1,param_1 + 0x113,0x38);
          AVIOutput_seekHeader(param_1,param_1[0x10a] + 8);
          AVIOutput_writeHeader(param_1,param_1[1] + 8,0x38);
          if ((*(char *)((int)param_1 + 0x4c5) != '\0') && (*param_1 != 0)) {
            AVIOutput_seekHeader(param_1,param_1[0x108] + 8);
            AVIOutput_writeHeader(param_1,*param_1 + 8,0x38);
            AVIOutput_seekHeader(param_1,param_1[0x109] + 8);
            AVIOutput_writeHeader
                      (param_1,*(undefined4 *)(*param_1 + 0x44),*(undefined4 *)(*param_1 + 0x40));
          }
          if ((char)param_1[0x123] != '\0') {
            (*g_medialib_printf)("##AVI Output: writing dmlh header...##\r\n");
            AVIOutput_seekHeader(param_1,param_1[0x10d] + 8);
            local_258 = *(undefined4 *)(param_1[1] + 0x28);
            AVIOutput_writeHeader(param_1,&local_258,4);
            if (1 < param_1[0x105]) {
              (*g_medialib_printf)("##AVI Output: writing video superindex...##\r\n");
              AVIOutput_seekHeader(param_1,param_1[0x10c]);
              AVIOutput_writeHeader(param_1,auStack_34,0x20);
              AVIOutput_writeHeader(param_1,auStack_154,0x100);
              if ((*(char *)((int)param_1 + 0x4c5) != '\0') && (*param_1 != 0)) {
                AVIOutput_seekHeader(param_1,param_1[0x10b]);
                AVIOutput_writeHeader(param_1,auStack_54,0x20);
                AVIOutput_writeHeader(param_1,auStack_254,0x100);
              }
            }
          }
          if (param_1[0x124] != 0) {
            AVIOutput_seekHeader(param_1,param_1[0x10e] + 8);
            AVIOutput_writeHeader(param_1,param_1[0x124],param_1[0x125]);
          }
          AVIOutput_flushHeader(param_1);
          for (local_14 = 0; local_14 < param_1[0x105]; local_14 = local_14 + 1) {
            local_25c = param_1[local_14 + 0xc5];
            AVIOutput_seekDirect(param_1,param_1[local_14 + 0x85] + 4);
            AVIOutput_writeDirect(param_1,&local_25c,4);
            local_25c = param_1[local_14 + 0x45];
            AVIOutput_seekDirect(param_1,param_1[local_14 + 5] + 4);
            AVIOutput_writeDirect(param_1,&local_25c,4);
          }
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined4 AVIOutputStream_Finalize(int *param_1)

{
  if (*param_1 == 0) {
    param_1[10] = 1;
  }
  else {
    param_1[10] = *param_1;
  }
  return 1;
}



void AVIOutput_SetCaptureMode(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x48d) = param_2;
  return;
}



void AVIOutput_SetCompressed(int param_1,char param_2)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    uVar1 = 0x62643030;
  }
  else {
    uVar1 = 0x63643030;
  }
  *(undefined4 *)(*(int *)(param_1 + 4) + 4) = uVar1;
  return;
}



int AVIOutput_writeHeader(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x448) < (int)(*(int *)(param_1 + 0xc) + param_3)) &&
     (*(size_t *)(param_1 + 0x448) = *(int *)(param_1 + 0xc) + param_3,
     0x3000 < *(int *)(param_1 + 0x448))) {
    *(undefined1 *)(param_1 + 0x4c6) = 0;
    *(byte *)(param_1 + 0x4c7) = *(byte *)(param_1 + 0x4c7) | 0x10;
    iVar1 = 0;
  }
  else {
    memcpy((void *)(*(int *)(param_1 + 0x444) + *(int *)(param_1 + 0xc)),param_2,param_3);
    *(size_t *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    iVar1 = *(int *)(param_1 + 0xc) - param_3;
  }
  return iVar1;
}



undefined4 AVIOutput_beginList(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0x5453494c;
  local_10 = 0;
  local_c = param_2;
  uVar1 = AVIOutput_writeHeader(param_1,&local_14,0xc);
  return uVar1;
}



undefined4
AVIOutput_writeHeaderChunk(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  
  local_14 = param_2;
  local_10 = param_4;
  local_c = AVIOutput_writeHeader(param_1,&local_14,8);
  AVIOutput_writeHeader(param_1,param_3,param_4);
  if ((param_4 & 1) != 0) {
    local_14 = 0;
    AVIOutput_writeHeader(param_1,&local_14,1);
  }
  return local_c;
}



void AVIOutput_seekHeader(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



void AVIOutput_closeList(int param_1,int param_2)

{
  int local_10;
  undefined4 local_c;
  
  local_c = *(undefined4 *)(param_1 + 0xc);
  local_10 = (*(int *)(param_1 + 0xc) - param_2) + -8;
  AVIOutput_seekHeader(param_1,param_2 + 4);
  AVIOutput_writeHeader(param_1,&local_10,4);
  AVIOutput_seekHeader(param_1,local_c);
  return;
}



undefined4 AVIOutput_getPosition(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



void AVIOutput_flushHeader(int param_1)

{
  int iVar1;
  
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 8),0);
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar1 = MediaFile_Write(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x444),
                          *(undefined4 *)(param_1 + 0x448));
  if (*(int *)(param_1 + 0x448) != iVar1) {
    *(undefined1 *)(param_1 + 0x4c6) = 0;
    *(byte *)(param_1 + 0x4c7) = *(byte *)(param_1 + 0x4c7) | 0x10;
    (*g_medialib_printf)("##AVI Output: ERROR--write into avi file error!##\r\n");
  }
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x448);
  if (*(uint *)(param_1 + 0x49c) < *(uint *)(param_1 + 0xc)) {
    *(undefined4 *)(param_1 + 0x49c) = *(undefined4 *)(param_1 + 0xc);
  }
  return;
}



int AVIOutput_writeDirect(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x4c6) == '\0') && ((*(byte *)(param_1 + 0x4c7) & 0x10) != 0)) {
    (*g_medialib_printf)("##AVI output: ERROR--Writing file is not valid##\r\n");
    param_3 = 0;
  }
  else {
    iVar1 = MediaFile_Write(*(undefined4 *)(param_1 + 8),param_2,param_3);
    if (param_3 != iVar1) {
      *(undefined1 *)(param_1 + 0x4c6) = 0;
      *(byte *)(param_1 + 0x4c7) = *(byte *)(param_1 + 0x4c7) | 0x10;
      (*g_medialib_printf)("##AVI output: ERROR--writeDirect error!##\r\n");
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    if (*(uint *)(param_1 + 0x49c) < *(uint *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0x49c) = *(undefined4 *)(param_1 + 0xc);
    }
    param_3 = *(int *)(param_1 + 0xc) - param_3;
  }
  return param_3;
}



void AVIOutput_seekDirect(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 8));
  if (uVar1 < param_2) {
    (*g_medialib_printf)("##AVI output: ERROR--seek error!##\r\n");
  }
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 8),param_2);
  *(uint *)(param_1 + 0xc) = param_2;
  return;
}



undefined1 AVIOutput_extendFile(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_1 + 0x498) <= param_2) {
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    AVIOutput_seekDirect(param_1,param_2);
    AVIOutput_seekDirect(param_1,uVar1);
    *(uint *)(param_1 + 0x498) = param_2;
  }
  return 1;
}



void AVIOutput_writeIn(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  AVIOutput_writeDirect(param_1,param_2,param_3);
  return;
}



void AVIOutput_openXblock(int param_1)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(int *)(param_1 + 0x414) < 0x40) {
    if (*(int *)(param_1 + 0x414) == 0) {
      *(undefined4 *)(param_1 + (*(int *)(param_1 + 0x414) + 0x84) * 4 + 4) = 0;
      *(undefined4 *)(param_1 + (*(int *)(param_1 + 0x414) + 4) * 4 + 4) =
           *(undefined4 *)(param_1 + 0xc);
      local_28 = 0x5453494c;
      local_24 = 0x7fffffff;
      local_20 = 0x69766f6d;
      if (*(char *)(param_1 + 0x48d) != '\0') {
        *(undefined4 *)(param_1 + 0x488) = 4;
      }
      AVIOutput_writeIn(param_1,&local_28,0xc);
    }
    else {
      *(undefined4 *)(param_1 + (*(int *)(param_1 + 0x414) + 0x84) * 4 + 4) =
           *(undefined4 *)(param_1 + 0xc);
      local_28 = 0x46464952;
      local_24 = 0x7f000000;
      if (*(int *)(param_1 + 0x414) == 0) {
        local_20 = 0x20495641;
      }
      else {
        local_20 = 0x58495641;
      }
      local_1c = 0x5453494c;
      local_18 = 0x7f000000;
      local_14 = 0x69766f6d;
      AVIOutput_writeIn(param_1,&local_28,0x18);
      *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 4) * 4 + 4) = *(int *)(param_1 + 0xc) + -0xc;
    }
  }
  else {
    (*g_medialib_printf)("##AVI Output: Exceeded maximum RIFF count %d##\r\n",0x40);
  }
  return;
}



int AVIOutput_writeLegacyIndex(int param_1)

{
  int iVar1;
  undefined4 local_18;
  int local_14;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x440) != 0) {
    if (*(char *)(*(int *)(param_1 + 0x440) + 0x15) == '\0') {
      local_18 = 0x31786469;
      local_14 = *(int *)(*(int *)(param_1 + 0x440) + 8) << 4;
      AVIOutput_writeIn(param_1,&local_18,8);
      iVar1 = AVIIndex_WriteIndexFromTemp(*(undefined4 *)(param_1 + 0x440));
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x4c6) = 0;
        *(byte *)(param_1 + 0x4c7) = *(byte *)(param_1 + 0x4c7) | 0x10;
        iVar1 = (*g_medialib_printf)("##AVI Output: ERROR--write Index error!##\r\n");
      }
    }
    else {
      (*g_medialib_printf)("##AVI Output: no index##\r\n");
      iVar1 = AVIOutput_writeLegacyIndex_extend(param_1);
    }
  }
  return iVar1;
}



void AVIOutput_closeXblock(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x414) == 0) {
    uVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 0x4d0) = uVar1;
  }
  iVar2 = *(int *)(param_1 + 0x414);
  *(int *)(param_1 + (iVar2 + 0x44) * 4 + 4) =
       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 4) * 4 + 4)) + -8;
  local_c = *(undefined4 *)(param_1 + (iVar2 + 0x44) * 4 + 4);
  AVIOutput_seekDirect(param_1,*(int *)(param_1 + (*(int *)(param_1 + 0x414) + 4) * 4 + 4) + 4);
  AVIOutput_writeDirect(param_1,&local_c,4);
  AVIOutput_seekDirect(param_1,*(undefined4 *)(param_1 + 0x4d0));
  if (*(int *)(param_1 + 0x414) == 0) {
    *(undefined4 *)(param_1 + 0x45c) = **(undefined4 **)(param_1 + 4);
    AVIOutput_writeLegacyIndex(param_1,0);
  }
  *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 0xc4) * 4 + 4) =
       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 0x84) * 4 + 4)) +
       -8;
  *(int *)(param_1 + 0x414) = *(int *)(param_1 + 0x414) + 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



void AVIOutput_writeLegacyIndex_extend(int param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*(int *)(param_1 + 0x440) != 0) {
    local_10 = 0x31786469;
    local_c = 0x10;
    AVIOutput_writeIn(param_1,&local_10,8);
    AVIOutput_writeIn(param_1,&local_20,local_c);
  }
  return;
}



void AVIOutput_closeXblock_extend(int param_1)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 0x44) * 4 + 4) =
       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 4) * 4 + 4)) + -8;
  if (*(int *)(param_1 + 0x414) == 0) {
    *(undefined4 *)(param_1 + 0x45c) = **(undefined4 **)(param_1 + 4);
    uVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 0x4d0) = uVar1;
    AVIOutput_writeLegacyIndex_extend(param_1);
  }
  *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 0xc4) * 4 + 4) =
       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + (*(int *)(param_1 + 0x414) + 0x84) * 4 + 4)) +
       -8;
  *(int *)(param_1 + 0x414) = *(int *)(param_1 + 0x414) + 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



undefined4
AVIOutput_writeIndexedChunk
          (int *param_1,uint param_2,uint param_3,void *param_4,uint param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_55;
  undefined1 local_54 [4];
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  uint *local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  char local_11;
  
  local_11 = '\0';
  local_18 = (uint)(0x3030 < (param_2 & 0xffff));
  local_2c = (param_5 & 1) + param_5 + 0x10;
  if ((char)param_1[0x123] != '\0') {
    if (param_1[0x105] == 0) {
      iVar1 = param_1[0x121];
    }
    else {
      iVar1 = 0x7f000000;
    }
    if (iVar1 < param_1[4] + local_2c) {
      (*g_medialib_printf)("##AVI Output: NewBlock##\r\n");
      local_11 = '\x01';
    }
  }
  local_1c = param_1[3];
  if (local_11 != '\0') {
    local_1c = local_1c + 0x18;
  }
  if (param_1[local_18 + 0x12a] == 0) {
    param_1[local_18 + 0x12a] = local_1c;
  }
  if (param_1[local_18 + 0x128] < (int)(local_1c - param_1[local_18 + 300])) {
    param_1[local_18 + 0x128] = local_1c - param_1[local_18 + 300];
  }
  param_1[local_18 + 0x12e] = param_1[local_18 + 0x12e] + 1;
  local_24 = 0;
  if (param_1[0x128] != 0) {
    local_20 = __aeabi_uidiv(0xffffffff,param_1[0x128]);
    if (0xc00 < local_20) {
      local_20 = 0xc00;
    }
    local_24 = __divsi3(param_1[0x12e] + local_20 + -1,local_20);
  }
  if (param_1[0x129] != 0) {
    local_20 = __aeabi_uidiv(0xffffffff,param_1[0x129]);
    if (0xc00 < local_20) {
      local_20 = 0xc00;
    }
    iVar1 = __divsi3(param_1[0x12f] + local_20 + -1,local_20);
    local_24 = local_24 + iVar1;
  }
  param_1[0x130] = 0;
  if ((char)param_1[0x123] != '\0') {
    param_1[0x130] = local_24 << 5;
  }
  param_1[0x130] = param_1[0x130] + (param_1[0x12e] + param_1[0x12f]) * 0x10 + 8;
  local_30 = param_5 + param_1[0x130] + 0x1816;
  if ((*(char *)((int)param_1 + 0x48f) == '\0') || (local_1c <= ~local_30)) {
    param_1[local_18 + 300] = local_1c;
    if (local_11 != '\0') {
      if (0x3e < param_1[0x105]) {
        (*g_medialib_printf)("##AVI Output: Exceeded maximum block count %d##\r\n",0x40);
        return 0;
      }
      AVIOutput_closeXblock_extend(param_1);
      AVIOutput_openXblock(param_1);
    }
    local_40 = (param_1[3] - param_1[5]) + -8;
    local_38 = param_5;
    if ((param_3 & 0x10) != 0) {
      local_38 = param_5 | 0x80000000;
    }
    param_1[4] = param_1[4] + local_2c;
    if ((param_2 & 0xffff) == 0x3130) {
      if (*(int *)(*param_1 + 0x2c) < (int)param_5) {
        *(uint *)(*param_1 + 0x2c) = param_5;
      }
    }
    else if (*(int *)(param_1[1] + 0x2c) < (int)param_5) {
      *(uint *)(param_1[1] + 0x2c) = param_5;
    }
    local_3c = param_2;
    if ((param_1[0x110] == 0) || (iVar1 = AVIIndex_AddEntry2(param_1[0x110],&local_40), iVar1 != 0))
    {
      local_50 = param_5;
      local_54 = (undefined1  [4])param_2;
      if (param_6 == 8) {
        memcpy(param_4,local_54,8);
      }
      else {
        AVIOutput_writeIn(param_1,local_54,8);
        AVIOutput_writeIn(param_1,param_4,param_5);
      }
      if (*(char *)((int)param_1 + 0x48d) == '\0') {
        if (param_6 == 8) {
          if ((param_5 & 1) == 0) {
            AVIOutput_writeIn(param_1,param_4,param_5 + 8);
          }
          else {
            *(undefined1 *)((int)param_4 + param_5 + 8) = 0;
            AVIOutput_writeIn(param_1,param_4,param_5 + 9);
          }
        }
        else if ((param_5 & 1) != 0) {
          local_55 = 0;
          AVIOutput_writeIn(param_1,&local_55,1);
        }
      }
      else {
        local_34 = param_1[0x122] + param_5 & 7;
        if (param_6 == 8) {
          AVIOutput_writeIn(param_1,param_4,param_5 + 8);
        }
        if (local_34 != 0) {
          local_54 = (undefined1  [4])0x0;
          local_50 = 0x4b4e554a;
          local_4c = -local_34 & 6;
          local_48 = 0;
          local_44 = 0;
          local_28 = &local_50;
          if ((local_34 & 1) != 0) {
            local_28 = (uint *)(local_54 + 3);
          }
          if ((local_34 + 1 & 7) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = local_4c + 8;
          }
          AVIOutput_writeIn(param_1,local_28,(local_34 & 1) + iVar1);
        }
        param_1[0x122] = 0;
      }
      uVar2 = 1;
    }
    else {
      (*g_medialib_printf)("##AVI Output: ERROR--couldn\'t add chunk to index!##\r\n");
      uVar2 = 0;
    }
  }
  else {
    (*g_medialib_printf)("##AVI output: ERROR--overflow!max length will be over 4G bytes##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



char AVIOutput_writeVideoIndex
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  
  cVar1 = AVIOutput_writeIndexedChunk
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_2,param_3,param_4,
                     *(undefined2 *)(param_1 + 0x4d4));
  if (cVar1 != '\0') {
    **(int **)(param_1 + 4) = **(int **)(param_1 + 4) + param_5;
  }
  return cVar1;
}



char AVIOutput_writeAudioIndex
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  char cVar1;
  
  cVar1 = AVIOutput_writeIndexedChunk
                    (param_1,0x62773130,param_2,param_3,param_4,
                     *(undefined2 *)((int)param_1 + 0x4d6));
  if (cVar1 != '\0') {
    *(int *)*param_1 = *(int *)*param_1 + param_5;
  }
  return cVar1;
}



undefined4
AVIOutput_createNewIndices_extend
          (int *param_1,int *param_2,undefined4 *param_3,int *param_4,char param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_126c [2];
  int local_1264;
  uint auStack_26c [128];
  uint local_6c;
  int local_68;
  undefined2 local_64;
  undefined1 local_62;
  undefined1 local_61;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  local_34 = 1;
  local_18 = 0;
  local_38 = *param_2;
  local_3c = param_2[2] - *(int *)(local_38 + 0xc04);
  ZeroMemory(param_4,0x100);
  ZeroMemory(param_3,0x20);
  *param_3 = 0x78646e69;
  param_3[1] = 0x118;
  *(undefined2 *)(param_3 + 2) = 4;
  *(undefined1 *)((int)param_3 + 10) = 0;
  *(undefined1 *)((int)param_3 + 0xb) = 0;
  if ((param_2 == (int *)0x0) || (param_2[2] == 0)) {
    uVar2 = 0;
  }
  else {
    *param_4 = param_1[3];
    param_4[2] = 0x28;
    if (param_5 == '\0') {
      local_5c = *(int *)(param_1[1] + 4);
    }
    else {
      local_5c = 0x62773130;
    }
    local_6c = local_5c << 0x10 | 0x7869;
    local_68 = param_4[2] + -8;
    local_64 = 2;
    local_62 = 0;
    local_61 = 1;
    local_60 = 0;
    local_58 = local_18;
    local_50 = 0;
    local_40 = local_5c;
    AVIOutput_writeIn(param_1,&local_6c,0x20);
    local_44 = param_2;
    if (param_2[2] == 0) {
      (*g_medialib_printf)("##AVI Output: WARNING--no frame is record##\r\n");
      uVar2 = 1;
    }
    else {
      local_20 = 0;
      local_1c = 0;
      if ((char)param_2[5] == '\0') {
        local_28 = 0;
        (**(code **)(param_2[9] + 0xc))(param_2[3],0,0);
        local_48 = 0x1000;
        local_2c = (**(code **)(local_44[9] + 4))(local_44[3],local_126c,0x1000);
        local_28 = local_2c >> 4;
        local_18 = local_1264;
        (*g_medialib_printf)("##AVI Output: FileRead successed and loop##\r\n");
        while (0 < local_2c) {
          if (local_3c < local_28) {
            local_2c = local_2c + (local_28 - local_3c) * -0x10;
          }
          local_24 = local_126c;
          for (local_14 = local_2c >> 4; 0 < local_14; local_14 = local_14 + -1) {
            if (*local_24 == local_40) {
              auStack_26c[local_1c * 2] = (local_24[2] - local_18) + param_1[5] + 0x10;
              if (local_24[1] == 0) {
                uVar3 = local_24[3] | 0x80000000;
              }
              else {
                uVar3 = local_24[3];
              }
              auStack_26c[local_1c * 2 + 1] = uVar3;
              local_20 = local_20 + 1;
              local_1c = local_1c + 1;
              if ((local_1c & 0x3f) == 0) {
                AVIOutput_writeIn(param_1,auStack_26c,local_1c * 8);
                if (*(char *)((int)param_1 + 0x4c6) == '\0') {
                  (*g_medialib_printf)("##AVI Output: ERROR--Writing index is not valid 1##\r\n");
                  return 0;
                }
                local_1c = 0;
              }
            }
            local_24 = local_24 + 4;
          }
          local_2c = (**(code **)(local_44[9] + 4))(local_44[3],local_126c,local_48);
          local_28 = local_28 + (local_2c >> 4);
        }
        (*g_medialib_printf)("##AVI Output: exit loop##\r\n");
        (**(code **)(local_44[9] + 0xc))(local_44[3],0,0);
      }
      else {
        (*g_medialib_printf)
                  ("##AVI Output: total_ents %d, entryBuffer 0x%x##\r\n",param_2[2],param_2[4]);
        local_14 = local_3c;
        local_24 = (int *)local_44[4];
        local_18 = local_24[2];
        for (; 0 < local_14; local_14 = local_14 + -1) {
          if (*local_24 == local_40) {
            auStack_26c[local_1c * 2] = (local_24[2] - local_18) + param_1[5] + 0x10;
            if (local_24[1] == 0) {
              uVar3 = local_24[3] | 0x80000000;
            }
            else {
              uVar3 = local_24[3];
            }
            auStack_26c[local_1c * 2 + 1] = uVar3;
            local_20 = local_20 + 1;
            local_1c = local_1c + 1;
            if ((local_1c & 0x3f) == 0) {
              AVIOutput_writeIn(param_1,auStack_26c,local_1c * 8);
              if (*(char *)((int)param_1 + 0x4c6) == '\0') {
                (*g_medialib_printf)("##AVI Output: ERROR--Writing index is not valid 2##\r\n");
                return 0;
              }
              local_1c = 0;
            }
          }
          local_24 = local_24 + 4;
        }
        local_44[8] = 0;
      }
      if (*(int *)(local_38 + 0xc04) != 0) {
        local_30 = (int *)(local_38 + 4);
        if (local_3c == 0) {
          local_18 = *local_30;
        }
        local_14 = *(int *)(local_38 + 0xc04);
        (*g_medialib_printf)("##AVI Output: num_ents %d##\r\n",local_14);
        for (; 0 < local_14; local_14 = local_14 + -1) {
          if (local_30[1] == local_40) {
            auStack_26c[local_1c * 2] = (*local_30 - local_18) + param_1[5] + 0x10;
            auStack_26c[local_1c * 2 + 1] = local_30[2];
            local_20 = local_20 + 1;
            local_1c = local_1c + 1;
            if ((local_1c & 0x3f) == 0) {
              AVIOutput_writeIn(param_1,auStack_26c,local_1c * 8);
              if (*(char *)((int)param_1 + 0x4c6) == '\0') {
                (*g_medialib_printf)("##AVI Output: ERROR--Writing index is not valid 3##\r\n");
                return 0;
              }
              local_1c = 0;
            }
          }
          local_30 = local_30 + 3;
        }
      }
      if ((local_1c == 0) ||
         (AVIOutput_writeIn(param_1,auStack_26c,local_1c << 3),
         *(char *)((int)param_1 + 0x4c6) != '\0')) {
        local_68 = local_20 * 8 + 0x20;
        local_60 = local_20;
        local_58 = local_18;
        local_54 = 0;
        local_18 = MediaFile_GetPosition(param_1[2]);
        MediaFile_SetPosition(param_1[2],*param_4);
        iVar1 = MediaFile_Write(param_1[2],&local_6c,0x20);
        if (iVar1 != 0x20) {
          (*g_medialib_printf)("##AVI Output: WARNING--Write asi_ix failed, index error##\r\n");
        }
        MediaFile_SetPosition(param_1[2],local_18);
        param_3[3] = local_34;
        if (param_5 == '\0') {
          uVar2 = *(undefined4 *)(param_1[1] + 4);
        }
        else {
          uVar2 = 0x62773130;
        }
        param_3[4] = uVar2;
        param_4[2] = (local_20 + 4) * 8;
        if (param_5 == '\0') {
          iVar1 = *(int *)(param_1[1] + 0x34);
        }
        else {
          iVar1 = *(int *)(*param_1 + 0x34);
        }
        if (iVar1 == 0) {
          param_4[3] = local_20;
        }
        else {
          if (param_5 == '\0') {
            iVar1 = *(int *)param_1[1];
          }
          else {
            iVar1 = *(int *)*param_1;
          }
          param_4[3] = iVar1;
        }
        uVar2 = 1;
      }
      else {
        (*g_medialib_printf)("##AVI Output: ERROR--Writing index is not valid##\r\n");
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



int AVIOutput_writeNewIndex
              (int *param_1,int *param_2,int *param_3,int param_4,undefined4 param_5,int param_6,
              int param_7)

{
  int iVar1;
  int iVar2;
  int local_250;
  int *local_24c;
  int aiStack_23c [128];
  uint local_3c;
  int local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined1 local_31;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = *param_3;
  local_10 = 0;
  while ((iVar1 = local_10, local_10 < param_4 && (param_3[local_10 * 3] - local_18 != -1))) {
    local_10 = local_10 + 1;
  }
  local_250 = local_10;
  local_1c = local_10;
  if (param_1[0x105] == 0) {
    iVar2 = param_1[0x121];
  }
  else {
    iVar2 = 0x7f000000;
  }
  if (iVar2 < param_1[4] + local_10 * 8 + 0x20) {
    AVIOutput_closeXblock(param_1);
    AVIOutput_openXblock(param_1);
  }
  *param_2 = param_1[3];
  param_2[2] = (iVar1 + 4) * 8;
  if (param_7 == 0) {
    param_2[3] = iVar1;
  }
  else {
    local_14 = 0;
    for (local_10 = 0; local_10 < iVar1; local_10 = local_10 + 1) {
      local_14 = local_14 + (param_3[2] & 0x7fffffffU);
    }
    iVar2 = __aeabi_uidiv(local_14,*(undefined4 *)(*param_1 + 0x34));
    param_2[3] = iVar2;
  }
  local_3c = param_6 << 0x10 | 0x7869;
  local_38 = param_2[2] + -8;
  local_34 = 2;
  local_32 = 0;
  local_31 = 1;
  local_30 = iVar1;
  local_2c = param_6;
  local_28 = local_18;
  local_20 = 0;
  AVIOutput_writeIn(param_1,&local_3c,0x20);
  local_24c = param_3;
  for (; 0 < local_250; local_250 = local_250 - local_c) {
    local_c = local_250;
    if (0x40 < local_250) {
      local_c = 0x40;
    }
    for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
      aiStack_23c[local_10 * 2] = (*local_24c - local_18) + param_1[5] + 0x10;
      aiStack_23c[local_10 * 2 + 1] = local_24c[2];
      local_24c = local_24c + 3;
    }
    AVIOutput_writeIn(param_1,aiStack_23c,local_c << 3);
  }
  return local_1c;
}



undefined4 AVIOutput_SetAudioSamples(int *param_1,undefined4 param_2)

{
  MulDiv(*param_1,*(undefined4 *)(*param_1 + 0x20),param_2,*(int *)(*param_1 + 0x1c) * 1000);
  return 1;
}



undefined4 AVIFilePerf_headerAnalysis(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  
  local_24 = 0;
  local_28 = 0;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x58),0);
  iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),auStack_40,0xc);
  if (iVar1 == 0xc) {
    iVar1 = memcmp(auStack_40,&DAT_0005a0f4,4);
    if (((iVar1 == 0) || (iVar1 = memcmp(auStack_40,&DAT_0005a0fc,4), iVar1 == 0)) &&
       ((iVar1 = memcmp(auStack_38,&DAT_0005a104,4), iVar1 == 0 ||
        (iVar1 = memcmp(auStack_38,&DAT_0005a0fc,4), iVar1 == 0)))) {
      local_2c = str2ulong(auStack_3c);
      local_2c = local_2c + 8;
      if (*(int *)(*(int *)(param_1 + 0x58) + 4) == local_2c) {
        (*(code *)**(undefined4 **)(param_1 + 0x68))
                  ("##AVI file is perfect, doesn\'s need recombin!");
        uVar3 = 1;
      }
      else {
        while (iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),auStack_40,8), iVar1 == 8) {
          iVar1 = str2ulong(auStack_3c);
          local_30 = iVar1 + 1U & 0xfffffffe;
          iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58));
          if (iVar1 + local_30 < local_30) {
            (*(code *)**(undefined4 **)(param_1 + 0x68))
                      ("##AVI filper: ERROR--length of chunk is too large##\r\n");
            return 0xffffffff;
          }
          uVar2 = str2ulong(auStack_40);
          if (uVar2 == 0x46464952) {
            local_14 = 0;
            if ((local_30 < 0xc) ||
               (iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),auStack_40,0xc), iVar1 != 0xc
               )) {
              (*(code *)**(undefined4 **)(param_1 + 0x68))
                        ("##AVI filper: ERROR--Fill header, Read RIFF error##\r\n");
              return 0;
            }
            iVar1 = memcmp(auStack_40,&DAT_0005a2b4,4);
            if ((iVar1 == 0) && (iVar1 = str2ulong(auStack_38), iVar1 + 0xcU == local_30)) {
              uVar4 = *(undefined4 *)(param_1 + 0x58);
              uVar3 = str2ulong(auStack_38);
              MediaFile_ChangePosition(uVar4,uVar3);
            }
            else if ((local_30 == 0) ||
                    (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
                    *(uint *)(*(int *)(param_1 + 0x58) + 4) < (iVar1 + local_30) - 0xc)) {
              MediaFile_SetPosition
                        (*(undefined4 *)(param_1 + 0x58),
                         *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
            }
            else {
              MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30 - 0xc);
            }
          }
          else if (uVar2 < 0x46464953) {
            if (uVar2 == 0x31786469) {
              local_14 = 0;
              *(int *)(param_1 + 0x10) = *(int *)(*(int *)(param_1 + 0x58) + 8) + -8;
              *(uint *)(param_1 + 0x14) = local_30;
              if ((local_30 == 0) ||
                 (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
                 *(uint *)(*(int *)(param_1 + 0x58) + 4) < iVar1 + local_30)) {
                MediaFile_SetPosition
                          (*(undefined4 *)(param_1 + 0x58),
                           *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
              }
              else {
                MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
              }
            }
            else {
LAB_00031098:
              if ((local_30 == 0) ||
                 (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
                 *(uint *)(*(int *)(param_1 + 0x58) + 4) < iVar1 + local_30)) {
                MediaFile_SetPosition
                          (*(undefined4 *)(param_1 + 0x58),
                           *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
              }
              else {
                MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
                local_14 = local_14 + local_30;
                if (0x1000 < local_14) {
                  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 8) == 0)) {
                    (*(code *)**(undefined4 **)(param_1 + 0x68))
                              (
                              "##AVI filper: ERROR--file corruption, this file is altered by somebody!##\r\n"
                              );
                    return 0;
                  }
                  (*(code *)**(undefined4 **)(param_1 + 0x68))
                            (
                            "##AVI filper: WARNING--file corruption, this file is altered by somebody!##\r\n"
                            );
                }
              }
            }
          }
          else if (uVar2 == 0x4b4e554a) {
            local_14 = 0;
            if ((local_30 == 0) ||
               (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
               *(uint *)(*(int *)(param_1 + 0x58) + 4) < iVar1 + local_30)) {
              MediaFile_SetPosition
                        (*(undefined4 *)(param_1 + 0x58),
                         *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
            }
            else {
              MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
            }
          }
          else {
            if (uVar2 != 0x5453494c) goto LAB_00031098;
            local_14 = 0;
            iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),auStack_40,4);
            if (iVar1 != 4) {
              (*(code *)**(undefined4 **)(param_1 + 0x68))
                        ("##AVI filper: ERROR--Fill header, Read(aviFile, data, 4) != 4##\r\n");
              return 0xffffffff;
            }
            local_30 = local_30 - 4;
            iVar1 = memcmp(auStack_40,&DAT_0005a1d8,4);
            if (iVar1 == 0) {
              local_18 = local_30;
              uVar3 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58));
              *(undefined4 *)(param_1 + 0x18) = uVar3;
              if (local_24 != 0) {
                (**(code **)(*(int *)(param_1 + 0x68) + 0x18))(local_24);
                *(undefined4 *)(param_1 + 0x20) = 0;
              }
              local_24 = (**(code **)(*(int *)(param_1 + 0x68) + 0x14))(local_30);
              if (local_24 == 0) {
                (*(code *)**(undefined4 **)(param_1 + 0x68))
                          ("##AVI filper: ERROR--Fill header, hdrl_data is NULL##\r\n");
                (**(code **)(*(int *)(param_1 + 0x68) + 0x18))(local_24);
                return 0xffffffff;
              }
              *(int *)(param_1 + 0x20) = local_24;
              uVar2 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),local_24,local_30);
              if (uVar2 != local_30) {
                (*(code *)**(undefined4 **)(param_1 + 0x68))
                          (
                          "##AVI filper: ERROR--Fill header, MediaFile_Read(avifpf->->aviFile, hdrl_data, n) != n##\r\n"
                          );
                return 0xffffffff;
              }
              *(uint *)(param_1 + 0x1c) = local_18;
            }
            else {
              iVar1 = memcmp(auStack_40,&DAT_0005a274,4);
              if (iVar1 == 0) {
                iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58));
                *(int *)(param_1 + 8) = iVar1 + -0xc;
                if ((local_30 == 0) ||
                   (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
                   *(uint *)(*(int *)(param_1 + 0x58) + 4) < iVar1 + local_30)) {
                  MediaFile_SetPosition
                            (*(undefined4 *)(param_1 + 0x58),
                             *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
                }
                else {
                  *(uint *)(param_1 + 0xc) = local_30;
                  MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
                }
              }
              else if ((local_30 == 0) ||
                      (iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x58)),
                      *(uint *)(*(int *)(param_1 + 0x58) + 4) < iVar1 + local_30)) {
                MediaFile_SetPosition
                          (*(undefined4 *)(param_1 + 0x58),
                           *(undefined4 *)(*(int *)(param_1 + 0x58) + 4));
              }
              else {
                MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
              }
            }
          }
        }
        local_20 = 0;
        local_1c = 0;
        while (local_1c < local_18) {
          iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a358,4);
          if (iVar1 == 0) {
            local_1c = local_1c + 0xc;
          }
          else {
            iVar1 = str2ulong(local_24 + local_1c + 4);
            local_34 = iVar1 + 1U & 0xfffffffe;
            iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a360,4);
            if (iVar1 == 0) {
              local_1c = local_1c + 8;
              *(uint *)(param_1 + 0x24) = local_1c;
            }
            else {
              iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a368,4);
              if (iVar1 == 0) {
                local_1c = local_1c + 8;
                iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a370,4);
                if (iVar1 == 0) {
                  *(uint *)(param_1 + 0x34) = local_1c;
                  memcpy(&local_48,(void *)(local_24 + local_1c + 4),8);
                  if ((0x60 < local_48) && (local_48 < 0x7b)) {
                    local_48 = local_48 - 0x20;
                  }
                  if ((0x60 < local_47) && (local_47 < 0x7b)) {
                    local_47 = local_47 - 0x20;
                  }
                  if ((0x60 < local_46) && (local_46 < 0x7b)) {
                    local_46 = local_46 - 0x20;
                  }
                  if ((0x60 < local_45) && (local_45 < 0x7b)) {
                    local_45 = local_45 - 0x20;
                  }
                  iVar1 = memcmp(&local_47,&DAT_0005a378,3);
                  if (iVar1 == 0) {
                    *(undefined4 *)(param_1 + 100) = 1;
                  }
                  else {
                    iVar1 = memcmp(&local_47,&DAT_0005a37c,3);
                    if ((iVar1 == 0) || (iVar1 = memcmp(&local_48,&DAT_0005a380,4), iVar1 == 0)) {
                      *(undefined4 *)(param_1 + 100) = 7;
                    }
                    else {
                      iVar1 = memcmp(&local_47,&DAT_0005a388,3);
                      if ((iVar1 == 0) || (iVar1 = memcmp(&local_48,&DAT_0005a38c,4), iVar1 == 0)) {
                        *(undefined4 *)(param_1 + 100) = 0xf;
                      }
                      else {
                        iVar1 = str2ulong(&local_48);
                        if (iVar1 == 0) {
                          memcpy(&local_48,auStack_44,4);
                        }
                        uVar2 = str2ulong(&local_48);
                        if (uVar2 != 0x44495658) {
                          if (uVar2 < 0x44495659) {
                            if (uVar2 != 0x32564933) {
                              if (uVar2 < 0x32564934) {
                                if (((uVar2 != 0x31585644) && (uVar2 != 0x3253344d)) &&
                                   (uVar2 != 0x30355844)) {
LAB_0003166c:
                                  (*(code *)**(undefined4 **)(param_1 + 0x68))
                                            ("##AVI : WARNING--video UNKNOWN##\r\n");
                                  *(undefined4 *)(param_1 + 100) = 0;
                                  return 0xffffffff;
                                }
                              }
                              else if (uVar2 != 0x414b4e41) {
                                if (uVar2 == 0x4356534d) {
                                  iVar1 = memcmp(auStack_44,&DAT_0005a394,4);
                                  if (iVar1 == 0) {
                                    *(undefined4 *)(param_1 + 100) = 2;
                                  }
                                  goto LAB_000316dc;
                                }
                                if (uVar2 != 0x34504d46) goto LAB_0003166c;
                              }
                            }
                          }
                          else if (uVar2 != 0x5334504d) {
                            if (uVar2 < 0x5334504e) {
                              if (uVar2 == 0x47504a4d) {
                                *(undefined4 *)(param_1 + 100) = 10;
                              }
                              else {
                                if (uVar2 == 0x4d475844) goto LAB_000315fc;
                                if (uVar2 != 0x4745504d) goto LAB_0003166c;
                                *(undefined4 *)(param_1 + 100) = 0xc;
                              }
                              goto LAB_000316dc;
                            }
                            if (((uVar2 != 0x58495658) && (uVar2 != 0x58564944)) &&
                               (uVar2 != 0x5634504d)) goto LAB_0003166c;
                          }
                        }
LAB_000315fc:
                        *(undefined4 *)(param_1 + 100) = 2;
                      }
                    }
                  }
                }
                else {
                  iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a3c0,4);
                  if (iVar1 == 0) {
                    *(uint *)(param_1 + 0x2c) = local_1c;
                  }
                }
LAB_000316dc:
                local_20 = local_20 + 1;
              }
              else {
                iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a3c8,4);
                if (iVar1 == 0) {
                  local_1c = local_1c + 8;
                }
                else {
                  iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a3d0,4);
                  if (iVar1 == 0) {
                    *(uint *)(param_1 + 0x38) = local_1c;
                    local_1c = local_1c + 8;
                  }
                  else {
                    iVar1 = memcmp((void *)(local_24 + local_1c),&DAT_0005a3d8,4);
                    if (((iVar1 == 0) && (iVar1 = str2ushort(local_24 + local_1c + 8), iVar1 == 4))
                       && (iVar1 = str2ushort(local_24 + local_1c + 10), iVar1 == 0)) {
                      local_1c = local_1c + 8;
                    }
                    else {
                      local_1c = local_1c + 8;
                    }
                  }
                }
              }
            }
            local_1c = local_1c + local_34;
          }
        }
        if (*(int *)(param_1 + 0x10) == 0) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x58) + 4);
          *(undefined4 *)(param_1 + 0x14) = 0;
        }
        *(int *)(param_1 + 0x50) = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) + -8;
        if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0xc) == 0x7fffffff)) ||
           (*(uint *)(*(int *)(param_1 + 0x58) + 4) <= *(uint *)(param_1 + 0xc))) {
          *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x50);
        }
        uVar3 = 2;
      }
    }
    else {
      (*(code *)**(undefined4 **)(param_1 + 0x68))("##ERR: This is not AVI file!");
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



undefined4 AVIFilePerf_Close(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    MediaFile_Close(*(undefined4 *)(param_1 + 0x58));
    MediaFile_Close(*(undefined4 *)(param_1 + 0x5c));
    MediaFile_Close(*(undefined4 *)(param_1 + 0x60));
    if (*(int *)(param_1 + 0x20) != 0) {
      (**(code **)(*(int *)(param_1 + 0x68) + 0x18))(*(undefined4 *)(param_1 + 0x20));
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    (**(code **)(*(int *)(param_1 + 0x68) + 0x18))(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



void * AVIFilePerf_Open(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  void *__s;
  undefined4 uVar1;
  
  __s = (void *)(**(code **)(param_4 + 0x14))(0x6c);
  if (__s == (void *)0x0) {
    __s = (void *)0x0;
  }
  else {
    memset(__s,0,0x6c);
    *(int *)((int)__s + 0x68) = param_4;
    uVar1 = MediaFile_Open(param_1,0,param_4);
    *(undefined4 *)((int)__s + 0x58) = uVar1;
    if (*(int *)((int)__s + 0x58) == 0) {
      AVIFilePerf_Close(__s);
      __s = (void *)0x0;
    }
    else {
      uVar1 = MediaFile_Open(param_2,0,param_4);
      *(undefined4 *)((int)__s + 0x5c) = uVar1;
      uVar1 = MediaFile_Open(param_3,1,param_4);
      *(undefined4 *)((int)__s + 0x60) = uVar1;
      if (*(int *)((int)__s + 0x60) == 0) {
        AVIFilePerf_Close(__s);
        __s = (void *)0x0;
      }
    }
  }
  return __s;
}



int AVIFilePerf_checkMoviData(int param_1)

{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  byte local_40 [14];
  byte local_32;
  byte local_31;
  uint local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x58),*(int *)(param_1 + 8) + 0xc);
  local_1c = 0xc;
  local_28 = *(uint *)(param_1 + 0xc);
  do {
    if (local_28 <= local_1c) {
LAB_00031f24:
      *(int *)(param_1 + 0x40) = local_c;
      *(int *)(param_1 + 0x44) = local_10;
      *(uint *)(param_1 + 0x48) = local_14;
      *(uint *)(param_1 + 0x4c) = local_18;
      *(int *)(param_1 + 0x54) = (local_c + local_10) * 0x10;
      iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x60));
      *(int *)(param_1 + 0x3c) = iVar1 + -8;
      return local_c;
    }
    local_24 = 0;
    local_2c = local_1c - 8;
    local_20 = 0;
    iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x58),&local_44,8);
    if (iVar1 != 8) goto LAB_00031f24;
    local_1c = local_1c + 8;
    local_30 = str2ulong(local_40);
    if (local_28 < local_1c + local_30) goto LAB_00031f24;
    iVar1 = memcmp(&local_44,&DAT_0005a3e0,4);
    if (iVar1 == 0) {
      local_10 = local_10 + 1;
      if (local_18 < local_30) {
        local_18 = local_30;
      }
      local_24 = 0x62773130;
    }
    else {
      iVar1 = memcmp(&local_44,&DAT_0005a3e8,4);
      if (iVar1 != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x68))
                  ("## err: invalid pack ID(%c%c%c%c)\n",local_44,local_43,local_42,local_41);
        goto LAB_00031f24;
      }
      local_c = local_c + 1;
      if (local_14 < local_30) {
        local_14 = local_30;
      }
      local_24 = 0x63643030;
      if (local_30 < 5) {
        local_20 = 0;
      }
      else if (*(int *)(param_1 + 100) == 7) {
        MediaFile_Read(*(undefined4 *)(param_1 + 0x58),&local_44,5);
        local_31 = local_40[0] & 0x1f;
        if (((local_31 == 5) || (local_31 == 7)) || (local_31 == 8)) {
          local_20 = 0x10;
        }
        MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),0xfffffffb);
      }
      else if (*(int *)(param_1 + 100) == 0xf) {
        MediaFile_Read(*(undefined4 *)(param_1 + 0x58),&local_44,5);
        local_32 = local_40[0] >> 1 & 0x3f;
        if ((((local_32 == 0x13) || (local_32 == 0x14)) || (local_32 == 0x20)) ||
           ((local_32 == 0x21 || (local_32 == 0x22)))) {
          local_20 = 0x10;
        }
        MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),0xfffffffb);
      }
      else {
        if (*(int *)(param_1 + 100) != 10) {
          (*(code *)**(undefined4 **)(param_1 + 0x68))
                    ("## err: can\'t chek IDR, videotype=%d\n",*(undefined4 *)(param_1 + 100));
          goto LAB_00031f24;
        }
        local_20 = 0x10;
      }
    }
    local_54 = local_24;
    local_50 = local_20;
    local_4c = local_2c;
    local_48 = local_30;
    MediaFile_Write(*(undefined4 *)(param_1 + 0x60),&local_54,0x10);
    local_30 = local_30 + 1 & 0xfffffffe;
    MediaFile_ChangePosition(*(undefined4 *)(param_1 + 0x58),local_30);
    local_1c = local_1c + local_30;
  } while( true );
}



int AVIFilePerf_checkIndexfile(int param_1)

{
  int iVar1;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 auStack_28 [4];
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x5c),0);
  local_20 = *(uint *)(*(int *)(param_1 + 0x5c) + 4);
  do {
    if ((local_20 <= local_1c) ||
       (iVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 0x5c),&local_34,0x10), iVar1 != 0x10))
    goto LAB_00032168;
    local_1c = local_1c + 0x10;
    local_24 = str2ulong(auStack_28);
    iVar1 = memcmp(&local_34,&DAT_0005a3e0,4);
    if (iVar1 == 0) {
      local_10 = local_10 + 1;
      if (local_18 < local_24) {
        local_18 = local_24;
      }
    }
    else {
      iVar1 = memcmp(&local_34,&DAT_0005a3e8,4);
      if (iVar1 != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x68))
                  ("## err: invalid pack ID(%c%c%c%c)\n",local_34,local_33,local_32,local_31);
LAB_00032168:
        *(int *)(param_1 + 0x40) = local_c;
        *(int *)(param_1 + 0x44) = local_10;
        *(uint *)(param_1 + 0x48) = local_14;
        *(uint *)(param_1 + 0x4c) = local_18;
        *(uint *)(param_1 + 0x54) = local_1c;
        iVar1 = MediaFile_GetPosition(*(undefined4 *)(param_1 + 0x60));
        *(int *)(param_1 + 0x3c) = iVar1 + -8;
        return local_c;
      }
      local_c = local_c + 1;
      if (local_14 < local_24) {
        local_14 = local_24;
      }
    }
    MediaFile_Write(*(undefined4 *)(param_1 + 0x60),&local_34,0x10);
  } while( true );
}



undefined4 AVIFilePerf_updateHead(int param_1)

{
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x60),4);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x3c,4);
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x60),*(int *)(param_1 + 8) + 4);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x50,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),
             *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x24) + 0x10);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x40,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),
             *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x34) + 0x20);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x40,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),
             *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x34) + 0x24);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x48,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),
             *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x2c) + 0x20);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x44,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),
             *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x2c) + 0x24);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x4c,4);
  MediaFile_SetPosition
            (*(undefined4 *)(param_1 + 0x60),*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x38) + 8
            );
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x40,4);
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 0x60),4);
  MediaFile_Write(*(undefined4 *)(param_1 + 0x60),param_1 + 0x3c,4);
  return 1;
}



undefined4 AVI_FilePerfect(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_a0 [128];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_14 = AVIFilePerf_Open(param_1,param_2,param_3,param_4);
  if (local_14 == 0) {
    uVar2 = 0;
  }
  else {
    local_18 = AVIFilePerf_headerAnalysis(local_14);
    if (local_18 == 1) {
      (*(code *)**(undefined4 **)(local_14 + 0x68))
                ("## the input avi file is intact, changer is undesired.\n");
    }
    else if (local_18 == 2) {
      if (param_3 != param_1) {
        local_10 = 0x80;
        MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x58),0);
        MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x60),0);
        for (local_c = 0; local_c < *(uint *)(local_14 + 0x10); local_c = local_c + local_10) {
          if (*(int *)(local_14 + 0x10) - local_c < local_10) {
            local_10 = *(int *)(local_14 + 0x10) - local_c;
          }
          iVar1 = MediaFile_Read(*(undefined4 *)(local_14 + 0x58),auStack_a0,local_10);
          if (iVar1 < 1) break;
          MediaFile_Write(*(undefined4 *)(local_14 + 0x60),auStack_a0,local_10);
        }
        if (*(uint *)(local_14 + 0x10) < *(uint *)(local_14 + 8)) {
          (*(code *)**(undefined4 **)(local_14 + 0x68))
                    ("## err: idx1 is before movi, change fail\n");
          return 0;
        }
      }
      MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x60),*(undefined4 *)(local_14 + 0x10));
      local_20 = 0x31786469;
      local_1c = 0;
      MediaFile_Write(*(undefined4 *)(local_14 + 0x60),&local_20,8);
      if (param_2 == 0) {
        AVIFilePerf_checkMoviData(local_14);
      }
      else {
        AVIFilePerf_checkIndexfile(local_14);
      }
      MediaFile_SetPosition(*(undefined4 *)(local_14 + 0x60),*(int *)(local_14 + 0x10) + 4);
      MediaFile_Write(*(undefined4 *)(local_14 + 0x60),local_14 + 0x54,4);
      (*(code *)**(undefined4 **)(local_14 + 0x68))
                ("## vframs=%d, aframs=%d\n",*(undefined4 *)(local_14 + 0x40),
                 *(undefined4 *)(local_14 + 0x44));
      *(int *)(local_14 + 0x3c) =
           *(int *)(*(int *)(local_14 + 0x58) + 4) + *(int *)(local_14 + 0x54);
      AVIFilePerf_updateHead(local_14);
    }
    else {
      (*(code *)**(undefined4 **)(local_14 + 0x68))
                ("## the input avi file is invalid, changer is fail.\n");
    }
    AVIFilePerf_Close(local_14);
    uVar2 = 1;
  }
  return uVar2;
}



bool AVC_ParseDecConfigRecord(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 auStack_16 [4];
  ushort local_12;
  ushort local_10;
  ushort local_e;
  void *local_c;
  
  iVar2 = *(int *)(param_3 + 0xc);
  local_10 = 0;
  **(char **)(param_3 + 0xc) = *(char *)(param_3 + 4) + '\x01';
  for (local_e = 1; local_e < *(byte *)(param_3 + 4); local_e = local_e + 1) {
    *(undefined1 *)(*(int *)(param_3 + 0xc) + (uint)local_e) = 0;
  }
  *(undefined1 *)(*(int *)(param_3 + 0xc) + (uint)local_e) = 1;
  *(undefined1 *)(*(int *)(param_3 + 0xc) + local_e + 1) = 6;
  local_c = (void *)(iVar2 + *(byte *)(param_3 + 4) + 2);
  for (local_e = 0; local_e < *(byte *)(param_3 + 5); local_e = local_e + 1) {
    local_12 = CONCAT11(*(undefined1 *)(param_1 + (uint)local_10),
                        *(undefined1 *)(param_1 + local_10 + 1));
    local_10 = local_10 + 2;
    cVar1 = *(char *)(param_3 + 4);
    if (cVar1 == '\x02') {
      memcpy((void *)((int)local_c + 3),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(&uStack_18,local_12);
      memcpy(local_c,&uStack_17,3);
      local_c = (void *)((int)local_c + local_12 + 3);
    }
    else if (cVar1 == '\x03') {
      memcpy((void *)((int)local_c + 4),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(local_c,local_12);
      local_c = (void *)((int)local_c + local_12 + 4);
    }
    else if (cVar1 == '\x01') {
      memcpy((void *)((int)local_c + 2),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(&uStack_18,local_12);
      memcpy(local_c,auStack_16,2);
      local_c = (void *)((int)local_c + local_12 + 2);
    }
    local_10 = local_10 + local_12;
  }
  local_10 = local_10 + 1;
  for (local_e = 0; local_e < *(byte *)(param_3 + 6); local_e = local_e + 1) {
    local_12 = CONCAT11(*(undefined1 *)(param_1 + (uint)local_10),
                        *(undefined1 *)(param_1 + local_10 + 1));
    local_10 = local_10 + 2;
    cVar1 = *(char *)(param_3 + 4);
    if (cVar1 == '\x02') {
      memcpy((void *)((int)local_c + 3),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(&uStack_18,local_12);
      memcpy(local_c,&uStack_17,3);
      local_c = (void *)((int)local_c + local_12 + 3);
    }
    else if (cVar1 == '\x03') {
      memcpy((void *)((int)local_c + 4),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(local_c,local_12);
      local_c = (void *)((int)local_c + local_12 + 4);
    }
    else if (cVar1 == '\x01') {
      memcpy((void *)((int)local_c + 2),(void *)(param_1 + (uint)local_10),(uint)local_12);
      mov_ulong2str(&uStack_18,local_12);
      memcpy(local_c,auStack_16,2);
      local_c = (void *)((int)local_c + local_12 + 2);
    }
    local_10 = local_10 + local_12;
  }
  if (local_10 <= param_2) {
    *(int *)(param_3 + 8) = (int)local_c - *(int *)(param_3 + 0xc);
  }
  return local_10 <= param_2;
}



undefined4 quicktime_atom_reset(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 0xe) = *(undefined1 *)(param_1 + 0xf);
  *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)(param_1 + 0xe);
  *(undefined1 *)(param_1 + 0xc) = *(undefined1 *)(param_1 + 0xd);
  return 0;
}



undefined4 quicktime_atom_read_header(int param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_18 [12];
  int local_c;
  
  iVar1 = quicktime_position(param_1);
  *param_2 = iVar1;
  quicktime_atom_reset(param_2);
  local_c = quicktime_read_data(param_1,auStack_18,8);
  if (local_c == 0) {
    local_c = 1;
  }
  else {
    if (local_c != 8) {
      ZeroMemory(auStack_18,8);
    }
    local_c = quicktime_atom_read_type(auStack_18,param_2 + 3);
    iVar1 = quicktime_atom_read_size(auStack_18);
    param_2[2] = iVar1;
    if (param_2[2] == 0) {
      param_2[2] = *(int *)(param_1 + 8) - *param_2;
    }
    param_2[1] = *param_2 + param_2[2];
    if (*(int *)(param_1 + 0x16c) == 0) {
      if (*(uint *)(param_1 + 8) < (uint)param_2[1]) {
        param_2[1] = *(int *)(param_1 + 8);
      }
      iVar1 = quicktime_match_32(param_2 + 3,&DAT_0005a4f0);
      if (iVar1 == 0) {
        if (param_2[2] == 1) {
          iVar1 = quicktime_read_data(param_1,auStack_18,8);
          if (iVar1 == 0) {
            local_c = 1;
          }
          else {
            iVar1 = quicktime_atom_read_size64(auStack_18);
            param_2[2] = iVar1;
          }
        }
      }
      else {
        iVar1 = quicktime_position(param_1);
        *param_2 = iVar1;
        quicktime_atom_reset(param_2);
        iVar1 = quicktime_read_data(param_1,auStack_18,8);
        if (iVar1 == 0) {
          local_c = 1;
        }
        else {
          local_c = quicktime_atom_read_type(auStack_18,param_2 + 3);
          param_2[2] = param_2[2] + -8;
          if (param_2[2] == 0) {
            iVar1 = quicktime_atom_read_size(auStack_18);
            param_2[2] = iVar1;
            if (param_2[2] == 0) {
              param_2[2] = *(int *)(param_1 + 8) - *param_2;
            }
          }
          param_2[1] = *param_2 + param_2[2];
          if (*(int *)(param_1 + 0x16c) == 0) {
            if (*(uint *)(param_1 + 8) < (uint)param_2[1]) {
              param_2[1] = *(int *)(param_1 + 8);
            }
          }
          else {
            param_2[1] = 0;
            local_c = 1;
          }
        }
      }
    }
    else {
      param_2[1] = 0;
      local_c = 1;
    }
  }
  return local_c;
}



bool quicktime_atom_write_header(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = quicktime_position(param_1);
  *param_2 = uVar1;
  quicktime_write_int32(param_1,0);
  iVar2 = quicktime_write_char32(param_1,param_3);
  if (iVar2 == -1) {
    *(undefined4 *)(param_1 + 0x168) = 3;
  }
  return iVar2 == -1;
}



bool quicktime_atom_write_footer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = quicktime_position(param_1);
  param_2[1] = iVar1;
  quicktime_set_position(param_1,*param_2);
  iVar1 = quicktime_write_int32(param_1,param_2[1] - *param_2);
  quicktime_set_position(param_1,param_2[1]);
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x168) = 3;
  }
  return iVar1 == -1;
}



undefined4 quicktime_atom_is(int param_1,char *param_2)

{
  undefined4 uVar1;
  
  if ((((*(char *)(param_1 + 0xc) == *param_2) && (*(char *)(param_1 + 0xd) == param_2[1])) &&
      (*(char *)(param_1 + 0xe) == param_2[2])) && (*(char *)(param_1 + 0xf) == param_2[3])) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint quicktime_atom_read_size(byte *param_1)

{
  uint local_c;
  
  local_c = (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[2] << 8 |
            (uint)param_1[3];
  if ((local_c != 0) && (local_c < 8)) {
    local_c = 8;
  }
  return local_c;
}



uint quicktime_atom_read_size64(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    local_c = local_c | *(byte *)(param_1 + local_10);
    if (local_10 < 7) {
      local_c = local_c << 8;
    }
  }
  if (local_c < 8) {
    local_c = 8;
  }
  return local_c;
}



undefined4 quicktime_atom_read_type(int param_1,byte *param_2)

{
  undefined4 uVar1;
  
  *param_2 = *(byte *)(param_1 + 4);
  param_2[1] = *(byte *)(param_1 + 5);
  param_2[2] = *(byte *)(param_1 + 6);
  param_2[3] = *(byte *)(param_1 + 7);
  if ((((((*param_2 < 0x61) || (0x7a < *param_2)) && ((*param_2 < 0x41 || (0x5a < *param_2)))) ||
       (((param_2[1] < 0x61 || (0x7a < param_2[1])) && ((param_2[1] < 0x41 || (0x5a < param_2[1]))))
       )) || (((param_2[2] < 0x61 || (0x7a < param_2[2])) &&
              ((param_2[2] < 0x41 || (0x5a < param_2[2])))))) ||
     (((param_2[3] < 0x61 || (0x7a < param_2[3])) && ((param_2[3] < 0x41 || (0x5a < param_2[3]))))))
  {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_atom_skip(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = quicktime_set_position(param_1,*(undefined4 *)(param_2 + 4));
  return uVar1;
}



undefined4 quicktime_dinf_init(undefined4 param_1)

{
  quicktime_dref_init(param_1);
  return 0;
}



undefined4 quicktime_dinf_delete(undefined4 param_1,undefined4 param_2)

{
  quicktime_dref_delete(param_1,param_2);
  return 0;
}



bool quicktime_dinf_init_all(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = quicktime_dref_init_all(param_1,param_2);
  return iVar1 == 1;
}



undefined4 quicktime_write_dinf(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a4f8);
  quicktime_write_dref(param_1,param_2);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_dref_table_init(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0x75;
  *(undefined1 *)((int)param_1 + 5) = 0x72;
  *(undefined1 *)((int)param_1 + 6) = 0x6c;
  *(undefined1 *)((int)param_1 + 7) = 0x20;
  param_1[2] = 0;
  param_1[3] = 1;
  *(undefined1 *)(param_1 + 4) = 0;
  return 0;
}



undefined4 quicktime_dref_table_delete(void)

{
  return 0;
}



undefined4 quicktime_write_dref_table(undefined4 param_1,int param_2)

{
  size_t sVar1;
  
  sVar1 = strlen((char *)(param_2 + 0x10));
  quicktime_write_int32(param_1,sVar1 + 0xc);
  quicktime_write_char32(param_1,param_2 + 4);
  quicktime_write_char(param_1,*(uint *)(param_2 + 8) & 0xff);
  quicktime_write_int24(param_1,*(undefined4 *)(param_2 + 0xc));
  if (sVar1 != 0) {
    quicktime_write_data(param_1,param_2 + 0x10,sVar1);
  }
  return 0;
}



undefined4 quicktime_dref_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x10);
  return 0;
}



undefined4 quicktime_dref_init_all(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = 1;
    uVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(*(int *)(param_1 + 8) * 0x110);
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    if (*(int *)(param_1 + 0xc) == 0) {
      return 1;
    }
    iVar2 = quicktime_dref_table_init(*(undefined4 *)(param_1 + 0xc));
    if (iVar2 == 1) {
      return 1;
    }
  }
  return 0;
}



undefined4 quicktime_dref_delete(int param_1,int param_2)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 8); local_c = local_c + 1) {
      quicktime_dref_table_delete(*(int *)(param_1 + 0xc) + local_c * 0x110);
    }
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}



undefined4 quicktime_write_dref(undefined4 param_1,uint *param_2)

{
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005a500);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  for (local_c = 0; local_c < (int)param_2[2]; local_c = local_c + 1) {
    quicktime_write_dref_table(param_1,param_2[3] + local_c * 0x110);
  }
  quicktime_atom_write_footer(param_1,auStack_1c);
  return 0;
}



undefined4 quicktime_esds_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x1c);
  return 0;
}



undefined4 quicktime_esds_delete(int param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x18));
  return 0;
}



undefined4 quicktime_read_esds(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = quicktime_read_char(param_1);
  *param_2 = uVar3;
  uVar3 = quicktime_read_int24(param_1);
  param_2[1] = uVar3;
  cVar1 = quicktime_read_char(param_1);
  if (cVar1 == '\x03') {
    iVar4 = quicktime_read_mp4_descr_length(param_1);
    if (iVar4 < 0x14) {
      return 1;
    }
    iVar4 = quicktime_position(param_1);
    quicktime_set_position(param_1,iVar4 + 3);
  }
  else {
    iVar4 = quicktime_position(param_1);
    quicktime_set_position(param_1,iVar4 + 2);
  }
  iVar4 = quicktime_read_char(param_1);
  if (iVar4 == 4) {
    uVar5 = quicktime_read_mp4_descr_length(param_1);
    uVar2 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 2) = uVar2;
    uVar2 = quicktime_read_char(param_1);
    *(undefined1 *)((int)param_2 + 9) = uVar2;
    quicktime_read_int24(param_1);
    uVar3 = quicktime_read_int32(param_1);
    param_2[3] = uVar3;
    uVar3 = quicktime_read_int32(param_1);
    param_2[4] = uVar3;
    if (uVar5 < 0xf) {
      uVar3 = 1;
    }
    else {
      iVar4 = quicktime_read_char(param_1);
      if (iVar4 == 5) {
        uVar3 = quicktime_read_mp4_descr_length(param_1);
        param_2[5] = uVar3;
        if (param_2[6] != 0) {
          (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(param_2[6]);
        }
        uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[5]);
        param_2[6] = uVar3;
        if (param_2[6] == 0) {
          param_2[5] = 0;
        }
        else {
          quicktime_read_data(param_1,param_2[6],param_2[5]);
        }
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



undefined4
quicktime_write_esds_common
          (int param_1,uint *param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5)

{
  undefined1 auStack_18 [16];
  
  if (*(int *)(param_1 + 0x134) != 0) {
    quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a508);
    quicktime_write_char(param_1,*param_2 & 0xff);
    quicktime_write_int24(param_1,param_2[1]);
    quicktime_write_char(param_1,3);
    quicktime_write_mp4_descr_length(param_1,param_2[5] + 0x1d,0);
    quicktime_write_int16(param_1,param_3);
    quicktime_write_char(param_1,0x10);
    quicktime_write_char(param_1,4);
    quicktime_write_mp4_descr_length(param_1,param_2[5] + 0x12,0);
    quicktime_write_char(param_1,param_4);
    quicktime_write_char(param_1,param_5);
    quicktime_write_int24(param_1,0);
    quicktime_write_int32(param_1,0);
    quicktime_write_int32(param_1,0);
    quicktime_write_char(param_1,5);
    quicktime_write_mp4_descr_length(param_1,param_2[5],0);
    quicktime_write_data(param_1,param_2[6],param_2[5]);
    quicktime_write_char(param_1,6);
    quicktime_write_char(param_1,1);
    quicktime_write_char(param_1,2);
    quicktime_atom_write_footer(param_1,auStack_18);
  }
  return 0;
}



undefined4 quicktime_write_esds_audio(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = quicktime_write_esds_common(param_1,param_2,param_3,0x40,0x15);
  return uVar1;
}



undefined4 quicktime_write_esds_video(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = quicktime_write_esds_common(param_1,param_2,param_3,0x20,0x11);
  return uVar1;
}



undefined4 quicktime_write_ftyp(undefined4 param_1)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a510);
  quicktime_write_char32(param_1,&DAT_0005a518);
  quicktime_write_int32(param_1,0);
  quicktime_write_char32(param_1,&DAT_0005a518);
  quicktime_write_char32(param_1,&DAT_0005a520);
  quicktime_write_char32(param_1,&DAT_0005a528);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_hdlr_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 3) = 0x76;
  *(undefined1 *)((int)param_1 + 0xd) = 0x69;
  *(undefined1 *)((int)param_1 + 0xe) = 100;
  *(undefined1 *)((int)param_1 + 0xf) = 0x65;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  memcpy(param_1 + 7,"Green Media Handler",0x14);
  return 0;
}



undefined4 quicktime_hdlr_init_video(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x76;
  *(undefined1 *)(param_1 + 0xd) = 0x69;
  *(undefined1 *)(param_1 + 0xe) = 100;
  *(undefined1 *)(param_1 + 0xf) = 0x65;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  return 0;
}



undefined4 quicktime_hdlr_init_audio(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 0x73;
  *(undefined1 *)(param_1 + 0xd) = 0x6f;
  *(undefined1 *)(param_1 + 0xe) = 0x75;
  *(undefined1 *)(param_1 + 0xf) = 0x6e;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  return 0;
}



undefined4 quicktime_hdlr_delete(void)

{
  return 0;
}



undefined4 quicktime_write_hdlr(int param_1,uint *param_2)

{
  size_t sVar1;
  undefined1 auStack_24 [16];
  int local_14;
  
  quicktime_atom_write_header(param_1,auStack_24,&DAT_0005a544);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_char32(param_1,param_2 + 2);
    quicktime_write_char32(param_1,param_2 + 3);
    quicktime_write_int32(param_1,param_2[4]);
    quicktime_write_int32(param_1,param_2[5]);
    quicktime_write_int32(param_1,param_2[6]);
    quicktime_write_pascal(param_1,param_2 + 7);
  }
  else {
    quicktime_write_int32(param_1,0);
    quicktime_write_char32(param_1,param_2 + 3);
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      quicktime_write_int32(param_1,0);
    }
    sVar1 = strlen((char *)(param_2 + 7));
    quicktime_write_data(param_1,param_2 + 7,sVar1 + 1);
  }
  quicktime_atom_write_footer(param_1,auStack_24);
  return 0;
}



undefined4 quicktime_matrix_init(undefined4 *param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < 9; local_c = local_c + 1) {
    param_1[local_c] = 0;
  }
  param_1[4] = 1;
  *param_1 = param_1[4];
  param_1[8] = 0x4000;
  return 0;
}



undefined4 quicktime_matrix_delete(void)

{
  return 0;
}



undefined4 quicktime_read_matrix(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  for (local_c = 0; local_c < 9; local_c = local_c + 1) {
    uVar1 = quicktime_read_fixed32(param_1);
    *(undefined4 *)(param_2 + local_c * 4) = uVar1;
  }
  return 0;
}



undefined4 quicktime_write_matrix(undefined4 param_1,int param_2)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < 9; local_c = local_c + 1) {
    quicktime_write_fixed32(param_1,*(undefined4 *)(param_2 + local_c * 4));
  }
  return 0;
}



undefined4 quicktime_mdat_init(undefined4 *param_1)

{
  param_1[1] = 8;
  *param_1 = 0;
  return 0;
}



undefined4 quicktime_mdat_delete(void)

{
  return 0;
}



undefined4 quicktime_read_mdat(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  param_2[1] = param_3[2];
  *param_2 = *param_3;
  quicktime_atom_skip(param_1,param_3);
  return 0;
}



undefined4 quicktime_write_mdat(undefined4 param_1,int *param_2)

{
  quicktime_set_position(param_1,*param_2);
  quicktime_write_int32(param_1,param_2[1]);
  quicktime_set_position(param_1,*param_2 + param_2[1]);
  return 0;
}



undefined4 quicktime_mdhd_init(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar1 = quicktime_current_time();
  param_1[2] = uVar1;
  uVar1 = quicktime_current_time();
  param_1[3] = uVar1;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return 0;
}



undefined4 quicktime_mdhd_init_video(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x10) = param_3;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return 0;
}



undefined4 quicktime_mdhd_init_audio(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x10) = param_3;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return 0;
}



undefined4 quicktime_mdhd_delete(void)

{
  return 0;
}



undefined4 quicktime_read_mdhd(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_read_char(param_1);
  *param_2 = iVar1;
  iVar1 = quicktime_read_int24(param_1);
  param_2[1] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[2] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[2] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[3] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[3] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[4] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[6] = iVar1;
  param_2[7] = iVar1 >> 0x1f;
  if (*param_2 == 1) {
    iVar2 = param_2[6];
    iVar1 = quicktime_read_int32(param_1,param_2,iVar2,param_2[7]);
    param_2[6] = iVar1;
    param_2[7] = iVar2;
  }
  iVar1 = quicktime_read_int16(param_1);
  param_2[8] = iVar1;
  iVar1 = quicktime_read_int16(param_1);
  param_2[9] = iVar1;
  return 0;
}



undefined4 quicktime_write_mdhd(int param_1,uint *param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a54c);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  quicktime_write_int32(param_1,param_2[3]);
  quicktime_write_int32(param_1,param_2[4]);
  quicktime_write_int32(param_1,param_2[6]);
  quicktime_write_int16(param_1,param_2[8]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_int16(param_1,param_2[9]);
  }
  else {
    quicktime_write_int16(param_1,0);
  }
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_mdia_init(int param_1)

{
  quicktime_mdhd_init(param_1);
  quicktime_hdlr_init(param_1 + 0x25c);
  quicktime_minf_init(param_1 + 0x28);
  return 0;
}



undefined4
quicktime_mdia_init_video
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  quicktime_mdhd_init_video(param_1,param_2,param_6);
  quicktime_minf_init_video
            (param_1,param_2 + 0x28,param_3,param_4,*(undefined4 *)(param_2 + 0x10),param_5,param_7)
  ;
  quicktime_hdlr_init_video(param_2 + 0x25c);
  return 0;
}



undefined4
quicktime_mdia_init_audio
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  quicktime_mdhd_init_audio(param_1,param_2,param_7);
  quicktime_minf_init_audio
            (param_1,param_2 + 0x28,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  quicktime_hdlr_init_audio(param_2 + 0x25c);
  return 0;
}



undefined4 quicktime_mdia_delete(int param_1,undefined4 param_2)

{
  quicktime_mdhd_delete(param_1);
  quicktime_hdlr_delete(param_1 + 0x25c);
  quicktime_minf_delete(param_1 + 0x28,param_2);
  return 0;
}



undefined4 quicktime_mdia_delete_rec(int param_1,undefined4 param_2)

{
  quicktime_mdhd_delete(param_1);
  quicktime_hdlr_delete(param_1 + 0x25c);
  quicktime_minf_delete_rec(param_1 + 0x28,param_2);
  return 0;
}



undefined4 quicktime_read_mdia(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_18);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(auStack_18,&DAT_0005a554);
    if (iVar1 == 0) {
      iVar1 = quicktime_atom_is(auStack_18,&DAT_0005a55c);
      if (iVar1 == 0) {
        quicktime_atom_skip(param_1,auStack_18);
      }
      else {
        iVar1 = quicktime_read_minf(param_1,param_2 + 0x28,auStack_18);
        if (iVar1 == 1) {
          return 1;
        }
      }
    }
    else {
      quicktime_read_mdhd(param_1,param_2);
    }
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_3 + 4));
  return 0;
}



undefined4 quicktime_write_mdia(undefined4 param_1,int param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a564);
  quicktime_write_mdhd(param_1,param_2);
  quicktime_write_hdlr(param_1,param_2 + 0x25c);
  quicktime_write_minf(param_1,param_2 + 0x28);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_write_mdia_soun(undefined4 param_1,int param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a564);
  quicktime_write_mdhd(param_1,param_2);
  quicktime_write_hdlr(param_1,param_2 + 0x25c);
  quicktime_write_minf_soun(param_1,param_2 + 0x28);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_minf_init(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = param_1[1];
  quicktime_vmhd_init(param_1 + 2);
  quicktime_smhd_init(param_1 + 8);
  quicktime_dinf_init(param_1 + 0x89);
  quicktime_stbl_init(param_1 + 0xc);
  return 0;
}



undefined4
quicktime_minf_init_video
          (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  *param_2 = 1;
  quicktime_vmhd_init_video(param_1,param_2 + 2,param_3,param_4,param_6);
  quicktime_stbl_init_video(param_1,param_2 + 0xc,param_3,param_4,param_5,param_6,param_7);
  iVar1 = quicktime_dinf_init_all(param_2 + 0x89,param_1);
  if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x168) = 4;
  }
  return 0;
}



bool quicktime_minf_init_audio
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 4) = 1;
  quicktime_stbl_init_audio
            (param_1,param_2 + 0x30,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  iVar1 = quicktime_dinf_init_all(param_2 + 0x224,param_1);
  if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x168) = 4;
  }
  return iVar1 == 1;
}



undefined4 quicktime_minf_delete(int param_1,undefined4 param_2)

{
  quicktime_vmhd_delete(param_1 + 8);
  quicktime_smhd_delete(param_1 + 0x20);
  quicktime_dinf_delete(param_1 + 0x224,param_2);
  quicktime_stbl_delete(param_1 + 0x30,param_2);
  return 0;
}



undefined4 quicktime_minf_delete_rec(int param_1,undefined4 param_2)

{
  quicktime_vmhd_delete(param_1 + 8);
  quicktime_smhd_delete(param_1 + 0x20);
  quicktime_dinf_delete(param_1 + 0x224,param_2);
  quicktime_stbl_delete_rec(param_1 + 0x30,param_2);
  return 0;
}



undefined4 quicktime_read_minf(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [16];
  undefined4 local_c;
  
  local_c = quicktime_position(param_1);
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_1c);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a56c);
    if (iVar1 == 0) {
      iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a574);
      if (iVar1 == 0) {
        quicktime_atom_skip(param_1,auStack_1c);
      }
      else {
        param_2[1] = 1;
        quicktime_atom_skip(param_1,auStack_1c);
      }
    }
    else {
      *param_2 = 1;
      quicktime_atom_skip(param_1,auStack_1c);
    }
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_3 + 4));
  quicktime_set_position(param_1,local_c);
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_1c);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a57c);
    if (iVar1 == 0) {
      quicktime_atom_skip(param_1,auStack_1c);
    }
    else {
      iVar1 = quicktime_read_stbl(param_1,param_2,param_2 + 0xc,auStack_1c);
      if (iVar1 == 1) {
        return 1;
      }
    }
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_3 + 4));
  return 0;
}



undefined4 quicktime_write_minf(undefined4 param_1,int *param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a584);
  if (*param_2 != 0) {
    quicktime_write_vmhd(param_1,param_2 + 2);
  }
  if (param_2[1] != 0) {
    quicktime_write_smhd(param_1,param_2 + 8);
  }
  quicktime_write_dinf(param_1,param_2 + 0x89);
  quicktime_write_stbl(param_1,param_2,param_2 + 0xc);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_write_minf_soun(undefined4 param_1,int *param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005a584);
  if (*param_2 != 0) {
    quicktime_write_vmhd(param_1,param_2 + 2);
  }
  if (param_2[1] != 0) {
    quicktime_write_smhd(param_1,param_2 + 8);
  }
  quicktime_write_dinf(param_1,param_2 + 0x89);
  quicktime_write_stbl_soun(param_1,param_2,param_2 + 0xc);
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_moov_init(undefined4 *param_1)

{
  int local_c;
  
  *param_1 = 0;
  for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
    param_1[local_c + 0x20] = 0;
  }
  quicktime_mvhd_init(param_1 + 2);
  quicktime_udta_init(param_1 + 0x40);
  return 0;
}



undefined4 quicktime_moov_delete(int *param_1,undefined4 param_2)

{
  while (*param_1 != 0) {
    quicktime_delete_trak(param_1,param_1[*param_1 + 0x1f],param_2);
  }
  quicktime_mvhd_delete(param_1 + 2);
  quicktime_udta_delete(param_1 + 0x40);
  return 0;
}



undefined4 quicktime_moov_delete_rec(int *param_1,undefined4 param_2)

{
  while (*param_1 != 0) {
    quicktime_delete_trak_rec(param_1,param_1[*param_1 + 0x1f],param_2);
  }
  quicktime_mvhd_delete(param_1 + 2);
  return 0;
}



undefined4 quicktime_read_moov(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [16];
  int local_c;
  
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_1c);
    if (iVar1 == 1) {
      return 1;
    }
    if (*(char *)(param_1 + 0x174) == '\0') {
      iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a594);
      if (iVar1 == 0) {
        iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a59c);
        if (iVar1 == 0) {
          iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a58c);
          if (iVar1 == 0) {
            quicktime_atom_skip(param_1,auStack_1c);
          }
          else {
            quicktime_read_udta(param_1,param_2 + 0x100,auStack_1c);
            quicktime_atom_skip(param_1,auStack_1c);
          }
        }
        else {
          local_c = quicktime_add_trak(param_2,param_1);
          if (local_c == 0) {
            return 1;
          }
          iVar1 = quicktime_read_trak(param_1,local_c,auStack_1c);
          if (iVar1 == 1) {
            return 1;
          }
        }
      }
      else {
        quicktime_read_mvhd(param_1,param_2 + 8);
      }
    }
    else {
      iVar1 = quicktime_atom_is(auStack_1c,&DAT_0005a58c);
      if (iVar1 != 0) {
        quicktime_read_udta(param_1,param_2 + 0x100,auStack_1c);
      }
      quicktime_atom_skip(param_1,auStack_1c);
      uVar2 = quicktime_position(param_1);
      if (*(uint *)(param_3 + 4) <= uVar2) {
        return 0;
      }
    }
    uVar2 = quicktime_position(param_1);
    if (*(uint *)(param_3 + 4) <= uVar2) {
      return 0;
    }
  } while( true );
}



undefined4 quicktime_write_moov(int param_1,int *param_2)

{
  undefined4 local_28;
  int local_24;
  undefined1 auStack_20 [16];
  int local_10;
  int local_c;
  
  local_10 = 0;
  quicktime_atom_write_header(param_1,auStack_20,&DAT_0005a5a4);
  for (local_c = 0; local_c < *(int *)(param_1 + 0x138); local_c = local_c + 1) {
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x13c) + local_c * 0x14) + 0x3f8) =
         *(undefined4 *)(*(int *)(param_1 + 0x13c) + local_c * 0x14 + 8);
  }
  for (local_c = 0; local_c < *(int *)(param_1 + 0x140); local_c = local_c + 1) {
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x144) + local_c * 0x40) + 0x3f8) =
         *(undefined4 *)(*(int *)(param_1 + 0x144) + local_c * 0x40 + 4);
  }
  for (local_c = 0; local_c < *param_2; local_c = local_c + 1) {
    quicktime_trak_fix_counts(param_1,param_2[local_c + 0x20]);
    quicktime_trak_duration(param_2[local_c + 0x20],&local_24,&local_28);
    MulDiv(&local_24,local_24,param_2[6],local_28);
    if (local_10 < local_24) {
      local_10 = local_24;
    }
  }
  param_2[8] = local_10;
  param_2[9] = local_10 >> 0x1f;
  param_2[0x1c] = local_10;
  quicktime_write_mvhd(param_1,param_2 + 2);
  for (local_c = 0; local_c < *param_2; local_c = local_c + 1) {
    if (*(int *)(param_2[local_c + 0x20] + 0x68) == 1) {
      quicktime_write_trak_soun(param_1,param_2[local_c + 0x20],param_2[6]);
    }
    else if (*(int *)(param_2[local_c + 0x20] + 100) == 1) {
      quicktime_write_trak_video(param_1,param_2[local_c + 0x20],param_2[6]);
    }
  }
  quicktime_atom_write_footer(param_1,auStack_20);
  return 0;
}



int MP4Demuxer_Init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[5])(0x6c);
  if (iVar1 == 0) {
    if (*param_1 != 0) {
      (*(code *)*param_1)("##MP4 Demuxer: ERROR--Init, malloc demuxer##\r\n");
    }
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x6c);
    *(int **)(iVar1 + 100) = param_1;
  }
  return iVar1;
}



undefined4 MP4Demuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    MP4Demuxer_Close(param_1);
    uVar1 = (**(code **)(*(int *)(param_1 + 100) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 MP4Demuxer_Open(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  byte *pbVar6;
  byte bStack_281c;
  byte local_281b;
  uint local_1c;
  int local_18;
  byte *local_14;
  
  local_1c = 0;
  local_14 = param_1;
  if (*(int *)(param_1 + 0x5c) == 0) {
    uVar5 = quicktime_open(*param_2,*(undefined4 *)(param_1 + 100),0,param_2[1]);
    *(undefined4 *)(local_14 + 0x5c) = uVar5;
    if (*(int *)(local_14 + 0x5c) == 0) {
      (*g_medialib_printf)("##MP4 Demuxer: ERROR--open quicktimeFile##\r\n");
      uVar5 = 0;
    }
    else {
      uVar2 = quicktime_video_tracks(*(undefined4 *)(local_14 + 0x5c));
      *(undefined2 *)(local_14 + 0x24) = uVar2;
      uVar2 = quicktime_audio_tracks(*(undefined4 *)(local_14 + 0x5c));
      *(undefined2 *)(local_14 + 0x38) = uVar2;
      uVar2 = quicktime_get_proper_videotrack(*(undefined4 *)(local_14 + 0x5c));
      *(undefined2 *)(local_14 + 0x26) = uVar2;
      uVar2 = quicktime_get_proper_audiotrack(*(undefined4 *)(local_14 + 0x5c));
      *(undefined2 *)(local_14 + 0x3a) = uVar2;
      iVar3 = quicktime_check_video_valid
                        (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
      if (iVar3 == 0) {
        local_14[0x24] = 0;
        local_14[0x25] = 0;
      }
      iVar3 = quicktime_check_audio_valid
                        (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
      pbVar6 = local_14;
      if (iVar3 == 0) {
        local_14[0x38] = 0;
        local_14[0x39] = 0;
      }
      if ((*(short *)(local_14 + 0x24) == 0) && (*(short *)(local_14 + 0x38) == 0)) {
        (*g_medialib_printf)("##MP4 Demuxer: ERROR--no valid video or audio##\r\n");
        MP4Demuxer_Close(local_14);
        uVar5 = 0;
      }
      else {
        if (*(short *)(local_14 + 0x24) != 0) {
          local_14[0x61] = 1;
          pvVar4 = (void *)quicktime_video_compressor
                                     (*(undefined4 *)(local_14 + 0x5c),
                                      *(undefined2 *)(local_14 + 0x26));
          memcpy(pbVar6,pvVar4,4);
          local_14[4] = 0;
          if ((0x60 < *local_14) && (*local_14 < 0x7b)) {
            *local_14 = *local_14 - 0x20;
          }
          if ((0x60 < local_14[1]) && (local_14[1] < 0x7b)) {
            local_14[1] = local_14[1] - 0x20;
          }
          if ((0x60 < local_14[2]) && (local_14[2] < 0x7b)) {
            local_14[2] = local_14[2] - 0x20;
          }
          if ((0x60 < local_14[3]) && (local_14[3] < 0x7b)) {
            local_14[3] = local_14[3] - 0x20;
          }
          (*g_medialib_printf)
                    ("##MP4 Demuxer: video_tracks = %d, cur_vtrack = %d, video_codec_name = %s\r\n",
                     *(undefined2 *)(local_14 + 0x24),*(undefined2 *)(local_14 + 0x26),local_14);
          iVar3 = memcmp(local_14 + 1,&DAT_0005a6c0,3);
          if (iVar3 == 0) {
            local_14[0xc] = 1;
            local_14[0xd] = 0;
            local_14[0xe] = 0;
            local_14[0xf] = 0;
          }
          else {
            iVar3 = memcmp(local_14,&DAT_0005a6c4,4);
            if (iVar3 == 0) {
              local_14[0xc] = 2;
              local_14[0xd] = 0;
              local_14[0xe] = 0;
              local_14[0xf] = 0;
              local_1c = quicktime_get_mp4_video_decoder_objcetTypeId
                                   (*(undefined4 *)(local_14 + 0x5c),
                                    *(undefined2 *)(local_14 + 0x26));
              if (0x5f < local_1c) {
                if (local_1c < 0x66) {
                  local_14[0xc] = 0xc;
                  local_14[0xd] = 0;
                  local_14[0xe] = 0;
                  local_14[0xf] = 0;
                }
                else if (local_1c == 0x6c) {
                  local_14[0xc] = 10;
                  local_14[0xd] = 0;
                  local_14[0xe] = 0;
                  local_14[0xf] = 0;
                }
              }
            }
            else {
              iVar3 = memcmp(local_14,&DAT_0005a6cc,4);
              if (iVar3 == 0) {
                local_14[0xc] = 9;
                local_14[0xd] = 0;
                local_14[0xe] = 0;
                local_14[0xf] = 0;
                iVar3 = quicktime_get_mp4_video_decoder_config_size
                                  (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26)
                                  );
                if (iVar3 == 0) {
                  local_14[0xc] = 7;
                  local_14[0xd] = 0;
                  local_14[0xe] = 0;
                  local_14[0xf] = 0;
                }
              }
              else {
                iVar3 = memcmp(local_14,&DAT_0005a6d4,4);
                if ((iVar3 == 0) || (iVar3 = memcmp(local_14,&DAT_0005a6dc,4), iVar3 == 0)) {
                  local_14[0xc] = 0x10;
                  local_14[0xd] = 0;
                  local_14[0xe] = 0;
                  local_14[0xf] = 0;
                  iVar3 = quicktime_get_mp4_video_decoder_config_size
                                    (*(undefined4 *)(local_14 + 0x5c),
                                     *(undefined2 *)(local_14 + 0x26));
                  if (iVar3 == 0) {
                    local_14[0xc] = 0xf;
                    local_14[0xd] = 0;
                    local_14[0xe] = 0;
                    local_14[0xf] = 0;
                  }
                }
                else {
                  local_14[0xc] = 0;
                  local_14[0xd] = 0;
                  local_14[0xe] = 0;
                  local_14[0xf] = 0;
                  (*g_medialib_printf)("##MP4 Demuxer: WARNING--video UNKNOWN##\r\n");
                }
              }
            }
          }
        }
        if (*(short *)(local_14 + 0x38) != 0) {
          local_14[0x60] = 1;
          pbVar6 = local_14 + 5;
          pvVar4 = (void *)quicktime_audio_compressor
                                     (*(undefined4 *)(local_14 + 0x5c),
                                      *(undefined2 *)(local_14 + 0x3a));
          memcpy(pbVar6,pvVar4,4);
          local_14[9] = 0;
          if ((0x60 < local_14[5]) && (local_14[5] < 0x7b)) {
            local_14[5] = local_14[5] - 0x20;
          }
          if ((0x60 < local_14[6]) && (local_14[6] < 0x7b)) {
            local_14[6] = local_14[6] - 0x20;
          }
          if ((0x60 < local_14[7]) && (local_14[7] < 0x7b)) {
            local_14[7] = local_14[7] - 0x20;
          }
          if ((0x60 < local_14[8]) && (local_14[8] < 0x7b)) {
            local_14[8] = local_14[8] - 0x20;
          }
          (*g_medialib_printf)
                    ("##MP4 Demuxer: audio_tracks = %d, cur_atrack = %d, audio_codec_name = %s\r\n",
                     *(undefined2 *)(local_14 + 0x38),*(undefined2 *)(local_14 + 0x3a),local_14 + 5)
          ;
          iVar3 = memcmp(local_14 + 5,&DAT_0005a75c,4);
          if (iVar3 == 0) {
            local_1c = quicktime_get_mp4_audio_decoder_objcetTypeId
                                 (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a))
            ;
            if ((local_1c == 0x6b) || (local_1c == 0x69)) {
              local_14[0x10] = 2;
              local_14[0x11] = 0;
              local_14[0x12] = 0;
              local_14[0x13] = 0;
            }
            else {
              local_14[0x10] = 4;
              local_14[0x11] = 0;
              local_14[0x12] = 0;
              local_14[0x13] = 0;
            }
          }
          else {
            iVar3 = memcmp(local_14 + 5,&DAT_0005a764,4);
            if (iVar3 == 0) {
              local_14[0x10] = 2;
              local_14[0x11] = 0;
              local_14[0x12] = 0;
              local_14[0x13] = 0;
            }
            else {
              iVar3 = memcmp(local_14 + 5,&DAT_0005a76c,4);
              if (iVar3 == 0) {
                local_14[0x10] = 3;
                local_14[0x11] = 0;
                local_14[0x12] = 0;
                local_14[0x13] = 0;
              }
              else {
                iVar3 = memcmp(local_14 + 5,&DAT_0005a774,4);
                if (iVar3 == 0) {
                  local_14[0x10] = 0x10;
                  local_14[0x11] = 0;
                  local_14[0x12] = 0;
                  local_14[0x13] = 0;
                }
                else {
                  iVar3 = memcmp(local_14 + 5,&DAT_0005a77c,4);
                  if (iVar3 == 0) {
                    local_14[0x10] = 6;
                    local_14[0x11] = 0;
                    local_14[0x12] = 0;
                    local_14[0x13] = 0;
                  }
                  else {
                    iVar3 = memcmp(local_14 + 5,&DAT_0005a784,4);
                    if (iVar3 == 0) {
                      local_14[0x10] = 0x11;
                      local_14[0x11] = 0;
                      local_14[0x12] = 0;
                      local_14[0x13] = 0;
                    }
                    else {
                      iVar3 = memcmp(local_14 + 5,&DAT_0005a78c,4);
                      if (iVar3 == 0) {
                        local_14[0x10] = 0x12;
                        local_14[0x11] = 0;
                        local_14[0x12] = 0;
                        local_14[0x13] = 0;
                      }
                      else {
                        local_14[0x60] = 0;
                        (*g_medialib_printf)
                                  ("##MP4 Demuxer: WARNING--UNKNOWN audio type, disable audio\r\n");
                        local_14[0x10] = 0;
                        local_14[0x11] = 0;
                        local_14[0x12] = 0;
                        local_14[0x13] = 0;
                      }
                    }
                  }
                }
              }
            }
          }
          if (*(int *)(local_14 + 0x10) == 2) {
            quicktime_seek_audio
                      (*(undefined4 *)(local_14 + 0x5c),0,*(undefined2 *)(local_14 + 0x3a));
            iVar3 = quicktime_read_audio_frame
                              (*(undefined4 *)(local_14 + 0x5c),&bStack_281c,0x2800,
                               *(undefined2 *)(local_14 + 0x3a));
            if (iVar3 < 0) {
              local_14[0x10] = 2;
              local_14[0x11] = 0;
              local_14[0x12] = 0;
              local_14[0x13] = 0;
            }
            else {
              iVar3 = check_mp3layer(&bStack_281c);
              if (iVar3 == 2) {
                local_14[0x10] = 2;
                local_14[0x11] = 0;
                local_14[0x12] = 0;
                local_14[0x13] = 0;
              }
              else if (iVar3 == 3) {
                local_14[0x10] = 2;
                local_14[0x11] = 0;
                local_14[0x12] = 0;
                local_14[0x13] = 0;
              }
              else if (iVar3 == 1) {
                local_14[0x10] = 2;
                local_14[0x11] = 0;
                local_14[0x12] = 0;
                local_14[0x13] = 0;
              }
              else {
                (*g_medialib_printf)("##MP4 Demuxer: WARNING--UNKNOWN mp3 layer##\r\n");
                local_14[0x10] = 2;
                local_14[0x11] = 0;
                local_14[0x12] = 0;
                local_14[0x13] = 0;
              }
            }
          }
        }
        uVar5 = quicktime_get_total_time(*(undefined4 *)(local_14 + 0x5c));
        *(undefined4 *)(local_14 + 0x14) = uVar5;
        if (local_14[0x61] != 0) {
          uVar5 = quicktime_video_height
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x20) = uVar5;
          uVar5 = quicktime_video_width
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x1c) = uVar5;
          uVar5 = quicktime_video_frame_rate
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x18) = uVar5;
          uVar5 = quicktime_get_video_total_keyframes
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x2c) = uVar5;
          uVar5 = quicktime_get_video_total_frames
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x30) = uVar5;
          uVar5 = quicktime_get_video_bitrate
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          *(undefined4 *)(local_14 + 0x34) = uVar5;
          local_1c = quicktime_video_totaltime
                               (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x26));
          if ((*(uint *)(local_14 + 0x14) <= local_1c) &&
             (*(uint *)(local_14 + 0x14) = local_1c, *(int *)(local_14 + 0x14) == 0)) {
            (*g_medialib_printf)("##MP4 Demuxer: ERROR--video time is zero##\r\n");
            MP4Demuxer_Close(local_14);
            return 0;
          }
          MulDiv(&local_1c,*(undefined4 *)(local_14 + 0x30),1000,*(undefined4 *)(local_14 + 0x14));
          (*g_medialib_printf)
                    ("##MP4 Demuxer: fps=%d, temp=%d##\r\n",*(undefined4 *)(local_14 + 0x18),
                     local_1c);
          if (*(int *)(local_14 + 0x18) == 0) {
            local_14[0x18] = 1;
            local_14[0x19] = 0;
            local_14[0x1a] = 0;
            local_14[0x1b] = 0;
            (*g_medialib_printf)("##MP4 Demuxer: WARNING--fps is zero, change it to 1##\r\n");
          }
          iVar3 = quicktime_is_anka_3gp(*(undefined4 *)(local_14 + 0x5c));
          if (iVar3 == 1) {
            (*g_medialib_printf)
                      ("##MP4 Demuxer: The 3gp file is recorded by the library itself##\r\n");
            local_14[0x62] = 1;
          }
          local_14[0x28] = 0;
          local_14[0x29] = 0;
          local_14[0x2a] = 0;
          local_14[0x2b] = 0;
          while (*(uint *)(local_14 + 0x28) < *(uint *)(local_14 + 0x30)) {
            iVar3 = MP4Demuxer_IsKeyframe(local_14,*(undefined4 *)(local_14 + 0x28));
            if (iVar3 == 1) {
              quicktime_seek_video
                        (*(undefined4 *)(local_14 + 0x5c),*(undefined4 *)(local_14 + 0x28),
                         *(undefined2 *)(local_14 + 0x26));
              iVar3 = quicktime_frame_size
                                (*(undefined4 *)(local_14 + 0x5c),*(undefined4 *)(local_14 + 0x28),
                                 *(undefined2 *)(local_14 + 0x26));
              if (iVar3 != 0) break;
            }
            *(int *)(local_14 + 0x28) = *(int *)(local_14 + 0x28) + 1;
          }
          if (*(uint *)(local_14 + 0x30) <= *(uint *)(local_14 + 0x28)) {
            (*g_medialib_printf)("##MP4 Demuxer: ERROR--first key frame not found\r\n");
            MP4Demuxer_Close(local_14);
            return 0;
          }
        }
        if (local_14[0x60] != 0) {
          uVar5 = quicktime_get_audio_total_bytes
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined4 *)(local_14 + 0x3c) = uVar5;
          uVar5 = quicktime_get_audio_total_samples
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined4 *)(local_14 + 0x48) = uVar5;
          uVar5 = quicktime_audio_sample_rate
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined4 *)(local_14 + 0x4c) = uVar5;
          uVar5 = quicktime_get_audio_bitrate
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined4 *)(local_14 + 0x44) = uVar5;
          uVar2 = quicktime_track_channels
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined2 *)(local_14 + 0x50) = uVar2;
          uVar2 = quicktime_track_bitspersample
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined2 *)(local_14 + 0x52) = uVar2;
          uVar5 = quicktime_audio_totaltime
                            (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          *(undefined4 *)(local_14 + 0x40) = uVar5;
          local_1c = quicktime_get_mp4_audio_decoder_config_size
                               (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a));
          if (((*(int *)(local_14 + 0x10) == 4) && (1 < local_1c)) && (local_1c < 0x2801)) {
            local_18 = 0;
            memset(&bStack_281c,0,0x2800);
            quicktime_get_mp4_audio_decoder_config2
                      (*(undefined4 *)(local_14 + 0x5c),*(undefined2 *)(local_14 + 0x3a),
                       &bStack_281c);
            local_1c = (bStack_281c & 7) << 1 | (uint)(local_281b >> 7);
            local_18 = get_aacsamplerate(local_1c);
            local_1c = local_281b >> 3 & 0xf;
            if ((*(int *)(local_14 + 0x4c) != local_18) && (local_18 != 0)) {
              (*g_medialib_printf)("##MP4 Demuxer: WARNING--samplerate is different!##\r\n");
              *(int *)(local_14 + 0x4c) = local_18;
            }
            if ((((local_1c & 0xffff) != (uint)*(ushort *)(local_14 + 0x50)) && (local_1c < 3)) &&
               (local_1c != 0)) {
              (*g_medialib_printf)("##MP4 Demuxer: WARNING--channels is different!##\r\n");
              *(short *)(local_14 + 0x50) = (short)local_1c;
            }
            bVar1 = get_aacFreqIndex(*(undefined4 *)(local_14 + 0x4c));
            local_14[99] = bVar1;
          }
          else {
            bVar1 = get_aacFreqIndex(*(undefined4 *)(local_14 + 0x4c));
            local_14[99] = bVar1;
          }
        }
        local_14[0x68] = 1;
        uVar5 = 1;
      }
    }
  }
  else {
    (*g_medialib_printf)("##MP4 Demuxer: ERROR--MP4 demxer opened already##\r\n");
    uVar5 = 0;
  }
  return uVar5;
}



undefined4 MP4Demuxer_Close(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    MP4Demuxer_ReleaseInfoMem(param_1);
    quicktime_close(*(undefined4 *)(param_1 + 0x5c));
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return 1;
}



undefined4 MP4Demuxer_GetFileInfo(int param_1,undefined4 *param_2)

{
  if (*(char *)(param_1 + 0x61) != '\0') {
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    param_2[1] = *(undefined4 *)(param_1 + 0x2c);
    if (param_2[1] == 0) {
      param_2[1] = 1;
    }
    param_2[2] = *(undefined4 *)(param_1 + 0x14);
    param_2[5] = *(undefined4 *)(param_1 + 0x34);
    MulDiv(param_2 + 7,*(undefined4 *)(param_1 + 0x30),10000,*(undefined4 *)(param_1 + 0x14));
    if (*(char *)(param_1 + 0x62) != '\0') {
      param_2[7] = *(int *)(param_1 + 0x18) * 10;
    }
    param_2[9] = *(undefined4 *)(param_1 + 0xc);
    param_2[0x16] = *(undefined4 *)(param_1 + 0x1c);
    param_2[0x17] = *(undefined4 *)(param_1 + 0x20);
    if (param_2[7] == 0) {
      param_2[7] = 1;
    }
  }
  if (*(char *)(param_1 + 0x60) != '\0') {
    param_2[3] = *(undefined4 *)(param_1 + 0x48);
    param_2[4] = *(undefined4 *)(param_1 + 0x3c);
    param_2[6] = *(undefined4 *)(param_1 + 0x44);
    param_2[0xc] = *(undefined4 *)(param_1 + 0x4c);
    *(undefined2 *)((int)param_2 + 0x2e) = *(undefined2 *)(param_1 + 0x50);
    *(undefined2 *)((int)param_2 + 0x3a) = *(undefined2 *)(param_1 + 0x52);
    param_2[10] = *(undefined4 *)(param_1 + 0x10);
  }
  param_2[0x18] = *(undefined4 *)(param_1 + 0x14);
  *(undefined1 *)(param_2 + 8) = *(undefined1 *)(param_1 + 0x62);
  if (param_2[1] == 1) {
    *(undefined1 *)((int)param_2 + 0x21) = 0;
  }
  else {
    *(undefined1 *)((int)param_2 + 0x21) = 1;
  }
  param_2[0x19] = *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x180);
  return 1;
}



undefined4 MP4Demuxer_ReleaseInfoMem(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = quicktime_release_infomem(*(undefined4 *)(param_1 + 0x5c));
  }
  return uVar1;
}



undefined4 MP4Demuxer_GetFirstKeyframeSize(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = MP4Demuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x28));
  if (iVar1 == 0) {
    (*g_medialib_printf)("##MP4 Demuxer: ERROR--GetFirstKeyframeSize return failed##\r\n");
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x28);
    quicktime_seek_video
              (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x28),
               *(undefined2 *)(param_1 + 0x26));
    *(undefined1 *)(param_1 + 0x68) = 1;
    uVar2 = MP4Demuxer_GetVideoFrameSize(param_1);
  }
  return uVar2;
}



undefined4 MP4Demuxer_GetFirstKeyframe(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = MP4Demuxer_GetVideoFrame(param_1,param_2,param_3);
  return uVar1;
}



undefined4 MP4Demuxer_GetVideoFrame(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  
  local_18 = 0;
  if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x30)) {
    if (*(char *)(param_1 + 0x68) != '\0') {
      local_18 = quicktime_get_mp4_video_decoder_config_size
                           (*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x26));
      *(undefined1 *)(param_1 + 0x68) = 0;
    }
    local_14 = quicktime_read_video_frame
                         (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x54),
                          param_2 + local_18 + 8,*(undefined2 *)(param_1 + 0x26));
    if (*(int *)(*(int *)(param_1 + 0x5c) + 0x16c) == 0) {
      if ((local_14 == 0) &&
         (iVar1 = quicktime_frame_size
                            (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x54),
                             *(undefined2 *)(param_1 + 0x26)), iVar1 != 0)) {
        (*g_medialib_printf)("##MP4 Demuxer: ERROR--read none while framesize is not zero##\r\n");
        uVar2 = 0;
      }
      else {
        if (local_18 != 0) {
          quicktime_get_mp4_video_decoder_config2
                    (*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x26),param_2 + 8);
          local_14 = local_14 + local_18;
        }
        ulong2str(param_2,*(undefined4 *)(param_1 + 0x54));
        uVar2 = MP4Demuxer_GetVideoPts(param_1,*(undefined4 *)(param_1 + 0x54));
        ulong2str(param_2 + 4,uVar2);
        *param_3 = local_14 + 8;
        *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
        uVar2 = 1;
      }
    }
    else {
      (*g_medialib_printf)("##MP4 Demuxer: ERROR--v read_status is not zero##\r\n");
      uVar2 = 0;
    }
  }
  else {
    (*g_medialib_printf)("##MP4 Demuxer: get video frame, out of range##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



int MP4Demuxer_GetAudioDataSize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = quicktime_audio_position(*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x3a));
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  if (*(uint *)(param_1 + 0x58) < *(uint *)(param_1 + 0x48)) {
    iVar2 = quicktime_audio_frame_size
                      (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58),
                       *(undefined2 *)(param_1 + 0x3a));
    if ((*(int *)(param_1 + 0x10) == 4) && (iVar2 != 0)) {
      iVar2 = iVar2 + 7;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



uint MP4Demuxer_GetAudioData(int param_1,undefined1 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  
  local_14 = 0;
  uVar1 = quicktime_audio_position(*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x3a));
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  if (*(uint *)(param_1 + 0x58) < *(uint *)(param_1 + 0x48)) {
    if (*(int *)(param_1 + 0x10) == 4) {
      if (param_3 < 8) {
        return 0;
      }
      *param_2 = 0xff;
      param_2[1] = 0xf9;
      param_2[2] = (*(byte *)(param_1 + 99) & 0xf) << 2 | 0x40;
      param_2[3] = (char)*(undefined2 *)(param_1 + 0x50) << 6;
      param_2[4] = (char)(param_3 >> 3);
      param_2[5] = (byte)((param_3 & 7) << 5) | 0x1f;
      param_2[6] = 0xfc;
      local_14 = 7;
    }
    iVar2 = quicktime_read_audio_frame
                      (*(undefined4 *)(param_1 + 0x5c),param_2 + local_14,param_3 - local_14,
                       *(undefined2 *)(param_1 + 0x3a));
    if (*(int *)(*(int *)(param_1 + 0x5c) + 0x16c) == 0) {
      if (iVar2 < 1) {
        param_3 = 0;
      }
      else {
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
      }
    }
    else {
      (*g_medialib_printf)("##MP4 Demuxer: ERROR--a read_status is not zero##\r\n");
      param_3 = 0;
    }
  }
  else {
    param_3 = 0;
  }
  return param_3;
}



int MP4Demuxer_GetVideoFrameSize(int param_1)

{
  int iVar1;
  undefined4 local_c;
  
  if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x30)) {
    local_c = quicktime_frame_size
                        (*(undefined4 *)(param_1 + 0x5c),*(uint *)(param_1 + 0x54),
                         *(undefined2 *)(param_1 + 0x26));
    if (*(char *)(param_1 + 0x68) != '\0') {
      iVar1 = quicktime_get_mp4_video_decoder_config_size
                        (*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x26));
      local_c = local_c + iVar1;
    }
    local_c = local_c + 8;
  }
  else {
    local_c = 0;
  }
  return local_c;
}



int MP4Demuxer_SeekVideoSetDirection(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x6a) = param_2;
  return param_1;
}



undefined4 MP4Demuxer_SeekVideo(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_2c = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_28 = 0;
  local_24 = param_1;
  if (*(int *)(param_1 + 0x2c) == 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      quicktime_seek_video(*(undefined4 *)(param_1 + 0x5c),0,*(undefined2 *)(param_1 + 0x26));
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    MulDiv(&local_2c,param_2,*(undefined4 *)(param_1 + 0x18),1000);
    if (local_2c < *(uint *)(local_24 + 0x30)) {
      if (local_2c < *(uint *)(local_24 + 0x28)) {
        local_2c = *(uint *)(local_24 + 0x28);
      }
    }
    else {
      local_2c = *(int *)(local_24 + 0x30) - 1;
    }
    iVar2 = MP4Demuxer_IsKeyframe(param_1,local_2c);
    if (iVar2 == 0) {
      *(uint *)(local_24 + 0x54) = local_2c;
      *(undefined1 *)(local_24 + 0x69) = 1;
      iVar2 = MP4Demuxer_SeekPrevKeyframe(param_1);
      if (iVar2 == 0) {
        (*g_medialib_printf)("##MP4 Demuxer: can\'t find prev key frame, exit.##\r\n");
        return 0xffffffff;
      }
      *(undefined1 *)(local_24 + 0x69) = 0;
    }
    else {
      *(uint *)(local_24 + 0x54) = local_2c;
    }
    *(undefined1 *)(local_24 + 0x69) = 1;
    local_28 = MP4Demuxer_GetVideoPts(local_24,*(undefined4 *)(local_24 + 0x54));
    if (param_2 < local_28) {
      do {
        local_18 = *(uint *)(local_24 + 0x54);
        local_20 = MP4Demuxer_GetVideoPts(local_24,*(undefined4 *)(local_24 + 0x54));
        iVar2 = MP4Demuxer_SeekPrevKeyframe(param_1);
        if (iVar2 == 0) break;
        local_14 = *(uint *)(local_24 + 0x54);
        local_1c = MP4Demuxer_GetVideoPts(local_24,*(undefined4 *)(local_24 + 0x54));
      } while (param_2 <= local_1c);
    }
    else if (local_28 < param_2) {
      do {
        local_14 = *(uint *)(local_24 + 0x54);
        local_1c = MP4Demuxer_GetVideoPts(local_24,*(undefined4 *)(local_24 + 0x54));
        iVar2 = MP4Demuxer_SeekNextKeyframe(param_1);
        if (iVar2 == 0) break;
        local_18 = *(uint *)(local_24 + 0x54);
        local_20 = MP4Demuxer_GetVideoPts(local_24,*(undefined4 *)(local_24 + 0x54));
      } while (local_20 <= param_2);
    }
    else {
      local_18 = *(uint *)(local_24 + 0x54);
      local_20 = local_28;
      local_1c = local_28;
      local_14 = local_18;
    }
    *(undefined1 *)(local_24 + 0x69) = 0;
    cVar1 = *(char *)(local_24 + 0x6a);
    if (cVar1 == '\x01') {
      local_2c = local_14;
    }
    else if (cVar1 == '\x02') {
      local_2c = local_18;
    }
    else if (cVar1 == '\0') {
      if (local_20 - param_2 < param_2 - local_1c) {
        local_2c = local_18;
      }
      else {
        local_2c = local_14;
      }
    }
    else {
      local_2c = local_14;
    }
    *(uint *)(local_24 + 0x54) = local_2c;
    quicktime_seek_video(*(undefined4 *)(local_24 + 0x5c),local_2c,*(undefined2 *)(local_24 + 0x26))
    ;
    uVar3 = MP4Demuxer_GetVideoPts(local_24,local_2c);
  }
  return uVar3;
}



undefined4 MP4Demuxer_SeekAudio(int param_1,undefined4 param_2)

{
  undefined4 local_1c;
  uint local_18;
  int local_14;
  
  local_1c = param_2;
  local_14 = param_1;
  MulDiv(&local_18,param_2,*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x40));
  if (local_18 < *(uint *)(local_14 + 0x48)) {
    quicktime_seek_audio(*(undefined4 *)(local_14 + 0x5c),local_18,*(undefined2 *)(local_14 + 0x3a))
    ;
    MulDiv(&local_1c,local_18,*(undefined4 *)(local_14 + 0x40),*(undefined4 *)(local_14 + 0x48));
    *(uint *)(local_14 + 0x58) = local_18;
  }
  else {
    (*g_medialib_printf)
              ("##MP4 Demuxer: can\'t seek that far (%d), audio total sample is %d##\r\n",local_18,
               *(undefined4 *)(local_14 + 0x48));
    local_1c = 0xffffffff;
  }
  return local_1c;
}



undefined4 MP4Demuxer_IsKeyframe(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      if (param_2 == 0) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      iVar1 = quicktime_is_keyframe
                        (*(undefined4 *)(param_1 + 0x5c),param_2,*(undefined2 *)(param_1 + 0x26));
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Demuxer_SeekPrevKeyframe(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(uint *)(param_1 + 0x30) < *(uint *)(param_1 + 0x54)) {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x30);
  }
  if ((uint)(*(char *)(param_1 + 0x69) == '\0') < *(uint *)(param_1 + 0x54)) {
    if (*(char *)(param_1 + 0x69) == '\0') {
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    while (iVar1 = MP4Demuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x54)), iVar1 == 0) {
      if (*(int *)(param_1 + 0x54) == 0) {
        return 0;
      }
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Demuxer_SeekNextKeyframe(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(uint *)(param_1 + 0x54) < *(int *)(param_1 + 0x30) - 1U) {
    if (*(char *)(param_1 + 0x69) != '\0') {
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    }
    while (iVar1 = MP4Demuxer_IsKeyframe(param_1,*(undefined4 *)(param_1 + 0x54)), iVar1 == 0) {
      if (*(int *)(param_1 + 0x30) - 1U <= *(uint *)(param_1 + 0x54)) {
        return 0;
      }
      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Demuxer_GetVideoPts(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = quicktime_cal_video_pts
                    (*(undefined4 *)(param_1 + 0x5c),param_2,*(undefined2 *)(param_1 + 0x26));
  return uVar1;
}



undefined4 MP4Demuxer_GetAudioPackPts(int param_1)

{
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = param_1;
  MulDiv(&local_10,*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x40),
         *(undefined4 *)(param_1 + 0x48));
  return local_10;
}



undefined4 MP4Demuxer_GetNextBlockInfo(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  if (*(int *)(*(int *)(param_1 + 0x5c) + 0x16c) == 0) {
    uVar1 = quicktime_audio_position
                      (*(undefined4 *)(param_1 + 0x5c),*(undefined2 *)(param_1 + 0x3a));
    *(undefined4 *)(param_1 + 0x58) = uVar1;
    if (*(uint *)(param_1 + 0x58) < *(uint *)(param_1 + 0x48)) {
      local_c = quicktime_get_file_position_audio
                          (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58),
                           *(undefined2 *)(param_1 + 0x3a));
    }
    if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x30)) {
      local_10 = quicktime_get_file_position_video
                           (*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x54),
                            *(undefined2 *)(param_1 + 0x26));
    }
    if ((local_c == 0) && (local_10 == 0)) {
      uVar1 = 0;
    }
    else {
      if (((local_10 < local_c) && (local_10 != 0)) || (local_c == 0)) {
        *param_2 = 1;
        uVar1 = MP4Demuxer_GetVideoFrameSize(param_1);
        param_2[1] = uVar1;
      }
      else {
        *param_2 = 2;
        uVar1 = MP4Demuxer_GetAudioDataSize(param_1);
        param_2[1] = uVar1;
      }
      uVar1 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##MP4 Demuxer: ERROR--read_status is not zero##\r\n");
    uVar1 = 0;
  }
  return uVar1;
}



int MP4_GetMetaInfo(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  ZeroMemory(&local_30,0x24);
  local_2c = 0xffffffff;
  local_30 = param_2;
  local_10 = param_3;
  local_c = quicktime_open(param_2,param_3,1,&local_30);
  if (local_c == 0) {
    local_c = 0;
  }
  else if (*(int *)(local_c + 0x180) == 0) {
    quicktime_close(local_c);
    local_c = 0;
  }
  else {
    memcpy(param_1,*(void **)(local_c + 0x180),0x40);
  }
  return local_c;
}



void MP4_ReleaseMetaInfo(undefined4 param_1)

{
  quicktime_close(param_1);
  return;
}



int MP4Muxer_CheckFileSize(int *param_1)

{
  int iVar1;
  
  iVar1 = quicktime_moov_size(*param_1);
  param_1[0x15] = iVar1;
  if (*(char *)((int)param_1 + 0x46) == '\0') {
    param_1[0x15] = param_1[0x15] + param_1[0x14] * 4;
  }
  iVar1 = param_1[0x15] + *(int *)(*(int *)(*param_1 + 4) + 4);
  if ((iVar1 < 0) || (0x7ffbffff < iVar1)) {
    param_1[0x16] = 5;
  }
  return param_1[0x16];
}



int * MP4Muxer_CheckWriteStatus(int *param_1)

{
  int *piVar1;
  int local_14;
  
  if (*param_1 == 0) {
    return param_1;
  }
  piVar1 = (int *)quicktime_file_write_status(*param_1);
  switch((char)piVar1) {
  case '\0':
    local_14 = param_1[0x16];
    break;
  case '\x01':
    goto LAB_00038294;
  case '\x02':
    goto LAB_00038294;
  case '\x03':
LAB_00038294:
    piVar1 = (int *)(*g_medialib_printf)
                              ("##MP4 Muxer: ERROR--Check Write Status : write file fail!##\r\n");
    local_14 = 4;
    *param_1 = 0;
    break;
  case '\x04':
    piVar1 = (int *)(*g_medialib_printf)
                              (
                              "##MP4 Muxer: ERROR--Check Write Status : memory full in initialization!##\r\n"
                              );
    local_14 = 4;
    *param_1 = 0;
    break;
  case '\x05':
    piVar1 = (int *)(*g_medialib_printf)
                              (
                              "##MP4 Muxer: WARNING--Check Write Status : memory full in handling!##\r\n"
                              );
    local_14 = 5;
    break;
  default:
    local_14 = param_1[0x16];
  }
  param_1[0x16] = local_14;
  return piVar1;
}



uint MP4Muxer_SetParam(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 local_20;
  int *local_1c;
  char local_15;
  int local_14;
  
  local_15 = '\0';
  local_14 = 0;
  if ((char)param_1[0x11] != '\0') {
    iVar2 = param_1[0x1a];
    if (iVar2 == 3) {
      local_20 = 0x6134706d;
    }
    else if (iVar2 == 0xd) {
      local_1c = param_1 + 0xb;
      if ((short)*local_1c == 6) {
        local_20 = 0x77616c61;
      }
      else {
        local_20 = 0x77616c75;
      }
    }
    else {
      if (iVar2 != 1) {
        return 0;
      }
      local_20 = 0x726d6173;
    }
    FIFO_Reset_Old(param_1[1]);
    local_14 = param_1[0xc];
    local_15 = quicktime_set_audio(*param_1,*(undefined2 *)((int)param_1 + 0x2e),param_1[0xc],
                                   *(undefined2 *)((int)param_1 + 0x3a),param_1[3],local_14,
                                   param_1[6],&local_20,param_1[7]);
    if (local_15 != '\0') {
      MP4Muxer_CheckWriteStatus(param_1);
      return 0;
    }
  }
  switch(param_1[0x19]) {
  case 1:
    local_20 = 0x7634706d;
    goto LAB_00038524;
  case 2:
    local_20 = 0x33363273;
    goto LAB_00038524;
  case 3:
    break;
  case 4:
    break;
  case 5:
    local_20 = 0x31637661;
    goto LAB_00038524;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    local_20 = 0x31637668;
LAB_00038524:
    if (*(char *)((int)param_1 + 0x47) == '\x02') {
      local_14 = 1000;
    }
    else {
      local_14 = (uint)*(ushort *)(param_1 + 8) * 10;
    }
    local_15 = quicktime_set_video(*param_1,1,param_1[9],param_1[10],(short)param_1[8],local_14,
                                   &local_20,param_1[0x12],param_1[0x13]);
    if (local_15 != '\0') {
      MP4Muxer_CheckWriteStatus(param_1);
      return 0;
    }
    if ((char)param_1[0x11] != '\0') {
      iVar2 = param_1[0x1a];
      if (iVar2 == 3) {
        cVar1 = quicktime_set_mp4_audio_decoder_config2(*param_1,0,0,0);
        if (cVar1 == '\0') {
          param_1[0x16] = 5;
          return param_1[0x16] & 0xff;
        }
        if (cVar1 != '\0') {
          *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | 2;
        }
      }
      else if (iVar2 == 0xd) {
        *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | 2;
      }
      else {
        if (iVar2 != 1) {
          return 0;
        }
        *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | 2;
      }
    }
    *(int *)(*(int *)(*param_1 + 0x144) + 0x2c) = param_1[0x18];
    return 1;
  }
  return 0;
}



undefined4 MP4Muxer_WriteAudioAmr(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  
  uVar1 = FIFO_ItemNum_Old(param_1[1]);
  if (((*(short *)((int)param_1 + 0x72) == 1000) && ((uVar1 == 0 || (4 < uVar1)))) ||
     ((*(short *)((int)param_1 + 0x72) == 500 && ((uVar1 < 2 || (8 < uVar1)))))) {
    if (*(char *)((int)param_1 + 0x45) == '\0') {
      (*g_medialib_printf)("##MP4 Muxer: ERROR--audio FIFO, empty or too full, %d##\r\n",uVar1);
      param_1[0x16] = 6;
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    *(undefined2 *)(param_1 + 5) = 0;
    (*g_medialib_printf)("#write amr, in fifo there are %d#\r\n",uVar1);
    local_14 = FIFO_Get_Old(param_1[1],param_1[2],2000);
    if (*(short *)((int)param_1 + 0x72) == 500) {
      iVar2 = FIFO_Get_Old(param_1[1],param_1[2] + local_14,2000);
      local_14 = local_14 + iVar2;
    }
    if (param_1[4] == local_14) {
      iVar2 = quicktime_write_audio_frame(*param_1,param_1[2],local_14,0,0,param_1[7]);
      if (iVar2 == 0) {
        param_1[0x14] = param_1[0x14] + param_1[7];
        uVar3 = 1;
      }
      else {
        MP4Muxer_CheckWriteStatus(param_1);
        uVar3 = 0;
      }
    }
    else {
      (*g_medialib_printf)("##MP4 Muxer: ERROR--audio FIFO, 2 packets length is %d##\r\n",local_14);
      param_1[0x16] = 6;
      uVar3 = 0;
    }
  }
  return uVar3;
}



undefined4 MP4Muxer_WriteAudioAmrLast(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  uint local_1c;
  
  while (((*(short *)(param_1 + 0x72) == 1000 &&
          (iVar1 = FIFO_ItemNum_Old(*(undefined4 *)(param_1 + 4)), iVar1 != 0)) ||
         ((*(short *)(param_1 + 0x72) == 500 &&
          (uVar2 = FIFO_ItemNum_Old(*(undefined4 *)(param_1 + 4)), 1 < uVar2))))) {
    iVar1 = MP4Muxer_WriteAudioAmr(param_1);
    if (iVar1 == 0) {
      MP4Muxer_CheckWriteStatus(param_1);
      return 0;
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + *(int *)(param_1 + 0x1c);
    (*g_medialib_printf)("##MP4 Muxer: audio buffer write back##\r\n");
  }
  if ((*(short *)(param_1 + 0x72) == 500) &&
     (iVar1 = FIFO_ItemNum_Old(*(undefined4 *)(param_1 + 4)), iVar1 == 1)) {
    local_20 = *(undefined4 *)(param_1 + 8);
    local_1c = *(uint *)(param_1 + 0x10) >> 1;
    ZeroMemory(local_20,local_1c);
    iVar1 = MP4Muxer_ProcessAudio(param_1,&local_20);
    if (iVar1 != 2) {
      return 0;
    }
    iVar1 = MP4Muxer_WriteAudioAmr(param_1);
    if (iVar1 == 0) {
      MP4Muxer_CheckWriteStatus(param_1);
      return 0;
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + *(int *)(param_1 + 0x1c);
    (*g_medialib_printf)("##MP4 Muxer: last audio buffer write back##\r\n");
  }
  return 1;
}



undefined4 MP4Muxer_WriteAudio(undefined4 *param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  uint local_14;
  
  if (*(char *)(param_1 + 0x11) == '\0') {
    uVar2 = 1;
  }
  else if ((param_1[0x1a] == 1) && (*(char *)((int)param_1 + 0x17) == '\0')) {
    if (param_2 == '\0') {
      uVar2 = MP4Muxer_WriteAudioAmr(param_1);
    }
    else {
      uVar2 = MP4Muxer_WriteAudioAmrLast(param_1);
    }
  }
  else {
    local_14 = FIFO_ItemNum_Old(param_1[1]);
    if ((uint)param_1[7] < local_14) {
      *(undefined2 *)(param_1 + 5) = 0;
      do {
        for (local_18 = 0; local_18 < (uint)param_1[7]; local_18 = local_18 + 1) {
          uVar2 = FIFO_Get_Old(param_1[1],param_1[2],2000);
          iVar1 = quicktime_write_audio_frame(*param_1,param_1[2],uVar2,0,local_18,1);
          if (iVar1 != 0) {
            MP4Muxer_CheckWriteStatus(param_1);
            return 0;
          }
        }
        local_14 = local_14 - param_1[7];
        param_1[0x14] = param_1[0x14] + param_1[7];
      } while ((uint)param_1[7] < local_14);
    }
    if ((param_2 != '\0') && (local_14 != 0)) {
      for (local_18 = 0; local_18 < local_14; local_18 = local_18 + 1) {
        uVar2 = FIFO_Get_Old(param_1[1],param_1[2],2000);
        iVar1 = quicktime_write_audio_frame(*param_1,param_1[2],uVar2,0,local_18,1);
        if (iVar1 != 0) {
          MP4Muxer_CheckWriteStatus(param_1);
          return 0;
        }
      }
      param_1[0x14] = param_1[0x14] + local_14;
      (*g_medialib_printf)("##MP4 Muxer: last audio buffer write back %d##\r\n",local_14);
    }
    uVar2 = 1;
  }
  return uVar2;
}



int MP4Muxer_Init(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x14))(0x80);
  if (iVar1 == 0) {
    (*g_medialib_printf)("##MP4 Muxer: ERROR--Init return FALSE, muxer malloc failed##\r\n");
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x80);
    *(int *)(iVar1 + 0x5c) = param_1;
    *(undefined4 *)(iVar1 + 0x58) = 0;
  }
  return iVar1;
}



undefined4 MP4Muxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x5c) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 MP4Muxer_Open(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  if (param_1[0x16] != 0) {
    return 0;
  }
  *(undefined1 *)((int)param_1 + 0x46) = *(undefined1 *)(param_2 + 0xd);
  *(undefined1 *)((int)param_1 + 0x45) = *(undefined1 *)(param_2 + 0xe);
  *(undefined1 *)(param_1 + 0x11) = *(undefined1 *)((int)param_2 + 0x36);
  *(undefined1 *)((int)param_1 + 0x47) = *(undefined1 *)((int)param_2 + 0x39);
  if ((char)param_1[0x11] != '\0') {
    local_1c = 0;
    MulDiv(&local_1c,1000,param_2[0x13],param_2[6]);
    if (local_1c == 0) {
      (*g_medialib_printf)("##MP4 Muxer: ERROR--Open, audio_duration##\r\n");
      return 0;
    }
    *(short *)((int)param_1 + 0x72) = (short)local_1c;
    param_1[0x1a] = param_2[0x11];
    iVar1 = param_1[0x1a];
    if (iVar1 == 3) {
      if (*(char *)((int)param_1 + 0x45) == '\0') {
        (*g_medialib_printf)("##MP4 Muxer: ERROR--Open, aac not bFlexible##\r\n");
        return 0;
      }
      param_1[6] = param_2[0x13];
      iVar1 = __aeabi_uidiv(1000,local_1c);
      param_1[7] = iVar1;
      local_14 = 2000;
      local_18 = 40000;
    }
    else if (iVar1 == 0xd) {
      if (*(char *)((int)param_1 + 0x45) == '\0') {
        (*g_medialib_printf)("##MP4 Muxer: ERROR--Open, G711 not bFlexible##\r\n");
        return 0;
      }
      param_1[6] = param_2[0x13];
      iVar1 = __aeabi_uidiv(1000,local_1c);
      param_1[7] = iVar1;
      local_14 = 2000;
      local_18 = 40000;
    }
    else {
      if (iVar1 != 1) {
        return 0;
      }
      if (*(char *)((int)param_2 + 0x35) == '\0') {
        iVar1 = 0xe;
      }
      else {
        iVar1 = 0x20;
      }
      param_1[3] = iVar1;
      param_1[7] = 0x32;
      param_1[4] = param_1[3] * param_1[7];
      MulDiv(param_1 + 6,0x14,param_2[6],1000);
      if (param_1[6] == param_2[0x13]) {
        *(undefined1 *)((int)param_1 + 0x17) = 1;
      }
      local_14 = 4000;
      local_18 = 8000;
    }
    if ((*(short *)(param_2 + 0x14) != 0) && ((uint)*(ushort *)(param_2 + 0x14) < (uint)param_1[7]))
    {
      param_1[7] = (uint)*(ushort *)(param_2 + 0x14);
    }
  }
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 0xb);
  param_1[9] = (uint)*(ushort *)(param_2 + 4);
  param_1[10] = (uint)*(ushort *)((int)param_2 + 0x12);
  *(undefined2 *)(param_1 + 0x1f) = *(undefined2 *)(param_2 + 0x1b);
  *(undefined2 *)((int)param_1 + 0x7e) = *(undefined2 *)((int)param_2 + 0x6e);
  if (*(char *)((int)param_1 + 0x46) != '\0') {
    iVar1 = (**(code **)(param_1[0x17] + 0x14))(param_2[0xf]);
    param_1[0x12] = iVar1;
    if (param_1[0x12] == 0) {
      MP4Muxer_Close(param_1);
      (*g_medialib_printf)("##MP4 Muxer: ERROR--Open, malloc VIDEO_MEM_BUF fail!##\r\n");
      return 0;
    }
    param_1[0x13] = param_2[0xf];
    ZeroMemory(param_1[0x12],param_1[0x13]);
  }
  if ((char)param_1[0x11] != '\0') {
    memcpy(param_1 + 0xb,param_2 + 5,0x18);
    iVar1 = (**(code **)(param_1[0x17] + 0x14))(local_14);
    param_1[2] = iVar1;
    if (param_1[2] == 0) {
      (*g_medialib_printf)("##MP4 Muxer: ERROR--can\'t malloc Audio Buf##\r\n");
      MP4Muxer_Close(param_1);
      return 0;
    }
    iVar1 = FIFO_Init_Old(local_18,param_1[0x17]);
    param_1[1] = iVar1;
    if (param_1[1] == 0) {
      MP4Muxer_Close(param_1);
      (*g_medialib_printf)("##MP4 Muxer: ERROR--can\'t malloc Audio fifo##\r\n");
      return 0;
    }
  }
  iVar1 = quicktime_open_rec(*param_2,*(undefined1 *)(param_2 + 0xd),*(undefined1 *)(param_2 + 0xe),
                             *(undefined2 *)((int)param_2 + 0x2e),param_1[0x17],param_2[1]);
  *param_1 = iVar1;
  if (*param_1 == 0) {
    (*g_medialib_printf)("##MP4 Muxer: ERROR--qtFile write file header##\r\n");
    uVar2 = 0;
  }
  else {
    MP4Muxer_CheckWriteStatus(param_1);
    if (param_1[0x16] == 0) {
      param_1[0x18] = param_2[3];
      param_1[0x19] = param_2[0x10];
      param_1[0x1b] = param_2[0x12];
      param_1[0x16] = 1;
      uVar2 = 1;
    }
    else {
      MP4Muxer_Close(param_1);
      (*g_medialib_printf)("##MP4 Muxer: ERROR--Open, status %d##\r\n",param_1[0x16]);
      uVar2 = 0;
    }
  }
  return uVar2;
}



bool MP4Muxer_Close(undefined4 *param_1)

{
  int iVar1;
  bool local_11;
  
  if (param_1[0x16] == 0) {
    local_11 = true;
  }
  else {
    MP4Muxer_Stop(param_1);
    iVar1 = quicktime_close_rec(*param_1);
    if (iVar1 != 0) {
      MP4Muxer_CheckWriteStatus(param_1);
      (*g_medialib_printf)("##MP4 Muxer: ERROR--quicktime close rec fail!##\r\n");
    }
    local_11 = iVar1 == 0;
    *param_1 = 0;
    FIFO_Destroy_Old(param_1[1]);
    (**(code **)(param_1[0x17] + 0x18))(param_1[2]);
    (**(code **)(param_1[0x17] + 0x18))(param_1[0x12]);
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x16] = 0;
  }
  return local_11;
}



undefined4 MP4Muxer_Start(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x58) == 1) {
    iVar1 = MP4Muxer_SetParam(param_1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x58) = 2;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Muxer_Restart(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x16] == 3) {
    *(undefined1 *)((int)param_1 + 0x16) = 0;
    param_1[0x14] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    *(undefined2 *)(param_1 + 0x1c) = 0;
    param_1[0x1d] = 0;
    iVar1 = quicktime_open_rec(*param_2,*(undefined1 *)((int)param_1 + 0x46),
                               *(undefined1 *)((int)param_1 + 0x45),
                               *(undefined2 *)((int)param_2 + 0x2e),param_1[0x17],param_2[1]);
    *param_1 = iVar1;
    if (*param_1 == 0) {
      (*g_medialib_printf)("##MP4 Muxer: ERROR--qtFile write file header##\r\n");
      uVar2 = 0;
    }
    else {
      MP4Muxer_CheckWriteStatus(param_1);
      if ((param_1[0x16] == 0) || (param_1[0x16] == 3)) {
        if (*(char *)((int)param_1 + 0x46) == '\0') {
          if (param_1[0x18] != param_2[3]) {
            param_1[0x18] = param_2[3];
          }
          (**(code **)(param_1[0x17] + 0xc))(param_1[0x18],0,0);
        }
        iVar1 = MP4Muxer_SetParam(param_1);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          param_1[0x16] = 2;
          uVar2 = 1;
        }
      }
      else {
        MP4Muxer_Close(param_1);
        (*g_medialib_printf)("##MP4 Muxer: ERROR--Restart, status %d##\r\n",param_1[0x16]);
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Muxer_Stop(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1[0x16] == 2) || (param_1[0x16] == 5)) || (param_1[0x16] == 6)) {
    (*g_medialib_printf)("#in finalize...#\r\n");
    if (((*(char *)(param_1 + 0x11) == '\0') || (param_1[0x16] != 2)) ||
       (iVar1 = MP4Muxer_WriteAudio(param_1,1), iVar1 != 0)) {
      iVar1 = quicktime_close_rec(*param_1);
      if (iVar1 != 0) {
        MP4Muxer_CheckWriteStatus(param_1);
        (*g_medialib_printf)("##MP4 Muxer: ERROR--quicktime close rec fail!##\r\n");
      }
      *param_1 = 0;
      if ((*(ushort *)(param_1 + 0x1c) & 1) == 0) {
        (*g_medialib_printf)("##MP4 Muxer: WARNING--video config##\r\n");
        param_1[0x16] = 4;
        uVar2 = 0;
      }
      else {
        param_1[0x16] = 3;
        uVar2 = 1;
      }
    }
    else {
      MP4Muxer_CheckWriteStatus(param_1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 MP4Muxer_ProcessAudio(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x58) == 2) {
    if (((*(int *)(param_1 + 0x68) == 1) && (*(char *)(param_1 + 0x17) == '\0')) &&
       (((*(short *)(param_1 + 0x72) == 1000 && (param_2[1] != *(int *)(param_1 + 0x10))) ||
        ((*(short *)(param_1 + 0x72) == 500 && (param_2[1] != *(uint *)(param_1 + 0x10) >> 1)))))) {
      *(undefined4 *)(param_1 + 0x58) = 6;
      if (*(short *)(param_1 + 0x72) == 1000) {
        uVar3 = *(uint *)(param_1 + 0x10);
      }
      else {
        uVar3 = *(uint *)(param_1 + 0x10) >> 1;
      }
      (*g_medialib_printf)
                ("##MP4 Muxer: ERROR--audio packet length %d, req %d##\r\n",param_2[1],uVar3);
      uVar2 = *(undefined4 *)(param_1 + 0x58);
    }
    else {
      iVar1 = FIFO_Add_Old(*(undefined4 *)(param_1 + 4),*param_2 + (uint)*(ushort *)(param_1 + 0x7e)
                           ,param_2[1]);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x58) = 6;
        (*g_medialib_printf)("##MP4 Muxer: ERROR--audio fifo overflow##\r\n");
        uVar2 = *(undefined4 *)(param_1 + 0x58);
      }
      else if (*(char *)(param_1 + 0x45) == '\0') {
        uVar2 = 2;
      }
      else {
        iVar1 = MP4Muxer_WriteAudio(param_1,0);
        if (iVar1 == 0) {
          uVar2 = *(undefined4 *)(param_1 + 0x58);
        }
        else {
          uVar2 = MP4Muxer_CheckFileSize(param_1);
        }
      }
    }
  }
  else {
    (*g_medialib_printf)
              ("##MP4 Muxer: ERROR--Process audio status %d##\r\n",*(undefined4 *)(param_1 + 0x58));
    uVar2 = *(undefined4 *)(param_1 + 0x58);
  }
  return uVar2;
}



int MP4Muxer_ProcessVideo(int *param_1,int *param_2)

{
  bool bVar1;
  uint extraout_r1;
  int iVar2;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  bVar1 = false;
  if (param_1[0x16] != 2) {
    (*g_medialib_printf)("##MP4 Muxer: ERROR--Process video status %d##\r\n",param_1[0x16]);
    return param_1[0x16];
  }
  if ((param_2[1] != 0) && ((param_1[0x19] == 5 || (param_1[0x19] == 9)))) {
    local_14 = h264_startcode2length(*param_2 + (uint)*(ushort *)(param_1 + 0x1f),param_2[1]);
  }
  if ((*(ushort *)(param_1 + 0x1c) & 1) == 0) {
    if ((*(char *)((int)param_1 + 0x45) != '\0') && (param_2[1] == 0)) {
      return param_1[0x16];
    }
    bVar1 = true;
    iVar2 = param_1[0x19];
    if ((iVar2 == 5) || (iVar2 == 9)) {
      if (local_14 == 0) {
        param_1[0x16] = 4;
        return param_1[0x16];
      }
      *(char *)(*param_1 + 0x17c) = (char)((uint)local_14 >> 0x18);
    }
    else if (iVar2 != 1) {
      *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | 1;
      goto LAB_00039e38;
    }
    iVar2 = quicktime_set_mp4_video_decoder_config2(*param_1,0,*param_2 + 8,param_2[1]);
    if (iVar2 == 0) {
      param_1[0x16] = 5;
      return param_1[0x16];
    }
    if (0 < iVar2) {
      *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_1 + 0x1c) | 1;
    }
  }
LAB_00039e38:
  if (*(char *)((int)param_1 + 0x45) != '\0') {
    if ((param_2[1] == 0) || (bVar1)) {
      if ((bVar1) && (*(char *)((int)param_1 + 0x47) == '\x02')) {
        param_1[0x1e] = param_2[2];
      }
    }
    else {
      iVar2 = str2ulong(*param_2);
      if (*(char *)((int)param_1 + 0x47) == '\x02') {
        local_18 = param_2[2] - param_1[0x1e];
        if ((local_18 == 0) || (60000 < local_18)) {
          (*g_medialib_printf)("## war: mp4 pts is suspicious:%d, %d\n",param_1[0x1e],param_2[2]);
          local_18 = (iVar2 - param_1[0x1d]) * 10;
        }
        param_1[0x1e] = param_2[2];
      }
      else {
        local_18 = (iVar2 - param_1[0x1d]) * 10;
      }
      param_1[0x1d] = iVar2;
    }
  }
  iVar2 = quicktime_write_video_frame
                    (*param_1,*param_2 + (uint)*(ushort *)(param_1 + 0x1f),param_2[1],0,
                     (char)param_2[3],local_18,(short)param_1[5]);
  if (iVar2 == 0) {
    if ((param_2[1] != 0) || (*(char *)((int)param_1 + 0x45) == '\0')) {
      param_1[0x14] = param_1[0x14] + 1;
      *(short *)(param_1 + 5) = (short)param_1[5] + 1;
    }
    if (((*(char *)((int)param_1 + 0x45) == '\0') && ((char)param_1[0x11] != '\0')) &&
       (__aeabi_uidivmod((short)param_1[5],(short)param_1[8]), (extraout_r1 & 0xffff) == 0)) {
      if (*(char *)((int)param_1 + 0x16) == '\0') {
        *(undefined1 *)((int)param_1 + 0x16) = 1;
      }
      else {
        iVar2 = MP4Muxer_WriteAudio(param_1,0);
        if (iVar2 == 0) {
          return param_1[0x16];
        }
      }
    }
    iVar2 = MP4Muxer_CheckFileSize(param_1);
  }
  else {
    MP4Muxer_CheckWriteStatus(param_1);
    iVar2 = param_1[0x16];
  }
  return iVar2;
}



undefined4 MP4Muxer_GetHeaderSize(int param_1)

{
  return *(undefined4 *)(param_1 + 0x54);
}



undefined4 MP4Muxer_GetCurrFileSize(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(*param_1 + 4) + 4);
  }
  return uVar1;
}



undefined4 quicktime_mvhd_init(undefined4 *param_1)

{
  undefined4 uVar1;
  int local_c;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar1 = quicktime_current_time();
  param_1[2] = uVar1;
  uVar1 = quicktime_current_time();
  param_1[3] = uVar1;
  param_1[4] = 9000;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    *(undefined1 *)((int)param_1 + local_c + 0x28) = 0;
  }
  quicktime_matrix_init(param_1 + 0xd);
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 1;
  return 0;
}



undefined4 quicktime_mvhd_delete(void)

{
  return 0;
}



undefined4 quicktime_read_mvhd(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_read_char(param_1);
  *param_2 = iVar1;
  iVar1 = quicktime_read_int24(param_1);
  param_2[1] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[2] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[2] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[3] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[3] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[4] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[6] = iVar1;
  param_2[7] = iVar1 >> 0x1f;
  if (*param_2 == 1) {
    iVar2 = param_2[6];
    iVar1 = quicktime_read_int32(param_1,param_2,iVar2,param_2[7]);
    param_2[6] = iVar1;
    param_2[7] = iVar2;
  }
  iVar1 = quicktime_read_fixed32(param_1);
  param_2[8] = iVar1;
  iVar1 = quicktime_read_fixed16(param_1);
  param_2[9] = iVar1;
  quicktime_read_data(param_1,param_2 + 10,10);
  quicktime_read_matrix(param_1,param_2 + 0xd);
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x16] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x17] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x18] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x19] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x1a] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x1b] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[0x1c] = iVar1;
  return 0;
}



undefined4 quicktime_write_mvhd(int param_1,uint *param_2)

{
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b090);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  quicktime_write_int32(param_1,param_2[3]);
  quicktime_write_int32(param_1,param_2[4]);
  quicktime_write_int32(param_1,param_2[6]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_fixed32(param_1,param_2[8]);
    quicktime_write_fixed16(param_1,param_2[9]);
    quicktime_write_data(param_1,param_2 + 10,10);
    quicktime_write_matrix(param_1,param_2 + 0xd);
    quicktime_write_int32(param_1,param_2[0x16]);
    quicktime_write_int32(param_1,param_2[0x17]);
    quicktime_write_int32(param_1,param_2[0x18]);
    quicktime_write_int32(param_1,param_2[0x19]);
    quicktime_write_int32(param_1,param_2[0x1a]);
    quicktime_write_int32(param_1,param_2[0x1b]);
  }
  else {
    quicktime_write_int32(param_1,0x10000);
    quicktime_write_int16(param_1,0x100);
    quicktime_write_int16(param_1,0);
    quicktime_write_int32(param_1,0);
    quicktime_write_int32(param_1,0);
    quicktime_write_int32(param_1,0x10000);
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    quicktime_write_int32(param_1,0x10000);
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    quicktime_write_int32(param_1,0x40000000);
    for (local_c = 0; local_c < 6; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
  }
  quicktime_write_int32(param_1,param_2[0x1c]);
  quicktime_atom_write_footer(param_1,auStack_1c);
  return 0;
}



int quicktime_video_tracks(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < *(int *)(param_1 + 0x18); local_c = local_c + 1) {
    if (*(int *)(*(int *)(param_1 + (local_c + 0x26) * 4) + 0x98) != 0) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}



int quicktime_audio_tracks(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  for (local_c = 0; local_c < *(int *)(param_1 + 0x18); local_c = local_c + 1) {
    if (*(int *)(*(int *)(param_1 + (local_c + 0x26) * 4) + 0x9c) != 0) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}



int quicktime_add_track(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(0x408);
  param_1[iVar2 + 0x20] = iVar1;
  iVar1 = param_1[iVar2 + 0x20];
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    quicktime_trak_init(iVar1);
    *(int *)(iVar1 + 0x10) = param_1[0x1e];
    param_1[0x1e] = param_1[0x1e] + 1;
    *param_1 = *param_1 + 1;
  }
  return iVar1;
}



undefined4 quicktime_init(int param_1)

{
  ZeroMemory(param_1,0x188);
  quicktime_mdat_init(param_1 + 0xc);
  quicktime_moov_init(param_1 + 0x18);
  return 0;
}



undefined4 quicktime_delete(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x138) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x138); local_c = local_c + 1) {
      quicktime_delete_audio_map(*(int *)(param_1 + 0x13c) + local_c * 0x14);
    }
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x13c));
  }
  if (*(int *)(param_1 + 0x140) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x140); local_c = local_c + 1) {
      quicktime_delete_video_map(*(int *)(param_1 + 0x144) + local_c * 0x40,param_1);
    }
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x144));
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  if (*(int *)(param_1 + 0x14c) != 0) {
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x150));
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  quicktime_moov_delete(param_1 + 0x18,param_1);
  quicktime_mdat_delete(param_1 + 0xc);
  return 0;
}



undefined4 quicktime_delete_rec(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x138) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x138); local_c = local_c + 1) {
      quicktime_delete_audio_map(*(int *)(param_1 + 0x13c) + local_c * 0x14);
    }
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x13c));
  }
  if (*(int *)(param_1 + 0x140) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x140); local_c = local_c + 1) {
      quicktime_delete_video_map(*(int *)(param_1 + 0x144) + local_c * 0x40,param_1);
    }
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x144));
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  if (*(int *)(param_1 + 0x14c) != 0) {
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x150));
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  quicktime_moov_delete_rec(param_1 + 0x18,param_1);
  quicktime_mdat_delete(param_1 + 0xc);
  return 0;
}



undefined4 quicktime_audio_position(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_video_position(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x140)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x144) + param_2 * 0x40 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4
quicktime_set_audio(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                   ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  int local_c;
  
  *(undefined4 *)(param_1 + 0x178) = param_9;
  for (local_c = 0; local_c < *(int *)(param_1 + 0x138); local_c = local_c + 1) {
    quicktime_delete_audio_map(*(int *)(param_1 + 0x13c) + local_c * 0x14);
    quicktime_delete_trak_rec
              (param_1 + 0x18,*(undefined4 *)(*(int *)(param_1 + 0x13c) + local_c * 0x14),param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  if (param_2 != 0) {
    iVar1 = quicktime_match_32(param_8,&DAT_0005b098);
    if ((iVar1 != 0) ||
       (iVar1 = quicktime_match_32(param_8,&DAT_0005b0a0), local_20 = param_4, iVar1 != 0)) {
      local_20 = 0x10;
    }
    uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(0x14);
    *(undefined4 *)(param_1 + 0x13c) = uVar2;
    if (*(int *)(param_1 + 0x13c) == 0) {
      quicktime_delete_rec(param_1);
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
    iVar1 = quicktime_add_track(param_1 + 0x18,param_1);
    if (iVar1 == 0) {
      quicktime_delete_rec(param_1);
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
    quicktime_trak_init_audio
              (param_1,iVar1,param_2,param_3,local_20,param_5,param_6,param_7,param_8);
    if (*(int *)(param_1 + 0x168) != 0) {
      quicktime_delete_rec(param_1);
      return 1;
    }
    quicktime_init_audio_map_rec(*(undefined4 *)(param_1 + 0x13c),iVar1);
    *(int *)(*(int *)(param_1 + 0x13c) + *(int *)(param_1 + 0x138) * 0x14) = iVar1;
    *(int *)(*(int *)(param_1 + 0x13c) + *(int *)(param_1 + 0x138) * 0x14 + 4) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + *(int *)(param_1 + 0x138) * 0x14 + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + *(int *)(param_1 + 0x138) * 0x14 + 0xc) = 1;
    *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
  }
  return 0;
}



undefined4
quicktime_set_video(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                   undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (0x18c00 < param_4 * param_3) {
    *(undefined1 *)(param_1 + 0x161) = 2;
  }
  for (local_c = 0; local_c < *(int *)(param_1 + 0x140); local_c = local_c + 1) {
    quicktime_delete_video_map(*(int *)(param_1 + 0x144) + local_c * 0x40,param_1);
    quicktime_delete_trak_rec
              (param_1 + 0x18,*(undefined4 *)(*(int *)(param_1 + 0x144) + local_c * 0x40),param_1);
  }
  (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x144));
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  if (0 < param_2) {
    *(int *)(param_1 + 0x140) = param_2;
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(*(int *)(param_1 + 0x140) << 6);
    *(undefined4 *)(param_1 + 0x144) = uVar1;
    if (*(int *)(param_1 + 0x144) == 0) {
      quicktime_delete_rec(param_1);
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
    for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
      iVar2 = quicktime_add_track(param_1 + 0x18,param_1);
      if (iVar2 == 0) {
        quicktime_delete_rec(param_1);
        *(undefined4 *)(param_1 + 0x168) = 4;
        return 1;
      }
      quicktime_trak_init_video(param_1,iVar2,param_3,param_4,param_5,param_6,param_7);
      if (*(int *)(param_1 + 0x168) != 0) {
        quicktime_delete_rec(param_1);
        return 1;
      }
      iVar2 = quicktime_init_video_map_rec
                        (*(int *)(param_1 + 0x144) + local_c * 0x40,iVar2,
                         *(undefined1 *)(param_1 + 0x160),param_8,param_9);
      if (iVar2 == 1) {
        quicktime_delete_rec(param_1);
        *(undefined4 *)(param_1 + 0x168) = 1;
        return 1;
      }
    }
  }
  return 0;
}



undefined4 quicktime_set_audio_position(int param_1,undefined4 param_2,int param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x138) != 0) {
    local_c = *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14);
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14 + 8) = param_2;
    quicktime_chunk_of_sample(&local_14,&local_18,local_c,param_2);
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14 + 0xc) = local_18;
    local_10 = quicktime_sample_to_offset(local_c,param_2,local_14,local_18);
    quicktime_set_position(param_1,local_10);
  }
  return 0;
}



undefined4 quicktime_set_video_position(int param_1,undefined4 param_2,int param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x140) != 0) {
    local_c = *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40);
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 4) = param_2;
    quicktime_chunk_of_sample(&local_14,&local_18,local_c,param_2);
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 8) = local_18;
    local_10 = quicktime_sample_to_offset(local_c,param_2,local_14,local_18);
    quicktime_set_position(param_1,local_10);
  }
  return 0;
}



bool quicktime_has_audio(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = quicktime_audio_tracks(param_1);
  return iVar1 != 0;
}



int quicktime_audio_sample_rate(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x80);
    if (iVar1 < 1) {
      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc) + 0x80)
      ;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 quicktime_audio_compressor(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    if (*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_track_channels(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14 + 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_track_bitspersample(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    uVar1 = *(undefined4 *)
             (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc) + 0x74);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



bool quicktime_has_video(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = quicktime_video_tracks(param_1);
  return iVar1 != 0;
}



int quicktime_video_width(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0x140)) {
    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc) + 0x24);
    if (iVar1 == 0) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x5c);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



int quicktime_video_height(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0x140)) {
    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc) + 0x28);
    if (iVar1 == 0) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x60);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 quicktime_video_frame_rate(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0;
  if (param_2 < *(int *)(param_1 + 0x140)) {
    local_c = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x80);
    for (local_14 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xe8);
        0 < local_14; local_14 = local_14 + -1) {
      iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xf0) +
                       local_10 * 8 + 4);
      if (iVar2 != 0) {
        uVar1 = __divsi3(local_c,iVar2);
        return uVar1;
      }
      local_10 = local_10 + 1;
    }
  }
  return local_c;
}



undefined4 quicktime_video_compressor(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x140)) {
    if (*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4
quicktime_write_audio_frame
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = quicktime_position(param_1);
  iVar2 = quicktime_write_data(param_1,param_2,param_3);
  if (iVar2 == -1) {
    quicktime_delete_rec(param_1);
    *(undefined4 *)(param_1 + 0x168) = 2;
    uVar1 = 1;
  }
  else {
    iVar2 = quicktime_update_tables_audio
                      (param_1,*(undefined4 *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14),uVar1,
                       *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 0xc),param_3,
                       *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 8),param_5);
    if (iVar2 == 1) {
      uVar1 = 1;
    }
    else {
      *(int *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 8) =
           *(int *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 8) + param_6;
      if (param_5 == 0) {
        iVar2 = *(int *)(param_1 + 0x13c) + param_4 * 0x14;
        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



undefined4
quicktime_write_video_frame
          (int param_1,undefined4 param_2,int param_3,int param_4,undefined1 param_5,
          undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = quicktime_position(param_1);
  if ((*(char *)(param_1 + 0x175) == '\0') || (param_3 != 0)) {
    if ((*(char *)(param_1 + 0x161) == '\x01') && (0xffff < param_3)) {
      (*g_medialib_printf)("##video size out of range(%d)\r\n#",param_3);
      *(undefined4 *)(param_1 + 0x168) = 5;
      uVar1 = 1;
    }
    else {
      iVar2 = quicktime_write_data(param_1,param_2,param_3);
      if (iVar2 == -1) {
        quicktime_delete_rec(param_1);
        *(undefined4 *)(param_1 + 0x168) = 2;
        uVar1 = 1;
      }
      else {
        iVar2 = quicktime_update_tables_video
                          (param_1,*(int *)(param_1 + 0x144) + param_4 * 0x40,
                           *(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40),uVar1,
                           *(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 8),
                           *(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4),param_7,
                           param_3,param_6,param_5);
        if (iVar2 == 1) {
          uVar1 = 1;
        }
        else {
          *(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4) =
               *(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4) + 1;
          if (param_7 == 0) {
            iVar2 = *(int *)(param_1 + 0x144) + param_4 * 0x40;
            *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
          }
          uVar1 = 0;
        }
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_frame_size(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40);
  if (*(int *)(iVar1 + 0x15c) == 0) {
    local_c = *(undefined4 *)(*(int *)(iVar1 + 0x168) + param_2 * 4);
  }
  else {
    local_c = *(undefined4 *)(iVar1 + 0x15c);
  }
  return local_c;
}



undefined4 quicktime_audio_frame_size(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14);
  if (*(int *)(iVar1 + 0x15c) == 0) {
    local_c = *(undefined4 *)(*(int *)(iVar1 + 0x168) + param_2 * 4);
  }
  else {
    local_c = *(undefined4 *)(iVar1 + 0x15c);
  }
  return local_c;
}



int quicktime_read_audio_frame(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_audio_frame_size
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 8),param_4
                    );
  if (param_3 < iVar1) {
    iVar1 = -iVar1;
  }
  else {
    quicktime_set_audio_position
              (param_1,*(undefined4 *)(*(int *)(param_1 + 0x13c) + param_4 * 0x14 + 8),param_4);
    iVar1 = quicktime_read_data(param_1,param_2,iVar1);
    iVar2 = *(int *)(param_1 + 0x13c) + param_4 * 0x14;
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
  }
  return iVar1;
}



bool quicktime_init_video_map(int *param_1,int param_2)

{
  bool bVar1;
  
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  bVar1 = *(int *)(param_2 + 0xf0) != 0;
  if (bVar1) {
    param_1[4] = **(int **)(param_2 + 0xf0);
  }
  else {
    param_1[4] = 0;
  }
  return !bVar1;
}



undefined4
quicktime_init_video_map_rec
          (undefined4 *param_1,undefined4 param_2,char param_3,int param_4,int param_5)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (param_3 == '\0') {
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
  }
  else {
    param_1[0xb] = 0;
    param_1[0xc] = param_4;
    param_1[0xd] = param_4 + param_5;
    param_1[0xe] = param_4;
  }
  param_1[10] = 0;
  return 0;
}



undefined4 quicktime_delete_video_map(int param_1,int param_2)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x24); local_c = local_c + 1) {
      (**(code **)(*(int *)(param_2 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x20) + local_c * 4));
    }
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return 0;
}



bool quicktime_init_audio_map(int *param_1,int param_2)

{
  bool bVar1;
  
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 1;
  bVar1 = *(int *)(param_2 + 0xdc) != 0;
  if (bVar1) {
    param_1[1] = *(int *)(*(int *)(param_2 + 0xdc) + 0x70);
  }
  else {
    param_1[1] = 0;
  }
  return !bVar1;
}



undefined4 quicktime_init_audio_map_rec(int *param_1,int param_2)

{
  *param_1 = param_2;
  param_1[1] = *(int *)(*(int *)(param_2 + 0xdc) + 0x70);
  param_1[2] = 0;
  param_1[3] = 1;
  return 0;
}



undefined4 quicktime_delete_audio_map(void)

{
  return 0;
}



bool quicktime_read_info(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = 0;
  local_c = 0;
  local_1c = quicktime_position(param_1);
  quicktime_read_char32(param_1,auStack_30);
  iVar1 = quicktime_match_32(auStack_30,&DAT_0005b0cc);
  if (iVar1 != 0) {
    quicktime_read_char32(param_1,auStack_30);
    quicktime_read_char32(param_1,auStack_30);
    iVar1 = quicktime_match_32(auStack_30,&DAT_0005b0d4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x130) = 1;
    }
  }
  quicktime_set_position(param_1,0);
  do {
    local_18 = quicktime_atom_read_header(param_1,auStack_2c);
    if (local_18 == 0) {
      iVar1 = quicktime_atom_is(auStack_2c,&DAT_0005b0dc);
      if (iVar1 == 0) {
        iVar1 = quicktime_atom_is(auStack_2c,&DAT_0005b0e4);
        if (iVar1 == 0) {
          quicktime_atom_skip(param_1,auStack_2c);
        }
        else {
          iVar1 = quicktime_read_moov(param_1,param_1 + 0x18,auStack_2c);
          if (iVar1 == 1) {
            return true;
          }
          local_c = 1;
        }
      }
      else {
        quicktime_read_mdat(param_1,param_1 + 0xc,auStack_2c);
        if ((local_c != 0) &&
           (iVar1 = MediaFile_GetTotalLen(*(undefined4 *)(param_1 + 4)), iVar1 == -1)) {
          *(undefined4 *)(*(int *)(param_1 + 4) + 4) = local_28;
LAB_0003c5e4:
          quicktime_set_position(param_1,local_1c);
          if ((local_c != 0) && (*(char *)(param_1 + 0x174) == '\0')) {
            uVar3 = quicktime_audio_tracks(param_1);
            *(undefined4 *)(param_1 + 0x138) = uVar3;
            if (*(int *)(param_1 + 0x138) != 0) {
              uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                                (*(int *)(param_1 + 0x138) * 0x14);
              *(undefined4 *)(param_1 + 0x13c) = uVar3;
              if (*(int *)(param_1 + 0x13c) == 0) {
                return true;
              }
            }
            local_14 = 0;
            for (local_10 = 0; local_10 < *(int *)(param_1 + 0x138); local_10 = local_10 + 1) {
              while (*(int *)(*(int *)(param_1 + (local_14 + 0x26) * 4) + 0x9c) == 0) {
                local_14 = local_14 + 1;
              }
              iVar1 = quicktime_init_audio_map
                                (*(int *)(param_1 + 0x13c) + local_10 * 0x14,
                                 *(undefined4 *)(param_1 + (local_14 + 0x26) * 4));
              if (iVar1 == 1) {
                return true;
              }
              local_14 = local_14 + 1;
            }
            uVar3 = quicktime_video_tracks(param_1);
            *(undefined4 *)(param_1 + 0x140) = uVar3;
            if (*(int *)(param_1 + 0x140) != 0) {
              uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                                (*(int *)(param_1 + 0x140) << 6);
              *(undefined4 *)(param_1 + 0x144) = uVar3;
              if (*(int *)(param_1 + 0x144) == 0) {
                return true;
              }
            }
            local_14 = 0;
            for (local_10 = 0; local_10 < *(int *)(param_1 + 0x140); local_10 = local_10 + 1) {
              while (*(int *)(*(int *)(param_1 + (local_14 + 0x26) * 4) + 0x98) == 0) {
                local_14 = local_14 + 1;
              }
              iVar1 = quicktime_init_video_map
                                (*(int *)(param_1 + 0x144) + local_10 * 0x40,
                                 *(undefined4 *)(param_1 + (local_14 + 0x26) * 4));
              if (iVar1 == 1) {
                return true;
              }
              local_14 = local_14 + 1;
            }
          }
          return local_c == 0;
        }
      }
    }
    if ((local_18 != 0) || (uVar2 = quicktime_position(param_1), *(uint *)(param_1 + 8) <= uVar2))
    goto LAB_0003c5e4;
  } while( true );
}



undefined4 *
quicktime_open_rec(undefined4 param_1,undefined1 param_2,undefined1 param_3,int param_4,int param_5,
                  undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x14))(0x188);
  if (puVar1 != (undefined4 *)0x0) {
    quicktime_init(puVar1);
    *(undefined1 *)((int)puVar1 + 0x175) = param_3;
    puVar1[0x59] = param_4 + 1;
    *(undefined1 *)(puVar1 + 0x58) = param_2;
    puVar1[0x5c] = param_5;
    *puVar1 = param_1;
    puVar1[0x4d] = 1;
    puVar1[0x5a] = 0;
    puVar1[1] = param_6;
    quicktime_write_ftyp(puVar1);
    if (puVar1[0x5a] == 0) {
      puVar1[3] = puVar1[0x52];
      quicktime_write_int32(puVar1,0);
      iVar2 = quicktime_write_char32(puVar1,&DAT_0005b0dc);
      if (iVar2 == -1) {
        puVar1[0x5a] = 1;
      }
      else {
        *(undefined1 *)((int)puVar1 + 0x161) = 1;
      }
    }
    else {
      puVar1[0x5a] = 1;
    }
  }
  return puVar1;
}



undefined4 * quicktime_open(undefined4 param_1,int param_2,char param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(**(code **)(param_2 + 0x14))(0x188);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    quicktime_init(puVar1);
    puVar1[3] = 0;
    puVar1[0x5c] = param_2;
    *puVar1 = param_1;
    if (param_3 == '\x01') {
      *(undefined1 *)(puVar1 + 0x5d) = 1;
    }
    puVar1[0x5b] = 0;
    puVar1[1] = param_4;
    uVar2 = MediaFile_GetTotalLen(puVar1[1]);
    puVar1[2] = uVar2;
    if (puVar1[2] == 0) {
      (*g_medialib_printf)("###File total length is zero\r\n");
      quicktime_close(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
    else {
      iVar3 = quicktime_read_info(puVar1);
      if (iVar3 == 0) {
        if (puVar1[0x5b] != 0) {
          quicktime_close(puVar1);
          puVar1 = (undefined4 *)0x0;
        }
      }
      else {
        quicktime_close(puVar1);
        puVar1 = (undefined4 *)0x0;
      }
    }
  }
  return puVar1;
}



undefined4 quicktime_close(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    quicktime_release_infomem(param_1);
    uVar1 = quicktime_delete(param_1);
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(param_1);
  }
  return uVar1;
}



undefined4 quicktime_close_rec(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x168) == 5) {
      *(undefined4 *)(param_1 + 0x168) = 0;
    }
    if (*(int *)(param_1 + 0x144) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x144) + 8);
      if (*(char *)(param_1 + 0x175) == '\0') {
        quicktime_update_stsc
                  (**(int **)(param_1 + 0x144) + 300,iVar2 + -1,
                   *(undefined4 *)(*(int *)(param_1 + 0x144) + 4));
      }
      else {
        quicktime_update_stsc_opt
                  (**(int **)(param_1 + 0x144) + 300,iVar2 + -1,
                   *(undefined4 *)(*(int *)(param_1 + 0x144) + 4),param_1);
        if (*(int *)(param_1 + 0x13c) != 0) {
          quicktime_update_stsc
                    (**(int **)(param_1 + 0x13c) + 300,
                     *(int *)(*(int *)(param_1 + 0x13c) + 0xc) + -1,
                     *(undefined4 *)(*(int *)(param_1 + 0x13c) + 8));
        }
      }
      quicktime_write_mdat(param_1,param_1 + 0xc);
      quicktime_write_moov(param_1,param_1 + 0x18);
    }
    quicktime_delete_rec(param_1);
    if (*(int *)(param_1 + 0x168) == 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



undefined1 quicktime_get_mp4_audio_decoder_objcetTypeId(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 0x138) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined1 *)
             (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc) + 0x8c);
  }
  return uVar1;
}



undefined1 quicktime_get_mp4_video_decoder_objcetTypeId(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 0x140) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined1 *)
             (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc) + 0x8c);
  }
  return uVar1;
}



undefined4 quicktime_get_mp4_video_decoder_config_size(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x140) == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
    iVar1 = str2ulong(iVar3);
    if (iVar1 == 0x31637668) {
      if ((*(int *)(iVar3 + 200) == 0) || (*(int *)(iVar3 + 0xc4) == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar3 + 0xc4);
      }
    }
    else if (iVar1 == 0x7634706d) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
      if ((*(int *)(iVar1 + 0x9c) == 0) || (*(int *)(iVar1 + 0x98) == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 0x98);
      }
    }
    else if (iVar1 == 0x31637661) {
      if ((*(int *)(iVar3 + 0xc0) == 0) || (*(int *)(iVar3 + 0xbc) == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar3 + 0xbc);
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined4 quicktime_get_mp4_audio_decoder_config_size(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x138) == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc);
    if ((*(int *)(iVar2 + 0x9c) == 0) || (*(int *)(iVar2 + 0x98) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(iVar2 + 0x98);
    }
  }
  return uVar1;
}



undefined4 quicktime_get_mp4_audio_decoder_config2(int param_1,int param_2,void *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == (void *)0x0) || (*(int *)(param_1 + 0x138) == 0)) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc);
    if ((*(int *)(iVar2 + 0x9c) == 0) || (*(int *)(iVar2 + 0x98) == 0)) {
      uVar1 = 0;
    }
    else {
      memcpy(param_3,*(void **)(iVar2 + 0x9c),*(size_t *)(iVar2 + 0x98));
      uVar1 = *(undefined4 *)(iVar2 + 0x98);
    }
  }
  return uVar1;
}



undefined4 quicktime_get_mp4_video_decoder_config2(int param_1,int param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_3 == (void *)0x0) || (*(int *)(param_1 + 0x140) == 0)) {
    uVar2 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
    iVar1 = str2ulong(iVar3);
    if (iVar1 == 0x31637668) {
      if ((*(int *)(iVar3 + 200) == 0) || (*(int *)(iVar3 + 0xc4) == 0)) {
        uVar2 = 0;
      }
      else {
        memcpy(param_3,*(void **)(iVar3 + 200),*(size_t *)(iVar3 + 0xc4));
        uVar2 = *(undefined4 *)(iVar3 + 0xc4);
      }
    }
    else if (iVar1 == 0x7634706d) {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
      if ((*(int *)(iVar1 + 0x9c) == 0) || (*(int *)(iVar1 + 0x98) == 0)) {
        uVar2 = 0;
      }
      else {
        memcpy(param_3,*(void **)(iVar1 + 0x9c),*(size_t *)(iVar1 + 0x98));
        uVar2 = *(undefined4 *)(iVar1 + 0x98);
      }
    }
    else if (iVar1 == 0x31637661) {
      if ((*(int *)(iVar3 + 0xc0) == 0) || (*(int *)(iVar3 + 0xbc) == 0)) {
        uVar2 = 0;
      }
      else {
        memcpy(param_3,*(void **)(iVar3 + 0xc0),*(size_t *)(iVar3 + 0xbc));
        uVar2 = *(undefined4 *)(iVar3 + 0xbc);
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



size_t quicktime_set_mp4_video_decoder_config2(int param_1,int param_2,byte *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  size_t local_24;
  size_t local_20;
  byte *local_1c;
  byte *local_18;
  size_t local_14;
  byte *local_10;
  size_t local_c;
  
  local_c = 0;
  if (((param_3 == (byte *)0x0) || (param_4 == 0)) || (*(int *)(param_1 + 0x140) == 0)) {
    local_c = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
    if (*(int *)(iVar3 + 0x9c) == 0) {
      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xdc);
      uVar1 = str2ulong(iVar4);
      if (uVar1 == 0x31637668) {
        iVar3 = quicktime_set_mp4_hvcC(param_1,param_3,param_4,iVar4);
        if (iVar3 == 1) {
          local_c = *(size_t *)(iVar4 + 0xc4);
        }
      }
      else {
        if (uVar1 < 0x31637669) {
          if (uVar1 == 0x31637661) {
            local_14 = 0;
            local_18 = (byte *)0x0;
            local_1c = (byte *)0x0;
            local_20 = 0;
            local_24 = 0;
            local_10 = param_3;
            do {
              local_10 = local_10 + local_14;
              if (param_3 + param_4 <= local_10) {
                return 0;
              }
              if (*(char *)(param_1 + 0x17c) == '\x03') {
                local_14 = (uint)*local_10 * 0x10000 + (uint)local_10[1] * 0x100 + (uint)local_10[2]
                ;
              }
              else {
                if (*(char *)(param_1 + 0x17c) != '\x04') {
                  return 0;
                }
                local_14 = mov_str2ulong(local_10);
              }
              local_10 = local_10 + *(byte *)(param_1 + 0x17c);
              if ((*local_10 & 0x1f) == 7) {
                local_20 = local_14;
                local_18 = local_10;
              }
              else if ((*local_10 & 0x1f) == 8) {
                local_24 = local_14;
                local_1c = local_10;
              }
            } while ((local_20 == 0) || (local_24 == 0));
            *(undefined1 *)(iVar4 + 0xb4) = 1;
            *(byte *)(iVar4 + 0xb5) = local_18[1];
            *(byte *)(iVar4 + 0xb6) = local_18[2];
            *(byte *)(iVar4 + 0xb7) = local_18[3];
            *(byte *)(iVar4 + 0xb8) = ~((byte)~((*(char *)(param_1 + 0x17c) + -1) * '@') >> 6);
            *(undefined1 *)(iVar4 + 0xb9) = 0xe1;
            *(size_t *)(iVar4 + 0xbc) = local_20 + local_24 + 5;
            uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(*(undefined4 *)(iVar4 + 0xbc));
            *(undefined4 *)(iVar4 + 0xc0) = uVar2;
            if (*(int *)(iVar4 + 0xc0) != 0) {
              **(undefined1 **)(iVar4 + 0xc0) = (char)(local_20 >> 8);
              *(char *)(*(int *)(iVar4 + 0xc0) + 1) = (char)local_20;
              memcpy((void *)(*(int *)(iVar4 + 0xc0) + 2),local_18,local_20);
              *(undefined1 *)(*(int *)(iVar4 + 0xc0) + local_20 + 2) = 1;
              *(char *)(*(int *)(iVar4 + 0xc0) + local_20 + 3) = (char)(local_24 >> 8);
              *(char *)(*(int *)(iVar4 + 0xc0) + local_20 + 4) = (char)local_24;
              memcpy((void *)(*(int *)(iVar4 + 0xc0) + local_20 + 5),local_1c,local_24);
              return local_20 + 5 + local_24;
            }
            return 0;
          }
        }
        else {
          if (uVar1 == 0x33363273) {
            return 0xffffffff;
          }
          if (uVar1 == 0x7634706d) {
            while (((int)local_c < param_4 + -3 &&
                   (iVar4 = mov_str2ulong(param_3 + local_c), iVar4 != 0x1b6))) {
              local_c = local_c + 1;
            }
            if (local_c == 0) {
              return 0xffffffff;
            }
            if (param_4 + -3 <= (int)local_c) {
              return 0;
            }
            uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(local_c + 8);
            *(undefined4 *)(iVar3 + 0x9c) = uVar2;
            if (*(int *)(iVar3 + 0x9c) != 0) {
              memcpy(*(void **)(iVar3 + 0x9c),param_3,local_c);
              *(undefined1 *)(*(int *)(iVar3 + 0x9c) + local_c) = 0;
              *(undefined1 *)(*(int *)(iVar3 + 0x9c) + local_c + 1) = 0;
              *(undefined1 *)(*(int *)(iVar3 + 0x9c) + local_c + 2) = 1;
              *(undefined1 *)(*(int *)(iVar3 + 0x9c) + local_c + 3) = 0xb2;
              memcpy((void *)(*(int *)(iVar3 + 0x9c) + local_c + 4),&DAT_0005b10c,4);
              *(size_t *)(iVar3 + 0x98) = local_c + 8;
              return local_c + 8;
            }
            return 0;
          }
        }
        local_c = 0;
      }
    }
    else {
      local_c = 0xffffffff;
    }
  }
  return local_c;
}



undefined4
quicktime_set_mp4_audio_decoder_config2(int param_1,int param_2,void *param_3,size_t param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x138) == 0) {
    uVar3 = 0;
  }
  else {
    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc);
    if (*(int *)(iVar4 + 0x9c) == 0) {
      if ((param_3 != (void *)0x0) && (param_4 != 0)) {
        uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_4);
        *(undefined4 *)(iVar4 + 0x9c) = uVar3;
        if (*(int *)(iVar4 + 0x9c) == 0) {
          return 0;
        }
        memcpy(*(void **)(iVar4 + 0x9c),param_3,param_4);
        *(size_t *)(iVar4 + 0x98) = param_4;
      }
      iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xdc);
      iVar2 = str2ulong(iVar5);
      if (iVar2 == 0x6134706d) {
        bVar1 = get_aacFreqIndex(*(undefined4 *)(iVar5 + 0x80));
        uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(2);
        *(undefined4 *)(iVar4 + 0x9c) = uVar3;
        if (*(int *)(iVar4 + 0x9c) == 0) {
          uVar3 = 0;
        }
        else {
          **(byte **)(iVar4 + 0x9c) = bVar1 >> 1 | 0x10;
          *(byte *)(*(int *)(iVar4 + 0x9c) + 1) =
               bVar1 << 7 | (byte)((*(uint *)(iVar5 + 0x70) & 0x1f) << 3);
          *(undefined4 *)(iVar4 + 0x98) = 2;
          uVar3 = 2;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}



size_t quicktime_read_video_frame(int param_1,undefined4 param_2,void *param_3,int param_4)

{
  uint local_10;
  size_t local_c;
  
  local_c = 0;
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x140)) {
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4) = param_2;
    local_c = quicktime_frame_size
                        (param_1,*(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4),
                         param_4);
    if (local_c == 0) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 0x24) == 0) {
      quicktime_set_video_position
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4),param_4);
      local_10 = quicktime_read_data(param_1,param_3,local_c);
    }
    else {
      local_10 = (uint)(*(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 0x24) <=
                       *(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4));
      if (local_10 == 0) {
        memcpy(param_3,*(void **)(*(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 0x20) +
                                 *(int *)(*(int *)(param_1 + 0x144) + param_4 * 0x40 + 4) * 4),
               local_c);
      }
    }
  }
  if (local_10 == 0) {
    local_c = 0;
  }
  return local_c;
}



undefined4 quicktime_get_video_total_keyframes(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 < *(int *)(param_1 + 0x140)) &&
     (*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) != 0)) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x114);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_is_keyframe(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = 0;
  if ((0 < *(int *)(param_1 + 0x140)) && (*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) != 0)
     ) {
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) + 0x114) == 0) {
      return 0;
    }
    local_10 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) + 0x114) + -1;
    if (local_10 < 0) {
      return 0;
    }
    while (local_c <= local_10) {
      iVar1 = (local_c + local_10) / 2;
      if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) + 0x11c) +
                  iVar1 * 4) == param_2 + 1) {
        return 1;
      }
      if (param_2 + 1 <
          *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) + 0x11c) +
                  iVar1 * 4)) {
        local_10 = iVar1 + -1;
      }
      else {
        local_c = iVar1 + 1;
      }
    }
  }
  return 0;
}



undefined4 quicktime_seek_audio(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x138) < 1) || (*(int *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14) == 0)
     ) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + param_3 * 0x14 + 8) = param_2;
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 quicktime_seek_video(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x140) < 1) || (*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40) == 0)
     ) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 4) = param_2;
    uVar1 = 1;
  }
  return uVar1;
}



int quicktime_get_video_total_frames(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  if ((param_2 < *(int *)(param_1 + 0x140)) &&
     (*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) != 0)) {
    for (local_c = 0;
        local_c < *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xe8);
        local_c = local_c + 1) {
      local_10 = local_10 +
                 *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xf0) +
                         local_c * 8);
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



int quicktime_get_audio_total_samples(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  if ((param_2 < *(int *)(param_1 + 0x138)) &&
     (*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) != 0)) {
    for (local_c = 0;
        local_c < *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xe8);
        local_c = local_c + 1) {
      local_10 = local_10 +
                 *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xf0) +
                         local_c * 8);
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



int quicktime_get_total_time(int param_1)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  undefined4 local_14;
  
  local_14 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    uVar2 = *(uint *)(param_1 + 0x3c);
    bVar3 = 0x20c49a < uVar2;
    if (uVar2 == 0x20c49b) {
      bVar3 = 0xa5e353f6 < *(uint *)(param_1 + 0x38);
    }
    if (!bVar3 || uVar2 == 0x20c49b && *(uint *)(param_1 + 0x38) == 0xa5e353f7) {
      lVar1 = (ulonglong)*(uint *)(param_1 + 0x38) * 1000;
      local_14 = __aeabi_ldivmod((int)lVar1,
                                 *(int *)(param_1 + 0x3c) * 1000 + (int)((ulonglong)lVar1 >> 0x20),
                                 *(int *)(param_1 + 0x30),*(int *)(param_1 + 0x30) >> 0x1f);
    }
    else {
      local_14 = __aeabi_ldivmod(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
                                 *(int *)(param_1 + 0x30),*(int *)(param_1 + 0x30) >> 0x1f);
      local_14 = local_14 * 1000;
    }
  }
  return local_14;
}



int quicktime_get_audio_total_bytes(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  if ((param_2 < *(int *)(param_1 + 0x138)) &&
     (*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) != 0)) {
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x15c) == 0) {
      for (local_10 = 0;
          local_10 < *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x160);
          local_10 = local_10 + 1) {
        local_c = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x168) +
                          local_10 * 4) + local_c;
      }
    }
    else {
      local_c = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x15c) *
                *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x160);
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}



int quicktime_get_proper_audiotrack(int param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_14 = 0;
  if (*(int *)(param_1 + 0x138) < 2) {
    local_14 = 0;
  }
  else {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x138); local_c = local_c + 1) {
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + local_c * 0x14) + 0x15c) == 0) {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + local_c * 0x14) + 0x160);
      }
      else {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + local_c * 0x14) + 0x188);
      }
      if (local_10 < iVar1) {
        local_14 = local_c;
        local_10 = iVar1;
      }
    }
  }
  return local_14;
}



int quicktime_get_proper_videotrack(int param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_14 = 0;
  if (*(int *)(param_1 + 0x140) < 2) {
    local_14 = 0;
  }
  else {
    for (local_c = 0; local_c < *(int *)(param_1 + 0x140); local_c = local_c + 1) {
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + local_c * 0x40) + 0x15c) == 0) {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + local_c * 0x40) + 0x160);
      }
      else {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + local_c * 0x40) + 0x188);
      }
      if (local_10 < iVar1) {
        local_14 = local_c;
        local_10 = iVar1;
      }
    }
  }
  return local_14;
}



int quicktime_get_video_bitrate(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  local_10 = 0;
  if (param_2 < *(int *)(param_1 + 0x140)) {
    for (local_c = 0;
        local_c < *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x160);
        local_c = local_c + 1) {
      local_10 = local_10 +
                 *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x168) +
                         local_c * 4);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40);
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x80);
    iVar1 = __aeabi_ldivmod(*(undefined4 *)(iVar1 + 0x88),*(undefined4 *)(iVar1 + 0x8c),iVar2,
                            iVar2 >> 0x1f);
    if (iVar1 != 0) {
      iVar1 = __aeabi_uidiv(local_10,iVar1);
      return iVar1 << 3;
    }
  }
  return 0;
}



int quicktime_get_audio_bitrate(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 < *(int *)(param_1 + 0x138)) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14),
     iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x80),
     iVar2 = __aeabi_ldivmod(*(undefined4 *)(iVar2 + 0x88),*(undefined4 *)(iVar2 + 0x8c),iVar3,
                             iVar3 >> 0x1f), iVar2 != 0)) {
    uVar1 = quicktime_get_audio_total_bytes(param_1,param_2);
    iVar2 = __divsi3(uVar1,iVar2);
    return iVar2 << 3;
  }
  return 0;
}



undefined4 quicktime_cal_video_pts(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  iVar5 = *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40);
  iVar6 = *(int *)(iVar5 + 0x400);
  *(int *)(iVar5 + 0x400) = param_2;
  iVar7 = *(int *)(iVar5 + 0x80);
  if (param_2 == 0) {
    iVar6 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0x10) =
         **(undefined4 **)(iVar5 + 0xf0);
  }
  else if (iVar6 + 1 == param_2) {
    if (*(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0x10) < param_2) {
      iVar6 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
      *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0x10) =
           *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0x10) +
           *(int *)(*(int *)(iVar5 + 0xf0) +
                   *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0xc) * 8);
    }
    uVar8 = *(uint *)(*(int *)(iVar5 + 0xf0) +
                      *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0xc) * 8 + 4);
    iVar6 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
    iVar5 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
    uVar2 = *(uint *)(iVar5 + 0x18);
    iVar5 = *(int *)(iVar5 + 0x1c);
    *(uint *)(iVar6 + 0x18) = uVar8 + uVar2;
    *(uint *)(iVar6 + 0x1c) = ((int)uVar8 >> 0x1f) + iVar5 + (uint)CARRY4(uVar8,uVar2);
  }
  else if (param_2 != iVar6) {
    iVar6 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    iVar6 = *(int *)(iVar5 + 0xe8);
    for (local_1c = 0; local_1c < iVar6; local_1c = local_1c + 1) {
      uVar2 = *(uint *)(*(int *)(iVar5 + 0xf0) + local_1c * 8 + 4);
      uVar8 = *(uint *)(*(int *)(iVar5 + 0xf0) + local_1c * 8);
      *(int *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0xc) = local_1c;
      if (param_2 < (int)(local_20 + uVar8)) {
        iVar6 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
        iVar5 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
        uVar11 = *(uint *)(iVar5 + 0x18);
        iVar5 = *(int *)(iVar5 + 0x1c);
        uVar9 = param_2 - local_20;
        uVar4 = (uint)((ulonglong)uVar9 * (ulonglong)uVar2);
        *(uint *)(iVar6 + 0x18) = uVar4 + uVar11;
        *(uint *)(iVar6 + 0x1c) =
             ((int)uVar9 >> 0x1f) * uVar2 + uVar9 * ((int)uVar2 >> 0x1f) +
             (int)((ulonglong)uVar9 * (ulonglong)uVar2 >> 0x20) + iVar5 + (uint)CARRY4(uVar4,uVar11)
        ;
        *(uint *)(*(int *)(param_1 + 0x144) + param_3 * 0x40 + 0x10) = local_20 + uVar8;
        break;
      }
      iVar12 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
      iVar10 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
      uVar9 = *(uint *)(iVar10 + 0x18);
      iVar10 = *(int *)(iVar10 + 0x1c);
      uVar4 = (uint)((ulonglong)uVar8 * (ulonglong)uVar2);
      *(uint *)(iVar12 + 0x18) = uVar4 + uVar9;
      *(uint *)(iVar12 + 0x1c) =
           ((int)uVar8 >> 0x1f) * uVar2 + uVar8 * ((int)uVar2 >> 0x1f) +
           (int)((ulonglong)uVar8 * (ulonglong)uVar2 >> 0x20) + iVar10 + (uint)CARRY4(uVar4,uVar9);
      local_20 = local_20 + uVar8;
    }
  }
  iVar5 = *(int *)(param_1 + 0x144) + param_3 * 0x40;
  lVar1 = (ulonglong)*(uint *)(iVar5 + 0x18) * 1000;
  uVar3 = __aeabi_ldivmod((int)lVar1,*(int *)(iVar5 + 0x1c) * 1000 + (int)((ulonglong)lVar1 >> 0x20)
                          ,iVar7,iVar7 >> 0x1f);
  return uVar3;
}



int quicktime_moov_size(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x144) + 4);
  iVar2 = *(int *)(*(int *)(param_1 + 0x144) + 8);
  if (*(char *)(param_1 + 0x175) == '\0') {
    iVar3 = __divsi3(iVar1,*(undefined4 *)(param_1 + 0x164));
    iVar1 = iVar3 + iVar2 * 2 + iVar1;
  }
  else {
    if (*(int *)(param_1 + 0x13c) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x13c) + 8);
    }
    if (*(int *)(param_1 + 0x13c) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0x13c) + 0xc);
    }
    iVar1 = (iVar2 + iVar4) * 2 + *(int *)(**(int **)(param_1 + 0x144) + 0x114) + iVar1 + iVar3;
  }
  local_c = (iVar1 + 0x96) * 4;
  return local_c;
}



int quicktime_file_write_status(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x168);
  if ((iVar1 != 0) && (iVar1 != 5)) {
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(param_1);
  }
  return iVar1;
}



undefined4 quicktime_is_anka_3gp(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x140) < 1) {
    uVar3 = 0;
  }
  else {
    iVar2 = *(int *)(**(int **)(param_1 + 0x144) + 0xdc);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      iVar1 = memcmp((void *)(iVar2 + 0xa0),&DAT_0005b10c,4);
      if ((iVar1 == 0) ||
         ((*(int *)(iVar2 + 0x9c) != 0 &&
          (iVar2 = memcmp((void *)(*(int *)(iVar2 + 0x9c) + *(int *)(iVar2 + 0x98) + -4),
                          &DAT_0005b10c,4), iVar2 == 0)))) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



undefined4 quicktime_check_video_valid(int param_1,int param_2)

{
  undefined4 uVar1;
  uint local_c;
  
  if (*(int *)(param_1 + 0x140) < 1) {
    uVar1 = 1;
  }
  else if (param_2 < *(int *)(param_1 + 0x140)) {
    if (*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) == 0) {
      (*g_medialib_printf)("##Check video: ERROR--track pointer is null##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x188) == 0) {
      (*g_medialib_printf)("##Check video: ERROR--no stco##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x134) == 0) {
      (*g_medialib_printf)("##Check video: ERROR--no stsc##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xd8) == 0) {
      (*g_medialib_printf)("##Check video: ERROR--no stsd##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xe8) == 0) {
      (*g_medialib_printf)("##Check video: ERROR--no stts##\r\n");
      uVar1 = 0;
    }
    else {
      local_c = (uint)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xf0
                                        ) + 4) == 0);
      if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0xf0) +
                   local_c * 8 + 4) == 0) {
        (*g_medialib_printf)("##Check video: ERROR--sample duration is zero##\r\n");
        uVar1 = 0;
      }
      else if (*(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x80) == 0) {
        (*g_medialib_printf)("##Check video: ERROR--time scale is zero##\r\n");
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else {
    (*g_medialib_printf)("##Check video: ERROR--track number is out of range##\r\n");
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_check_audio_valid(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x138) < 1) {
    uVar1 = 1;
  }
  else if (param_2 < *(int *)(param_1 + 0x138)) {
    if (*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) == 0) {
      (*g_medialib_printf)("##Check audio: ERROR--track pointer is null##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x188) == 0) {
      (*g_medialib_printf)("##Check audio: ERROR--no stco##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x134) == 0) {
      (*g_medialib_printf)("##Check audio: ERROR--no stsc##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0xd8) == 0) {
      (*g_medialib_printf)("##Check audio: ERROR--no stsd##\r\n");
      uVar1 = 0;
    }
    else if (*(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x80) == 0) {
      (*g_medialib_printf)("##Check audio: ERROR--time scale is zero##\r\n");
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##Check audio: ERROR--track number is out of range##\r\n");
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_audio_totaltime(int param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 < *(int *)(param_1 + 0x138)) {
    if (*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14);
      lVar1 = (ulonglong)*(uint *)(iVar3 + 0x88) * 1000;
      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x13c) + param_2 * 0x14) + 0x80);
      uVar2 = __aeabi_ldivmod((int)lVar1,
                              *(int *)(iVar3 + 0x8c) * 1000 + (int)((ulonglong)lVar1 >> 0x20),iVar4,
                              iVar4 >> 0x1f);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 quicktime_video_totaltime(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 < *(int *)(param_1 + 0x140)) {
    if (*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) == 0) {
      uVar3 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40);
      lVar1 = (ulonglong)*(uint *)(iVar4 + 0x88) * 1000;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x144) + param_2 * 0x40) + 0x80);
      uVar3 = __aeabi_ldivmod((int)lVar1,
                              *(int *)(iVar4 + 0x8c) * 1000 + (int)((ulonglong)lVar1 >> 0x20),iVar2,
                              iVar2 >> 0x1f);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



undefined4 quicktime_release_infomem(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x180) != 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x28));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x24));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x30));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x34));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x20));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x38));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x1c));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))
                (*(undefined4 *)(*(int *)(param_1 + 0x180) + 0x2c));
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x180));
      *(undefined4 *)(param_1 + 0x180) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 quicktime_get_file_position_audio(int param_1,undefined4 param_2,undefined4 param_3)

{
  quicktime_set_audio_position(param_1,param_2,param_3);
  return *(undefined4 *)(param_1 + 0x148);
}



undefined4 quicktime_get_file_position_video(int param_1,undefined4 param_2,undefined4 param_3)

{
  quicktime_set_video_position(param_1,param_2,param_3);
  return *(undefined4 *)(param_1 + 0x148);
}



undefined4 quicktime_smhd_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return 0;
}



undefined4 quicktime_smhd_delete(void)

{
  return 0;
}



undefined4 quicktime_write_smhd(int param_1,uint *param_2)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005b374);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_int16(param_1,param_2[2]);
    quicktime_write_int16(param_1,param_2[3]);
  }
  else {
    quicktime_write_int32(param_1,0);
  }
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_stbl_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  quicktime_stsd_init(param_1 + 2);
  quicktime_stts_init(param_1 + 6);
  quicktime_stss_init(param_1 + 0x11);
  quicktime_stsc_init(param_1 + 0x19);
  quicktime_stsz_init(param_1 + 0x23);
  quicktime_stco_init(param_1 + 0x2e);
  return 0;
}



undefined4
quicktime_stbl_init_video
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  quicktime_stsd_init_video(param_1,param_2 + 8,param_3,param_4,param_6,param_7);
  quicktime_stts_init_video(param_1,param_2 + 0x18,param_5,param_6);
  quicktime_stsc_init_video(param_1,param_2 + 100);
  quicktime_stsz_init_video_opt(param_1,param_2 + 0x8c);
  return 0;
}



undefined4
quicktime_stbl_init_audio
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  quicktime_stsd_init_audio(param_1,param_2 + 8,param_3,param_4,param_5,param_9);
  quicktime_stts_init_audio(param_1,param_2 + 0x18,param_7,param_8);
  quicktime_stsc_init_audio(param_1,param_2 + 100);
  quicktime_stsz_init_audio(param_1,param_2 + 0x8c,param_6);
  return 0;
}



undefined4 quicktime_stbl_delete(int param_1,undefined4 param_2)

{
  quicktime_stsd_delete(param_1 + 8,param_2);
  quicktime_stts_delete(param_1 + 0x18,param_2);
  quicktime_stss_delete(param_1 + 0x44,param_2);
  quicktime_stsc_delete(param_1 + 100,param_2);
  quicktime_stsz_delete(param_1 + 0x8c,param_2);
  quicktime_stco_delete(param_1 + 0xb8,param_2);
  return 0;
}



undefined4 quicktime_stbl_delete_rec(int param_1,undefined4 param_2)

{
  quicktime_stsd_delete(param_1 + 8,param_2);
  quicktime_stts_delete(param_1 + 0x18,param_2);
  quicktime_stss_delete(param_1 + 0x44,param_2);
  quicktime_stsc_delete(param_1 + 100,param_2);
  quicktime_stsz_delete_opt(param_1 + 0x8c,param_2);
  quicktime_stco_delete_opt(param_1 + 0xb8,param_2);
  return 0;
}



undefined4 quicktime_read_stbl(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_18);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b37c);
    if (iVar1 == 0) {
      iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b384);
      if (iVar1 == 0) {
        iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b38c);
        if (iVar1 == 0) {
          iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b394);
          if (iVar1 == 0) {
            iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b39c);
            if (iVar1 == 0) {
              iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b3a4);
              if (iVar1 == 0) {
                iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b3ac);
                if (iVar1 == 0) {
                  quicktime_atom_skip(param_1,auStack_18);
                }
                else {
                  iVar1 = quicktime_read_co64(param_1,param_3 + 0xb8);
                  if (iVar1 == 1) {
                    return 1;
                  }
                }
              }
              else {
                iVar1 = quicktime_read_stco(param_1,param_3 + 0xb8);
                if (iVar1 == 1) {
                  return 1;
                }
              }
            }
            else {
              iVar1 = quicktime_read_stsz(param_1,param_3 + 0x8c);
              if (iVar1 == 1) {
                return 1;
              }
            }
          }
          else {
            iVar1 = quicktime_read_stsc(param_1,param_3 + 100);
            if (iVar1 == 1) {
              return 1;
            }
          }
        }
        else {
          iVar1 = quicktime_read_stss(param_1,param_3 + 0x44);
          if (iVar1 == 1) {
            return 1;
          }
        }
      }
      else {
        iVar1 = quicktime_read_stts(param_1,param_3 + 0x18);
        if (iVar1 == 1) {
          return 1;
        }
      }
    }
    else {
      iVar1 = quicktime_read_stsd(param_1,param_2,param_3 + 8);
      if (iVar1 == 1) {
        return 1;
      }
      quicktime_atom_skip(param_1,auStack_18);
    }
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_4 + 4));
  return 0;
}



undefined4 quicktime_write_stbl(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005b3b4);
  if (*(int *)(param_1 + 0x168) == 0) {
    quicktime_write_stsd(param_1,param_2,param_3 + 8);
    if (*(int *)(param_1 + 0x168) == 0) {
      if (*(char *)(param_1 + 0x175) == '\0') {
        quicktime_write_stts(param_1,param_3 + 0x18);
      }
      else {
        quicktime_write_stts_opt(param_1,param_3 + 0x18);
      }
      if (*(int *)(param_1 + 0x168) == 0) {
        quicktime_write_stss(param_1,param_3 + 0x44);
        if (*(int *)(param_1 + 0x168) == 0) {
          if (*(char *)(param_1 + 0x175) == '\0') {
            quicktime_write_stsc(param_1,param_3 + 100);
          }
          else {
            quicktime_write_stsc_opt(param_1,param_3 + 100);
          }
          if (*(int *)(param_1 + 0x168) == 0) {
            quicktime_write_stsz_opt_vide(param_1,param_3 + 0x8c);
            if (*(int *)(param_1 + 0x168) == 0) {
              quicktime_write_stco_opt_vide(param_1,param_3 + 0xb8);
              if (*(int *)(param_1 + 0x168) == 0) {
                quicktime_atom_write_footer(param_1,auStack_18);
                uVar1 = 0;
              }
              else {
                uVar1 = 1;
              }
            }
            else {
              uVar1 = 1;
            }
          }
          else {
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 quicktime_write_stbl_soun(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,&DAT_0005b3b4);
  if (*(int *)(param_1 + 0x168) == 0) {
    quicktime_write_stsd(param_1,param_2,param_3 + 8);
    quicktime_write_stts(param_1,param_3 + 0x18);
    if (*(int *)(param_1 + 0x168) == 0) {
      quicktime_write_stsc(param_1,param_3 + 100);
      if (*(int *)(param_1 + 0x168) == 0) {
        quicktime_write_stsz_opt(param_1,param_3 + 0x8c);
        quicktime_write_stco_opt(param_1,param_3 + 0xb8);
        if (*(int *)(param_1 + 0x168) == 0) {
          quicktime_atom_write_footer(param_1,auStack_18);
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 quicktime_stco_init(int param_1)

{
  ZeroMemory(param_1,0x20);
  *(undefined4 *)(param_1 + 0x1c) = 2;
  return 0;
}



undefined4 quicktime_stco_delete(int param_1,int param_2)

{
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}



undefined4 quicktime_read_stco(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_42c [1024];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  local_20 = 0x100;
  uVar1 = quicktime_read_char(param_1);
  *param_2 = uVar1;
  uVar1 = quicktime_read_int24(param_1);
  param_2[1] = uVar1;
  uVar1 = quicktime_read_int32(param_1);
  param_2[2] = uVar1;
  param_2[3] = param_2[2];
  if ((int)param_2[3] < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[3] << 2);
    param_2[4] = uVar1;
    if (param_2[4] == 0) {
      *(undefined4 *)(param_1 + 0x16c) = 2;
      uVar1 = 1;
    }
    else {
      iVar3 = param_2[3] * 4;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0x3ff;
      }
      local_24 = (iVar3 >> 10) + 1;
      local_28 = (param_2[3] * 4) % 0x400;
      local_2c = local_28;
      if (local_28 < 0) {
        local_2c = local_28 + 3;
      }
      local_2c = local_2c >> 2;
      for (local_14 = 0; local_14 < local_24 + -1; local_14 = local_14 + 1) {
        quicktime_read_data(param_1,auStack_42c,0x400);
        for (local_18 = 0; local_18 < local_20; local_18 = local_18 + 1) {
          iVar2 = param_2[4];
          iVar3 = local_1c * 4;
          uVar1 = mov_str2ulong(auStack_42c + local_18 * 4);
          *(undefined4 *)(iVar2 + iVar3) = uVar1;
          local_1c = local_1c + 1;
        }
      }
      quicktime_read_data(param_1,auStack_42c,local_28);
      for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
        iVar2 = param_2[4];
        iVar3 = local_1c * 4;
        uVar1 = mov_str2ulong(auStack_42c + local_18 * 4);
        *(undefined4 *)(iVar2 + iVar3) = uVar1;
        local_1c = local_1c + 1;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



undefined4 quicktime_read_co64(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_434 [4];
  undefined1 auStack_430 [1020];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  local_20 = 0;
  local_24 = 0x80;
  local_28 = 0;
  uVar1 = quicktime_read_char(param_1);
  *param_2 = uVar1;
  uVar1 = quicktime_read_int24(param_1);
  param_2[1] = uVar1;
  uVar1 = quicktime_read_int32(param_1);
  param_2[2] = uVar1;
  param_2[3] = param_2[2];
  uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[3] << 2);
  param_2[4] = uVar1;
  if (param_2[4] == 0) {
    *(undefined4 *)(param_1 + 0x16c) = 2;
    uVar1 = 1;
  }
  else {
    iVar3 = param_2[3] * 8;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x3ff;
    }
    local_2c = (iVar3 >> 10) + 1;
    local_30 = (param_2[3] * 8) % 0x400;
    local_34 = local_30;
    if (local_30 < 0) {
      local_34 = local_30 + 7;
    }
    local_34 = local_34 >> 3;
    for (local_14 = 0; local_14 < local_2c + -1; local_14 = local_14 + 1) {
      local_1c = 0;
      quicktime_read_data(param_1,auStack_434,0x400);
      for (local_18 = 0; local_18 < local_24; local_18 = local_18 + 1) {
        local_28 = mov_str2ulong(auStack_434 + local_1c);
        if (local_28 != 0) {
          *(undefined4 *)(param_1 + 0x16c) = 2;
          return 1;
        }
        iVar2 = param_2[4];
        iVar3 = local_20 * 4;
        uVar1 = mov_str2ulong(auStack_430 + local_1c);
        *(undefined4 *)(iVar2 + iVar3) = uVar1;
        local_20 = local_20 + 1;
        local_1c = local_1c + 8;
      }
    }
    local_1c = 0;
    quicktime_read_data(param_1,auStack_434,local_30);
    for (local_18 = 0; local_18 < local_34; local_18 = local_18 + 1) {
      local_28 = mov_str2ulong(auStack_434 + local_1c);
      if (local_28 != 0) {
        *(undefined4 *)(param_1 + 0x16c) = 2;
        return 1;
      }
      iVar2 = param_2[4];
      iVar3 = local_20 * 4;
      uVar1 = mov_str2ulong(auStack_430 + local_1c);
      *(undefined4 *)(iVar2 + iVar3) = uVar1;
      local_20 = local_20 + 1;
      local_1c = local_1c + 8;
    }
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_update_stco_opt(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  local_c = param_3;
  iVar1 = MEML_StoreElement(param_1 + 0x14,&local_c,param_4);
  if (iVar1 == 1) {
    uVar2 = 1;
  }
  else {
    if (*(int *)(param_1 + 8) < param_2) {
      *(int *)(param_1 + 8) = param_2;
    }
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 quicktime_write_stco_opt(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b3bc);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  param_2[6] = param_2[5];
  local_c = 0;
  while( true ) {
    if ((int)param_2[2] <= local_c) {
      quicktime_atom_write_footer(param_1,auStack_1c);
      return 0;
    }
    MEML_GetElement(param_2 + 5,&local_20);
    iVar1 = quicktime_write_int32(param_1,local_20);
    if (iVar1 == -1) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(param_1 + 0x168) = 3;
  return 1;
}



undefined4 quicktime_write_stco_opt_vide(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int local_3c;
  undefined1 auStack_38 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_18 = 0;
  iVar2 = *(int *)(param_1 + 0x144);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
  local_1c = *(int *)(iVar2 + 8);
  local_20 = 0;
  local_24 = 0;
  quicktime_atom_write_header(param_1,auStack_38,&DAT_0005b3bc);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,local_1c);
  if ((*(char *)(param_1 + 0x175) == '\0') && (*(int *)(param_1 + 0x138) != 0)) {
    iVar2 = **(int **)(param_1 + 0x13c);
    local_20 = *(int *)(iVar2 + 0x188);
    if (1 < local_1c - local_20) {
      (*g_medialib_printf)
                ("#chunk offset of video and sound error#\r\n#total_entries_vide: %d\r\ntotal_entries_soun: %d#\r\n"
                 ,local_1c,local_20);
      *(undefined4 *)(param_1 + 0x168) = 3;
      return 1;
    }
    *(undefined4 *)(iVar2 + 0x198) = *(undefined4 *)(iVar2 + 0x194);
    local_28 = *(int *)(param_1 + 0x178) * *(int *)(**(int **)(param_1 + 0x13c) + 0x15c);
    quicktime_write_int32(param_1,*(int *)(param_1 + 0xc) + 8);
    local_24 = local_1c;
    if (local_20 <= local_1c) {
      local_24 = local_20;
    }
    for (local_14 = 1; local_14 < local_24; local_14 = local_14 + 1) {
      MEML_GetElement(iVar2 + 0x194,&local_3c);
      local_18 = local_3c + local_28;
      iVar1 = quicktime_write_int32(param_1,local_18);
      if (iVar1 == -1) {
        *(undefined4 *)(param_1 + 0x168) = 3;
        return 1;
      }
    }
    if ((local_20 < local_1c) && (local_1c != 1)) {
      MEML_GetElement(iVar2 + 0x194,&local_3c);
      local_18 = local_3c + local_28;
      quicktime_write_int32(param_1,local_18);
    }
  }
  else {
    param_2[6] = param_2[5];
    for (local_14 = 0; local_14 < local_1c; local_14 = local_14 + 1) {
      MEML_GetElement(param_2 + 5,&local_3c);
      iVar2 = quicktime_write_int32(param_1,local_3c);
      if (iVar2 == -1) {
        *(undefined4 *)(param_1 + 0x168) = 3;
        return 1;
      }
    }
  }
  quicktime_atom_write_footer(param_1,auStack_38);
  return 0;
}



undefined4 quicktime_stco_delete_opt(int param_1,undefined4 param_2)

{
  MEML_Destroy(param_1 + 0x14,param_2);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}



undefined4 quicktime_stsc_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x28);
  return 0;
}



undefined4 quicktime_stsc_init_table(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 5;
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(*(int *)(param_2 + 0xc) * 0xc);
    *(undefined4 *)(param_2 + 0x10) = uVar1;
    if (*(int *)(param_2 + 0x10) == 0) {
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
  }
  return 0;
}



undefined4 quicktime_stsc_init_video(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x175) == '\0') {
    iVar1 = quicktime_stsc_init_table(param_1,param_2);
    if (iVar1 == 1) {
      return 1;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x24) = 3;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  return 0;
}



undefined4 quicktime_stsc_init_audio(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = quicktime_stsc_init_table(param_1,param_2);
  if (iVar1 == 1) {
    uVar2 = 1;
  }
  else {
    if (*(char *)(param_1 + 0x175) == '\0') {
      puVar3 = *(undefined4 **)(param_2 + 0x10);
      *puVar3 = 1;
      puVar3[1] = *(undefined4 *)(param_1 + 0x178);
      puVar3[2] = 1;
      *(undefined4 *)(param_2 + 8) = 1;
    }
    else {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 quicktime_stsc_delete(int param_1,int param_2)

{
  (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 8) = 0;
  MEML_Destroy(param_1 + 0x1c,param_2);
  return 0;
}



undefined4 quicktime_read_stsc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_324 [4];
  undefined1 auStack_320 [4];
  undefined1 auStack_31c [760];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_24 = 0x300;
  local_1c = 0;
  uVar2 = quicktime_read_char(param_1);
  *param_2 = uVar2;
  uVar2 = quicktime_read_int24(param_1);
  param_2[1] = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  param_2[2] = uVar2;
  param_2[3] = param_2[2];
  if (param_2[2] == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[2] * 0xc);
    param_2[4] = uVar2;
    if (param_2[4] == 0) {
      *(undefined4 *)(param_1 + 0x16c) = 2;
      uVar2 = 1;
    }
    else {
      local_14 = 0;
      local_1c = param_2[2] * 0xc;
      while (local_14 < (int)param_2[2]) {
        local_20 = local_24;
        if (local_1c <= local_24) {
          local_20 = local_1c;
        }
        local_20 = quicktime_read_data(param_1,auStack_324,local_20);
        if (local_20 == 0) break;
        local_1c = local_1c - local_20;
        for (local_18 = 0; local_18 < local_20 + -0xb; local_18 = local_18 + 0xc) {
          iVar3 = param_2[4];
          iVar1 = local_14 * 0xc;
          uVar2 = mov_str2ulong(auStack_324 + local_18);
          *(undefined4 *)(iVar3 + iVar1) = uVar2;
          iVar3 = param_2[4];
          iVar1 = local_14 * 0xc;
          uVar2 = mov_str2ulong(auStack_320 + local_18);
          *(undefined4 *)(iVar3 + iVar1 + 4) = uVar2;
          iVar3 = param_2[4];
          iVar1 = local_14 * 0xc;
          uVar2 = mov_str2ulong(auStack_31c + local_18);
          *(undefined4 *)(iVar3 + iVar1 + 8) = uVar2;
          local_14 = local_14 + 1;
        }
      }
      if (*(int *)(param_1 + 0x16c) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



undefined4 quicktime_write_stsc(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b420);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  local_c = 0;
  while( true ) {
    if ((int)param_2[2] <= local_c) {
      quicktime_atom_write_footer(param_1,auStack_1c);
      return 0;
    }
    quicktime_write_int32(param_1,*(undefined4 *)(param_2[4] + local_c * 0xc));
    quicktime_write_int32(param_1,*(undefined4 *)(param_2[4] + local_c * 0xc + 4));
    iVar1 = quicktime_write_int32(param_1,*(undefined4 *)(param_2[4] + local_c * 0xc + 8));
    if (iVar1 == -1) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(param_1 + 0x168) = 3;
  return 1;
}



undefined4 quicktime_update_stsc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_3 - *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x18) = param_3;
  if (*(int *)(param_1 + 0x14) != iVar1) {
    if (*(int *)(param_1 + 0xc) == param_2) {
      (*g_medialib_printf)("#ERROR: stsc overflow#\r\n");
      return 1;
    }
    *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 0xc + 4) = iVar1;
    *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 0xc) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2 * 0xc + 8) = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return 0;
}



undefined4 quicktime_write_stsc_opt(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b420);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  param_2[8] = param_2[7];
  local_20 = 1;
  local_c = 0;
  while( true ) {
    if ((int)param_2[2] <= local_c) {
      quicktime_atom_write_footer(param_1,auStack_1c);
      return 0;
    }
    MEML_GetElement(param_2 + 7,&local_28);
    quicktime_write_int32(param_1,local_28);
    quicktime_write_int32(param_1,local_24);
    iVar1 = quicktime_write_int32(param_1,local_20);
    if (iVar1 == -1) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(param_1 + 0x168) = 3;
  return 1;
}



undefined4 quicktime_update_stsc_opt(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_18;
  int local_14;
  int local_c;
  
  local_14 = param_3 - *(int *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = param_3;
  if (*(int *)(param_1 + 0x14) != local_14) {
    local_18 = param_2;
    local_c = local_14;
    iVar1 = MEML_StoreElement(param_1 + 0x1c,&local_18,param_4);
    if (iVar1 == 1) {
      return 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(param_1 + 0x14) = local_c;
  }
  return 0;
}



undefined4 quicktime_stsd_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x10);
  return 0;
}



undefined4 quicktime_stsd_init_table(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = 1;
    uVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(*(int *)(param_1 + 8) * 0xcc);
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    if (*(int *)(param_1 + 0xc) == 0) {
      return 1;
    }
    quicktime_stsd_table_init(*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}



bool quicktime_stsd_init_video
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_stsd_init_table(param_2,param_1);
  if (iVar1 != 1) {
    iVar2 = *(int *)(param_2 + 0xc);
    quicktime_copy_char32(iVar2,param_6);
    *(undefined4 *)(iVar2 + 0x24) = param_3;
    *(undefined4 *)(iVar2 + 0x28) = param_4;
    *(undefined4 *)(iVar2 + 0x38) = 1;
    *(undefined4 *)(iVar2 + 0x5c) = 0x18;
    *(undefined4 *)(iVar2 + 0x60) = 0xffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x168) = 4;
  }
  return iVar1 == 1;
}



bool quicktime_stsd_init_audio
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_stsd_init_table(param_2,param_1);
  if (iVar1 != 1) {
    iVar2 = *(int *)(param_2 + 0xc);
    quicktime_copy_char32(iVar2,param_6);
    *(undefined4 *)(iVar2 + 0x70) = param_3;
    *(undefined4 *)(iVar2 + 0x74) = param_5;
    *(undefined4 *)(iVar2 + 0x80) = param_4;
  }
  else {
    *(undefined4 *)(param_1 + 0x168) = 4;
  }
  return iVar1 == 1;
}



undefined4 quicktime_stsd_delete(int param_1,int param_2)

{
  undefined4 local_c;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    for (local_c = 0; local_c < *(int *)(param_1 + 8); local_c = local_c + 1) {
      quicktime_stsd_table_delete(*(int *)(param_1 + 0xc) + local_c * 0xcc,param_2);
    }
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}



undefined4 quicktime_read_stsd(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  uVar1 = quicktime_read_char(param_1);
  *param_3 = uVar1;
  uVar1 = quicktime_read_int24(param_1);
  param_3[1] = uVar1;
  uVar1 = quicktime_read_int32(param_1);
  param_3[2] = uVar1;
  uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_3[2] * 0xcc);
  param_3[3] = uVar1;
  if (param_3[3] == 0) {
    *(undefined4 *)(param_1 + 0x16c) = 2;
    uVar1 = 1;
  }
  else {
    ZeroMemory(param_3[3],param_3[2] * 0xcc);
    for (local_c = 0; local_c < (int)param_3[2]; local_c = local_c + 1) {
      quicktime_stsd_table_init(param_3[3] + local_c * 0xcc);
      iVar2 = quicktime_read_stsd_table(param_1,param_2,param_3[3] + local_c * 0xcc);
      if (iVar2 == 1) {
        return 1;
      }
      if (*(int *)(param_1 + 0x16c) != 0) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_write_stsd(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b444);
  quicktime_write_char(param_1,*param_3 & 0xff);
  quicktime_write_int24(param_1,param_3[1]);
  quicktime_write_int32(param_1,param_3[2]);
  for (local_c = 0; local_c < (int)param_3[2]; local_c = local_c + 1) {
    quicktime_write_stsd_table(param_1,param_2,param_3[3]);
  }
  quicktime_atom_write_footer(param_1,auStack_1c);
  return 0;
}



undefined4 quicktime_stsd_table_init(undefined1 *param_1)

{
  int local_c;
  
  ZeroMemory(param_1,0xcc);
  *param_1 = 0x79;
  param_1[1] = 0x75;
  param_1[2] = 0x76;
  param_1[3] = 0x32;
  for (local_c = 0; local_c < 6; local_c = local_c + 1) {
    param_1[local_c + 4] = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1[0x18] = 0x6c;
  param_1[0x19] = 0x6e;
  param_1[0x1a] = 0x75;
  param_1[0x1b] = 0x78;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0x102;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0x48;
  *(undefined4 *)(param_1 + 0x30) = 0x48;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 1;
  for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
    param_1[local_c + 0x3c] = 0;
  }
  memcpy(param_1 + 0x3c,"Quicktime for Green",0x14);
  *(undefined4 *)(param_1 + 0x5c) = 0x18;
  *(undefined4 *)(param_1 + 0x60) = 0xffff;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 1;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  quicktime_esds_init(param_1 + 0x84);
  return 0;
}



undefined4 quicktime_stsd_table_delete(int param_1,int param_2)

{
  quicktime_esds_delete(param_1 + 0x84,param_2);
  (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0xc0));
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 200));
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  return 0;
}



undefined4 quicktime_read_stsd_table(undefined4 param_1,int *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [12];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  iVar1 = quicktime_atom_read_header(param_1,auStack_18);
  if (iVar1 == 1) {
    uVar2 = 1;
  }
  else {
    *param_3 = local_c;
    param_3[1] = local_b;
    param_3[2] = local_a;
    param_3[3] = local_9;
    quicktime_read_data(param_1,param_3 + 4,6);
    uVar2 = quicktime_read_int16(param_1);
    *(undefined4 *)(param_3 + 0xc) = uVar2;
    if ((param_2[1] == 0) ||
       (iVar1 = quicktime_read_stsd_audio(param_1,param_3,auStack_18), iVar1 != 1)) {
      if ((*param_2 == 0) ||
         (iVar1 = quicktime_read_stsd_video(param_1,param_3,auStack_18), iVar1 != 1)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4 quicktime_write_stsd_table(undefined4 param_1,int *param_2,int param_3)

{
  undefined1 auStack_18 [16];
  
  quicktime_atom_write_header(param_1,auStack_18,param_3);
  quicktime_write_data(param_1,param_3 + 4,6);
  quicktime_write_int16(param_1,*(undefined4 *)(param_3 + 0xc));
  if (param_2[1] != 0) {
    quicktime_write_stsd_audio(param_1,param_3);
  }
  if (*param_2 != 0) {
    quicktime_write_stsd_video(param_1,param_3);
  }
  quicktime_atom_write_footer(param_1,auStack_18);
  return 0;
}



undefined4 quicktime_read_stsd_audio(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_18 [16];
  
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x10) = uVar3;
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  quicktime_read_data(param_1,param_2 + 0x18,4);
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x70) = uVar3;
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x74) = uVar3;
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x78) = uVar3;
  uVar3 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x7c) = uVar3;
  uVar3 = quicktime_read_fixed32(param_1);
  *(undefined4 *)(param_2 + 0x80) = uVar3;
  while( true ) {
    uVar5 = quicktime_position(param_1);
    if (*(uint *)(param_3 + 4) <= uVar5) {
      return 0;
    }
    iVar4 = quicktime_atom_read_header(param_1,auStack_18);
    if (iVar4 == 1) break;
    iVar4 = quicktime_atom_is(auStack_18,&DAT_0005b460);
    if (iVar4 == 0) {
      iVar4 = quicktime_atom_is(auStack_18,&DAT_0005b468);
      if (iVar4 == 0) {
        quicktime_atom_skip(param_1,auStack_18);
      }
      else {
        quicktime_read_data(param_1,param_2 + 0xa8,4);
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xac) = uVar1;
        uVar2 = quicktime_read_int16(param_1);
        *(undefined2 *)(param_2 + 0xae) = uVar2;
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xb0) = uVar1;
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xb1) = uVar1;
        quicktime_atom_skip(param_1,auStack_18);
      }
    }
    else {
      quicktime_read_esds(param_1,param_2 + 0x84);
      quicktime_atom_skip(param_1,auStack_18);
    }
  }
  return 1;
}



undefined4 quicktime_write_stsd_audio(int param_1,void *param_2)

{
  int iVar1;
  undefined1 auStack_18 [16];
  
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x10));
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x14));
    quicktime_write_data(param_1,(int)param_2 + 0x18,4);
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x70));
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x74));
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x78));
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x7c));
    quicktime_write_fixed32(param_1,*(undefined4 *)((int)param_2 + 0x80));
  }
  else {
    quicktime_write_int32(param_1,0);
    quicktime_write_int32(param_1,0);
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x70));
    quicktime_write_int16(param_1,0x10);
    quicktime_write_int32(param_1,0);
    quicktime_write_int16(param_1,*(undefined4 *)((int)param_2 + 0x80));
    quicktime_write_int16(param_1,0);
    iVar1 = memcmp(param_2,&DAT_0005b470,4);
    if (iVar1 == 0) {
      quicktime_atom_write_header(param_1,auStack_18,&DAT_0005b468);
      quicktime_write_char32(param_1,&DAT_0005b478);
      quicktime_write_char(param_1,0);
      quicktime_write_int16(param_1,0x80);
      quicktime_write_char(param_1,0);
      quicktime_write_char(param_1,1);
      quicktime_atom_write_footer(param_1,auStack_18);
    }
    else {
      iVar1 = memcmp(param_2,&DAT_0005b480,4);
      if (iVar1 == 0) {
        quicktime_write_esds_audio
                  (param_1,(int)param_2 + 0x84,*(undefined4 *)(**(int **)(param_1 + 0x13c) + 0x10));
      }
    }
  }
  return 0;
}



undefined4 quicktime_read_stsd_video(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_24 [8];
  uint local_1c;
  int local_14;
  int local_10;
  ushort local_c;
  ushort local_a;
  
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x10) = uVar2;
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x14) = uVar2;
  quicktime_read_data(param_1,param_2 + 0x18,4);
  uVar2 = quicktime_read_int32(param_1);
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  *(undefined4 *)(param_2 + 0x20) = uVar2;
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x24) = uVar2;
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  uVar2 = quicktime_read_fixed32(param_1);
  *(undefined4 *)(param_2 + 0x2c) = uVar2;
  uVar2 = quicktime_read_fixed32(param_1);
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  *(undefined4 *)(param_2 + 0x34) = uVar2;
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x38) = uVar2;
  quicktime_read_char(param_1);
  quicktime_read_data(param_1,param_2 + 0x3c,0x1f);
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x5c) = uVar2;
  uVar2 = quicktime_read_int16(param_1);
  *(undefined4 *)(param_2 + 0x60) = uVar2;
  ZeroMemory(param_2 + 0xa0,4);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          uVar4 = quicktime_position(param_1);
          if (*(uint *)(param_3 + 4) <= uVar4) {
            return 0;
          }
          iVar3 = quicktime_atom_read_header(param_1,auStack_24);
          if (iVar3 == 1) {
            return 1;
          }
          iVar3 = quicktime_atom_is(auStack_24,&DAT_0005b460);
          if (iVar3 == 0) break;
          quicktime_read_esds(param_1,param_2 + 0x84);
          quicktime_atom_skip(param_1,auStack_24);
        }
        iVar3 = quicktime_atom_is(auStack_24,&DAT_0005b488);
        if (iVar3 == 0) break;
        quicktime_read_data(param_1,param_2 + 0xa0,4);
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xa4) = uVar1;
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xa5) = uVar1;
        uVar1 = quicktime_read_char(param_1);
        *(undefined1 *)(param_2 + 0xa6) = uVar1;
        quicktime_atom_skip(param_1,auStack_24);
      }
      iVar3 = quicktime_atom_is(auStack_24,&DAT_0005b490);
      if (iVar3 != 0) break;
      iVar3 = quicktime_atom_is(auStack_24,&DAT_0005b498);
      if (iVar3 == 0) {
        quicktime_atom_skip(param_1,auStack_24);
      }
      else if (local_1c < 0x1a) {
        quicktime_atom_skip(param_1,auStack_24);
      }
      else {
        quicktime_get_mp4_hvcC(param_1,param_2);
      }
    }
    local_10 = 0;
    local_a = 0;
    local_c = 0;
    local_14 = 0;
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb4) = uVar1;
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb5) = uVar1;
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb6) = uVar1;
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb7) = uVar1;
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb8) = uVar1;
    *(byte *)(param_2 + 0xb8) = *(byte *)(param_2 + 0xb8) & 3;
    if (((*(char *)(param_2 + 0xb8) != '\x03') && (*(char *)(param_2 + 0xb8) != '\x02')) &&
       (*(char *)(param_2 + 0xb8) != '\x01')) {
      return 1;
    }
    uVar1 = quicktime_read_char(param_1);
    *(undefined1 *)(param_2 + 0xb9) = uVar1;
    *(byte *)(param_2 + 0xb9) = *(byte *)(param_2 + 0xb9) & 0x1f;
    if (local_1c < 0xf) {
      return 1;
    }
    *(uint *)(param_2 + 0xbc) = local_1c - 0xe;
    local_10 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(*(undefined4 *)(param_2 + 0xbc));
    if (local_10 == 0) break;
    local_14 = *(int *)(param_2 + 0xbc);
    iVar3 = quicktime_read_data(param_1,local_10,local_14);
    if (iVar3 != local_14) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(local_10);
      return 1;
    }
    for (local_a = 0; local_a < *(byte *)(param_2 + 0xb9); local_a = local_a + 1) {
      local_c = CONCAT11(*(undefined1 *)(local_10 + (uint)local_c),
                         *(undefined1 *)(local_10 + local_c + 1)) + local_c + 2;
    }
    *(undefined1 *)(param_2 + 0xba) = *(undefined1 *)(local_10 + (uint)local_c);
    *(uint *)(param_2 + 0xbc) =
         *(int *)(param_2 + 0xbc) +
         ((uint)*(byte *)(param_2 + 0xb9) + (uint)*(byte *)(param_2 + 0xba)) * 2 + -1;
    *(uint *)(param_2 + 0xbc) = *(int *)(param_2 + 0xbc) + (uint)*(byte *)(param_2 + 0xb8) + 2;
    uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(*(undefined4 *)(param_2 + 0xbc));
    *(undefined4 *)(param_2 + 0xc0) = uVar2;
    if (*(int *)(param_2 + 0xc0) == 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(local_10);
      return 1;
    }
    iVar3 = AVC_ParseDecConfigRecord(local_10,local_14,param_2 + 0xb4);
    if (iVar3 == 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(local_10);
      return 1;
    }
    (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(local_10);
  }
  return 1;
}



undefined4 quicktime_write_stsd_video(int param_1,int param_2)

{
  size_t sVar1;
  undefined1 auStack_20 [16];
  uint local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x10));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x14));
    quicktime_write_data(param_1,param_2 + 0x18,4);
    quicktime_write_int32(param_1,*(undefined4 *)(param_2 + 0x1c));
    quicktime_write_int32(param_1,*(undefined4 *)(param_2 + 0x20));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x24));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x28));
    quicktime_write_fixed32(param_1,*(undefined4 *)(param_2 + 0x2c));
    quicktime_write_fixed32(param_1,*(undefined4 *)(param_2 + 0x30));
    quicktime_write_int32(param_1,*(undefined4 *)(param_2 + 0x34));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x38));
    sVar1 = strlen((char *)(param_2 + 0x3c));
    quicktime_write_char(param_1,sVar1 & 0xff);
    quicktime_write_data(param_1,param_2 + 0x3c,0x1f);
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x5c));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x60));
  }
  else {
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x24));
    quicktime_write_int16(param_1,*(undefined4 *)(param_2 + 0x28));
    quicktime_write_int32(param_1,0x480000);
    quicktime_write_int32(param_1,0x480000);
    quicktime_write_int32(param_1,0);
    quicktime_write_int16(param_1,1);
    for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
      quicktime_write_char(param_1,0);
    }
    quicktime_write_int16(param_1,0x18);
    quicktime_write_int16(param_1,0xffffffff);
    local_10 = str2ulong(param_2);
    if (local_10 == 0x31637668) {
      quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b498);
      if (*(int *)(param_2 + 200) != 0) {
        quicktime_write_data(param_1,*(undefined4 *)(param_2 + 200),*(undefined4 *)(param_2 + 0xc4))
        ;
      }
      quicktime_atom_write_footer(param_1,auStack_20);
    }
    else if (local_10 < 0x31637669) {
      if (local_10 == 0x31637661) {
        quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b490);
        if (*(int *)(param_2 + 0xc0) != 0) {
          quicktime_write_data(param_1,param_2 + 0xb4,6);
          quicktime_write_data
                    (param_1,*(undefined4 *)(param_2 + 0xc0),*(undefined4 *)(param_2 + 0xbc));
        }
        quicktime_atom_write_footer(param_1,auStack_20);
      }
    }
    else if (local_10 == 0x33363273) {
      quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b488);
      quicktime_write_char32(param_1,&DAT_0005b478);
      quicktime_write_char(param_1,0);
      quicktime_write_char(param_1,10);
      quicktime_write_char(param_1,0);
      quicktime_atom_write_footer(param_1,auStack_20);
    }
    else if (local_10 == 0x7634706d) {
      if (*(int *)(param_2 + 0x9c) == 0) {
        return 1;
      }
      quicktime_write_esds_video
                (param_1,param_2 + 0x84,*(undefined4 *)(**(int **)(param_1 + 0x144) + 0x10));
    }
  }
  if (*(int *)(param_2 + 0x68) != 0) {
    quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b4a0);
    quicktime_write_char(param_1,*(uint *)(param_2 + 0x68) & 0xff);
    quicktime_write_char(param_1,*(uint *)(param_2 + 0x6c) & 0xff);
    quicktime_atom_write_footer(param_1,auStack_20);
  }
  return 0;
}



undefined4 quicktime_stss_init(int param_1)

{
  ZeroMemory(param_1,0x20);
  *(undefined4 *)(param_1 + 0x1c) = 2;
  return 0;
}



undefined4 quicktime_stss_delete(int param_1,int param_2)

{
  if (*(int *)(param_1 + 8) != 0) {
    MEML_Destroy(param_1 + 0x14,param_2);
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}



undefined4 quicktime_read_stss(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_224 [512];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_24 = 0x200;
  local_1c = 0;
  uVar2 = quicktime_read_char(param_1);
  *param_2 = uVar2;
  uVar2 = quicktime_read_int24(param_1);
  param_2[1] = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  param_2[2] = uVar2;
  if ((int)param_2[2] < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[2] << 2);
    param_2[4] = uVar2;
    if (param_2[4] == 0) {
      *(undefined4 *)(param_1 + 0x16c) = 2;
      uVar2 = 1;
    }
    else {
      local_14 = 0;
      local_1c = param_2[2] << 2;
      while (local_14 < (int)param_2[2]) {
        local_20 = local_24;
        if (local_1c <= local_24) {
          local_20 = local_1c;
        }
        local_20 = quicktime_read_data(param_1,auStack_224,local_20);
        if (local_20 == 0) break;
        local_1c = local_1c - local_20;
        for (local_18 = 0; local_18 < local_20 + -3; local_18 = local_18 + 4) {
          iVar3 = param_2[4];
          iVar1 = local_14 * 4;
          uVar2 = mov_str2ulong(auStack_224 + local_18);
          *(undefined4 *)(iVar3 + iVar1) = uVar2;
          local_14 = local_14 + 1;
        }
      }
      if (*(int *)(param_1 + 0x16c) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



undefined4 quicktime_write_stss_opt(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  int local_c;
  
  if (param_2[2] != 0) {
    quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b4a8);
    quicktime_write_char(param_1,*param_2 & 0xff);
    quicktime_write_int24(param_1,param_2[1]);
    quicktime_write_int32(param_1,param_2[2]);
    param_2[6] = param_2[5];
    for (local_c = 0; local_c < (int)param_2[2]; local_c = local_c + 1) {
      MEML_GetElement(param_2 + 5,&local_20);
      iVar1 = quicktime_write_int32(param_1,local_20);
      if (iVar1 == -1) {
        *(undefined4 *)(param_1 + 0x168) = 3;
        return 1;
      }
    }
    quicktime_atom_write_footer(param_1,auStack_1c);
  }
  return 0;
}



undefined4 quicktime_write_stss(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_1c [16];
  int local_c;
  
  if (*(char *)(param_1 + 0x175) == '\0') {
    iVar2 = __divsi3(*(int *)(*(int *)(param_1 + 0x144) + 4) + -1,*(undefined4 *)(param_1 + 0x164));
    param_2[2] = iVar2 + 1;
    if (param_2[2] != 0) {
      quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b4a8);
      quicktime_write_char(param_1,*param_2 & 0xff);
      quicktime_write_int24(param_1,param_2[1]);
      quicktime_write_int32(param_1,param_2[2]);
      for (local_c = 0; local_c < (int)param_2[2]; local_c = local_c + 1) {
        iVar2 = quicktime_write_int32(param_1,local_c * *(int *)(param_1 + 0x164) + 1);
        if (iVar2 == -1) {
          *(undefined4 *)(param_1 + 0x168) = 3;
          return 1;
        }
      }
      quicktime_atom_write_footer(param_1,auStack_1c);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = quicktime_write_stss_opt(param_1,param_2);
  }
  return uVar1;
}



bool quicktime_update_stss_opt(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_c;
  
  local_c = param_2 + 1;
  iVar1 = MEML_StoreElement(param_1 + 0x14,&local_c,param_3);
  if (iVar1 != 1) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return iVar1 == 1;
}



undefined4 quicktime_stsz_init(int param_1)

{
  ZeroMemory(param_1,0x2c);
  *(undefined4 *)(param_1 + 0x28) = 2;
  return 0;
}



undefined4 quicktime_stsz_init_video_opt(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_c;
  
  *(undefined4 *)(param_2 + 8) = 0;
  if (*(char *)(param_1 + 0x160) == '\x01') {
    local_c = 8;
  }
  else {
    local_c = 0x80;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    *(undefined4 *)(param_2 + 0xc) = 0;
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                      (local_c * (uint)*(byte *)(param_1 + 0x161) * 2);
    *(undefined4 *)(param_2 + 0x18) = uVar1;
    if (*(int *)(param_2 + 0x18) == 0) {
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                      ((uint)*(byte *)(param_1 + 0x161) * 0x2800);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_1 + 0x168) = 4;
      return 1;
    }
    *(int *)(param_2 + 0x10) = local_c;
  }
  return 0;
}



undefined4 quicktime_stsz_init_audio(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 8) = param_3;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}



undefined4 quicktime_stsz_delete(int param_1,int param_2)

{
  if (*(int *)(param_1 + 8) == 0) {
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



undefined4 quicktime_stsz_delete_opt(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x18));
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  MEML_Destroy(param_1 + 0x20,param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



undefined4 quicktime_read_stsz(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_224 [512];
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  
  local_18 = 0;
  local_1c = 0;
  uVar2 = quicktime_read_char(param_1);
  *param_2 = uVar2;
  uVar2 = quicktime_read_int24(param_1);
  param_2[1] = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  param_2[2] = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  param_2[3] = uVar2;
  param_2[4] = param_2[3];
  if ((param_2[2] == 0) && (0 < (int)param_2[4])) {
    uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[4] << 2);
    param_2[5] = uVar2;
    if (param_2[5] == 0) {
      *(undefined4 *)(param_1 + 0x16c) = 2;
      return 1;
    }
    local_20 = ((uint)(param_2[4] << 2) >> 9) + 1;
    local_24 = (param_2[4] & 0x7f) << 2;
    local_1c = 0;
    for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
      if (local_20 + -1 == local_14) {
        quicktime_read_data(param_1,auStack_224,local_24);
        if (*(int *)(param_1 + 0x16c) != 0) {
          return 1;
        }
        for (local_18 = 0; (int)local_18 < local_24; local_18 = local_18 + 4) {
          iVar3 = param_2[5];
          iVar1 = local_1c * 4;
          uVar2 = mov_str2ulong(auStack_224 + local_18);
          *(undefined4 *)(iVar3 + iVar1) = uVar2;
          local_1c = local_1c + 1;
        }
      }
      else {
        quicktime_read_data(param_1,auStack_224,0x200);
        if (*(int *)(param_1 + 0x16c) != 0) {
          return 1;
        }
        for (local_18 = 0; local_18 < 0x200; local_18 = local_18 + 4) {
          iVar3 = param_2[5];
          iVar1 = local_1c * 4;
          uVar2 = mov_str2ulong(auStack_224 + local_18);
          *(undefined4 *)(iVar3 + iVar1) = uVar2;
          local_1c = local_1c + 1;
        }
      }
    }
  }
  return 0;
}



undefined4 quicktime_write_stsz_vide(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2c [16];
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 *local_10;
  int local_c;
  
  local_14 = param_2[3];
  local_18 = *(undefined4 *)(*(int *)(param_1 + 0x144) + 0x2c);
  quicktime_atom_write_header(param_1,auStack_2c,&DAT_0005b4b0);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  if (param_2[2] == 0) {
    quicktime_write_int32(param_1,param_2[3]);
    if (*(int *)(*(int *)(param_1 + 0x144) + 0x28) != 0) {
      local_14 = local_14 - *(int *)(*(int *)(param_1 + 0x144) + 0x28);
    }
    if (*(char *)(param_1 + 0x160) == '\0') {
      (**(code **)(*(int *)(param_1 + 0x170) + 0xc))(local_18,0,0);
      local_1c = param_2[7];
      while (-1 < (int)(local_14 - 0x1400)) {
        local_14 = local_14 - 0x1400;
        (**(code **)(*(int *)(param_1 + 0x170) + 4))(local_18,local_1c,0x5000);
        for (local_c = 0; local_c < 0x1400; local_c = local_c + 1) {
          quicktime_write_int32(param_1,*(undefined4 *)(local_1c + local_c * 4));
        }
      }
      (**(code **)(*(int *)(param_1 + 0x170) + 4))(local_18,local_1c,local_14 << 2);
      for (local_c = 0; local_c < (int)local_14; local_c = local_c + 1) {
        quicktime_write_int32(param_1,*(undefined4 *)(local_1c + local_c * 4));
      }
    }
    else {
      local_10 = *(undefined4 **)(*(int *)(param_1 + 0x144) + 0x30);
      for (local_c = 0; local_c < (int)local_14; local_c = local_c + 1) {
        uVar2 = *local_10;
        local_10 = local_10 + 1;
        quicktime_write_int32(param_1,uVar2);
      }
    }
    if (*(int *)(*(int *)(param_1 + 0x144) + 0x28) != 0) {
      local_10 = (undefined4 *)param_2[6];
      for (local_c = 0; local_c < *(int *)(*(int *)(param_1 + 0x144) + 0x28); local_c = local_c + 1)
      {
        uVar2 = *local_10;
        local_10 = local_10 + 1;
        iVar1 = quicktime_write_int32(param_1,uVar2);
        if (iVar1 == -1) {
          *(undefined4 *)(param_1 + 0x168) = 3;
          return 1;
        }
      }
    }
  }
  else {
    quicktime_write_int32(param_1,param_2[3]);
  }
  quicktime_atom_write_footer(param_1,auStack_2c);
  return 0;
}



undefined4 quicktime_write_stsz_opt_vide(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_34 [16];
  uint local_24;
  ushort *local_20;
  undefined4 local_1c;
  uint local_18;
  ushort *local_14;
  ushort *local_10;
  int local_c;
  
  local_18 = param_2[3];
  local_1c = *(undefined4 *)(*(int *)(param_1 + 0x144) + 0x2c);
  if (*(char *)(param_1 + 0x161) == '\x02') {
    uVar1 = quicktime_write_stsz_vide(param_1,param_2);
  }
  else {
    quicktime_atom_write_header(param_1,auStack_34,&DAT_0005b4b0);
    quicktime_write_char(param_1,*param_2 & 0xff);
    quicktime_write_int24(param_1,param_2[1]);
    quicktime_write_int32(param_1,param_2[2]);
    if (param_2[2] == 0) {
      quicktime_write_int32(param_1,param_2[3]);
      if (*(int *)(*(int *)(param_1 + 0x144) + 0x28) != 0) {
        local_18 = local_18 - *(int *)(*(int *)(param_1 + 0x144) + 0x28);
      }
      if (*(char *)(param_1 + 0x160) == '\0') {
        (**(code **)(*(int *)(param_1 + 0x170) + 0xc))(local_1c,0,0);
        local_20 = (ushort *)param_2[7];
        local_14 = local_20;
        while (-1 < (int)(local_18 - 0x1400)) {
          local_18 = local_18 - 0x1400;
          (**(code **)(*(int *)(param_1 + 0x170) + 4))(local_1c,local_20,0x2800);
          local_14 = local_20;
          for (local_c = 0; local_c < 0x1400; local_c = local_c + 1) {
            local_24 = (uint)*local_14;
            local_14 = local_14 + 1;
            iVar2 = quicktime_write_int32(param_1,local_24);
            if (iVar2 == -1) {
              *(undefined4 *)(param_1 + 0x168) = 3;
              return 1;
            }
          }
        }
        (**(code **)(*(int *)(param_1 + 0x170) + 4))(local_1c,local_20,local_18 << 1);
        local_14 = local_20;
        for (local_c = 0; local_c < (int)local_18; local_c = local_c + 1) {
          local_24 = (uint)*local_14;
          local_14 = local_14 + 1;
          quicktime_write_int32(param_1,local_24);
        }
      }
      else {
        local_10 = *(ushort **)(*(int *)(param_1 + 0x144) + 0x30);
        for (local_c = 0; local_c < (int)local_18; local_c = local_c + 1) {
          local_24 = (uint)*local_10;
          local_10 = local_10 + 1;
          iVar2 = quicktime_write_int32(param_1,local_24);
          if (iVar2 == -1) {
            *(undefined4 *)(param_1 + 0x168) = 3;
            return 1;
          }
        }
      }
      if (*(int *)(*(int *)(param_1 + 0x144) + 0x28) != 0) {
        local_10 = (ushort *)param_2[6];
        for (local_c = 0; local_c < *(int *)(*(int *)(param_1 + 0x144) + 0x28);
            local_c = local_c + 1) {
          local_24 = (uint)*local_10;
          local_10 = local_10 + 1;
          iVar2 = quicktime_write_int32(param_1,local_24);
          if (iVar2 == -1) {
            *(undefined4 *)(param_1 + 0x168) = 3;
            return 1;
          }
        }
      }
    }
    else {
      quicktime_write_int32(param_1,param_2[3]);
    }
    quicktime_atom_write_footer(param_1,auStack_34);
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 quicktime_write_stsz_opt(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 local_24;
  undefined1 auStack_20 [16];
  uint local_10;
  int local_c;
  
  local_10 = param_2[3];
  quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b4b0);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  quicktime_write_int32(param_1,param_2[3]);
  if (param_2[2] == 0) {
    param_2[9] = param_2[8];
    for (local_c = 0; local_c < (int)param_2[3]; local_c = local_c + 1) {
      MEML_GetElement(param_2 + 8,&local_24);
      iVar1 = quicktime_write_int32(param_1,local_24);
      if (iVar1 == -1) {
        *(undefined4 *)(param_1 + 0x168) = 3;
        return 1;
      }
    }
  }
  quicktime_atom_write_footer(param_1,auStack_20);
  return 0;
}



undefined4 quicktime_update_stsz_opt_vide(int param_1,int param_2,undefined4 param_3,int param_4)

{
  size_t __n;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if ((*(byte *)(param_4 + 0x161) & 1) == 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x18) + iVar1 * 4) = param_3;
  }
  else {
    *(short *)(*(int *)(param_2 + 0x18) + iVar1 * 2) = (short)param_3;
  }
  if (*(int *)(param_2 + 0x10) == iVar1 + 1) {
    __n = *(int *)(param_2 + 0x10) << *(sbyte *)(param_4 + 0x161);
    if (*(char *)(param_4 + 0x160) == '\x01') {
      if (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x38) < (int)__n) {
        return 2;
      }
      memcpy(*(void **)(param_1 + 0x38),*(void **)(param_2 + 0x18),__n);
      *(size_t *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + __n;
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_4 + 0x170) + 8))
                        (*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x18),__n);
      if (iVar1 == -1) {
        return 1;
      }
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  else {
    *(int *)(param_1 + 0x28) = iVar1 + 1;
  }
  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  return 0;
}



undefined4 quicktime_update_stsz_opt(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 8) == 0) {
    local_c = param_2;
    iVar1 = MEML_StoreElement(param_1 + 0x20,&local_c,param_3);
    if (iVar1 == 1) {
      uVar2 = 1;
    }
    else {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 quicktime_stts_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x2c);
  return 0;
}



undefined4 quicktime_stts_init_table(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 0xc) = 1;
    uVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(*(int *)(param_1 + 0xc) << 3);
    *(undefined4 *)(param_1 + 0x10) = uVar1;
    if (*(int *)(param_1 + 0x10) == 0) {
      return 1;
    }
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return 0;
}



undefined4 quicktime_stts_init_video(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (*(char *)(param_1 + 0x175) == '\0') {
    iVar1 = quicktime_stts_init_table(param_2,param_1);
    if (iVar1 == 1) {
      *(undefined4 *)(param_1 + 0x168) = 4;
      uVar2 = 1;
    }
    else {
      puVar3 = *(undefined4 **)(param_2 + 0x10);
      *puVar3 = 0;
      if (param_4 == 0) {
        puVar3[1] = 0;
      }
      else {
        uVar2 = __divsi3(param_3,param_4);
        puVar3[1] = uVar2;
      }
      uVar2 = 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x28) = 3;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    uVar2 = 0;
  }
  return uVar2;
}



bool quicktime_stts_init_audio(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = quicktime_stts_init_table(param_2,param_1);
  if (iVar1 != 1) {
    puVar2 = *(undefined4 **)(param_2 + 0x10);
    *puVar2 = 0;
    puVar2[1] = param_4;
  }
  else {
    *(undefined4 *)(param_1 + 0x168) = 4;
  }
  return iVar1 == 1;
}



undefined4 quicktime_stts_delete(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  MEML_Destroy(param_1 + 0x20,param_2);
  return 0;
}



undefined4 quicktime_read_stts(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_224 [4];
  undefined1 auStack_220 [508];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  local_24 = 0x200;
  local_1c = 0;
  uVar2 = quicktime_read_char(param_1);
  *param_2 = uVar2;
  uVar2 = quicktime_read_int24(param_1);
  param_2[1] = uVar2;
  uVar2 = quicktime_read_int32(param_1);
  param_2[2] = uVar2;
  uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(param_2[2] << 3);
  param_2[4] = uVar2;
  if (param_2[4] == 0) {
    *(undefined4 *)(param_1 + 0x16c) = 2;
    uVar2 = 1;
  }
  else {
    local_14 = 0;
    local_1c = param_2[2] << 3;
    while (local_14 < (int)param_2[2]) {
      local_20 = local_24;
      if (local_1c <= local_24) {
        local_20 = local_1c;
      }
      local_20 = quicktime_read_data(param_1,auStack_224,local_20);
      if (local_20 == 0) break;
      local_1c = local_1c - local_20;
      for (local_18 = 0; local_18 < local_20 + -7; local_18 = local_18 + 8) {
        iVar3 = param_2[4];
        iVar1 = local_14 * 8;
        uVar2 = mov_str2ulong(auStack_224 + local_18);
        *(undefined4 *)(iVar3 + iVar1) = uVar2;
        iVar3 = param_2[4];
        iVar1 = local_14 * 8;
        uVar2 = mov_str2ulong(auStack_220 + local_18);
        *(undefined4 *)(iVar3 + iVar1 + 4) = uVar2;
        local_14 = local_14 + 1;
      }
    }
    if (*(int *)(param_1 + 0x16c) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4 quicktime_write_stts(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b4b8);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  local_c = 0;
  while( true ) {
    if ((int)param_2[2] <= local_c) {
      quicktime_atom_write_footer(param_1,auStack_1c);
      return 0;
    }
    quicktime_write_int32(param_1,*(undefined4 *)(param_2[4] + local_c * 8));
    iVar1 = quicktime_write_int32(param_1,*(undefined4 *)(param_2[4] + local_c * 8 + 4));
    if (iVar1 == -1) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(param_1 + 0x168) = 3;
  return 1;
}



undefined4 quicktime_write_stts_opt(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b4b8);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  quicktime_write_int32(param_1,param_2[2]);
  param_2[9] = param_2[8];
  local_c = 0;
  while( true ) {
    if ((int)param_2[2] <= local_c) {
      quicktime_atom_write_footer(param_1,auStack_1c);
      return 0;
    }
    MEML_GetElement(param_2 + 8,&local_24);
    quicktime_write_int32(param_1,local_24);
    iVar1 = quicktime_write_int32(param_1,local_20);
    if (iVar1 == -1) break;
    local_c = local_c + 1;
  }
  *(undefined4 *)(param_1 + 0x168) = 3;
  return 1;
}



undefined4 quicktime_update_stts_opt(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  undefined4 local_c;
  
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + param_2;
  if (param_3 == 1) {
    *(int *)(param_1 + 0x14) = param_2;
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  if (*(int *)(param_1 + 0x14) != param_2) {
    local_10 = param_3 - *(int *)(param_1 + 0x18);
    local_c = *(undefined4 *)(param_1 + 0x14);
    iVar1 = MEML_StoreElement(param_1 + 0x20,&local_10,param_4);
    if (iVar1 == 1) {
      return 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(param_1 + 0x14) = param_2;
    *(int *)(param_1 + 0x18) = param_3;
  }
  return 0;
}



undefined4 quicktime_tkhd_init(undefined4 *param_1)

{
  undefined4 uVar1;
  int local_c;
  
  *param_1 = 0;
  param_1[1] = 0xf;
  uVar1 = quicktime_current_time();
  param_1[2] = uVar1;
  uVar1 = quicktime_current_time();
  param_1[3] = uVar1;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    *(undefined1 *)((int)param_1 + local_c + 0x20) = 0;
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  quicktime_matrix_init(param_1 + 0xe);
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  return 0;
}



undefined4 quicktime_tkhd_init_audio(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x68) = 1;
  return 0;
}



undefined4
quicktime_tkhd_init_video(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_2 + 100) = 1;
  *(undefined4 *)(param_2 + 0x5c) = param_3;
  *(undefined4 *)(param_2 + 0x60) = param_4;
  *(undefined4 *)(param_2 + 0x30) = 0;
  return 0;
}



undefined4 quicktime_tkhd_delete(void)

{
  return 0;
}



undefined4 quicktime_read_tkhd(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = quicktime_read_char(param_1);
  *param_2 = iVar1;
  iVar1 = quicktime_read_int24(param_1);
  param_2[1] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[2] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[2] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[3] = iVar1;
  if (*param_2 == 1) {
    iVar1 = quicktime_read_int32(param_1);
    param_2[3] = iVar1;
  }
  iVar1 = quicktime_read_int32(param_1);
  param_2[4] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[5] = iVar1;
  iVar1 = quicktime_read_int32(param_1);
  param_2[6] = iVar1;
  param_2[7] = iVar1 >> 0x1f;
  if (*param_2 == 1) {
    iVar2 = param_2[6];
    iVar1 = quicktime_read_int32(param_1,param_2,iVar2,param_2[7]);
    param_2[6] = iVar1;
    param_2[7] = iVar2;
  }
  quicktime_read_data(param_1,param_2 + 8,8);
  iVar1 = quicktime_read_int16(param_1);
  param_2[10] = iVar1;
  iVar1 = quicktime_read_int16(param_1);
  param_2[0xb] = iVar1;
  iVar1 = quicktime_read_fixed16(param_1);
  param_2[0xc] = iVar1;
  iVar1 = quicktime_read_int16(param_1);
  param_2[0xd] = iVar1;
  quicktime_read_matrix(param_1,param_2 + 0xe);
  iVar1 = quicktime_read_fixed32(param_1);
  param_2[0x17] = iVar1;
  iVar1 = quicktime_read_fixed32(param_1);
  param_2[0x18] = iVar1;
  return 0;
}



undefined4 quicktime_write_tkhd(int param_1,uint *param_2)

{
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005b4c0);
  quicktime_write_char(param_1,*param_2 & 0xff);
  if ((*(int *)(param_1 + 0x134) == 0) || (param_2[1] == 0)) {
    quicktime_write_int24(param_1,param_2[1]);
  }
  else {
    quicktime_write_int24(param_1,1);
  }
  quicktime_write_int32(param_1,param_2[2]);
  quicktime_write_int32(param_1,param_2[3]);
  quicktime_write_int32(param_1,param_2[4]);
  quicktime_write_int32(param_1,param_2[5]);
  quicktime_write_int32(param_1,param_2[6]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_data(param_1,param_2 + 8,8);
    quicktime_write_int16(param_1,param_2[10]);
    quicktime_write_int16(param_1,param_2[0xb]);
    quicktime_write_fixed16(param_1,param_2[0xc]);
    quicktime_write_int16(param_1,param_2[0xd]);
    quicktime_write_matrix(param_1,param_2 + 0xe);
    quicktime_write_fixed32(param_1,param_2[0x17]);
    quicktime_write_fixed32(param_1,param_2[0x18]);
  }
  else {
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    if (param_2[0x1a] == 0) {
      quicktime_write_int16(param_1,0);
    }
    else {
      quicktime_write_int16(param_1,0x100);
    }
    quicktime_write_int16(param_1,0);
    quicktime_write_int32(param_1,0x10000);
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    quicktime_write_int32(param_1,0x10000);
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int32(param_1,0);
    }
    quicktime_write_int32(param_1,0x40000000);
    if (param_2[0x19] == 0) {
      quicktime_write_int32(param_1,0);
      quicktime_write_int32(param_1,0);
    }
    else {
      quicktime_write_fixed32(param_1,param_2[0x17]);
      quicktime_write_fixed32(param_1,param_2[0x18]);
    }
  }
  quicktime_atom_write_footer(param_1,auStack_1c);
  return 0;
}



undefined4 quicktime_trak_init(int param_1)

{
  ZeroMemory(param_1,0x408);
  quicktime_tkhd_init(param_1);
  quicktime_mdia_init(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x3f0) = 0xffffffff;
  return 0;
}



undefined4
quicktime_trak_init_video
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

{
  quicktime_tkhd_init_video(param_1,param_2,param_3,param_4);
  quicktime_mdia_init_video(param_1,param_2 + 0x70,param_3,param_4,param_5,param_6,param_7);
  return 0;
}



undefined4
quicktime_trak_init_audio
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  quicktime_tkhd_init_audio(param_1,param_2);
  quicktime_mdia_init_audio
            (param_1,param_2 + 0x70,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return 0;
}



undefined4 quicktime_trak_delete(int param_1,undefined4 param_2)

{
  quicktime_tkhd_delete(param_1);
  quicktime_mdia_delete(param_1 + 0x70,param_2);
  return 0;
}



undefined4 quicktime_trak_delete_rec(int param_1,undefined4 param_2)

{
  quicktime_tkhd_delete(param_1);
  quicktime_mdia_delete_rec(param_1 + 0x70,param_2);
  return 0;
}



int quicktime_add_trak(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 < 0x20) {
    iVar2 = *param_1;
    iVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(0x408);
    param_1[iVar2 + 0x20] = iVar1;
    if (param_1[*param_1 + 0x20] == 0) {
      return 0;
    }
    quicktime_trak_init(param_1[*param_1 + 0x20]);
    *param_1 = *param_1 + 1;
  }
  return param_1[*param_1 + 0x1f];
}



undefined4 quicktime_delete_trak(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*param_1 <= local_c) {
      return 0xffffffff;
    }
    if (param_1[local_c + 0x20] == param_2) break;
    local_c = local_c + 1;
  }
  quicktime_trak_delete(param_2,param_3);
  (**(code **)(*(int *)(param_3 + 0x170) + 0x18))(param_2);
  param_1[local_c + 0x20] = 0;
  iVar1 = local_c;
  while (local_10 = iVar1 + 1, local_10 < *param_1) {
    param_1[local_c + 0x20] = param_1[iVar1 + 0x21];
    local_c = local_c + 1;
    iVar1 = local_10;
  }
  param_1[iVar1 + 0x21] = 0;
  *param_1 = *param_1 + -1;
  return 0;
}



undefined4 quicktime_delete_trak_rec(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iStack_10;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*param_1 <= local_c) {
      return 0xffffffff;
    }
    if (param_1[local_c + 0x20] == param_2) break;
    local_c = local_c + 1;
  }
  quicktime_trak_delete_rec(param_2,param_3);
  (**(code **)(*(int *)(param_3 + 0x170) + 0x18))(param_2);
  param_1[local_c + 0x20] = 0;
  iVar1 = local_c;
  while (iStack_10 = iVar1 + 1, iStack_10 < *param_1) {
    param_1[local_c + 0x20] = param_1[iVar1 + 0x21];
    local_c = local_c + 1;
    iVar1 = iStack_10;
  }
  param_1[iVar1 + 0x21] = 0;
  *param_1 = *param_1 + -1;
  return 0;
}



undefined4 FUN_00045acc(void)

{
  int unaff_r11;
  
  do {
    *(undefined4 *)(*(int *)(unaff_r11 + -0x10) + (*(int *)(unaff_r11 + -8) + 0x20) * 4) =
         *(undefined4 *)(*(int *)(unaff_r11 + -0x10) + (*(int *)(unaff_r11 + -0xc) + 0x20) * 4);
    *(int *)(unaff_r11 + -0xc) = *(int *)(unaff_r11 + -0xc) + 1;
    *(int *)(unaff_r11 + -8) = *(int *)(unaff_r11 + -8) + 1;
  } while (*(int *)(unaff_r11 + -0xc) < **(int **)(unaff_r11 + -0x10));
  *(undefined4 *)(*(int *)(unaff_r11 + -0x10) + (*(int *)(unaff_r11 + -0xc) + 0x20) * 4) = 0;
  **(int **)(unaff_r11 + -0x10) = **(int **)(unaff_r11 + -0x10) + -1;
  return 0;
}



undefined4 quicktime_read_trak(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_18);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b4c8);
    if (iVar1 == 0) {
      iVar1 = quicktime_atom_is(auStack_18,&DAT_0005b4d0);
      if (iVar1 == 0) {
        quicktime_atom_skip(param_1,auStack_18);
      }
      else {
        iVar1 = quicktime_read_mdia(param_1,param_2 + 0x70,auStack_18);
        if (iVar1 == 1) {
          return 1;
        }
      }
    }
    else {
      iVar1 = quicktime_read_tkhd(param_1,param_2);
      if (iVar1 == 1) {
        return 1;
      }
    }
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_3 + 4));
  return 0;
}



undefined4 FUN_00045b94(void)

{
  int iVar1;
  uint uVar2;
  int in_r3;
  int unaff_r11;
  
  while( true ) {
    iVar1 = quicktime_atom_read_header(*(undefined4 *)(unaff_r11 + -0x18),in_r3);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = quicktime_atom_is(unaff_r11 + -0x14,&DAT_0005b4c8);
    if (iVar1 == 0) {
      iVar1 = quicktime_atom_is(unaff_r11 + -0x14,&DAT_0005b4d0);
      if (iVar1 == 0) {
        quicktime_atom_skip(*(undefined4 *)(unaff_r11 + -0x18),unaff_r11 + -0x14);
      }
      else {
        iVar1 = quicktime_read_mdia(*(undefined4 *)(unaff_r11 + -0x18),
                                    *(int *)(unaff_r11 + -0x1c) + 0x70,unaff_r11 + -0x14);
        if (iVar1 == 1) {
          return 1;
        }
      }
    }
    else {
      iVar1 = quicktime_read_tkhd(*(undefined4 *)(unaff_r11 + -0x18),
                                  *(undefined4 *)(unaff_r11 + -0x1c));
      if (iVar1 == 1) {
        return 1;
      }
    }
    uVar2 = quicktime_position(*(undefined4 *)(unaff_r11 + -0x18));
    if (*(uint *)(*(int *)(unaff_r11 + -0x20) + 4) <= uVar2) break;
    in_r3 = unaff_r11 + -0x14;
  }
  return 0;
}



undefined4 quicktime_write_trak_video(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined1 auStack_20 [16];
  int local_10;
  int iStack_c;
  
  quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b4d8);
  quicktime_trak_duration(param_2,&iStack_c,&local_10);
  if (local_10 == 0) {
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  else {
    MulDiv(param_2 + 0x18,iStack_c,param_3,local_10);
  }
  *(int *)(param_2 + 0x88) = iStack_c;
  *(int *)(param_2 + 0x8c) = iStack_c >> 0x1f;
  *(int *)(param_2 + 0x80) = local_10;
  quicktime_write_tkhd(param_1,param_2);
  quicktime_write_mdia(param_1,param_2 + 0x70);
  quicktime_atom_write_footer(param_1,auStack_20);
  return 0;
}



undefined4 FUN_00045ce8(void)

{
  int iVar1;
  int iVar2;
  int unaff_r11;
  bool in_ZR;
  
  if (in_ZR) {
    iVar1 = *(int *)(unaff_r11 + -0x24);
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  else {
    MulDiv(*(int *)(unaff_r11 + -0x24) + 0x18,*(undefined4 *)(unaff_r11 + -8),
           *(undefined4 *)(unaff_r11 + -0x28),*(undefined4 *)(unaff_r11 + -0xc));
  }
  iVar2 = *(int *)(unaff_r11 + -8);
  iVar1 = *(int *)(unaff_r11 + -0x24);
  *(int *)(iVar1 + 0x88) = iVar2;
  *(int *)(iVar1 + 0x8c) = iVar2 >> 0x1f;
  *(undefined4 *)(*(int *)(unaff_r11 + -0x24) + 0x80) = *(undefined4 *)(unaff_r11 + -0xc);
  quicktime_write_tkhd(*(undefined4 *)(unaff_r11 + -0x20),*(undefined4 *)(unaff_r11 + -0x24));
  quicktime_write_mdia(*(undefined4 *)(unaff_r11 + -0x20),*(int *)(unaff_r11 + -0x24) + 0x70);
  quicktime_atom_write_footer(*(undefined4 *)(unaff_r11 + -0x20),unaff_r11 + -0x1c);
  return 0;
}



undefined4 FUN_00045d24(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int unaff_r11;
  
  iVar1 = *(int *)(unaff_r11 + -0x24);
  *(int *)(iVar1 + 0x88) = param_3;
  *(int *)(iVar1 + 0x8c) = param_3 >> 0x1f;
  *(undefined4 *)(*(int *)(unaff_r11 + -0x24) + 0x80) = *(undefined4 *)(unaff_r11 + -0xc);
  quicktime_write_tkhd(*(undefined4 *)(unaff_r11 + -0x20),*(undefined4 *)(unaff_r11 + -0x24));
  quicktime_write_mdia(*(undefined4 *)(unaff_r11 + -0x20),*(int *)(unaff_r11 + -0x24) + 0x70);
  quicktime_atom_write_footer(*(undefined4 *)(unaff_r11 + -0x20),unaff_r11 + -0x1c);
  return 0;
}



undefined4 FUN_00045d60(void)

{
  int unaff_r11;
  
  quicktime_atom_write_footer(*(undefined4 *)(unaff_r11 + -0x20),unaff_r11 + -0x1c);
  return 0;
}



undefined4 quicktime_write_trak_soun(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined1 auStack_20 [16];
  int local_10;
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_20,&DAT_0005b4d8);
  quicktime_trak_duration(param_2,&local_c,&local_10);
  if (local_10 == 0) {
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  else {
    MulDiv(param_2 + 0x18,local_c,param_3,local_10);
  }
  *(int *)(param_2 + 0x88) = local_c;
  *(int *)(param_2 + 0x8c) = local_c >> 0x1f;
  *(int *)(param_2 + 0x80) = local_10;
  quicktime_write_tkhd(param_1,param_2);
  quicktime_write_mdia_soun(param_1,param_2 + 0x70);
  quicktime_atom_write_footer(param_1,auStack_20);
  return 0;
}



undefined4 quicktime_chunk_of_sample(int *param_1,int *param_2,int param_3,int param_4)

{
  int extraout_r1;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_24 = 0;
  if (param_3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x13c);
    iVar3 = *(int *)(param_3 + 0x134);
    iVar4 = *(int *)(param_3 + 0x3f0);
    *(int *)(param_3 + 0x3f0) = param_4;
    if ((param_4 == 0) || (iVar4 + 1 != param_4)) {
      local_2c = 0;
    }
    else {
      local_24 = *(int *)(param_3 + 0x3ec);
      local_2c = *(int *)(iVar2 + local_24 * 0xc + 4);
    }
    if (local_2c == 0) {
      local_10 = 1;
      local_14 = 0;
      local_c = 0;
      do {
        iVar4 = *(int *)(iVar2 + local_c * 0xc);
        *param_2 = iVar4 - local_10;
        iVar5 = local_14 * *param_2;
        if (param_4 < local_18 + iVar5) break;
        local_14 = *(int *)(iVar2 + local_c * 0xc + 4);
        if (local_c < iVar3) {
          local_c = local_c + 1;
          local_18 = local_18 + iVar5;
        }
        local_10 = iVar4;
      } while (local_c < iVar3);
      if (local_14 == 0) {
        *param_2 = 1;
      }
      else {
        iVar2 = __divsi3(param_4 - local_18,local_14);
        *param_2 = iVar2 + local_10;
      }
      *param_1 = (*param_2 - local_10) * local_14 + local_18;
      *(int *)(param_3 + 0x3ec) = local_c + -1;
      *(int *)(param_3 + 1000) = *param_2;
      *(int *)(param_3 + 0x3f8) = *param_1;
      if (local_14 != 0) {
        __aeabi_idivmod(param_4 - local_18,local_14);
        *(int *)(param_3 + 0x3f4) = extraout_r1 + 1;
      }
      if (*(int *)(param_3 + 0x15c) == 0) {
        uStack_1c = *param_1;
        uStack_20 = 0;
        for (; uStack_1c < param_4; uStack_1c = uStack_1c + 1) {
          uStack_20 = *(int *)(*(int *)(param_3 + 0x168) + uStack_1c * 4) + uStack_20;
        }
      }
      else {
        uStack_1c = *param_1;
        uStack_20 = 0;
        for (; uStack_1c < param_4; uStack_1c = uStack_1c + 1) {
          uStack_20 = uStack_20 + *(int *)(param_3 + 0x15c);
        }
      }
      *(int *)(param_3 + 0x3fc) = uStack_20;
    }
    else {
      iVar4 = *(int *)(param_3 + 1000);
      iVar5 = *(int *)(param_3 + 0x3f4);
      iVar6 = *(int *)(param_3 + 0x3f8);
      if (iVar5 < local_2c) {
        *param_2 = iVar4;
        *param_1 = iVar6;
        *(int *)(param_3 + 0x3f4) = iVar5 + 1;
        if (*(int *)(param_3 + 0x15c) == 0) {
          *(int *)(param_3 + 0x3fc) =
               *(int *)(param_3 + 0x3fc) + *(int *)(*(int *)(param_3 + 0x168) + (param_4 + -1) * 4);
        }
        else {
          *(int *)(param_3 + 0x3fc) = *(int *)(param_3 + 0x3fc) + *(int *)(param_3 + 0x15c);
        }
      }
      else {
        if (local_24 < iVar3 + -1) {
          local_28 = *(int *)(iVar2 + (local_24 + 1) * 0xc);
        }
        else {
          local_28 = 0x7fffffff;
        }
        if (iVar4 + 1 < local_28) {
          *param_2 = iVar4 + 1;
          iVar6 = iVar6 + *(int *)(iVar2 + local_24 * 0xc + 4);
          *param_1 = iVar6;
          *(int *)(param_3 + 1000) = iVar4 + 1;
          *(int *)(param_3 + 0x3f8) = iVar6;
          *(undefined4 *)(param_3 + 0x3f4) = 1;
          *(undefined4 *)(param_3 + 0x3fc) = 0;
        }
        else {
          *param_2 = iVar4 + 1;
          iVar6 = iVar6 + *(int *)(iVar2 + (local_24 + 1) * 0xc + -8);
          *param_1 = iVar6;
          *(int *)(param_3 + 0x3ec) = local_24 + 1;
          *(int *)(param_3 + 1000) = iVar4 + 1;
          *(int *)(param_3 + 0x3f8) = iVar6;
          *(undefined4 *)(param_3 + 0x3f4) = 1;
          *(undefined4 *)(param_3 + 0x3fc) = 0;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 FUN_000461f8(undefined4 param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int extraout_r1;
  int unaff_r11;
  
  while( true ) {
    *param_4 = param_3;
    *(int *)(unaff_r11 + -0x4c) = *(int *)(unaff_r11 + -0x10) * **(int **)(unaff_r11 + -0x54);
    if (*(int *)(unaff_r11 + -0x5c) < *(int *)(unaff_r11 + -0x14) + *(int *)(unaff_r11 + -0x4c))
    break;
    *(undefined4 *)(unaff_r11 + -0x10) =
         *(undefined4 *)(*(int *)(unaff_r11 + -0x2c) + *(int *)(unaff_r11 + -8) * 0xc + 4);
    *(undefined4 *)(unaff_r11 + -0xc) = *(undefined4 *)(unaff_r11 + -0x48);
    if (*(int *)(unaff_r11 + -8) < *(int *)(unaff_r11 + -0x30)) {
      *(int *)(unaff_r11 + -8) = *(int *)(unaff_r11 + -8) + 1;
      *(int *)(unaff_r11 + -0x14) = *(int *)(unaff_r11 + -0x14) + *(int *)(unaff_r11 + -0x4c);
    }
    if (*(int *)(unaff_r11 + -0x30) <= *(int *)(unaff_r11 + -8)) break;
    *(undefined4 *)(unaff_r11 + -0x48) =
         *(undefined4 *)(*(int *)(unaff_r11 + -0x2c) + *(int *)(unaff_r11 + -8) * 0xc);
    param_3 = *(int *)(unaff_r11 + -0x48) - *(int *)(unaff_r11 + -0xc);
    param_4 = *(int **)(unaff_r11 + -0x54);
  }
  if (*(int *)(unaff_r11 + -0x10) == 0) {
    **(undefined4 **)(unaff_r11 + -0x54) = 1;
  }
  else {
    iVar1 = __divsi3(*(int *)(unaff_r11 + -0x5c) - *(int *)(unaff_r11 + -0x14),
                     *(undefined4 *)(unaff_r11 + -0x10));
    **(int **)(unaff_r11 + -0x54) = iVar1 + *(int *)(unaff_r11 + -0xc);
  }
  **(int **)(unaff_r11 + -0x50) =
       (**(int **)(unaff_r11 + -0x54) - *(int *)(unaff_r11 + -0xc)) * *(int *)(unaff_r11 + -0x10) +
       *(int *)(unaff_r11 + -0x14);
  *(int *)(*(int *)(unaff_r11 + -0x58) + 0x3ec) = *(int *)(unaff_r11 + -8) + -1;
  *(undefined4 *)(*(int *)(unaff_r11 + -0x58) + 1000) = **(undefined4 **)(unaff_r11 + -0x54);
  *(undefined4 *)(*(int *)(unaff_r11 + -0x58) + 0x3f8) = **(undefined4 **)(unaff_r11 + -0x50);
  if (*(int *)(unaff_r11 + -0x10) != 0) {
    __aeabi_idivmod(*(int *)(unaff_r11 + -0x5c) - *(int *)(unaff_r11 + -0x14),
                    *(undefined4 *)(unaff_r11 + -0x10));
    *(int *)(*(int *)(unaff_r11 + -0x58) + 0x3f4) = extraout_r1 + 1;
  }
  if (*(int *)(*(int *)(unaff_r11 + -0x58) + 0x15c) == 0) {
    *(undefined4 *)(unaff_r11 + -0x18) = **(undefined4 **)(unaff_r11 + -0x50);
    *(undefined4 *)(unaff_r11 + -0x1c) = 0;
    while (*(int *)(unaff_r11 + -0x18) < *(int *)(unaff_r11 + -0x5c)) {
      *(int *)(unaff_r11 + -0x1c) =
           *(int *)(*(int *)(*(int *)(unaff_r11 + -0x58) + 0x168) + *(int *)(unaff_r11 + -0x18) * 4)
           + *(int *)(unaff_r11 + -0x1c);
      *(int *)(unaff_r11 + -0x18) = *(int *)(unaff_r11 + -0x18) + 1;
    }
  }
  else {
    *(undefined4 *)(unaff_r11 + -0x18) = **(undefined4 **)(unaff_r11 + -0x50);
    *(undefined4 *)(unaff_r11 + -0x1c) = 0;
    while (*(int *)(unaff_r11 + -0x18) < *(int *)(unaff_r11 + -0x5c)) {
      *(int *)(unaff_r11 + -0x1c) =
           *(int *)(unaff_r11 + -0x1c) + *(int *)(*(int *)(unaff_r11 + -0x58) + 0x15c);
      *(int *)(unaff_r11 + -0x18) = *(int *)(unaff_r11 + -0x18) + 1;
    }
  }
  *(undefined4 *)(*(int *)(unaff_r11 + -0x58) + 0x3fc) = *(undefined4 *)(unaff_r11 + -0x1c);
  return 0;
}



undefined4 quicktime_chunk_to_offset(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
  }
  else if ((*(int *)(param_1 + 0x188) == 0) || (param_2 <= *(int *)(param_1 + 0x188))) {
    if (*(int *)(param_1 + 0x188) == 0) {
      uVar1 = 8;
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 400) + (param_2 + 0x3fffffff) * 4);
    }
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 400) + (*(int *)(param_1 + 0x188) + 0x3fffffff) * 4);
  }
  return uVar1;
}



int quicktime_sample_range_size(int param_1,int param_2,int param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0x15c) == 0) {
    local_10 = *(int *)(param_1 + 0x3fc);
  }
  else {
    local_10 = 0;
    for (local_c = param_2; local_c < param_3; local_c = local_c + 1) {
      local_10 = local_10 + *(int *)(param_1 + 0x15c);
    }
  }
  return local_10;
}



int quicktime_sample_to_offset(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = -1;
  }
  else {
    iVar1 = quicktime_chunk_to_offset(param_1,param_4);
    iVar2 = quicktime_sample_range_size(param_1,param_3,param_2);
    iVar2 = iVar2 + iVar1;
  }
  return iVar2;
}



undefined4
quicktime_update_tables_video
          (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7,int param_8,int param_9,char param_10)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x10) < param_4 + param_8) {
    *(int *)(param_1 + 0x10) = (param_4 + param_8) - *(int *)(param_1 + 0xc);
  }
  if ((param_7 == 0) &&
     (((*(char *)(param_1 + 0x175) != '\0' || (*(int *)(param_1 + 0x138) == 0)) &&
      (iVar1 = quicktime_update_stco_opt(param_3 + 0x180,param_5,param_4,param_1), iVar1 == 1)))) {
    *(undefined4 *)(param_1 + 0x168) = 5;
    uVar2 = 1;
  }
  else {
    iVar1 = quicktime_update_stsz_opt_vide(param_2,param_3 + 0x154,param_8,param_1);
    if (iVar1 == 0) {
      if ((param_7 == 0) && (param_6 != 0)) {
        if (*(char *)(param_1 + 0x175) == '\0') {
          quicktime_update_stsc(param_3 + 300,param_5 + -1,param_6);
        }
        else {
          quicktime_update_stsc_opt(param_3 + 300,param_5 + -1,param_6,param_1);
        }
      }
      if (param_9 != 0) {
        quicktime_update_stts_opt(param_3 + 0xe0,param_9,param_6,param_1);
      }
      if ((*(char *)(param_1 + 0x175) != '\0') && (param_10 != '\0')) {
        quicktime_update_stss_opt(param_3 + 0x10c,param_6,param_1);
      }
      if (*(int *)(param_1 + 0x168) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x168) = 5;
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4
quicktime_update_tables_audio
          (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  *(int *)(param_1 + 0x10) = (param_3 + param_5) - *(int *)(param_1 + 0xc);
  if ((param_7 == 0) &&
     (iVar1 = quicktime_update_stco_opt(param_2 + 0x180,param_4,param_3,param_1), iVar1 == 1)) {
    *(undefined4 *)(param_1 + 0x168) = 5;
    uVar2 = 1;
  }
  else {
    if (*(char *)(param_1 + 0x175) != '\0') {
      iVar1 = quicktime_update_stsz_opt(param_2 + 0x154,param_5,param_1);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x168) = 5;
        return 1;
      }
      if ((param_7 == 0) && (param_6 != 0)) {
        quicktime_update_stsc(param_2 + 300,param_4 + -1,param_6);
      }
    }
    if (*(int *)(param_1 + 0x168) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4 quicktime_trak_duration(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 local_c;
  
  *param_2 = 0;
  if (*(int *)(param_1 + 0xf0) == 0) {
    *param_2 = *(int *)(param_1 + 0xfc);
  }
  else {
    for (local_c = 0; local_c < *(int *)(param_1 + 0xe8); local_c = local_c + 1) {
      *param_2 = *param_2 +
                 *(int *)(*(int *)(param_1 + 0xf0) + local_c * 8) *
                 *(int *)(*(int *)(param_1 + 0xf0) + local_c * 8 + 4);
    }
  }
  *param_3 = *(undefined4 *)(param_1 + 0x80);
  return 0;
}



undefined4 quicktime_trak_fix_counts(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x3f8);
  if (*(int *)(param_2 + 0xf0) == 0) {
    quicktime_update_stts_opt(param_2 + 0xe0,0,iVar1 + 1,param_1);
  }
  else if (*(int *)(param_2 + 0xe8) == 1) {
    **(int **)(param_2 + 0xf0) = iVar1;
  }
  *(int *)(param_2 + 0x160) = iVar1;
  return 0;
}



undefined4 quicktime_udta_init(undefined4 param_1)

{
  ZeroMemory(param_1,0x18);
  return 0;
}



undefined4 quicktime_udta_delete(undefined4 param_1)

{
  quicktime_udta_init(param_1);
  return 0;
}



undefined4 quicktime_parse_tag(int param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  char acStack_458 [32];
  undefined1 auStack_438 [1024];
  undefined1 auStack_38 [8];
  uint local_30;
  ushort local_26;
  undefined2 local_24;
  ushort local_22;
  uint local_20;
  char *local_1c;
  undefined2 *local_18;
  int *local_14;
  
  local_20 = 0;
  local_14 = (int *)0x0;
  local_18 = (undefined2 *)0x0;
  while( true ) {
    quicktime_atom_read_header(param_1,auStack_38);
    iVar1 = quicktime_atom_is(auStack_38,&DAT_0005baf4);
    if ((iVar1 == 0) || (local_30 < 0x12)) {
      iVar1 = quicktime_atom_is(auStack_38,&DAT_0005bb50);
      if (iVar1 != 0) {
        quicktime_read_char(param_1);
        quicktime_read_int24(param_1);
      }
    }
    else {
      quicktime_read_char(param_1);
      quicktime_read_int24(param_1);
      quicktime_read_int32(param_1);
      iVar1 = quicktime_atom_is(param_2,&DAT_0005bafc);
      if ((iVar1 == 0) && (iVar1 = quicktime_atom_is(param_2,&DAT_0005bb04), iVar1 == 0)) {
        iVar1 = quicktime_atom_is(param_2,&DAT_0005bb0c);
        if ((iVar1 == 0) && (iVar1 = quicktime_atom_is(param_2,&DAT_0005bb14), iVar1 == 0)) {
          iVar1 = quicktime_atom_is(param_2,&DAT_0005bb20);
          if (iVar1 == 0) {
            iVar1 = quicktime_atom_is(param_2,&DAT_0005bb28);
            if (iVar1 == 0) {
              iVar1 = quicktime_atom_is(param_2,&DAT_0005bb30);
              if (iVar1 == 0) {
                iVar1 = quicktime_atom_is(param_2,&DAT_0005bb38);
                if (iVar1 == 0) {
                  iVar1 = quicktime_atom_is(param_2,&DAT_0005bb40);
                  if (iVar1 == 0) {
                    iVar1 = quicktime_atom_is(param_2,&DAT_0005bb48);
                    if (iVar1 != 0) {
                      local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x30);
                      local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0x14);
                    }
                  }
                  else {
                    local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x2c);
                    local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0x12);
                  }
                }
                else {
                  local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x28);
                  local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0x10);
                }
              }
              else {
                local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x24);
                local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0xe);
              }
            }
            else {
              local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x20);
              local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0xc);
            }
          }
          else {
            local_14 = (int *)(*(int *)(param_1 + 0x180) + 0x34);
            local_18 = (undefined2 *)(*(int *)(param_1 + 0x180) + 0x16);
          }
        }
        else {
          quicktime_read_int16(param_1);
          local_22 = quicktime_read_int16(param_1);
          local_24 = quicktime_read_int16(param_1);
          quicktime_read_int16(param_1);
          sprintf(acStack_458,"%d",(uint)local_22);
          iVar1 = quicktime_atom_is(param_2,&DAT_0005bb0c);
          if ((iVar1 != 0) && (*(int *)(*(int *)(param_1 + 0x180) + 0x38) == 0)) {
            iVar1 = *(int *)(param_1 + 0x180);
            sVar2 = strlen(acStack_458);
            *(short *)(iVar1 + 0x18) = (short)(((sVar2 & 0xffff) + 1) * 0x10000 >> 0x10);
            iVar1 = *(int *)(param_1 + 0x180);
            uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                              (*(undefined2 *)(*(int *)(param_1 + 0x180) + 0x18));
            *(undefined4 *)(iVar1 + 0x38) = uVar3;
            if (*(int *)(*(int *)(param_1 + 0x180) + 0x38) == 0) {
              *(undefined2 *)(*(int *)(param_1 + 0x180) + 0x18) = 0;
            }
            else {
              memset(*(void **)(*(int *)(param_1 + 0x180) + 0x38),0,
                     (uint)*(ushort *)(*(int *)(param_1 + 0x180) + 0x18));
              memcpy(*(void **)(*(int *)(param_1 + 0x180) + 0x38),acStack_458,
                     (uint)*(ushort *)(*(int *)(param_1 + 0x180) + 0x18));
              *(undefined1 *)(*(int *)(param_1 + 0x180) + 7) = 1;
            }
          }
        }
      }
      else {
        local_26 = quicktime_read_int16(param_1);
        iVar1 = quicktime_atom_is(param_2,&DAT_0005bb04);
        if (iVar1 == 0) {
          local_1c = (char *)0x0;
          if ((local_26 != 0) && (local_26 < 0x95)) {
            local_1c = (&g_sID3v1GenreList)[local_26 - 1];
          }
          if ((local_1c != (char *)0x0) && (*(int *)(*(int *)(param_1 + 0x180) + 0x34) == 0)) {
            iVar1 = *(int *)(param_1 + 0x180);
            sVar2 = strlen(local_1c);
            *(short *)(iVar1 + 0x16) = (short)(((sVar2 & 0xffff) + 1) * 0x10000 >> 0x10);
            iVar1 = *(int *)(param_1 + 0x180);
            uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))
                              (*(undefined2 *)(*(int *)(param_1 + 0x180) + 0x16));
            *(undefined4 *)(iVar1 + 0x34) = uVar3;
            if (*(int *)(*(int *)(param_1 + 0x180) + 0x34) == 0) {
              *(undefined2 *)(*(int *)(param_1 + 0x180) + 0x16) = 0;
            }
            else {
              memset(*(void **)(*(int *)(param_1 + 0x180) + 0x34),0,
                     (uint)*(ushort *)(*(int *)(param_1 + 0x180) + 0x16));
              memcpy(*(void **)(*(int *)(param_1 + 0x180) + 0x34),local_1c,
                     (uint)*(ushort *)(*(int *)(param_1 + 0x180) + 0x16));
              *(undefined1 *)(*(int *)(param_1 + 0x180) + 6) = 1;
            }
          }
        }
      }
      if (local_14 != (int *)0x0) {
        if ((*local_14 == 0) && (local_20 = local_30 - 0xf, local_20 < 0x400)) {
          memset(auStack_438,0,local_20);
          quicktime_read_data(param_1,auStack_438,local_20 - 1);
          local_20 = ConvertUTF82Unicode(auStack_438,0);
          if (1 < local_20) {
            local_20 = local_20 << 1;
            *local_18 = (short)local_20;
            iVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(local_20);
            *local_14 = iVar1;
            if (*local_14 != 0) {
              ConvertUTF82Unicode(auStack_438,*local_14);
            }
          }
        }
        local_14 = (int *)0x0;
      }
    }
    quicktime_atom_skip(param_1,auStack_38);
    if (*(int *)(param_1 + 0x16c) != 0) break;
    uVar4 = quicktime_position(param_1);
    if (*(uint *)(param_2 + 4) <= uVar4) {
      return 0;
    }
  }
  return 1;
}



undefined4 quicktime_read_meta(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  do {
    iVar1 = quicktime_atom_read_header(param_1,auStack_18);
    if (iVar1 == 1) {
      return 1;
    }
    quicktime_parse_tag(param_1,auStack_18);
    uVar2 = quicktime_position(param_1);
  } while (uVar2 < *(uint *)(param_2 + 4));
  return 0;
}



undefined4 quicktime_read_udta(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [8];
  undefined1 auStack_24 [4];
  uint local_20;
  int local_14;
  
  do {
    iVar4 = *(int *)(param_3 + 4);
    iVar1 = quicktime_position(param_1);
    if ((uint)(iVar4 - iVar1) < 8) {
      iVar1 = *(int *)(param_3 + 4);
      local_14 = quicktime_position(param_1);
      local_14 = iVar1 - local_14;
      quicktime_read_data(param_1,auStack_2c,local_14);
      return 0;
    }
    quicktime_atom_read_header(param_1,auStack_24);
    iVar1 = quicktime_atom_is(auStack_24,&DAT_0005bb58);
    if (iVar1 == 0) {
      quicktime_atom_skip(param_1,auStack_24);
    }
    else {
      quicktime_read_char(param_1);
      quicktime_read_int24(param_1);
      do {
        quicktime_atom_read_header(param_1,auStack_3c);
        iVar1 = quicktime_atom_is(auStack_3c,&DAT_0005bb60);
        if (iVar1 == 0) {
          quicktime_atom_skip(param_1,auStack_3c);
        }
        else if (*(int *)(param_1 + 0x180) == 0) {
          uVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(0x40);
          *(undefined4 *)(param_1 + 0x180) = uVar2;
          if (*(int *)(param_1 + 0x180) == 0) {
            quicktime_atom_skip(param_1,auStack_3c);
          }
          else {
            ZeroMemory(*(undefined4 *)(param_1 + 0x180),0x40);
            iVar1 = quicktime_read_meta(param_1,auStack_3c);
            if (iVar1 == 1) {
              return 1;
            }
          }
        }
        else {
          iVar1 = quicktime_read_meta(param_1,auStack_3c);
          if (iVar1 == 1) {
            return 1;
          }
        }
        uVar3 = quicktime_position(param_1);
      } while (uVar3 < local_20);
    }
    uVar3 = quicktime_position(param_1);
  } while (uVar3 < *(uint *)(param_3 + 4));
  return 0;
}



undefined4 quicktime_read_data(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x148));
  uVar1 = MediaFile_Read(*(undefined4 *)(param_1 + 4),param_2,param_3);
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x10);
  *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + param_3;
  return uVar1;
}



undefined4 quicktime_write_data(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  MediaFile_SetPosition(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x148));
  uVar1 = MediaFile_Write(*(undefined4 *)(param_1 + 4),param_2,param_3);
  *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + param_3;
  return uVar1;
}



undefined4 quicktime_write_pascal(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  undefined1 local_9;
  
  sVar1 = strlen(param_2);
  local_9 = (undefined1)sVar1;
  quicktime_write_data(param_1,&local_9,1);
  quicktime_write_data(param_1,param_2,local_9);
  return 0;
}



int quicktime_read_fixed32(undefined4 param_1)

{
  byte local_1c;
  byte local_1b;
  
  quicktime_read_data(param_1,&local_1c,4);
  return (uint)local_1c * 0x100 + (uint)local_1b;
}



undefined4 quicktime_write_fixed32(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_14 = (undefined1)((uint)param_2 >> 8);
  local_13 = (undefined1)param_2;
  local_12 = 0;
  local_11 = 0;
  local_c = param_2;
  uVar1 = quicktime_write_data(param_1,&local_14,4);
  return uVar1;
}



undefined4 quicktime_write_int64(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint local_20;
  undefined1 auStack_14 [8];
  int local_c;
  
  local_20 = param_2;
  for (local_c = 7; -1 < local_c; local_c = local_c + -1) {
    auStack_14[local_c] = (char)local_20;
    local_20 = local_20 >> 8;
  }
  uVar1 = quicktime_write_data(param_1,auStack_14,8);
  return uVar1;
}



undefined4 quicktime_write_int32(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  local_c = (undefined1)((uint)param_2 >> 0x18);
  local_b = (undefined1)((uint)param_2 >> 0x10);
  local_a = (undefined1)((uint)param_2 >> 8);
  local_9 = (undefined1)param_2;
  uVar1 = quicktime_write_data(param_1,&local_c,4);
  return uVar1;
}



undefined4 quicktime_write_char32(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = quicktime_write_data(param_1,param_2,4);
  return uVar1;
}



undefined1 quicktime_read_fixed16(undefined4 param_1)

{
  undefined1 local_c [4];
  
  quicktime_read_data(param_1,local_c,2);
  return local_c[0];
}



undefined4 quicktime_write_fixed16(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_14 = (undefined1)param_2;
  local_13 = 0;
  local_c = param_2;
  uVar1 = quicktime_write_data(param_1,&local_14,2);
  return uVar1;
}



uint quicktime_read_int32(undefined4 param_1)

{
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  
  quicktime_read_data(param_1,&local_20,4);
  return (uint)local_20 << 0x18 | (uint)local_1f << 0x10 | (uint)local_1e << 8 | (uint)local_1d;
}



uint quicktime_read_int24(undefined4 param_1)

{
  byte local_1c;
  byte local_1b;
  byte local_1a;
  
  quicktime_read_data(param_1,&local_1c,3);
  return (uint)local_1c << 0x10 | (uint)local_1b << 8 | (uint)local_1a;
}



undefined4 quicktime_write_int24(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  
  local_c = (undefined1)((uint)param_2 >> 0x10);
  local_b = (undefined1)((uint)param_2 >> 8);
  local_a = (undefined1)param_2;
  uVar1 = quicktime_write_data(param_1,&local_c,3);
  return uVar1;
}



uint quicktime_read_int16(undefined4 param_1)

{
  byte local_10;
  byte local_f;
  
  quicktime_read_data(param_1,&local_10,2);
  return ((uint)local_10 << 0x18) >> 0x10 | (uint)local_f;
}



undefined4 quicktime_write_int16(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_c;
  undefined1 local_b;
  
  local_c = (undefined1)((uint)param_2 >> 8);
  local_b = (undefined1)param_2;
  uVar1 = quicktime_write_data(param_1,&local_c,2);
  return uVar1;
}



undefined1 quicktime_read_char(undefined4 param_1)

{
  undefined1 local_9;
  
  quicktime_read_data(param_1,&local_9,1);
  return local_9;
}



undefined4 quicktime_write_char(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  undefined1 local_d;
  undefined4 local_c;
  
  local_d = param_2;
  local_c = param_1;
  uVar1 = quicktime_write_data(param_1,&local_d,1);
  return uVar1;
}



undefined4 quicktime_read_char32(undefined4 param_1,undefined4 param_2)

{
  quicktime_read_data(param_1,param_2,4);
  return 0;
}



undefined4 quicktime_position(int param_1)

{
  return *(undefined4 *)(param_1 + 0x148);
}



undefined4 quicktime_set_position(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x148) = param_2;
  return 0;
}



undefined4 quicktime_seek_position(undefined4 *param_1,undefined4 param_2)

{
  param_1[0x52] = param_2;
  (**(code **)(param_1[0x5c] + 0xc))(*param_1,param_2,0);
  return 0;
}



undefined4 quicktime_skip_data(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_1[0x5c] + 0x10))(*param_1);
  if (iVar1 != param_1[0x52]) {
    (**(code **)(param_1[0x5c] + 0xc))(*param_1,param_1[0x52],0);
  }
  uVar2 = (**(code **)(param_1[0x5c] + 0xc))(*param_1,param_2,1);
  param_1[0x52] = param_1[0x52] + param_2;
  return uVar2;
}



undefined4 quicktime_copy_char32(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return 0;
}



undefined4 quicktime_current_time(void)

{
  return 0x7c25b080;
}



undefined4 quicktime_match_32(char *param_1,char *param_2)

{
  undefined4 uVar1;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint quicktime_read_mp4_descr_length(undefined4 param_1)

{
  byte bVar1;
  undefined4 local_10;
  undefined1 local_9;
  
  local_9 = 0;
  local_10 = 0;
  do {
    bVar1 = quicktime_read_char(param_1);
    local_9 = local_9 + 1;
    local_10 = local_10 << 7 | bVar1 & 0x7f;
    if (-1 < (char)bVar1) {
      return local_10;
    }
  } while (local_9 < 4);
  return local_10;
}



char quicktime_write_mp4_descr_length(undefined4 param_1,int param_2,char param_3)

{
  char local_d;
  short local_c;
  byte local_9;
  
  if (param_3 == '\0') {
    local_d = '\x04';
  }
  else if (param_2 < 0x80) {
    local_d = '\x01';
  }
  else if (param_2 < 0x4000) {
    local_d = '\x02';
  }
  else if (param_2 < 0x200000) {
    local_d = '\x03';
  }
  else {
    local_d = '\x04';
  }
  local_c = (short)local_d;
  while (local_c = local_c + -1, -1 < local_c) {
    local_9 = (byte)(param_2 >> (local_c * 7 & 0xffU)) & 0x7f;
    if (local_c != 0) {
      local_9 = ~((byte)~(byte)(((uint)local_9 << 0x19) >> 0x18) >> 1);
    }
    quicktime_write_char(param_1,local_9);
  }
  return local_d;
}



undefined4 MEML_InitNode(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



bool MEML_AllocMemBlock(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint local_c;
  
  local_c = 0xb;
  do {
    if ((int)local_c < 1) {
LAB_00048184:
      return local_c == 0;
    }
    iVar1 = (**(code **)(*(int *)(param_3 + 0x170) + 0x14))(param_2 << (local_c & 0xff));
    if (iVar1 != 0) {
      *param_1 = iVar1;
      param_1[3] = 1 << (local_c & 0xff);
      goto LAB_00048184;
    }
    local_c = local_c - 1;
  } while( true );
}



undefined4 MEML_LinkIsFull(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1[1] + 0xc) == *(int *)(param_1[1] + 8) + 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



bool MEML_AddNewNode(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(0x14);
    *param_1 = iVar1;
    if (param_1 == (int *)0x0) {
      return true;
    }
    MEML_InitNode(*param_1);
    param_1[1] = *param_1;
  }
  else if (*(int *)(param_1[1] + 0x10) == 0) {
    iVar1 = param_1[1];
    uVar2 = (**(code **)(*(int *)(param_2 + 0x170) + 0x14))(0x14);
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    if (param_1 == (int *)0x0) {
      return true;
    }
    param_1[1] = *(int *)(param_1[1] + 0x10);
    MEML_InitNode(param_1[1]);
  }
  iVar1 = MEML_AllocMemBlock(param_1[1],1 << (param_1[2] & 0xffU),param_2);
  return iVar1 == 1;
}



bool MEML_AddElement(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  bVar2 = *(int *)(*(int *)(param_1 + 4) + 4) == 0;
  if (bVar2) {
    memcpy((void *)(**(int **)(param_1 + 4) +
                   (*(int *)(iVar1 + 8) << (*(uint *)(param_1 + 8) & 0xff))),param_2,
           1 << (*(uint *)(param_1 + 8) & 0xff));
  }
  return !bVar2;
}



undefined4 MEML_GetElement(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  memcpy(param_2,(void *)(**(int **)(param_1 + 4) + (iVar1 << (*(uint *)(param_1 + 8) & 0xff))),
         1 << (*(uint *)(param_1 + 8) & 0xff));
  if (*(int *)(*(int *)(param_1 + 4) + 0x10) == 0) {
    if (*(int *)(*(int *)(param_1 + 4) + 8) == iVar1) {
      *(undefined4 *)(*(int *)(param_1 + 4) + 4) = 0;
    }
    else {
      *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(*(int *)(param_1 + 4) + 4) + 1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
    if (*(int *)(*(int *)(param_1 + 4) + 0xc) == *(int *)(iVar1 + 4)) {
      *(undefined4 *)(*(int *)(param_1 + 4) + 4) = 0;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(param_1 + 4) + 0x10);
    }
  }
  return 0;
}



undefined4 MEML_Destroy(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    while (*(int *)(*param_1 + 0x10) != 0) {
      (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)*param_1);
      iVar1 = *(int *)(*param_1 + 0x10);
      (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*param_1);
      *param_1 = iVar1;
    }
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*(undefined4 *)*param_1);
    (**(code **)(*(int *)(param_2 + 0x170) + 0x18))(*param_1);
  }
  return 0;
}



undefined4 MEML_StoreElement(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = MEML_LinkIsFull(param_1);
  if (iVar1 == 1) {
    iVar1 = MEML_AddNewNode(param_1,param_3);
    if (iVar1 == 1) {
      *(undefined4 *)(param_3 + 0x168) = 5;
      return 1;
    }
    MEML_AddElement(param_1,param_2);
  }
  else {
    MEML_AddElement(param_1,param_2);
  }
  return 0;
}



undefined4 quicktime_vmhd_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 0x40;
  param_1[3] = 0x8000;
  param_1[4] = 0x8000;
  param_1[5] = 0x8000;
  return 0;
}



undefined4 quicktime_vmhd_init_video(void)

{
  return 0;
}



undefined4 quicktime_vmhd_delete(void)

{
  return 0;
}



undefined4 quicktime_write_vmhd(int param_1,uint *param_2)

{
  undefined1 auStack_1c [16];
  int local_c;
  
  quicktime_atom_write_header(param_1,auStack_1c,&DAT_0005bb68);
  quicktime_write_char(param_1,*param_2 & 0xff);
  quicktime_write_int24(param_1,param_2[1]);
  if (*(int *)(param_1 + 0x134) == 0) {
    quicktime_write_int16(param_1,param_2[2]);
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      quicktime_write_int16(param_1,param_2[local_c + 3]);
    }
  }
  else {
    quicktime_write_int64(param_1,0);
  }
  quicktime_atom_write_footer(param_1,auStack_1c);
  return 0;
}



undefined8 get_bits64(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Bitstream_ReadBits(param_1,param_2 + -0x20,0);
  uVar2 = Bitstream_ReadBits(param_1,0x20,0);
  return CONCAT44(uVar1,uVar2);
}



void hvcc_update_ptl(int param_1,undefined1 *param_2)

{
  byte bVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 1) = *param_2;
  if (*(byte *)(param_1 + 2) < (byte)param_2[1]) {
    *(undefined1 *)(param_1 + 0x10) = param_2[0x10];
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x10);
    if (*(byte *)(param_1 + 0x10) <= (byte)param_2[0x10]) {
      bVar1 = param_2[0x10];
    }
    *(byte *)(param_1 + 0x10) = bVar1;
  }
  bVar1 = *(byte *)(param_1 + 2);
  if (*(byte *)(param_1 + 2) <= (byte)param_2[1]) {
    bVar1 = param_2[1];
  }
  *(byte *)(param_1 + 2) = bVar1;
  bVar1 = *(byte *)(param_1 + 3);
  if (*(byte *)(param_1 + 3) <= (byte)param_2[2]) {
    bVar1 = param_2[2];
  }
  *(byte *)(param_1 + 3) = bVar1;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & *(uint *)(param_2 + 4);
  uVar2 = *(uint *)(param_2 + 0xc);
  *(uint *)(param_1 + 8) = *(uint *)(param_2 + 8) & *(uint *)(param_1 + 8);
  *(uint *)(param_1 + 0xc) = uVar2 & *(uint *)(param_1 + 0xc);
  return;
}



void hvcc_parse_ptl(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  char acStack_38 [8];
  char acStack_30 [8];
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined4 local_24;
  undefined8 local_20;
  undefined1 local_18;
  uint local_c;
  
  local_28 = Bitstream_ReadBits(param_1,2,0);
  local_27 = Bitstream_ReadBits(param_1,1,0);
  local_26 = Bitstream_ReadBits(param_1,5,0);
  local_24 = Bitstream_ReadBits(param_1,0x20,0);
  local_20 = get_bits64(param_1,0x30);
  local_18 = Bitstream_ReadBits(param_1,8,0);
  hvcc_update_ptl(param_2,&local_28);
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    cVar1 = Bitstream_ReadBits(param_1,1,0);
    acStack_30[local_c] = cVar1;
    cVar1 = Bitstream_ReadBits(param_1,1,0);
    acStack_38[local_c] = cVar1;
  }
  local_c = param_3;
  if (param_3 != 0) {
    for (; local_c < 8; local_c = local_c + 1) {
      Bitstream_ReadBits(param_1,2,0);
    }
  }
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    if (acStack_30[local_c] != '\0') {
      Bitstream_ReadBits(param_1,0x20,0);
      Bitstream_ReadBits(param_1,0x20,0);
      Bitstream_ReadBits(param_1,0x18,0);
    }
    if (acStack_38[local_c] != '\0') {
      Bitstream_ReadBits(param_1,8,0);
    }
  }
  return;
}



void skip_sub_layer_hrd_parameters(undefined4 param_1,uint param_2,char param_3)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c <= param_2; local_c = local_c + 1) {
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    if (param_3 != '\0') {
      Bitstream_ReadBits(param_1,0x20,0);
      Bitstream_ReadBits(param_1,0x20,0);
    }
    Bitstream_ReadBits(param_1,1,0);
  }
  return;
}



undefined4 skip_hrd_parameters(undefined4 param_1,char param_2,uint param_3)

{
  char cVar1;
  char local_16;
  char local_15;
  uint local_14;
  char local_f;
  char local_e;
  char local_d;
  uint local_c;
  
  local_d = '\0';
  local_e = '\0';
  local_f = '\0';
  if (param_2 != '\0') {
    local_e = Bitstream_ReadBits(param_1,1,0);
    local_f = Bitstream_ReadBits(param_1,1,0);
    if ((local_e != '\0') || (local_f != '\0')) {
      local_d = Bitstream_ReadBits(param_1,1,0);
      if (local_d != '\0') {
        Bitstream_ReadBits(param_1,0x13,0);
      }
      Bitstream_ReadBits(param_1,8,0);
      if (local_d != '\0') {
        Bitstream_ReadBits(param_1,4,0);
      }
      Bitstream_ReadBits(param_1,0xf,0);
    }
  }
  local_c = 0;
  while( true ) {
    if (param_3 < local_c) {
      return 0;
    }
    local_14 = 0;
    local_15 = '\0';
    local_16 = '\0';
    cVar1 = Bitstream_ReadBits(param_1,1,0);
    if (cVar1 == '\0') {
      local_16 = Bitstream_ReadBits(param_1,1,0);
    }
    if (local_16 == '\0') {
      local_15 = Bitstream_ReadBits(param_1,1,0);
    }
    else {
      Bitstream_ReadBits(param_1,0x20,0);
    }
    if ((local_15 == '\0') && (local_14 = Bitstream_ReadBits(param_1,0x20,0), 0x1f < local_14))
    break;
    if (local_e != '\0') {
      skip_sub_layer_hrd_parameters(param_1,local_14,local_d);
    }
    if (local_f != '\0') {
      skip_sub_layer_hrd_parameters(param_1,local_14,local_d);
    }
    local_c = local_c + 1;
  }
  return 0xffffffff;
}



void skip_timing_info(undefined4 param_1)

{
  int iVar1;
  
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,0x20,0);
  }
  return;
}



void hvcc_parse_vui(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if ((iVar1 != 0) && (iVar1 = Bitstream_ReadBits(param_1,8,0), iVar1 == 0xff)) {
    Bitstream_ReadBits(param_1,0x20,0);
  }
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,1,0);
  }
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,4,0);
    iVar1 = Bitstream_ReadBits(param_1,1,0);
    if (iVar1 != 0) {
      Bitstream_ReadBits(param_1,0x18,0);
    }
  }
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
  }
  Bitstream_ReadBits(param_1,3,0);
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
  }
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    skip_timing_info(param_1);
    iVar1 = Bitstream_ReadBits(param_1,1,0);
    if (iVar1 != 0) {
      skip_hrd_parameters(param_1,1,param_3);
    }
  }
  iVar1 = Bitstream_ReadBits(param_1,1,0);
  if (iVar1 != 0) {
    Bitstream_ReadBits(param_1,3,0);
    uVar2 = Bitstream_ReadBits(param_1,0x20,0);
    if (*(ushort *)(param_2 + 0x12) < uVar2) {
      uVar2 = (uint)*(ushort *)(param_2 + 0x12);
    }
    *(short *)(param_2 + 0x12) = (short)uVar2;
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
  }
  return;
}



void skip_sub_layer_ordering_info(undefined4 param_1)

{
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  return;
}



undefined4 hvcc_parse_vps(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  Bitstream_ReadBits(param_1,0xc,0);
  iVar1 = Bitstream_ReadBits(param_1,3,0);
  uVar2 = (uint)*(byte *)(param_2 + 0x1b);
  if ((uint)*(byte *)(param_2 + 0x1b) <= iVar1 + 1U) {
    uVar2 = iVar1 + 1U;
  }
  *(char *)(param_2 + 0x1b) = (char)uVar2;
  Bitstream_ReadBits(param_1,0x11,0);
  hvcc_parse_ptl(param_1,param_2,iVar1);
  return 0;
}



void skip_scaling_list_data(undefined4 param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    local_10 = 0;
    while( true ) {
      if (local_c == 3) {
        iVar1 = 2;
      }
      else {
        iVar1 = 6;
      }
      if (iVar1 <= local_10) break;
      iVar1 = Bitstream_ReadBits(param_1,1,0);
      if (iVar1 == 0) {
        Bitstream_ReadBits(param_1,0x20,0);
      }
      else {
        iVar1 = 1 << (local_c * 2 + 4U & 0xff);
        if (0x3f < iVar1) {
          iVar1 = 0x40;
        }
        if (1 < local_c) {
          Bitstream_ReadBits(param_1,0x20,0);
        }
        for (local_14 = 0; local_14 < iVar1; local_14 = local_14 + 1) {
          Bitstream_ReadBits(param_1,0x20,0);
        }
      }
      local_10 = local_10 + 1;
    }
  }
  return;
}



undefined4 parse_rps(int param_1,uint param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint local_1c;
  
  if ((param_2 == 0) || (iVar2 = Bitstream_ReadBits(param_1,1,0), iVar2 == 0)) {
    uVar3 = Bitstream_ReadBits(param_1,0x20,0);
    uVar4 = Bitstream_ReadBits(param_1,0x20,0);
    uVar5 = uVar3 + uVar4;
    iVar7 = *(int *)(param_1 + 0x18);
    iVar2 = Bitstream_UsedBits(param_1);
    if ((char)(CARRY4(uVar3,uVar4) * '\x02' + CARRY4(uVar5,uVar5)) != '\0' ||
        (uint)(iVar7 * 8 - iVar2) < uVar5 * 2) {
      return 0xffffffff;
    }
    *(uint *)(param_4 + param_2 * 4) = uVar3 + uVar4;
    for (local_1c = 0; local_1c < uVar3; local_1c = local_1c + 1) {
      Bitstream_ReadBits(param_1,0x20,0);
      Bitstream_ReadBits(param_1,1,0);
    }
    for (local_1c = 0; local_1c < uVar4; local_1c = local_1c + 1) {
      Bitstream_ReadBits(param_1,0x20,0);
      Bitstream_ReadBits(param_1,1,0);
    }
  }
  else {
    if (param_3 <= param_2) {
      return 0xffffffff;
    }
    Bitstream_ReadBits(param_1,1,0);
    Bitstream_ReadBits(param_1,0x20,0);
    *(undefined4 *)(param_4 + param_2 * 4) = 0;
    for (local_1c = 0; local_1c <= *(uint *)(param_4 + (param_2 + 0x3fffffff) * 4);
        local_1c = local_1c + 1) {
      cVar1 = Bitstream_ReadBits(param_1,1,0);
      if ((cVar1 != '\0') || (cVar1 = Bitstream_ReadBits(param_1,1,0), cVar1 != '\0')) {
        piVar6 = (int *)(param_4 + param_2 * 4);
        *piVar6 = *piVar6 + 1;
      }
    }
  }
  return 0;
}



int hvcc_parse_sps(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_124 [256];
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  Bitstream_ReadBits(param_1,4,0);
  local_10 = Bitstream_ReadBits(param_1,3,0);
  uVar3 = (uint)*(byte *)(param_2 + 0x1b);
  if ((uint)*(byte *)(param_2 + 0x1b) <= local_10 + 1) {
    uVar3 = local_10 + 1;
  }
  *(char *)(param_2 + 0x1b) = (char)uVar3;
  uVar1 = Bitstream_ReadBits(param_1,1,0);
  *(undefined1 *)(param_2 + 0x1c) = uVar1;
  hvcc_parse_ptl(param_1,param_2,local_10);
  Bitstream_ReadBits(param_1,0x20,0);
  uVar1 = Bitstream_ReadBits(param_1,0x20,0);
  *(undefined1 *)(param_2 + 0x15) = uVar1;
  if (*(char *)(param_2 + 0x15) == '\x03') {
    Bitstream_ReadBits(param_1,1,0);
  }
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  iVar2 = Bitstream_ReadBits(param_1,1,0);
  if (iVar2 != 0) {
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
  }
  uVar1 = Bitstream_ReadBits(param_1,0x20,0);
  *(undefined1 *)(param_2 + 0x16) = uVar1;
  uVar1 = Bitstream_ReadBits(param_1,0x20,0);
  *(undefined1 *)(param_2 + 0x17) = uVar1;
  local_14 = Bitstream_ReadBits(param_1,0x20,0);
  iVar2 = Bitstream_ReadBits(param_1,1,0);
  local_c = local_10;
  if (iVar2 != 0) {
    local_c = 0;
  }
  for (; local_c <= local_10; local_c = local_c + 1) {
    skip_sub_layer_ordering_info(param_1);
  }
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  iVar2 = Bitstream_ReadBits(param_1,1,0);
  if ((iVar2 != 0) && (iVar2 = Bitstream_ReadBits(param_1,1,0), iVar2 != 0)) {
    skip_scaling_list_data(param_1);
  }
  Bitstream_ReadBits(param_1,1,0);
  Bitstream_ReadBits(param_1,1,0);
  iVar2 = Bitstream_ReadBits(param_1,1,0);
  if (iVar2 != 0) {
    Bitstream_ReadBits(param_1,4,0);
    Bitstream_ReadBits(param_1,4,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,0x20,0);
    Bitstream_ReadBits(param_1,1,0);
  }
  local_18 = Bitstream_ReadBits(param_1,0x20,0);
  if (local_18 < 0x41) {
    for (local_c = 0; local_c < local_18; local_c = local_c + 1) {
      local_1c = parse_rps(param_1,local_c,local_18,auStack_124);
      if (local_1c < 0) {
        return local_1c;
      }
    }
    iVar2 = Bitstream_ReadBits(param_1,1,0);
    if (iVar2 != 0) {
      local_20 = Bitstream_ReadBits(param_1,0x20,0);
      if (0x1f < local_20) {
        return -1;
      }
      for (local_c = 0; local_c < local_20; local_c = local_c + 1) {
        local_24 = local_14 + 4;
        if (0xf < local_24) {
          local_24 = 0x10;
        }
        Bitstream_ReadBits(param_1,local_24,0);
        Bitstream_ReadBits(param_1,1,0);
      }
    }
    Bitstream_ReadBits(param_1,1,0);
    Bitstream_ReadBits(param_1,1,0);
    iVar2 = Bitstream_ReadBits(param_1,1,0);
    if (iVar2 != 0) {
      hvcc_parse_vui(param_1,param_2,local_10);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



undefined4 hvcc_parse_pps(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,7,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,2,0);
  iVar3 = Bitstream_ReadBits(param_1,1,0);
  if (iVar3 != 0) {
    Bitstream_ReadBits(param_1,0x20,0);
  }
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,0x20,0);
  Bitstream_ReadBits(param_1,4,0);
  cVar1 = Bitstream_ReadBits(param_1,1,0);
  cVar2 = Bitstream_ReadBits(param_1,1,0);
  if ((cVar2 == '\0') || (cVar1 == '\0')) {
    if (cVar2 == '\0') {
      if (cVar1 == '\0') {
        *(undefined1 *)(param_2 + 0x14) = 1;
      }
      else {
        *(undefined1 *)(param_2 + 0x14) = 2;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x14) = 3;
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  return 0;
}



undefined4
hvcc_array_add_nal_unit
          (int param_1,undefined4 param_2,undefined2 param_3,char param_4,undefined1 param_5,
          int param_6)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  byte local_9;
  
  local_9 = 0;
  while ((local_9 < *(byte *)(param_6 + 0x1e) &&
         (param_4 != *(char *)(*(int *)(param_6 + 0x20) + (uint)local_9 * 0xc + 1)))) {
    local_9 = local_9 + 1;
  }
  if (local_9 < *(byte *)(param_6 + 0x1e)) {
    puVar3 = (undefined1 *)(*(int *)(param_6 + 0x20) + (uint)local_9 * 0xc);
    uVar1 = *(ushort *)(puVar3 + 2);
    if (uVar1 < 2) {
      *(undefined4 *)(*(int *)(puVar3 + 8) + (uint)uVar1 * 4) = param_2;
      *(undefined2 *)(*(int *)(puVar3 + 4) + (uint)uVar1 * 2) = param_3;
      puVar3[1] = param_4;
      *(short *)(puVar3 + 2) = *(short *)(puVar3 + 2) + 1;
      if (((param_4 == ' ') || (param_4 == '!')) || (param_4 == '\"')) {
        *puVar3 = param_5;
      }
      uVar2 = 0;
    }
    else {
      (*(code *)**(undefined4 **)(param_1 + 0x170))("## error numNalus: %d, %d\n",uVar1,1);
      uVar2 = 0xfffffffe;
    }
  }
  else {
    (*(code *)**(undefined4 **)(param_1 + 0x170))
              ("## error array index: %d, %d\n",local_9,*(undefined1 *)(param_6 + 0x1e));
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}



undefined4
hvcc_add_nal_unit(int param_1,byte *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_50 [31];
  char local_31;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte *local_c;
  
  local_10 = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_2c = 0;
  local_30 = (uint)*(byte *)(param_1 + 0x17c);
  local_c = param_2;
  do {
    local_c = local_c + local_10;
    if (param_2 + param_3 <= local_c) {
      return 0xffffffff;
    }
    if (local_30 == 3) {
      local_10 = (uint)*local_c * 0x10000 + (uint)local_c[1] * 0x100 + (uint)local_c[2];
    }
    else {
      if (local_30 != 4) {
        return 0xffffffff;
      }
      local_10 = mov_str2ulong(local_c);
    }
    local_c = local_c + local_30;
    Bitstream_Init(auStack_50,local_c,0,local_10);
    Bitstream_ReadBits(auStack_50,1,0);
    local_31 = Bitstream_ReadBits(auStack_50,6,0);
    Bitstream_ReadBits(auStack_50,9,0);
    switch(local_31) {
    case ' ':
      break;
    case '!':
      break;
    case '\"':
      break;
    case '#':
      goto LAB_0004a108;
    case '$':
      return 0xffffffff;
    case '%':
      return 0xffffffff;
    case '&':
      return 0xffffffff;
    case '\'':
      break;
    case '(':
      break;
    default:
      return 0xffffffff;
    }
    iVar1 = hvcc_array_add_nal_unit(param_1,local_c,local_10,local_31,param_4,param_5);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    if (local_31 == '!') {
      hvcc_parse_sps(auStack_50,param_5);
      local_18 = local_10;
    }
    else if (local_31 == '\"') {
      hvcc_parse_pps(auStack_50,param_5);
      local_1c = local_10;
    }
    else if (local_31 == ' ') {
      hvcc_parse_vps(auStack_50,param_5);
      local_14 = local_10;
    }
LAB_0004a108:
    if (((local_14 != 0) && (local_18 != 0)) && (local_1c != 0)) {
      return 0;
    }
  } while( true );
}



undefined4 hvcc_write(int param_1,undefined1 *param_2)

{
  char cVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int local_38;
  int local_34;
  byte *local_30;
  ushort local_2a;
  ushort local_28;
  ushort local_26;
  ushort local_24;
  byte local_21;
  
  local_26 = 0;
  local_28 = 0;
  local_2a = 0;
  *param_2 = 1;
  if (0x1000 < *(ushort *)(param_2 + 0x12)) {
    *(undefined2 *)(param_2 + 0x12) = 0;
  }
  if (*(short *)(param_2 + 0x12) == 0) {
    param_2[0x14] = 0;
  }
  *(undefined2 *)(param_2 + 0x18) = 0;
  param_2[0x1a] = 0;
  for (local_21 = 0; local_21 < (byte)param_2[0x1e]; local_21 = local_21 + 1) {
    cVar1 = *(char *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 1);
    if (cVar1 == '!') {
      local_28 = *(short *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 2) + local_28;
    }
    else if (cVar1 == '\"') {
      local_2a = *(short *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 2) + local_2a;
    }
    else if (cVar1 == ' ') {
      local_26 = *(short *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 2) + local_26;
    }
  }
  if ((((local_26 == 0) || (0x10 < local_26)) || (local_28 == 0)) ||
     (((0x20 < local_28 || (local_2a == 0)) || (0x100 < local_2a)))) {
    (*(code *)**(undefined4 **)(param_1 + 0x170))
              ("## err: mp4 invalid vps(%d), sps(%d), pps(%d)\n",local_26,local_28,local_2a);
    uVar3 = 0xffffffff;
  }
  else {
    local_38 = 0x17;
    for (local_21 = 0; local_21 < (byte)param_2[0x1e]; local_21 = local_21 + 1) {
      local_38 = local_38 + 3;
      for (local_24 = 0; local_24 < *(ushort *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 2)
          ; local_24 = local_24 + 1) {
        local_38 = local_38 + 2 +
                   (uint)*(ushort *)
                          (*(int *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc + 4) +
                          (uint)local_24 * 2);
      }
    }
    uVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(local_38);
    *(undefined4 *)(param_2 + 0x28) = uVar3;
    puVar4 = *(undefined1 **)(param_2 + 0x28);
    *puVar4 = *param_2;
    puVar4[1] = param_2[1] << 6 | param_2[2] << 5 | param_2[3];
    puVar4[2] = (char)((uint)*(undefined4 *)(param_2 + 4) >> 0x18);
    puVar4[3] = (char)((uint)*(undefined4 *)(param_2 + 4) >> 0x10);
    puVar4[4] = (char)((uint)*(undefined4 *)(param_2 + 4) >> 8);
    puVar4[5] = (char)*(undefined4 *)(param_2 + 4);
    uVar7 = *(uint *)(param_2 + 0xc) >> 8;
    uVar8 = 0;
    puVar4[6] = (char)(*(uint *)(param_2 + 0xc) >> 8);
    uVar3 = *(undefined4 *)(param_2 + 0xc);
    uVar6 = 0;
    puVar4[7] = (char)uVar3;
    puVar4[8] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x18);
    puVar4[9] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x10);
    puVar4[10] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 8);
    puVar4[0xb] = (char)*(undefined4 *)(param_2 + 8);
    puVar4[0xc] = param_2[0x10];
    puVar4[0xd] = ~((byte)~(byte)(((uint)*(ushort *)(param_2 + 0x12) << 0x14) >> 0x18) >> 4);
    puVar4[0xe] = (char)*(undefined2 *)(param_2 + 0x12);
    puVar4[0xf] = ~((byte)~(byte)(((uint)(byte)param_2[0x14] << 0x1e) >> 0x18) >> 6);
    puVar4[0x10] = ~((byte)~(byte)(((uint)(byte)param_2[0x15] << 0x1e) >> 0x18) >> 6);
    puVar4[0x11] = ~((byte)~(byte)(((uint)(byte)param_2[0x16] << 0x1d) >> 0x18) >> 5);
    puVar4[0x12] = ~((byte)~(byte)(((uint)(byte)param_2[0x17] << 0x1d) >> 0x18) >> 5);
    puVar4[0x13] = (char)((ushort)*(undefined2 *)(param_2 + 0x18) >> 8);
    puVar4[0x14] = (char)*(undefined2 *)(param_2 + 0x18);
    puVar4[0x15] = param_2[0x1a] << 6 | param_2[0x1b] << 3 | param_2[0x1c] << 2 | param_2[0x1d];
    local_30 = puVar4 + 0x17;
    puVar4[0x16] = param_2[0x1e];
    local_34 = 0x17;
    for (local_21 = 0; local_21 < (byte)param_2[0x1e]; local_21 = local_21 + 1) {
      pcVar5 = (char *)(*(int *)(param_2 + 0x20) + (uint)local_21 * 0xc);
      *local_30 = *pcVar5 << 7 | pcVar5[1] & 0x3fU;
      pbVar2 = local_30 + 2;
      local_30[1] = (byte)((ushort)*(undefined2 *)(pcVar5 + 2) >> 8);
      local_30 = local_30 + 3;
      *pbVar2 = (byte)*(undefined2 *)(pcVar5 + 2);
      local_34 = local_34 + 3;
      for (local_24 = 0; local_24 < *(ushort *)(pcVar5 + 2); local_24 = local_24 + 1) {
        *local_30 = (byte)((ushort)*(undefined2 *)(*(int *)(pcVar5 + 4) + (uint)local_24 * 2) >> 8);
        local_30[1] = (byte)*(undefined2 *)(*(int *)(pcVar5 + 4) + (uint)local_24 * 2);
        memcpy(local_30 + 2,*(void **)(*(int *)(pcVar5 + 8) + (uint)local_24 * 4),
               (uint)*(ushort *)(*(int *)(pcVar5 + 4) + (uint)local_24 * 2));
        local_30 = local_30 + 2 + *(ushort *)(*(int *)(pcVar5 + 4) + (uint)local_24 * 2);
        local_34 = local_34 + 2 + (uint)*(ushort *)(*(int *)(pcVar5 + 4) + (uint)local_24 * 2);
      }
    }
    if (local_34 != local_38) {
      (*(code *)**(undefined4 **)(param_1 + 0x170))
                ("## hvcc err: ulDataLen=%d, mallen=%d\n",local_34,local_38,
                 (code *)**(undefined4 **)(param_1 + 0x170),uVar3,uVar6,uVar7,uVar8);
    }
    *(int *)(param_2 + 0x24) = local_34;
    uVar3 = 0;
  }
  return uVar3;
}



undefined4 hvcc_init_arrayn(int param_1,void *param_2)

{
  undefined4 uVar1;
  
  memset(param_2,0,0xc);
  uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(4);
  *(undefined4 *)((int)param_2 + 8) = uVar1;
  if (*(int *)((int)param_2 + 8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(2);
    *(undefined4 *)((int)param_2 + 4) = uVar1;
    if (*(int *)((int)param_2 + 4) == 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)((int)param_2 + 8));
      *(undefined4 *)((int)param_2 + 8) = 0;
      uVar1 = 0;
    }
    else {
      memset(*(void **)((int)param_2 + 8),0,4);
      memset(*(void **)((int)param_2 + 4),0,2);
      *(undefined2 *)((int)param_2 + 2) = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}



void hvcc_init(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int local_c;
  
  memset(param_2,0,0x30);
  *param_2 = 1;
  param_2[0x1d] = 3;
  *(undefined4 *)(param_2 + 4) = 0xffffffff;
  *(undefined4 *)(param_2 + 8) = 0xffffffff;
  *(undefined4 *)(param_2 + 0xc) = 0xffff;
  *(undefined2 *)(param_2 + 0x12) = 0x1001;
  uVar1 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(0x24);
  *(undefined4 *)(param_2 + 0x20) = uVar1;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    hvcc_init_arrayn(param_1,*(int *)(param_2 + 0x20) + local_c * 0xc);
  }
  *(undefined1 *)(*(int *)(param_2 + 0x20) + 1) = 0x20;
  *(undefined1 *)(*(int *)(param_2 + 0x20) + 0xd) = 0x21;
  *(undefined1 *)(*(int *)(param_2 + 0x20) + 0x19) = 0x22;
  param_2[0x1e] = 3;
  return;
}



undefined4 hvcc_destroy_arrayn(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_2 + 8) != 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_2 + 8));
      *(undefined4 *)(param_2 + 8) = 0;
    }
    if (*(int *)(param_2 + 4) != 0) {
      (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_2 + 4));
      *(undefined4 *)(param_2 + 4) = 0;
    }
    *(undefined2 *)(param_2 + 2) = 0;
    uVar1 = 1;
  }
  return uVar1;
}



void hvcc_close(int param_1,int param_2)

{
  byte bVar1;
  undefined1 local_9;
  
  bVar1 = 3;
  if (3 < *(byte *)(param_2 + 0x1e)) {
    bVar1 = *(byte *)(param_2 + 0x1e);
  }
  for (local_9 = 0; local_9 < bVar1; local_9 = local_9 + 1) {
    hvcc_destroy_arrayn(param_1,*(int *)(param_2 + 0x20) + (uint)local_9 * 0xc);
  }
  *(undefined1 *)(param_2 + 0x1e) = 0;
  (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)(param_2 + 0x20) = 0;
  return;
}



bool quicktime_set_mp4_hvcC(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_40 [36];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_c;
  
  local_c = 0;
  hvcc_init(param_1,auStack_40);
  iVar1 = hvcc_add_nal_unit(param_1,param_2,param_3,1,auStack_40);
  if (iVar1 == 0) {
    local_c = hvcc_write(param_1,auStack_40);
    *(undefined4 *)(param_4 + 200) = local_18;
    *(undefined4 *)(param_4 + 0xc4) = local_1c;
    hvcc_close(param_1,auStack_40);
  }
  else {
    hvcc_close(param_1,auStack_40);
  }
  return iVar1 == 0;
}



undefined4 hvcc_read(int param_1,undefined1 *param_2)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 *puVar9;
  int *piVar10;
  byte *pbVar11;
  uint uVar12;
  undefined1 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  byte local_19;
  
  uVar2 = quicktime_read_char(param_1);
  *param_2 = uVar2;
  bVar3 = quicktime_read_char(param_1);
  param_2[1] = bVar3 >> 6;
  param_2[2] = bVar3 >> 5 & 1;
  param_2[3] = bVar3 & 0x1f;
  uVar6 = quicktime_read_int32(param_1);
  *(undefined4 *)(param_2 + 4) = uVar6;
  iVar7 = quicktime_read_int32(param_1);
  *(int *)(param_2 + 8) = iVar7;
  *(int *)(param_2 + 0xc) = iVar7 >> 0x1f;
  uVar8 = *(uint *)(param_2 + 8);
  *(uint *)(param_2 + 8) = uVar8 << 0x10;
  *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) << 0x10 | uVar8 >> 0x10;
  uVar12 = *(uint *)(param_2 + 8);
  uVar6 = *(undefined4 *)(param_2 + 0xc);
  uVar8 = quicktime_read_int16(param_1);
  *(uint *)(param_2 + 8) = uVar8 | uVar12;
  *(undefined4 *)(param_2 + 0xc) = uVar6;
  uVar2 = quicktime_read_char(param_1);
  param_2[0x10] = uVar2;
  uVar4 = quicktime_read_int16(param_1);
  *(ushort *)(param_2 + 0x12) = uVar4 & 0xfff;
  bVar3 = quicktime_read_char(param_1);
  param_2[0x14] = bVar3 & 3;
  bVar3 = quicktime_read_char(param_1);
  param_2[0x15] = bVar3 & 3;
  bVar3 = quicktime_read_char(param_1);
  param_2[0x16] = bVar3 & 7;
  bVar3 = quicktime_read_char(param_1);
  param_2[0x17] = bVar3 & 7;
  uVar5 = quicktime_read_int16(param_1);
  *(undefined2 *)(param_2 + 0x18) = uVar5;
  bVar3 = quicktime_read_char(param_1);
  param_2[0x1a] = bVar3 >> 6;
  param_2[0x1b] = bVar3 >> 3 & 7;
  param_2[0x1c] = bVar3 >> 2 & 1;
  param_2[0x1d] = bVar3 & 3;
  uVar2 = quicktime_read_char(param_1);
  param_2[0x1e] = uVar2;
  local_20 = 0x17;
  (*(code *)**(undefined4 **)(param_1 + 0x170))("## hvcc numOfArrays(%d)\n",param_2[0x1e]);
  if (3 < (byte)param_2[0x1e]) {
    (*(code *)**(undefined4 **)(param_1 + 0x170))
              ("## hvcc numOfArrays(%d) overflow\n",param_2[0x1e]);
    param_2[0x1e] = 3;
  }
  local_24 = 0;
  local_19 = 0;
  do {
    if ((byte)param_2[0x1e] <= local_19) {
      uVar6 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(local_24);
      *(undefined4 *)(param_2 + 0x28) = uVar6;
      local_2c = *(undefined1 **)(param_2 + 0x28);
      for (local_19 = 0; local_19 < (byte)param_2[0x1e]; local_19 = local_19 + 1) {
        iVar7 = *(int *)(param_2 + 0x20) + (uint)local_19 * 0xc;
        bVar1 = false;
        while (!bVar1) {
          *local_2c = 0;
          local_2c[1] = 0;
          local_2c[2] = (char)((ushort)**(undefined2 **)(iVar7 + 4) >> 8);
          local_2c[3] = (char)**(undefined2 **)(iVar7 + 4);
          memcpy(local_2c + 4,(void *)**(undefined4 **)(iVar7 + 8),(uint)**(ushort **)(iVar7 + 4));
          (**(code **)(*(int *)(param_1 + 0x170) + 0x18))(**(undefined4 **)(iVar7 + 8));
          local_2c = local_2c + 4 + **(ushort **)(iVar7 + 4);
          bVar1 = true;
        }
      }
      (*(code *)**(undefined4 **)(param_1 + 0x170))("## hvcc: ulDataLen=%d\n",local_20);
      *(int *)(param_2 + 0x24) = local_24;
      return 1;
    }
    pbVar11 = (byte *)(*(int *)(param_2 + 0x20) + (uint)local_19 * 0xc);
    bVar3 = quicktime_read_char(param_1);
    *pbVar11 = bVar3 >> 7;
    pbVar11[1] = bVar3 & 0x3f;
    uVar5 = quicktime_read_int16(param_1);
    *(undefined2 *)(pbVar11 + 2) = uVar5;
    local_20 = local_20 + 3;
    if (1 < *(ushort *)(pbVar11 + 2)) {
      (*(code *)**(undefined4 **)(param_1 + 0x170))
                ("## hvcc war: numNalus(%d) overflow\n",*(undefined2 *)(pbVar11 + 2));
    }
    bVar1 = false;
    while (!bVar1) {
      puVar9 = *(undefined2 **)(pbVar11 + 4);
      uVar5 = quicktime_read_int16(param_1);
      *puVar9 = uVar5;
      if (**(short **)(pbVar11 + 4) == 0) {
        (*g_medialib_printf)
                  ("## err: hvcc_read invalid nalUnitLength(%d)\n",**(undefined2 **)(pbVar11 + 4));
        **(undefined2 **)(pbVar11 + 4) = 1;
      }
      piVar10 = *(int **)(pbVar11 + 8);
      iVar7 = (**(code **)(*(int *)(param_1 + 0x170) + 0x14))(**(undefined2 **)(pbVar11 + 4));
      *piVar10 = iVar7;
      iVar7 = *piVar10;
      if (iVar7 == 0) {
        (*g_medialib_printf)("## err: hvcc_read malloc fail\n");
        return 0;
      }
      for (local_28 = 0; local_28 < (int)(uint)**(ushort **)(pbVar11 + 4); local_28 = local_28 + 1)
      {
        uVar2 = quicktime_read_char(param_1);
        *(undefined1 *)(iVar7 + local_28) = uVar2;
      }
      local_20 = local_20 + 2 + (uint)**(ushort **)(pbVar11 + 4);
      local_24 = local_24 + 4 + (uint)**(ushort **)(pbVar11 + 4);
      bVar1 = true;
    }
    local_19 = local_19 + 1;
  } while( true );
}



undefined4 quicktime_get_mp4_hvcC(undefined4 param_1,int param_2)

{
  undefined1 auStack_40 [36];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_c;
  
  local_c = 0;
  hvcc_init(param_1,auStack_40);
  local_c = hvcc_read(param_1,auStack_40);
  *(undefined4 *)(param_2 + 200) = local_18;
  *(undefined4 *)(param_2 + 0xc4) = local_1c;
  hvcc_close(param_1,auStack_40);
  return 1;
}



int * FIFO_Init_Old(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint local_c;
  
  if (param_1 < 8) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(param_2 + 0x14))(0x28);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      ZeroMemory(piVar2,0x28);
      piVar2[8] = param_2;
      local_c = param_1;
      if ((param_1 & 3) != 0) {
        local_c = (param_1 & 0xfffffffc) + 4;
      }
      iVar1 = (**(code **)(piVar2[8] + 0x14))(local_c + 4);
      piVar2[7] = iVar1;
      if (piVar2[7] == 0) {
        (**(code **)(piVar2[8] + 0x18))(piVar2);
        piVar2 = (int *)0x0;
      }
      else {
        iVar1 = piVar2[7] + (4 - (piVar2[7] & 3U));
        *piVar2 = iVar1;
        piVar2[1] = local_c;
        piVar2[2] = iVar1 + local_c + -4;
        piVar2[4] = iVar1;
        piVar2[3] = iVar1;
        piVar2[5] = local_c;
        piVar2[6] = 0;
      }
    }
  }
  return piVar2;
}



void FIFO_Reset_Old(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[4] = *param_1;
    param_1[3] = *param_1;
    param_1[5] = param_1[1];
    param_1[6] = 0;
  }
  return;
}



void FIFO_Destroy_Old(int param_1)

{
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x24) == '\x01') {
      (**(code **)(*(int *)(param_1 + 0x20) + 0x48))(*(undefined4 *)(param_1 + 0x1c));
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(*(undefined4 *)(param_1 + 0x1c));
    }
    (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(param_1);
  }
  return;
}



undefined4 FIFO_Add_Old(int *param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  size_t __n;
  uint local_c;
  
  if (((param_3 == 0) || (param_2 == (void *)0x0)) || (param_1 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    if ((param_3 & 3) == 0) {
      local_c = param_3 + 4;
    }
    else {
      local_c = (param_3 & 0xfffffffc) + 8;
    }
    if ((uint)param_1[5] < local_c) {
      uVar1 = 0;
    }
    else {
      param_1[6] = param_1[6] + 1;
      if (param_1[4] == param_1[2] + 4) {
        param_1[4] = *param_1;
      }
      *(uint *)param_1[4] = param_3;
      param_1[5] = param_1[5] - local_c;
      if (param_1[2] + 4U < param_1[4] + local_c) {
        if ((uint)param_1[4] < (uint)param_1[2]) {
          __n = param_1[2] - param_1[4];
          memcpy((void *)(param_1[4] + 4),param_2,__n);
          memcpy((void *)*param_1,(void *)((int)param_2 + __n),param_3 - __n);
          param_1[4] = ((*param_1 + local_c) - __n) + -4;
        }
        else if (param_1[4] == param_1[2]) {
          memcpy((void *)*param_1,param_2,param_3);
          param_1[4] = *param_1 + local_c + -4;
        }
      }
      else {
        memcpy((void *)(param_1[4] + 4),param_2,param_3);
        param_1[4] = param_1[4] + local_c;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



uint FIFO_Get_Old(int *param_1,void *param_2,uint param_3)

{
  uint __n;
  size_t __n_00;
  int local_c;
  
  if ((uint)param_1[5] < (uint)param_1[1]) {
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    __n = *(uint *)param_1[3];
    if (param_3 < __n) {
      __n = 0;
    }
    else {
      if ((__n & 3) == 0) {
        local_c = __n + 4;
      }
      else {
        local_c = (__n & 0xfffffffc) + 8;
      }
      param_1[5] = param_1[5] + local_c;
      param_1[6] = param_1[6] + -1;
      if (param_1[2] + 4U < param_1[3] + __n + 4) {
        if ((uint)param_1[3] < (uint)param_1[2]) {
          __n_00 = param_1[2] - param_1[3];
          memcpy(param_2,(void *)(param_1[3] + 4),__n_00);
          memcpy((void *)((int)param_2 + __n_00),(void *)*param_1,__n - __n_00);
          param_1[3] = ((*param_1 + local_c) - __n_00) + -4;
        }
        else if (param_1[3] == param_1[2]) {
          memcpy(param_2,(void *)*param_1,__n);
          param_1[3] = *param_1 + local_c + -4;
        }
      }
      else {
        memcpy(param_2,(void *)(param_1[3] + 4),__n);
        param_1[3] = param_1[3] + local_c;
      }
    }
  }
  else {
    __n = 0;
  }
  return __n;
}



int FIFO_FreeSpace_Old(int param_1)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 0x14) < 8) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14) + -8;
  }
  return iVar1;
}



int FIFO_UsedSpace_Old(int param_1)

{
  return *(int *)(param_1 + 4) - *(int *)(param_1 + 0x14);
}



undefined4 FIFO_ItemNum_Old(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



uint FIFO_Drop_Old(int *param_1)

{
  uint uVar1;
  int local_c;
  
  if ((uint)param_1[5] < (uint)param_1[1]) {
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    uVar1 = *(uint *)param_1[3];
    if ((uVar1 & 3) == 0) {
      local_c = uVar1 + 4;
    }
    else {
      local_c = (uVar1 & 0xfffffffc) + 8;
    }
    param_1[5] = param_1[5] + local_c;
    param_1[6] = param_1[6] + -1;
    if (param_1[2] + 4U < param_1[3] + uVar1 + 4) {
      if ((uint)param_1[3] < (uint)param_1[2]) {
        param_1[3] = ((*param_1 + local_c) - (param_1[2] - param_1[3])) + -4;
      }
      else if (param_1[3] == param_1[2]) {
        param_1[3] = *param_1 + local_c + -4;
      }
    }
    else {
      param_1[3] = param_1[3] + local_c;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 FIFO_Init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FIFO_Init_Old(param_1,param_2);
  return uVar1;
}



int * FIFO_Init2(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint local_c;
  
  if (param_1 < 8) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(param_2 + 0x14))(0x28);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      ZeroMemory(piVar2,0x28);
      piVar2[8] = param_2;
      local_c = param_1;
      if ((param_1 & 3) != 0) {
        local_c = (param_1 & 0xfffffffc) + 4;
      }
      iVar1 = (**(code **)(param_2 + 0x44))(local_c + 4);
      piVar2[7] = iVar1;
      if (piVar2[7] == 0) {
        (**(code **)(piVar2[8] + 0x18))(piVar2);
        piVar2 = (int *)0x0;
      }
      else {
        iVar1 = piVar2[7] + (4 - (piVar2[7] & 3U));
        *piVar2 = iVar1;
        piVar2[1] = local_c;
        piVar2[2] = iVar1 + local_c + -4;
        piVar2[4] = iVar1;
        piVar2[3] = iVar1;
        piVar2[5] = local_c;
        piVar2[6] = 0;
        *(undefined1 *)(piVar2 + 9) = 1;
      }
    }
  }
  return piVar2;
}



void FIFO_Reset(undefined4 param_1)

{
  FIFO_Reset_Old(param_1);
  return;
}



void FIFO_Destroy(undefined4 param_1)

{
  FIFO_Destroy_Old(param_1);
  return;
}



int FIFO_Get_Inaddr(int *param_1,uint param_2)

{
  bool bVar1;
  int local_10;
  uint local_c;
  
  bVar1 = true;
  if ((param_2 == 0) || (param_1 == (int *)0x0)) {
    local_10 = 0;
  }
  else {
    if ((param_2 & 3) == 0) {
      local_c = param_2 + 4;
    }
    else {
      local_c = (param_2 & 0xfffffffc) + 8;
    }
    local_10 = param_1[4];
    if ((uint)param_1[5] < local_c) {
      bVar1 = false;
    }
    else if (param_1[2] + 4U < param_1[4] + local_c) {
      if (((param_1[4] - param_1[2]) + param_1[5]) - 4U < local_c) {
        bVar1 = false;
      }
      else {
        local_10 = *param_1;
      }
    }
    if (bVar1) {
      local_10 = local_10 + 4;
    }
    else {
      local_10 = 0;
    }
  }
  return local_10;
}



undefined1 FIFO_Add(int *param_1,int param_2,uint param_3)

{
  undefined1 local_19;
  int local_18;
  uint local_14;
  undefined4 *local_10;
  uint local_c;
  
  local_10 = (undefined4 *)0x0;
  local_19 = 0;
  if (((param_3 == 0) || (param_2 == 0)) || (param_1 == (int *)0x0)) {
    local_19 = 0;
  }
  else {
    if ((param_3 & 3) == 0) {
      local_c = param_3 + 4;
    }
    else {
      local_c = (param_3 & 0xfffffffc) + 8;
    }
    local_18 = param_1[4];
    local_14 = param_1[5];
    if (local_c <= local_14) {
      if (param_1[2] + 4U < param_1[4] + local_c) {
        if (param_1[4] != param_1[2] + 4) {
          local_10 = (undefined4 *)param_1[4];
        }
        local_14 = ((param_1[4] - param_1[2]) + local_14) - 4;
        if (local_14 < local_c) {
          return 0;
        }
        local_18 = *param_1;
      }
      if (local_18 + 4 == param_2) {
        param_1[5] = local_14;
        param_1[4] = local_18;
        if (local_10 != (undefined4 *)0x0) {
          *local_10 = 0xffffffff;
        }
        *(uint *)param_1[4] = param_3;
        param_1[5] = param_1[5] - local_c;
        param_1[4] = param_1[4] + local_c;
        param_1[6] = param_1[6] + 1;
        local_19 = 1;
      }
    }
  }
  return local_19;
}



uint FIFO_Get(undefined4 *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint local_10;
  int local_c;
  
  if (((uint)param_1[5] < (uint)param_1[1]) && (param_1[6] != 0)) {
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    local_10 = *(uint *)param_1[3];
    if (local_10 == 0xffffffff) {
      *(uint *)param_1[3] = 0;
      param_1[5] = param_1[5] + (param_1[2] - param_1[3]) + 4;
      param_1[3] = *param_1;
      local_10 = *(uint *)param_1[3];
    }
    if (param_3 < local_10) {
      local_10 = 0;
    }
    else {
      if ((local_10 & 3) == 0) {
        local_c = local_10 + 4;
      }
      else {
        local_c = (local_10 & 0xfffffffc) + 8;
      }
      param_1[5] = param_1[5] + local_c;
      param_1[6] = param_1[6] + -1;
      iVar1 = param_1[3];
      param_1[3] = param_1[3] + local_c;
      memcpy(param_2,(void *)(iVar1 + 4),local_10);
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



uint FIFO_Drop(undefined4 *param_1)

{
  uint local_10;
  int local_c;
  
  if (((uint)param_1[5] < (uint)param_1[1]) && (param_1[6] != 0)) {
    param_1[6] = param_1[6] + -1;
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    local_10 = *(uint *)param_1[3];
    if (local_10 == 0xffffffff) {
      *(uint *)param_1[3] = 0;
      param_1[5] = param_1[5] + (param_1[2] - param_1[3]) + 4;
      param_1[3] = *param_1;
      local_10 = *(uint *)param_1[3];
    }
    if ((local_10 & 3) == 0) {
      local_c = local_10 + 4;
    }
    else {
      local_c = (local_10 & 0xfffffffc) + 8;
    }
    param_1[5] = param_1[5] + local_c;
    param_1[3] = param_1[3] + local_c;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



int FIFO_Get_Outaddr(undefined4 *param_1)

{
  int iVar1;
  
  if (((uint)param_1[5] < (uint)param_1[1]) && (param_1[6] != 0)) {
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    if (*(int *)param_1[3] == -1) {
      *(int *)param_1[3] = 0;
      param_1[5] = param_1[5] + (param_1[2] - param_1[3]) + 4;
      param_1[3] = *param_1;
    }
    iVar1 = param_1[3] + 4;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



int FIFO_Get_Length(undefined4 *param_1)

{
  int iVar1;
  
  if (((uint)param_1[5] < (uint)param_1[1]) && (param_1[6] != 0)) {
    if (param_1[3] == param_1[2] + 4) {
      param_1[3] = *param_1;
    }
    iVar1 = *(int *)param_1[3];
    if (iVar1 == -1) {
      *(int *)param_1[3] = 0;
      param_1[5] = param_1[5] + (param_1[2] - param_1[3]) + 4;
      param_1[3] = *param_1;
      iVar1 = *(int *)param_1[3];
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



int FIFO_FreeSpace(undefined4 *param_1)

{
  uint uVar1;
  int local_c;
  
  local_c = 0;
  if (8 < (uint)param_1[5]) {
    if (param_1[2] + 4 < (uint)(param_1[4] + param_1[5])) {
      if (param_1[6] == 0) {
        param_1[4] = *param_1;
        param_1[3] = *param_1;
        param_1[5] = param_1[1];
        local_c = param_1[5] + -8;
      }
      else {
        uVar1 = (param_1[2] - param_1[4]) + 4;
        if (uVar1 <= param_1[5] - uVar1) {
          uVar1 = param_1[5] - uVar1;
        }
        if (uVar1 < 9) {
          local_c = 0;
        }
        else {
          local_c = uVar1 - 8;
        }
      }
    }
    else {
      local_c = param_1[5] + -8;
    }
  }
  return local_c;
}



int FIFO_UsedSpace(int param_1)

{
  return *(int *)(param_1 + 4) - *(int *)(param_1 + 0x14);
}



undefined4 FIFO_ItemNum(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



int cal_log2(int param_1)

{
  uint local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  if (param_1 == 0) {
    local_c = 1;
  }
  else {
    for (local_14 = param_1 - 1; 0xff < local_14; local_14 = local_14 >> 8) {
      local_10 = local_10 + 8;
    }
    local_c = (uint)(byte)(&Log_table)[local_14] + local_10;
    if (local_c == 0) {
      local_c = 1;
    }
  }
  return local_c;
}



void ZeroMemory(void *param_1,size_t param_2)

{
  memset(param_1,0,param_2);
  return;
}



undefined4 mov_str2ulong(undefined1 *param_1)

{
  return CONCAT13(*param_1,CONCAT12(param_1[1],CONCAT11(param_1[2],param_1[3])));
}



uint mov_str2ushort(byte *param_1)

{
  return (uint)param_1[1] | ((uint)*param_1 << 0x18) >> 0x10;
}



void mov_ulong2str(undefined1 *param_1,undefined4 param_2)

{
  param_1[3] = (char)param_2;
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  *param_1 = (char)((uint)param_2 >> 0x18);
  return;
}



void ulong2str(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}



undefined4 str2ulong(undefined4 *param_1)

{
  return *param_1;
}



uint str2ushort(byte *param_1)

{
  return (uint)*param_1 | ((uint)param_1[1] << 0x18) >> 0x10;
}



undefined4 U64DivU32(uint param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0;
  local_18 = 0;
  local_10 = 0;
  if (param_3 == 0) {
    uVar1 = 1;
  }
  else {
    for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
      if ((0x80000000U >> (local_c & 0xff) & param_1) == 0) {
        local_10 = local_10 << 1;
      }
      else {
        local_10 = local_10 << 1 | 1;
      }
      if (local_10 < param_3) {
        local_14 = local_14 << 1;
      }
      else {
        local_10 = local_10 - param_3;
        local_14 = local_14 << 1 | 1;
      }
    }
    for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
      if ((0x80000000U >> (local_c & 0xff) & param_2) == 0) {
        local_10 = local_10 << 1;
      }
      else {
        local_10 = local_10 << 1 | 1;
      }
      if (local_10 < param_3) {
        local_18 = local_18 << 1;
      }
      else {
        local_10 = local_10 - param_3;
        local_18 = local_18 << 1 | 1;
      }
    }
    *param_4 = local_14;
    *param_5 = local_18;
    uVar1 = 0;
  }
  return uVar1;
}



void U32MuxU32(uint param_1,uint param_2,int *param_3,uint *param_4)

{
  bool bVar1;
  uint local_3c [7];
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_14 = 0;
  local_18 = 0;
  for (local_c = 0; local_c < 2; local_c = local_c + 1) {
    local_3c[local_c + 2] = 0;
    local_3c[local_c] = 0;
  }
  local_c = 0;
  do {
    if (0x1f < local_c) {
      *param_3 = local_14;
      *param_4 = local_18;
      return;
    }
    if (local_c == 0) {
      if ((param_2 & 1) != 0) {
        local_10 = 0;
        local_3c[2] = param_1;
LAB_0004d510:
        local_3c[3] = local_3c[2] >> 0x10;
        local_3c[2] = local_3c[2] & 0xffff;
        local_3c[0] = local_3c[0] + local_3c[2];
        bVar1 = 0xffff < local_3c[0];
        if (bVar1) {
          local_3c[0] = local_3c[0] & 0xffff;
        }
        local_1c = (uint)bVar1;
        local_3c[1] = local_3c[1] + local_3c[3] + local_1c;
        bVar1 = 0xffff < local_3c[1];
        if (bVar1) {
          local_3c[1] = local_3c[1] & 0xffff;
        }
        local_20 = (uint)bVar1;
        local_18 = local_3c[1] << 0x10 | local_3c[0];
        local_14 = local_14 + local_10 + local_20;
      }
    }
    else if ((1 << (local_c & 0xff) & param_2) != 0) {
      local_10 = param_1 >> (0x20 - local_c & 0xff);
      local_3c[2] = param_1 << (local_c & 0xff);
      goto LAB_0004d510;
    }
    local_c = local_c + 1;
  } while( true );
}



undefined4 MulDiv(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = 0;
  if (param_4 == 0) {
    (*g_medialib_printf)("##MulDiv: ERROR -- div is 0##\r\n");
    uVar1 = 0;
  }
  else {
    U32MuxU32(param_2,param_3,&local_18,&local_1c);
    local_14 = U64DivU32(local_18,local_1c,param_4,&local_20,&local_24);
    if ((local_20 != 0) || (local_14 != 0)) {
      (*g_medialib_printf)("##MulDiv: ERROR -- result is out of 32 bits##\r\n");
    }
    *param_1 = local_24;
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 get_aacsamplerate(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0xc) {
    uVar1 = *(undefined4 *)(g_aac_sample_rates + (uint)param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



byte get_aacFreqIndex(int param_1)

{
  byte local_9;
  
  local_9 = 0;
  while ((local_9 < 0xc && (*(int *)(g_aac_sample_rates + (uint)local_9 * 4) != param_1))) {
    local_9 = local_9 + 1;
  }
  return local_9;
}



undefined4 get_mp3samplerate(uint param_1)

{
  return *(undefined4 *)
          (g_mp3_freqs +
          (((uint)((char)(param_1 >> 0x14) + 1U & 1) + (uint)((char)(param_1 >> 0x13) + 1U & 1)) * 3
          + (uint)((byte)(param_1 >> 10) & 3)) * 4);
}



int check_mp3layer(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = mov_str2ulong(param_1);
  if (uVar1 == 0) {
    iVar2 = 4;
  }
  else if (uVar1 < 0x100) {
    iVar2 = 5;
  }
  else if (uVar1 < 0x10000) {
    iVar2 = 6;
  }
  else if (uVar1 < 0x1000000) {
    iVar2 = 7;
  }
  else if ((uVar1 & 0xffe00000) == 0xffe00000) {
    if ((uVar1 >> 0x11 & 3) == 0) {
      (*g_medialib_printf)("##mp3: ERROR--layer is invalid##\r\n");
      iVar2 = 0;
    }
    else {
      iVar2 = 4 - (uVar1 >> 0x11 & 3);
      if (iVar2 == 0) {
        (*g_medialib_printf)("##mp3: ERROR--layer is 0##\r\n");
        iVar2 = 0;
      }
      else if ((uVar1 >> 0xc & 0xf) == 0xf) {
        (*g_medialib_printf)("##mp3: ERROR--bit rate is forbidden##\r\n");
        iVar2 = 0;
      }
      else if ((uVar1 >> 0xc & 0xf) == 0) {
        (*g_medialib_printf)("##mp3: ERROR--this version don\'t support free bit rate##\r\n");
        iVar2 = 0;
      }
      else if ((uVar1 >> 10 & 3) == 3) {
        (*g_medialib_printf)("##mp3: ERROR--sampling is invalid##\r\n");
        iVar2 = 0;
      }
    }
  }
  else {
    (*g_medialib_printf)("##mp3: ERROR--check sync word failed##\r\n");
    iVar2 = 0;
  }
  return iVar2;
}



uint Dnp_Crc(byte *param_1,int param_2)

{
  int local_18;
  byte *local_14;
  uint local_10;
  byte local_9;
  
  local_10 = 0;
  local_14 = param_1;
  for (local_18 = param_2; local_18 != 0; local_18 = local_18 + -1) {
    local_10 = local_10 ^ *local_14;
    for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
      if ((local_10 & 1) == 0) {
        local_10 = local_10 >> 1;
      }
      else {
        local_10 = local_10 >> 1 ^ 0xa6bc;
      }
    }
    local_14 = local_14 + 1;
  }
  return ~local_10;
}



undefined4 info_print(void)

{
  return 0;
}



uint h264_startcode2length(int param_1,uint param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_18 = 0;
  local_1c = 0;
  local_10 = 0;
  for (local_c = param_2; local_c != 0; local_c = local_c - 1) {
    local_18 = 0;
    for (; (*(char *)(param_1 + local_10) == '\0' && (local_c != 0)); local_c = local_c - 1) {
      if (param_2 <= local_10) {
        return 0;
      }
      local_18 = local_18 + 1;
      local_10 = local_10 + 1;
    }
    if ((1 < local_18) && (*(char *)(param_1 + local_10) == '\x01')) break;
    local_10 = local_10 + 1;
  }
  uVar4 = local_18 + 1;
  do {
    if (local_c == 0) {
      if ((local_1c == 0) || (4 < uVar4)) {
        local_1c = 0;
      }
      else {
        local_1c = uVar4 * 0x1000000 | local_1c;
      }
      return local_1c;
    }
    local_14 = 0;
    iVar5 = local_10 - local_18;
    local_c = local_c - 1;
    local_10 = local_10 + 1;
    while (local_18 = 0, local_c != 0) {
      if (*(char *)(param_1 + local_10) == '\0') {
        do {
          uVar3 = local_10 + 1;
          if (param_2 <= local_10) {
            return 0;
          }
          local_18 = local_18 + 1;
          local_10 = uVar3;
        } while ((*(char *)(param_1 + uVar3) == '\0') && (local_c != 0));
        local_c = local_c - local_18;
        if ((1 < local_18) && (*(char *)(param_1 + uVar3) == '\x01')) break;
        local_14 = local_14 + local_18;
      }
      else {
        local_10 = local_10 + 1;
        local_c = local_c - 1;
        local_14 = local_14 + 1;
      }
    }
    if ((local_c != 0) && (local_18 + 1 != uVar4)) {
      return 0;
    }
    uVar2 = (undefined1)((uint)local_14 >> 8);
    uVar1 = (undefined1)((uint)local_14 >> 0x10);
    if (uVar4 == 3) {
      *(undefined1 *)(param_1 + iVar5) = uVar1;
      *(undefined1 *)(param_1 + iVar5 + 1) = uVar2;
      *(char *)(param_1 + iVar5 + 2) = (char)local_14;
    }
    else {
      if (uVar4 != 4) {
        return 0;
      }
      *(char *)(param_1 + iVar5) = (char)((uint)local_14 >> 0x18);
      *(undefined1 *)(param_1 + iVar5 + 1) = uVar1;
      *(undefined1 *)(param_1 + iVar5 + 2) = uVar2;
      *(char *)(param_1 + iVar5 + 3) = (char)local_14;
    }
    local_1c = local_1c + 1;
  } while( true );
}



uint Bitstream_ShowBits(int param_1,int param_2)

{
  if (*(int *)(param_1 + 8) < param_2) {
    Bitstream_FillBuffer(param_1);
  }
  return *(uint *)(param_1 + 4) >> (*(int *)(param_1 + 8) - param_2 & 0xffU) &
         *(uint *)(&msk + param_2 * 4);
}



uint * Bitstream_FillBuffer(uint *param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (3 < local_c) {
      return param_1;
    }
    if (*param_1 < param_1[5]) {
      param_1[1] = param_1[1] << 8 | (uint)*(byte *)*param_1;
      *param_1 = *param_1 + 1;
    }
    else {
      param_1[1] = param_1[1] << 8;
    }
    param_1[2] = param_1[2] + 8;
    if (0x18 < (int)param_1[2]) break;
    local_c = local_c + 1;
  }
  return param_1;
}



int Bitstream_FlushBits(int param_1,int param_2)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - param_2;
  if (*(int *)(param_1 + 8) < 0) {
    param_1 = Bitstream_FillBuffer(param_1);
  }
  return param_1;
}



uint Bitstream_ReadBits(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 < 0x19) {
    uVar1 = Bitstream_ShowBits(param_1,param_2);
    Bitstream_FlushBits(param_1,param_2);
  }
  else {
    iVar2 = Bitstream_ReadBits(param_1,0x18,"24 bits");
    uVar1 = Bitstream_ReadBits(param_1,param_2 - 0x18,"remain bits");
    uVar1 = iVar2 << (param_2 - 0x18 & 0xff) | uVar1;
  }
  return uVar1;
}



uint Bitstream_ByteAlign(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 8) & 7;
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    Bitstream_FlushBits(param_1,uVar1);
  }
  return uVar1;
}



undefined4 Bitstream_Init(int *param_1,int param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint local_14;
  
  if (((param_1 == (int *)0x0) || (param_2 == 0)) || (param_4 == 0)) {
    uVar1 = 0;
  }
  else {
    *param_1 = param_2;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[1] = 0;
    param_1[4] = param_2;
    param_1[5] = param_2 + param_4;
    param_1[6] = param_4;
    local_14 = param_3;
    if (param_3 != 0) {
      for (; 0x18 < local_14; local_14 = local_14 - 0x18) {
        Bitstream_FlushBits(param_1,0x18);
      }
      Bitstream_FlushBits(param_1,local_14);
    }
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 Bitstream_ShowByteAlign(int param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  local_c = *(uint *)(param_1 + 8) & 7;
  if (local_c == 0) {
    local_c = 8;
  }
  *param_2 = local_c;
  uVar1 = Bitstream_ShowBits(param_1,local_c);
  return uVar1;
}



bool Bitstream_IsLastByte(int param_1)

{
  return *(int *)(param_1 + 0x18) - 1U <= *(uint *)(param_1 + 0xc) >> 3;
}



undefined4 Bitstream_UsedBits(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



int MediaFile_GetFileLen(undefined4 *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1[8] + 0x40) == 0) {
    iVar1 = (**(code **)(param_1[8] + 0xc))(*param_1,0,2);
    if (iVar1 == -1) {
      if (*(int *)param_1[8] != 0) {
        (**(code **)param_1[8])("##MFILE: WARNING--unknown filelen##\r\n");
      }
      iVar1 = -1;
    }
    else {
      iVar1 = (**(code **)(param_1[8] + 0x10))(*param_1);
      if (*(int *)param_1[8] != 0) {
        (**(code **)param_1[8])("##MFILE: get filelen %u(0x%x)##\r\n",iVar1,iVar1);
      }
      if (iVar1 == -1) {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = (**(code **)(param_1[8] + 0x40))(*param_1);
    if (*(int *)param_1[8] != 0) {
      (**(code **)param_1[8])("##MFILE: filelen %u(0x%x)##\r\n",iVar1,iVar1);
    }
  }
  return iVar1;
}



bool MediaFile_SetReadMode(int param_1,byte param_2)

{
  if (param_2 < 2) {
    *(byte *)(param_1 + 0x18) = param_2;
  }
  return param_2 < 2;
}



int MediaFile_Read(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_c;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(param_1[8] + 0x10))(*param_1);
    if ((iVar1 == param_1[2]) ||
       (iVar1 = (**(code **)(param_1[8] + 0xc))(*param_1,param_1[2],0), param_1[2] == iVar1)) {
      local_c = param_3;
      if (((uint)param_1[1] <= (uint)(param_1[2] + param_3)) &&
         ((param_1[1] != 0 && (param_1[1] != -1)))) {
        if ((uint)param_1[1] < (uint)param_1[2]) {
          if (*(int *)param_1[8] != 0) {
            (**(code **)param_1[8])
                      ("##MFILE: WARNING--read return zero, pos 0x%x, total 0x%x##\r\n",param_1[2],
                       param_1[1]);
          }
          return 0;
        }
        local_c = param_1[1] - param_1[2];
        if (local_c == 0) {
          return 0;
        }
      }
      iVar1 = (**(code **)(param_1[8] + 4))(*param_1,param_2,local_c);
      if (iVar1 != local_c) {
        if ((*(char *)(param_1 + 6) == '\x01') && (param_1[1] == -1)) {
          param_1[1] = param_1[2] + iVar1;
        }
        if (*(int *)param_1[8] != 0) {
          (**(code **)param_1[8])
                    ("##MFILE: WARNING--FileRead in Read, postion 0x%x, size %d, result %d##\r\n",
                     param_1[2],local_c,iVar1);
        }
        if ((*(char *)(param_1 + 6) == '\0') || (local_c = iVar1, iVar1 == 0)) {
          return 0;
        }
      }
      param_1[2] = param_1[2] + local_c;
    }
    else {
      if (*(int *)param_1[8] != 0) {
        (**(code **)param_1[8])
                  ("##MFILE: WARNING--FileSeek in Read, pos 0x%x, size %d, result 0x%x##\r\n",
                   param_1[2],param_3,iVar1);
      }
      iVar1 = (**(code **)(param_1[8] + 0xc))(*param_1,0,0);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(param_1[8] + 4))(*param_1,param_2,1);
        if (iVar1 != 1) {
          param_1[2] = param_1[1];
          param_1[4] = 1;
        }
      }
      else {
        param_1[2] = param_1[1];
        param_1[4] = 1;
      }
      if ((param_1[4] == 1) && (*(int *)param_1[8] != 0)) {
        (**(code **)param_1[8])("##MFILE: ERROR--read failed##\r\n");
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



int MediaFile_Write(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1[8] + 0x10))(*param_1);
  if ((iVar1 == param_1[2]) ||
     (iVar1 = (**(code **)(param_1[8] + 0xc))(*param_1,param_1[2],0), param_1[2] == iVar1)) {
    iVar1 = (**(code **)(param_1[8] + 8))(*param_1,param_2,param_3);
    if (iVar1 == param_3) {
      param_1[2] = param_1[2] + param_3;
      if ((uint)param_1[1] < (uint)param_1[2]) {
        param_1[1] = param_1[2];
      }
    }
    else {
      if (*(int *)param_1[8] != 0) {
        (**(code **)param_1[8])
                  ("##MFILE: ERROR--FileWrite in Write, postion 0x%x, size %d, result %d##\r\n",
                   param_1[2],param_3,iVar1);
      }
      param_1[5] = 1;
      iVar1 = -1;
    }
  }
  else {
    if (*(int *)param_1[8] != 0) {
      (**(code **)param_1[8])
                ("##MFILE: ERROR--FileSeek in Write, postion 0x%x, moveresult 0x%x##\r\n",param_1[2]
                 ,iVar1);
    }
    param_1[5] = 1;
    iVar1 = -1;
  }
  return iVar1;
}



undefined4 MediaFile_GetTotalLen(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



undefined4 MediaFile_GetPosition(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



undefined4 MediaFile_SetPosition(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return *(undefined4 *)(param_1 + 8);
}



undefined4 MediaFile_ChangePosition(int param_1,int param_2)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2;
  return *(undefined4 *)(param_1 + 8);
}



undefined4 * MediaFile_Open(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(param_3 + 0x14))(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    ZeroMemory(puVar1,0x24);
    *puVar1 = param_1;
    puVar1[3] = param_2;
    puVar1[8] = param_3;
    if (puVar1[3] == 0) {
      uVar2 = MediaFile_GetFileLen(puVar1);
      puVar1[1] = uVar2;
      if (puVar1[1] == 0) {
        if (*(int *)puVar1[8] != 0) {
          (**(code **)puVar1[8])("##MFILE: ERROR--File total length is zero##\r\n");
        }
        MediaFile_Close(puVar1);
        puVar1 = (undefined4 *)0x0;
      }
    }
    else if (puVar1[3] != 1) {
      puVar1[1] = 0xffffffff;
    }
  }
  return puVar1;
}



undefined4 MediaFile_ReOpen(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *param_1;
    *param_1 = param_2;
    if (param_1[3] == 0) {
      uVar1 = MediaFile_GetFileLen(param_1);
      param_1[1] = uVar1;
      if (param_1[1] == 0) {
        if (*(int *)param_1[8] != 0) {
          (**(code **)param_1[8])("##MFILE: ERROR--Reopen, File total length is zero##\r\n");
        }
        *param_1 = uVar2;
        return 0;
      }
      param_1[4] = 0;
    }
    else {
      if (param_1[3] != 1) {
        return 0;
      }
      param_1[1] = 0;
      param_1[5] = 0;
    }
    param_1[2] = 0;
    uVar2 = 1;
  }
  return uVar2;
}



undefined4 MediaFile_Close(int param_1)

{
  if (param_1 != 0) {
    (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(param_1);
  }
  return 0;
}



undefined4 check_midi_file(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [20];
  short local_14;
  short local_12;
  uint local_10;
  undefined1 *local_c;
  
  local_10 = 0;
  local_12 = 0;
  local_14 = 0;
  local_c = auStack_28;
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar1 = memcmp((void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),&DAT_0005c32c,4);
  if (iVar1 == 0) {
    MediaFile_SetPosition(param_1,0x14);
    iVar1 = MediaFile_Read(param_1,local_c,0x12);
    if (iVar1 != 0x12) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--read midi data error\r\n");
      }
      return 0;
    }
  }
  else {
    memcpy(local_c,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),0x12);
    MediaFile_SetPosition(param_1,0x12);
  }
  iVar1 = memcmp(local_c,&DAT_0005c35c,4);
  if ((iVar1 == 0) && (iVar1 = memcmp(local_c + 0xe,&DAT_0005c364,4), iVar1 == 0)) {
    local_10 = mov_str2ulong(local_c + 4);
    local_12 = CONCAT11(local_c[8],local_c[9]);
    local_14 = CONCAT11(local_c[10],local_c[0xb]);
    if (((local_12 == 0) && (local_14 != 1)) || (local_10 < 6)) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--unsupported midi##\r\n");
      }
      *(undefined4 *)(param_1 + 0x10) = 2;
      uVar2 = 0;
    }
    else {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: find midi header##\r\n");
      }
      uVar2 = 0xe;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



int check_riff_header(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_48 [36];
  uint local_24;
  undefined1 *local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_24 = 0;
  local_18 = 0;
  local_20 = auStack_48;
  *(undefined4 *)(param_1 + 0x10) = 0;
  memcpy(local_20,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),0xc);
  MediaFile_SetPosition(param_1,0xc);
  iVar1 = memcmp(local_20,&DAT_0005c32c,4);
  if ((iVar1 == 0) || (iVar1 = memcmp(local_20,&DAT_0005c3b4,4), iVar1 == 0)) {
    iVar1 = str2ulong(local_20 + 4);
    local_18 = iVar1 + 8;
    local_24 = str2ulong(local_20 + 8);
    if (local_24 == 0x414b4e41) {
      local_14 = 1;
      *(uint *)(param_1 + 4) = local_18;
    }
    else {
      if (local_24 < 0x414b4e42) {
        if (local_24 == 0x20495641) {
          local_14 = 2;
          goto LAB_0004f47c;
        }
      }
      else {
        if (local_24 == 0x44494d52) {
          iVar1 = check_midi_file(param_1,param_2);
          return iVar1;
        }
        if (local_24 == 0x45564157) {
          local_1c = 0x14;
          do {
            iVar1 = MediaFile_Read(param_1,local_20,10);
            if (iVar1 != 10) {
              if (**(int **)(param_1 + 0x20) != 0) {
                (*(code *)**(undefined4 **)(param_1 + 0x20))
                          ("##MFILE: ERROR--Read while checking wav header %d##\r\n",local_1c);
              }
              *(undefined4 *)(param_1 + 0x10) = 2;
              return 0;
            }
            iVar1 = memcmp(local_20,&DAT_0005c3f4,4);
            if (iVar1 == 0) break;
            local_1c = local_1c + -1;
            iVar1 = str2ulong(local_20 + 4);
            MediaFile_ChangePosition(param_1,iVar1 + -2);
          } while (local_1c != 0);
          if (local_1c == 0) {
            if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--wav header##\r\n");
            }
            *(undefined4 *)(param_1 + 0x10) = 2;
            return 0;
          }
          local_1c = str2ushort(local_20 + 8);
          if ((local_1c == 0x50) || (local_1c == 0x55)) {
            local_14 = 10;
            if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: mp3 file in WAV##\r\n");
            }
          }
          else {
            local_14 = 3;
            if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: WAV file##\r\n");
            }
          }
          goto LAB_0004f47c;
        }
      }
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: unknown RIFF file##\r\n");
      }
      *(undefined4 *)(param_1 + 0x10) = 2;
    }
  }
LAB_0004f47c:
  if (local_14 != 0) {
    if (local_14 == 2) {
      if ((local_18 < *(uint *)(param_1 + 4)) || (*(int *)(param_1 + 4) == -1)) {
        MediaFile_SetPosition(param_1,local_18);
        iVar1 = MediaFile_Read(param_1,local_20,8);
        if ((iVar1 == 8) && (local_24 = str2ulong(local_20), local_24 == 0x414b4e41)) {
          local_1c = str2ulong(local_20 + 4);
          local_18 = local_1c + local_18 + 8;
          iVar1 = MediaFile_Read(param_1,local_20,0x24);
          if (iVar1 == 0x24) {
            iVar1 = str2ulong(local_20 + 4);
            iVar2 = str2ulong(local_20 + 0xc);
            if (((uint)(iVar1 + iVar2) < local_1c) &&
               ((local_18 <= *(uint *)(param_1 + 4) || (*(int *)(param_1 + 4) == -1)))) {
              local_1c = Dnp_Crc(local_20,0x20);
              iVar1 = str2ulong(local_20 + 0x20);
              if (iVar1 == local_1c) {
                local_14 = 0xb;
              }
              else if (**(int **)(param_1 + 0x20) != 0) {
                (*(code *)**(undefined4 **)(param_1 + 0x20))
                          ("##MFILE: ERROR--Crc error while checking akv header##\r\n");
              }
            }
            else if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))
                        (
                        "##MFILE: ERROR--file length error while checking akv, so open as normal file##\r\n"
                        );
            }
          }
          else if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))
                      ("##MFILE: ERROR--Read error while checking akv header 2##\r\n");
          }
        }
      }
    }
    else if ((*(uint *)(param_1 + 4) < local_18) && (**(int **)(param_1 + 0x20) != 0)) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))
                ("##MFILE: WARNING--File is likely to be damaged, because real filelen(0x%x) is less than length in file(0x%x)##\r\n"
                 ,*(undefined4 *)(param_1 + 4),local_18);
    }
  }
  return local_14;
}



int check_mov_header(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_34 [8];
  uint local_2c;
  uint local_28;
  undefined1 *local_24;
  char local_1d;
  int local_1c;
  ushort local_16;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  local_28 = 0;
  local_14 = 0;
  local_16 = 0;
  local_1c = 10;
  local_1d = '\0';
  if ((((0x7a < *(byte *)(param_2 + 4)) || (*(byte *)(param_2 + 4) < 0x61)) ||
      (0x7a < *(byte *)(param_2 + 5))) ||
     (((*(byte *)(param_2 + 5) < 0x61 || (0x7a < *(byte *)(param_2 + 6))) ||
      ((*(byte *)(param_2 + 6) < 0x61 ||
       ((0x7a < *(byte *)(param_2 + 7) || (*(byte *)(param_2 + 7) < 0x61)))))))) {
    return 0;
  }
  local_24 = auStack_34;
  *(undefined4 *)(param_1 + 0x10) = 0;
  memcpy(local_24,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),8);
  MediaFile_SetPosition(param_1,8);
  do {
    if (*(int *)(param_1 + 0x10) == 1) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: ERROR--Read error while checking mov header##\r\n");
      }
      goto LAB_0004fcc4;
    }
    local_10 = mov_str2ulong(local_24);
    local_28 = str2ulong(local_24 + 4);
    if ((local_10 < 8) ||
       (iVar1 = MediaFile_GetPosition(param_1), (iVar1 + local_10) - 8 < local_10 - 8)) {
      if ((local_10 != 1) || ((local_c != 0x16 && (local_c != 4)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--Atom size error while checking mov header##\r\n");
        }
LAB_0004fcc4:
        if (local_c == 0) {
          return 0;
        }
        if ((local_16 & 2) == 0) {
          if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))
                      ("##MFILE: ERROR--missing header (moov/cmov) chunk! Maybe broken file##\r\n");
          }
          *(undefined4 *)(param_1 + 0x10) = 2;
          return 0;
        }
        if ((local_16 & 4) == 0) {
          if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))
                      ("##MFILE: ERROR--missing data (mdat) chunk! Maybe broken file##\r\n");
          }
          *(undefined4 *)(param_1 + 0x10) = 2;
          return 0;
        }
        if ((local_16 & 1) != 0) {
          return local_c;
        }
        if (**(int **)(param_1 + 0x20) == 0) {
          return local_c;
        }
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: unknown QT file##\r\n");
        return local_c;
      }
      iVar1 = MediaFile_Read(param_1,local_24,8);
      if (iVar1 == 8) {
        local_10 = mov_str2ulong(local_24);
        if (local_10 != 0) {
          if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))
                      ("##MFILE: ERROR--Length error while checking mov header##\r\n");
          }
          goto LAB_0004fcc4;
        }
        local_10 = mov_str2ulong(local_24 + 4);
      }
    }
    local_14 = local_14 + local_10;
    if (local_28 == 0x7461646d) {
      local_1d = '\x01';
      local_16 = local_16 | 4;
    }
    else if (local_28 < 0x7461646e) {
      if (local_28 == 0x70797466) {
        local_1d = '\x01';
        local_16 = local_16 | 1;
        iVar1 = MediaFile_Read(param_1,local_24,4);
        if (iVar1 == 4) {
          iVar1 = memcmp(local_24,&DAT_0005c668,3);
          if (iVar1 == 0) {
            local_c = 5;
          }
          else {
            local_2c = str2ulong(local_24);
            if (local_2c == 0x3134706d) {
              local_c = 4;
            }
            else if (local_2c < 0x3134706e) {
              if (local_2c == 0x2041344d) {
                local_c = 6;
              }
              else if (local_2c < 0x2041344e) {
                if (local_2c == 0x20207471) {
                  local_c = 7;
                }
              }
              else if (local_2c == 0x2050344d) {
                local_c = 6;
              }
              else if (local_2c == 0x20763466) {
                local_c = 0x16;
              }
            }
            else if (local_2c == 0x346f7369) {
              local_c = 4;
            }
            else if (local_2c < 0x346f736a) {
              if (local_2c == 0x3234706d) {
                local_c = 4;
              }
            }
            else if (local_2c == 0x34706d6d) {
              local_c = 4;
            }
            else if (local_2c == 0x6d6f7369) {
              local_c = 4;
            }
          }
        }
      }
      else {
LAB_0004fc48:
        if (local_1d == '\0') {
          local_1c = local_1c + -1;
        }
      }
    }
    else {
      if ((local_28 != 0x766f6d63) && (local_28 != 0x766f6f6d)) goto LAB_0004fc48;
      local_1d = '\x01';
      local_16 = local_16 | 2;
      if (local_c == 0) {
        local_c = 7;
      }
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("#MOV: Movie header found!#\r\n");
      }
    }
    if ((((local_16 & 6) == 6) || (local_1c == 0)) || (*(uint *)(param_1 + 4) <= local_14))
    goto LAB_0004fcc4;
    MediaFile_SetPosition(param_1,local_14);
    iVar1 = MediaFile_Read(param_1,local_24,8);
    if (iVar1 != 8) goto LAB_0004fcc4;
  } while( true );
}



undefined4 check_id3_header(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*param_2 < 10) {
    uVar2 = 0;
  }
  else {
    uVar1 = mov_str2ulong(param_1);
    if (uVar1 >> 8 == 0x494433) {
      *param_2 = (*(byte *)(param_1 + 6) & 0x7f) * 0x200000 +
                 (*(byte *)(param_1 + 7) & 0x7f) * 0x4000 + (*(byte *)(param_1 + 8) & 0x7f) * 0x80 +
                 (*(byte *)(param_1 + 9) & 0x7f) + 10;
      uVar2 = 1;
    }
    else {
      *param_2 = 0;
      uVar2 = 0;
    }
  }
  return uVar2;
}



uint MediaFile_SkipID3(undefined4 param_1,uint param_2)

{
  int iVar1;
  int local_20;
  undefined1 auStack_1c [12];
  uint local_10;
  int local_c;
  
  local_20 = 10;
  local_c = 5;
  local_10 = 0;
  local_10 = MediaFile_GetTotalLen(param_1);
  if (local_10 < param_2) {
    if (local_10 < 0x8001) {
      param_2 = 0;
    }
    else {
      param_2 = local_10 - 0x8000;
    }
  }
  else {
    MediaFile_SetPosition(param_1,param_2);
    iVar1 = MediaFile_Read(param_1,auStack_1c,10);
    if (iVar1 == 10) {
      do {
        if (local_c == 0) break;
        local_c = local_c + -1;
        local_20 = 10;
        iVar1 = check_id3_header(auStack_1c,&local_20);
        if (iVar1 == 0) break;
        if (0 < local_20 + -10) {
          MediaFile_ChangePosition(param_1,local_20 + -10);
        }
        iVar1 = MediaFile_Read(param_1,auStack_1c,10);
      } while (iVar1 == 10);
      iVar1 = MediaFile_GetPosition(param_1);
      param_2 = (iVar1 + local_20) - 10;
      if (local_10 < param_2) {
        if (local_10 < 0x8001) {
          param_2 = 0;
        }
        else {
          param_2 = local_10 - 0x8000;
        }
      }
    }
  }
  return param_2;
}



undefined4 check_mp3_file(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined1 auStack_1c [12];
  int local_10;
  undefined1 *local_c;
  
  local_10 = 0;
  local_20 = 10;
  local_c = auStack_1c;
  *(undefined4 *)(param_1 + 0x10) = 0;
  memcpy(local_c,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),10);
  iVar1 = check_id3_header(auStack_1c,&local_20);
  if (iVar1 == 0) {
    MediaFile_SetPosition(param_1,4);
  }
  else {
    local_20 = MediaFile_SkipID3(param_1,local_20);
    MediaFile_SetPosition(param_1,local_20);
    iVar1 = MediaFile_Read(param_1,local_c,4);
    if (iVar1 != 4) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: ERROR--Read error while checking mp3 header##\r\n");
      }
      return 0;
    }
  }
  local_10 = check_mp3layer(local_c);
  if (local_10 - 1U < 3) {
    *(undefined4 *)(param_1 + 0x1c) = local_20;
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: MP3 layer %d##\r\n",local_10);
    }
    uVar2 = 10;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 check_flv_header(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp((void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),&DAT_0005c790,3);
  if (iVar1 == 0) {
    uVar2 = 0xf;
  }
  else {
    iVar1 = memcmp((void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),&DAT_0005c794,3);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),&DAT_0005c798,3),
       iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined4 check_amr_file(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp((void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),"#!AMR\n",6);
  if (iVar1 == 0) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: find #!AMR\\n##\r\n");
    }
    uVar2 = 0xd;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 check_aac_file(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined1 auStack_24 [12];
  int local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_18 = 0;
  local_10 = 10;
  local_28 = 10;
  local_14 = auStack_24;
  *(undefined4 *)(param_1 + 0x10) = 0;
  memcpy(local_14,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),10);
  iVar1 = check_id3_header(auStack_24,&local_28);
  if (iVar1 != 0) {
    MediaFile_SetPosition(param_1,local_28);
    iVar1 = MediaFile_Read(param_1,local_14,4);
    if (iVar1 != 4) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: ERROR--Read error while checking aac header##\r\n");
      }
      return 0;
    }
  }
  iVar1 = memcmp(local_14,&DAT_0005c7fc,4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = local_28;
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: find ADIF##\r\n");
    }
    uVar3 = 0xc;
  }
  else {
    local_c = 3;
    MediaFile_SetPosition(param_1,local_28);
    for (; local_10 != 0; local_10 = local_10 + -1) {
      local_18 = AACDemuxer_GetNextHeader(param_1);
      if (local_18 < 1) {
        return 0;
      }
      MediaFile_ChangePosition(param_1,local_18);
      iVar1 = MediaFile_Read(param_1,auStack_24,2);
      if (iVar1 != 2) {
        return 0;
      }
      uVar2 = mov_str2ushort(auStack_24);
      if (((uVar2 & 0xfff6) == 0xfff0) && (iVar1 = mov_str2ushort(auStack_24), iVar1 != 0xfff0)) {
        local_c = local_c + -1;
        if (local_c == 0) break;
      }
      else {
        local_c = 3;
      }
      MediaFile_ChangePosition(param_1,0xfffffffe);
    }
    if (local_10 == 0) {
      uVar3 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = local_28;
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: find aac header##\r\n");
      }
      uVar3 = 0xc;
    }
  }
  return uVar3;
}



int MediaFile_SkipZeroBytes(int param_1,int param_2)

{
  undefined1 auStack_11c [256];
  undefined1 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = 0;
  local_c = 0;
  local_14 = 2000;
  local_1c = auStack_11c;
  local_10 = param_2;
  MediaFile_SetPosition(param_1,param_2);
  for (; local_14 != 0; local_14 = local_14 + -1) {
    local_c = 0;
    local_18 = MediaFile_Read(param_1,auStack_11c,0x100);
    if (local_18 < 0x40) {
      return -1;
    }
    local_18 = local_18 >> 2;
    for (; (local_c < local_18 && (*(int *)(local_1c + local_c * 4) == 0)); local_c = local_c + 1) {
    }
    local_10 = local_10 + local_c * 4;
    if (local_c < local_18) break;
  }
  if (local_14 == 0) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--so many zero bytes##\r\n");
    }
    local_10 = -1;
  }
  else {
    while ((*(uint *)(local_1c + local_c * 4) & 0xff) == 0) {
      local_10 = local_10 + 1;
      *(uint *)(local_1c + local_c * 4) = *(uint *)(local_1c + local_c * 4) >> 8;
    }
  }
  return local_10;
}



undefined4 check_mp3_header(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = 10;
  MediaFile_SetPosition(param_1,0);
  iVar1 = check_id3_header(param_2 + (uint)*(ushort *)(param_2 + 0x40),&local_18);
  if (iVar1 == 0) {
    local_18 = MediaFile_SkipZeroBytes(param_1,0);
    if (local_18 < 0) {
      return 0;
    }
    MediaFile_SetPosition(param_1,local_18);
    *(int *)(param_1 + 0x1c) = local_18;
  }
  else {
    if (*(int *)(param_1 + 4) == -1) {
      uVar2 = MediaFile_GetFileLen(param_1);
      *(undefined4 *)(param_1 + 4) = uVar2;
    }
    local_18 = MediaFile_SkipID3(param_1,local_18);
    MediaFile_SetPosition(param_1,local_18);
  }
  local_10 = 0;
  local_c = 0;
  local_14 = (**(code **)(*(int *)(param_1 + 0x20) + 0x14))(0x8000);
  if (local_14 == 0) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--malloc:%d\n",0x8000);
    }
    uVar2 = 0;
  }
  else {
    local_10 = MediaFile_Read(param_1,local_14,0x8000);
    if (*(int *)(param_1 + 0x10) == 0) {
      do {
        while( true ) {
          if (local_10 + -1 <= local_c) {
            return 0;
          }
          if (*(char *)(local_14 + local_c) == -1) break;
          local_c = local_c + 1;
        }
        local_c = local_c + 1;
      } while ((*(byte *)(local_14 + local_c) & 0xe0) != 0xe0);
      (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(local_14);
      uVar2 = 10;
    }
    else {
      (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(local_14);
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined4 check_ape_header(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  uint local_28;
  char *local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = 8;
  local_10 = 0;
  local_28 = 10;
  local_14 = 0;
  local_18 = 0;
  local_20 = 0x4d414320;
  local_1c = 0;
  local_24 = (char *)(**(code **)(*(int *)(param_1 + 0x20) + 0x14))(0x1000);
  if (local_24 == (char *)0x0) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--malloc:%d\n",0x1000);
    }
    return 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  memcpy(local_24,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),0x40);
  local_10 = 0x40;
  iVar1 = check_id3_header(local_24,&local_28);
  if (iVar1 != 0) {
    MediaFile_SetPosition(param_1,local_28);
    local_10 = MediaFile_Read(param_1,local_24,0x10);
    if (local_10 != 0x10) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: ERROR--Read error while checking ape header 1##\r\n");
      }
      local_1c = 0;
      goto LAB_00050eb8;
    }
    local_14 = 1;
  }
  if ((((*local_24 == 'A') && (local_24[1] == 'P')) && (local_24[2] == 'E')) &&
     (((local_24[3] == 'T' && (local_24[4] == 'A')) &&
      ((local_24[5] == 'G' && ((local_24[6] == 'E' && (local_24[7] == 'X')))))))) {
    iVar1 = str2ulong(local_24 + 0xc);
    local_28 = iVar1 + local_28;
    MediaFile_SetPosition(param_1,local_28);
    local_10 = MediaFile_Read(param_1,local_24,4);
    if ((*(int *)(param_1 + 0x10) != 0) || (local_10 != 4)) {
      if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: ERROR--Read error while checking ape header 2##\r\n");
      }
      local_1c = 0;
      goto LAB_00050eb8;
    }
  }
  if ((((*local_24 == 'M') && (local_24[1] == 'A')) && (local_24[2] == 'C')) && (local_24[3] == ' ')
     ) {
    *(uint *)(param_1 + 0x1c) = local_28;
    local_1c = 0x10;
  }
  else {
    if (local_14 != 0) {
      local_28 = local_28 >> 2;
      MediaFile_SetPosition(param_1,local_28);
      local_10 = MediaFile_Read(param_1,local_24,0x1000);
    }
    local_18 = mov_str2ulong(local_24);
    local_14 = 4;
    do {
      for (; local_14 < local_10; local_14 = local_14 + 1) {
        if (local_20 == local_18) {
          *(uint *)(param_1 + 0x1c) = local_28 + local_14 + -4;
          local_1c = 0x10;
          goto LAB_00050eb8;
        }
        local_18 = local_18 << 8 | (uint)(byte)local_24[local_14];
      }
      local_28 = local_28 + local_10;
      MediaFile_SetPosition(param_1,local_28);
      local_10 = MediaFile_Read(param_1,local_24,0x1000);
      if ((*(int *)(param_1 + 0x10) != 0) || (local_10 < 0x40)) {
        local_1c = 0;
        goto LAB_00050eb8;
      }
      local_14 = 0;
      iVar1 = local_c + -1;
      bVar2 = local_c != 0;
      local_c = iVar1;
    } while (bVar2);
    local_1c = 0;
  }
LAB_00050eb8:
  (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(local_24);
  return local_1c;
}



undefined4 check_flac_header(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined1 auStack_14 [12];
  
  local_18 = 10;
  memcpy(auStack_14,(void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40)),10);
  iVar1 = check_id3_header(auStack_14,&local_18);
  if (iVar1 != 0) {
    MediaFile_SetPosition(param_1,0);
    local_18 = MediaFile_SkipID3(param_1,local_18);
    MediaFile_SetPosition(param_1,local_18);
    MediaFile_Read(param_1,auStack_14,4);
  }
  iVar1 = memcmp(auStack_14,&DAT_0005c8f8,4);
  if (iVar1 == 0) {
    uVar2 = 0x11;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 check_ogg_header(int param_1,int param_2)

{
  int iVar1;
  int local_14;
  void *local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = (void *)(param_2 + (uint)*(ushort *)(param_2 + 0x40));
  iVar1 = memcmp(local_10,&DAT_0005c900,4);
  if (iVar1 == 0) {
    iVar1 = memcmp((void *)((int)local_10 + 0x1d),"vorbis",6);
    if (iVar1 == 0) {
      local_c = 0x14;
    }
    else {
      iVar1 = memcmp((void *)((int)local_10 + 0x1d),&DAT_0005c910,4);
      if (iVar1 == 0) {
        if (*(char *)((int)local_10 + 0x1c) == '\x7f') {
          local_c = 0x12;
        }
        else {
          if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--unsupported ogg##\r\n");
          }
          *(undefined4 *)(param_1 + 0x10) = 2;
        }
      }
      else {
        iVar1 = memcmp((void *)((int)local_10 + 0x1c),"Speex   ",8);
        if (iVar1 == 0) {
          local_14 = 8000;
          MediaFile_SetPosition(param_1,0x40);
          iVar1 = MediaFile_Read(param_1,&local_14,4);
          if (iVar1 == 4) {
            if (local_14 == 8000) {
              local_c = 0x18;
            }
            else if ((local_14 == 16000) || (local_14 == 32000)) {
              local_c = 0x19;
            }
            else if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))
                        ("##MFILE: ERROR--unsupported speex: sr=%d\r\n",local_14);
            }
          }
          else {
            if (**(int **)(param_1 + 0x20) != 0) {
              (*(code *)**(undefined4 **)(param_1 + 0x20))
                        ("##MFILE: ERROR--read speex sr data error\r\n");
            }
            local_c = 0;
          }
        }
        else {
          if (**(int **)(param_1 + 0x20) != 0) {
            (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--unsupported ogg##\r\n");
          }
          *(undefined4 *)(param_1 + 0x10) = 2;
        }
      }
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}



undefined4 check_ac3_header(int param_1,char *param_2)

{
  int iVar1;
  byte bVar2;
  int aiStack_74 [19];
  int local_28;
  char *local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  uint local_10;
  char *local_c;
  
  local_1c = 0;
  local_20 = 0;
  local_10 = 0;
  memcpy(aiStack_74,&DAT_0005c9a0,0x4c);
  local_18 = 0;
  local_24 = (char *)(**(code **)(*(int *)(param_1 + 0x20) + 0x14))(500);
  if (local_24 == (char *)0x0) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--malloc:%d\n",500);
    }
    return 0;
  }
  local_c = param_2;
  if ((*param_2 != '\v') || (param_2[1] != 'w')) {
    MediaFile_SetPosition(param_1,0);
    local_20 = MediaFile_Read(param_1,local_24,500);
    if (local_20 < 6) {
      local_18 = 0;
      goto LAB_000515c4;
    }
    local_20 = local_20 - 6;
    for (; local_10 < local_20; local_10 = local_10 + 1) {
      if ((local_24[local_10] == '\v') && (local_24[local_10 + 1] == 'w')) {
        local_c = local_24 + local_10;
        break;
      }
    }
    if (local_20 == local_10) {
      local_18 = 0;
      goto LAB_000515c4;
    }
  }
  if ((byte)local_c[5] < 0x60) {
    local_1c = (byte)local_c[4] & 0x3f;
    if (local_1c < 0x26) {
      local_28 = aiStack_74[local_1c >> 1];
      bVar2 = local_c[4] & 0xc0;
      if (bVar2 == 0x40) {
        local_14 = ((uint)(local_28 * 0x140) / 0x93 + ((byte)local_c[4] & 1)) * 2;
      }
      else if (bVar2 == 0x80) {
        local_14 = local_28 * 6;
      }
      else {
        if ((local_c[4] & 0xc0U) != 0) {
          local_18 = 0;
          goto LAB_000515c4;
        }
        local_14 = local_28 << 2;
      }
      MediaFile_SetPosition(param_1,local_14 + local_10);
      iVar1 = MediaFile_Read(param_1,local_24,7);
      if (iVar1 == 7) {
        if ((*local_24 == '\v') && (local_24[1] == 'w')) {
          *(uint *)(param_1 + 0x1c) = local_10;
          local_18 = 0x17;
        }
        else {
          local_18 = 0;
        }
      }
      else {
        local_18 = 0;
      }
    }
    else {
      local_18 = 0;
    }
  }
  else {
    local_18 = 0;
  }
LAB_000515c4:
  (**(code **)(*(int *)(param_1 + 0x20) + 0x18))(local_24);
  return local_18;
}



int MediaFile_CheckMediaType(int param_1,uint param_2)

{
  int iVar1;
  undefined1 auStack_58 [64];
  undefined2 local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(uint *)(param_1 + 4);
  if (local_10 == 0xffffffff) {
    MediaFile_SetReadMode(param_1,1);
  }
  else if (local_10 < 0x40) {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))
                ("##MFILE: ERROR--(%d)length of file is not enough, maybe it is not a media file\r\n"
                 ,local_10);
    }
    return 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_14 = local_10;
  local_18 = 0;
  MediaFile_SetPosition(param_1,0);
  iVar1 = MediaFile_Read(param_1,auStack_58,0x40);
  if (iVar1 == 0x40) {
    if (((param_2 & 3) == 0) ||
       (local_c = check_riff_header(param_1,auStack_58), *(int *)(param_1 + 0x10) == 0)) {
      if ((local_c == 0) &&
         (((param_2 & 3) != 0 &&
          (local_c = check_mov_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--mov checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 1) != 0 &&
               (local_c = check_midi_file(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--mid checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 1) != 0 &&
               (local_c = check_amr_file(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--amr checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 1) != 0 &&
               (local_c = check_flv_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--flv checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 3) != 0 &&
               (local_c = check_ogg_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--ogg checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 3) != 0 &&
               (local_c = check_flac_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--flac checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 1) != 0 &&
               (local_c = check_ape_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--asf checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 1) != 0 &&
               (local_c = check_ac3_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--ac3 checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 5) != 0 &&
               (local_c = check_mp3_file(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--mp3 checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 5) != 0 &&
               (local_c = check_aac_file(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--aac checking terminate abnormally##\r\n");
        }
      }
      else if ((local_c == 0) &&
              (((param_2 & 5) != 0 &&
               (local_c = check_mp3_header(param_1,auStack_58), *(int *)(param_1 + 0x10) != 0)))) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))
                    ("##MFILE: ERROR--checking terminate abnormally##\r\n");
        }
      }
      else if (local_c == 0) {
        if (**(int **)(param_1 + 0x20) != 0) {
          (*(code *)**(undefined4 **)(param_1 + 0x20))("##UNKNOWN FILE TYPE##\r\n");
        }
      }
      else if (**(int **)(param_1 + 0x20) != 0) {
        (*(code *)**(undefined4 **)(param_1 + 0x20))
                  ("##MFILE: check file successfully, and type id is %d (%s file)##\r\n",local_c,
                   "UNKNOWN" + local_c * 8);
      }
    }
    else if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))
                ("##MFILE: ERROR--riff checking terminate abnormally##\r\n");
    }
  }
  else {
    if (**(int **)(param_1 + 0x20) != 0) {
      (*(code *)**(undefined4 **)(param_1 + 0x20))("##MFILE: ERROR--read first data error\r\n");
    }
    local_c = 0;
  }
  return local_c;
}



undefined4 MediaFile_CheckType(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_c;
  
  ZeroMemory(&local_2c,0x24,param_3,&local_2c,param_2,param_1);
  local_28 = 0xffffffff;
  local_2c = param_1;
  local_c = param_2;
  uVar1 = MediaFile_CheckMediaType(&local_2c,1);
  return uVar1;
}



int MediaFile_CheckTypeForID3(undefined4 param_1,int *param_2)

{
  undefined4 local_30;
  undefined4 local_2c;
  int *local_10;
  int local_c;
  
  local_c = 0;
  ZeroMemory(&local_30,0x24);
  local_2c = 0xffffffff;
  local_30 = param_1;
  local_10 = param_2;
  local_c = MediaFile_CheckMediaType(&local_30,2);
  if (local_c == 0) {
    if (*local_10 != 0) {
      (*(code *)*local_10)("##MFILE: maybe other media file##\r\n");
    }
    local_c = 10;
  }
  else if (*local_10 != 0) {
    (*(code *)*local_10)("##MFILE: CheckTypeForID3 %d##\r\n",local_c);
  }
  return local_c;
}



undefined4 Demuxer_SetDataEnd(int param_1,char param_2)

{
  if (param_2 == '\x01') {
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  else if (param_2 == '\x02') {
    *(undefined1 *)(param_1 + 0xd) = 1;
  }
  else if (param_2 == '\0') {
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined1 *)(param_1 + 0xd) = 1;
  }
  if (((*(int *)(param_1 + 8) - 3U < 3) && (*(char *)(param_1 + 0xc) != '\0')) &&
     (*(char *)(param_1 + 0xd) != '\0')) {
    (*g_medialib_printf)("##Demuxer: end(%d)##\r\n",*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return *(undefined4 *)(param_1 + 8);
}



undefined4 S_Demuxer_SeekVideo(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < (uint)param_1[5]) && (param_1[0x1c] != 0)) {
    if (param_1[0x1b] != 0) {
      (*(code *)param_1[0x1b])(param_1[0xb],param_1[0x28]);
    }
    param_1[0x10] = 0;
    param_1[0x11] = -1;
    param_1[0xf] = -1;
    iVar1 = (*(code *)param_1[0x1c])(param_1[0xb],param_2);
    if (iVar1 < 0) {
      (*g_medialib_printf)("##Demuxer: ERROR--seek video %d##\r\n",param_2);
      uVar2 = 0;
    }
    else {
      *param_1 = iVar1;
      (*g_medialib_printf)("##Demuxer: SeekVideo %d (%d)##\r\n",param_2,iVar1);
      uVar2 = 1;
    }
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--video can\'t seek that far##\r\n");
    uVar2 = 0;
  }
  return uVar2;
}



int S_Demuxer_SeekAudio(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x74) == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--SeekAudio func##\r\n");
    iVar1 = -1;
  }
  else {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    iVar1 = (**(code **)(param_1 + 0x74))(*(undefined4 *)(param_1 + 0x2c),param_2);
    if (iVar1 < 0) {
      (*g_medialib_printf)("##Demuxer: ERROR--seek audio %d##\r\n",param_2);
    }
    else {
      *(int *)(param_1 + 4) = iVar1;
      (*g_medialib_printf)
                ("##Demuxer: SeekAudio %d (%d)##\r\n",param_2,*(undefined4 *)(param_1 + 4));
      iVar1 = *(int *)(param_1 + 4);
    }
  }
  return iVar1;
}



undefined4 S_Demuxer_GetVideoFrame(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x60) == 0)) {
    (*g_medialib_printf)("##Demuxer: ERROR--get video frame, NO VIDEO##\r\n");
    uVar2 = 0;
  }
  else if (param_2 == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--get video frame, buffer is NULL##\r\n");
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    iVar1 = (**(code **)(param_1 + 0x60))(*(undefined4 *)(param_1 + 0x2c),param_2,param_3);
    if (iVar1 == 0) {
      Demuxer_SetDataEnd(param_1,1);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



int Demuxer_GetAudioData(int param_1,int param_2,int param_3)

{
  int local_14;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    (*g_medialib_printf)("##Demuxer: ERROR--get audio, buffer is NULL or bytes is zero##\r\n");
    local_14 = 0;
  }
  else if (*(char *)(param_1 + 0xd) == '\0') {
    if (((*(int *)(param_1 + 0x38) == -1) || (*(int *)(param_1 + 0x38) == 0)) ||
       (*(int *)(param_1 + 0x38) != param_3)) {
      (*g_medialib_printf)
                ("##Demuxer: WARINIG--no a_last_size or size error %d##\r\n",
                 *(undefined4 *)(param_1 + 0x38));
      local_14 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      if (*(int *)(param_1 + 100) == 0) {
        local_14 = MediaFile_Read(*(undefined4 *)(param_1 + 0x20),param_2,param_3);
      }
      else {
        local_14 = (**(code **)(param_1 + 100))(*(undefined4 *)(param_1 + 0x2c),param_2,param_3);
      }
      if (local_14 == 0) {
        (*g_medialib_printf)("##Demuxer: GetAudioData is NULL, no more audio data##\r\n");
        Demuxer_SetDataEnd(param_1,2);
      }
    }
  }
  else {
    local_14 = 0;
  }
  return local_14;
}



int Demuxer_GetAudioDataSize(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xd) == '\0') {
    if (*(int *)(param_1 + 0x88) == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0x400;
      iVar1 = 0x400;
    }
    else if (*(int *)(param_1 + 0x38) == -1) {
      *(undefined4 *)(param_1 + 0x40) = 0;
      iVar1 = (**(code **)(param_1 + 0x88))(*(undefined4 *)(param_1 + 0x2c));
      if (iVar1 == 0) {
        (*g_medialib_printf)("##Demuxer: no more audio data##\r\n");
        Demuxer_SetDataEnd(param_1,2);
      }
      *(int *)(param_1 + 0x38) = iVar1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x38);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 Demuxer_GetAudioPackPts(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    uVar1 = 0;
  }
  else if ((*(int *)(param_1 + 0x38) == -1) || (*(int *)(param_1 + 0x38) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x8c))(*(undefined4 *)(param_1 + 0x2c));
    *param_2 = uVar1;
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 S_Demuxer_GetFirstKeyframeSize(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x7c) == 0)) {
    (*g_medialib_printf)("##Demuxer: ERROR--get first key frame size, NO VIDEO##\r\n");
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x7c))(*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



undefined4 S_Demuxer_GetFirstKeyframe(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x78) == 0)) {
    (*g_medialib_printf)("##Demuxer: ERROR--get first key frame, NO VIDEO##\r\n");
    uVar1 = 0;
  }
  else if (param_2 == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--get first key frame, buffer is NULL##\r\n");
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x78))(*(undefined4 *)(param_1 + 0x2c),param_2,param_3);
  }
  return uVar1;
}



uint S_Demuxer_GetVideoFrameSize(uint *param_1)

{
  uint uVar1;
  
  if (param_1[0x1a] == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--GetVideoSize func##\r\n");
    uVar1 = 0;
  }
  else if (*param_1 < param_1[5]) {
    if (param_1[0xf] == 0xffffffff) {
      param_1[0x10] = 0;
      uVar1 = (*(code *)param_1[0x1a])(param_1[0xb]);
      param_1[0xf] = uVar1;
      uVar1 = param_1[0xf];
    }
    else {
      uVar1 = param_1[0xf];
    }
  }
  else {
    (*g_medialib_printf)("##Demuxer: WARNING--get frame size, no next frame##\r\n");
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 S_Demuxer_GetNextKeyframeSize(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--get next key frame size, NO VIDEO##\r\n");
    uVar2 = 0;
  }
  else if ((*(int *)(param_1 + 0x80) == 0) || (*(int *)(param_1 + 0x68) == 0)) {
    (*g_medialib_printf)("##Demuxer: WARNING--SeekNextKey func##\r\n");
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x3c) == -1) {
    if ((*(char *)(param_1 + 0x30) == '\0') &&
       (iVar1 = (**(code **)(param_1 + 0x80))(*(undefined4 *)(param_1 + 0x2c)), iVar1 == 0)) {
      (*g_medialib_printf)("##Demuxer: WARNING--seek next key frame##\r\n");
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x68))(*(undefined4 *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x3c);
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x3c);
  }
  return uVar2;
}



undefined4 S_Demuxer_GetPrevKeyframeSize(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--get prev key frame size, NO VIDEO##\r\n");
    uVar2 = 0;
  }
  else if ((*(int *)(param_1 + 0x84) == 0) || (*(int *)(param_1 + 0x68) == 0)) {
    (*g_medialib_printf)("##Demuxer: WARNING--SeekPrevKey func##\r\n");
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x3c) == -1) {
    if ((*(char *)(param_1 + 0x30) == '\0') &&
       (iVar1 = (**(code **)(param_1 + 0x84))(*(undefined4 *)(param_1 + 0x2c)), iVar1 == 0)) {
      (*g_medialib_printf)("##Demuxer: WARNING--seek prev key frame##\r\n");
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x68))(*(undefined4 *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x3c);
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x3c);
  }
  return uVar2;
}



undefined4 S_Demuxer_CheckFileInfo(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4a;
  undefined4 local_48;
  undefined2 local_3e;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  iVar1 = Demuxer_GetInfo(param_1,&local_78);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((local_70 == 0) && (local_6c == 0)) {
    (*g_medialib_printf)("##Demuxer: ERROR--no video and no audio##\r\n");
    uVar2 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x1c) == 6) && (local_70 != 0)) {
      *(undefined4 *)(param_1 + 0x1c) = 4;
    }
    if (local_70 == 0) {
      (*g_medialib_printf)
                ("##Demuxer: total time: %dms, bits/sample: %d, channel: %d, samplerate: %d##\r\n",
                 local_18,local_3e,local_4a,local_48);
      (*g_medialib_printf)
                ("##Demuxer: total bytes: %d, bitrate: %d, audio type: %d##\r\n",local_68,local_60,
                 local_50);
    }
    else {
      (*g_medialib_printf)("\r\n#####################################\r\n");
      (*g_medialib_printf)
                ("##MOVIE INFO: (file type is %d; self record is %d)\r\n",
                 *(undefined4 *)(param_1 + 0x1c),local_58);
      (*g_medialib_printf)
                ("##\tmovie--total seconds: %ds; width: %d, height: %d\r\n",local_18 / 1000,local_20
                 ,local_1c);
      (*g_medialib_printf)("##\tvideo--key frames: %d; first key frame: %d\r\n",local_74,local_78);
      (*g_medialib_printf)("##\taudio--audio bytes: %d; channels: %d\r\n",local_68,local_4a);
      (*g_medialib_printf)("##\tbps--video: %d; audio: %d\r\n",local_64,local_60);
      (*g_medialib_printf)("##\tvideo fps: %d; audio sample rate: %d\r\n",local_5c / 10,local_48);
      (*g_medialib_printf)("##\tvideo type: %d; audio type: %d\r\n",local_54,local_50);
      (*g_medialib_printf)("#####################################\r\n\r\n");
    }
    *(int *)(param_1 + 0x14) = local_70;
    *(int *)(param_1 + 0x18) = local_6c;
    *(uint *)(param_1 + 0x10) = local_18;
    uVar2 = 1;
  }
  return uVar2;
}



undefined4 S_Demuxer_HandleStart(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FIFO_Reset(param_1[10]);
  if (param_1[5] == 0) {
    *param_1 = param_2;
  }
  else if (*(char *)((int)param_1 + 0x31) != '\0') {
    FIFO_Reset(param_1[9]);
    param_1[0x28] = 1;
    iVar1 = S_Demuxer_SeekVideo(param_1,param_2);
    if (iVar1 == 0) {
      return 8;
    }
    *(undefined1 *)((int)param_1 + 0x31) = 0;
  }
  param_1[1] = *param_1;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    if (((*(char *)((int)param_1 + 0x31) == '\0') && (param_1[5] == 0)) ||
       (iVar1 = S_Demuxer_SeekAudio(param_1,*param_1), -1 < iVar1)) {
      uVar2 = 0xb;
    }
    else {
      (*g_medialib_printf)("##Demuxer: WARNING--seek audio error, disable audio##\r\n");
      *(undefined1 *)((int)param_1 + 0xd) = 1;
      if (param_1[5] == 0) {
        uVar2 = 8;
      }
      else {
        uVar2 = 0xc;
      }
    }
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}



int Demuxer_Init(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x14))(0xa4);
  if (iVar1 == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--Handle malloc##\r\n");
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0xa4);
    *(int *)(iVar1 + 0x48) = param_1;
  }
  return iVar1;
}



undefined4 Demuxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 0x48) + 0x18))(param_1);
  return uVar1;
}



bool Demuxer_InitFifo(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 8) == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x24) = param_2;
    *(undefined4 *)(param_1 + 0x28) = param_3;
    FIFO_Reset(*(undefined4 *)(param_1 + 0x24));
    FIFO_Reset(*(undefined4 *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 8) = 7;
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--InitFifo, status is not OPEN##\r\n");
  }
  return bVar1;
}



undefined4 Demuxer_function_register(int param_1)

{
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 1:
    goto LAB_000531a0;
  case 2:
LAB_000531a0:
    *(code **)(param_1 + 0x4c) = AVIDemuxer_Init;
    *(code **)(param_1 + 0x50) = AVIDemuxer_Destroy;
    *(code **)(param_1 + 0x54) = AVIDemuxer_Open;
    *(code **)(param_1 + 0x58) = AVIDemuxer_Close;
    *(code **)(param_1 + 0x5c) = AVIDemuxer_GetFileInfo;
    *(code **)(param_1 + 0x60) = AVIDemuxer_GetVideoFrame;
    *(code **)(param_1 + 100) = AVIDemuxer_GetAudioData;
    *(code **)(param_1 + 0x68) = AVIDemuxer_GetVideoFrameSize;
    *(code **)(param_1 + 0x70) = AVIDemuxer_SeekVideo;
    *(code **)(param_1 + 0x74) = AVIDemuxer_SeekAudio;
    *(code **)(param_1 + 0x78) = AVIDemuxer_GetFirstKeyframe;
    *(code **)(param_1 + 0x7c) = AVIDemuxer_GetFirstKeyframeSize;
    *(code **)(param_1 + 0x80) = AVIDemuxer_SeekNextKeyframe;
    *(code **)(param_1 + 0x84) = AVIDemuxer_SeekPrevKeyframe;
    *(code **)(param_1 + 0x88) = AVIDemuxer_GetAudioDataSize;
    *(code **)(param_1 + 0x8c) = AVIDemuxer_GetAudioPackPts;
    *(code **)(param_1 + 0x98) = AVIDemuxer_GetNextBlockInfo;
    return 1;
  case 3:
    *(code **)(param_1 + 0x4c) = WAVDemuxer_Init;
    *(code **)(param_1 + 0x50) = WAVDemuxer_Destroy;
    *(code **)(param_1 + 0x54) = WAVDemuxer_Open;
    *(code **)(param_1 + 0x58) = WAVDemuxer_Close;
    *(code **)(param_1 + 0x5c) = WAVDemuxer_GetFileInfo;
    *(code **)(param_1 + 0x74) = WAVDemuxer_Seek;
    return 1;
  case 4:
    goto LAB_000532b4;
  case 5:
    goto LAB_000532b4;
  case 6:
    goto LAB_000532b4;
  case 7:
    goto LAB_000532b4;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    *(code **)(param_1 + 0x4c) = AACDemuxer_Init;
    *(code **)(param_1 + 0x50) = AACDemuxer_Destroy;
    *(code **)(param_1 + 0x54) = AACDemuxer_Open;
    *(code **)(param_1 + 0x58) = AACDemuxer_Close;
    *(code **)(param_1 + 0x5c) = AACDemuxer_GetFileInfo;
    *(code **)(param_1 + 0x74) = AACDemuxer_Seek;
    *(code **)(param_1 + 0x90) = AACDemuxer_ReleaseInfoMem;
    return 1;
  case 0xd:
    *(code **)(param_1 + 0x4c) = AMRDemuxer_Init;
    *(code **)(param_1 + 0x50) = AMRDemuxer_Destroy;
    *(code **)(param_1 + 0x54) = AMRDemuxer_Open;
    *(code **)(param_1 + 0x58) = AMRDemuxer_Close;
    *(code **)(param_1 + 0x5c) = AMRDemuxer_GetFileInfo;
    *(code **)(param_1 + 0x74) = AMRDemuxer_Seek;
    return 1;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
LAB_000532b4:
    *(code **)(param_1 + 0x4c) = MP4Demuxer_Init;
    *(code **)(param_1 + 0x50) = MP4Demuxer_Destroy;
    *(code **)(param_1 + 0x54) = MP4Demuxer_Open;
    *(code **)(param_1 + 0x58) = MP4Demuxer_Close;
    *(code **)(param_1 + 0x5c) = MP4Demuxer_GetFileInfo;
    *(code **)(param_1 + 0x60) = MP4Demuxer_GetVideoFrame;
    *(code **)(param_1 + 100) = MP4Demuxer_GetAudioData;
    *(code **)(param_1 + 0x68) = MP4Demuxer_GetVideoFrameSize;
    *(code **)(param_1 + 0x70) = MP4Demuxer_SeekVideo;
    *(code **)(param_1 + 0x74) = MP4Demuxer_SeekAudio;
    *(code **)(param_1 + 0x6c) = MP4Demuxer_SeekVideoSetDirection;
    *(code **)(param_1 + 0x78) = MP4Demuxer_GetFirstKeyframe;
    *(code **)(param_1 + 0x7c) = MP4Demuxer_GetFirstKeyframeSize;
    *(code **)(param_1 + 0x80) = MP4Demuxer_SeekNextKeyframe;
    *(code **)(param_1 + 0x84) = MP4Demuxer_SeekPrevKeyframe;
    *(code **)(param_1 + 0x88) = MP4Demuxer_GetAudioDataSize;
    *(code **)(param_1 + 0x8c) = MP4Demuxer_GetAudioPackPts;
    *(code **)(param_1 + 0x90) = MP4Demuxer_ReleaseInfoMem;
    *(code **)(param_1 + 0x98) = MP4Demuxer_GetNextBlockInfo;
    return 1;
  }
  (*g_medialib_printf)("##Demuxer: ERROR--Open, Unsupported file type##\r\n");
  Demuxer_Close(param_1);
  return 0;
}



int Demuxer_Open(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_11;
  
  local_11 = 0;
  uVar1 = MediaFile_Open(*param_1,0,param_2);
  param_1[1] = uVar1;
  if (param_1[1] == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--malloc mediaFile##\r\n");
    iVar3 = 0;
  }
  else {
    if (param_1[2] == 0) {
      uVar1 = MediaFile_CheckMediaType(param_1[1],1);
      param_1[2] = uVar1;
      if (param_1[2] == 0) {
        (*g_medialib_printf)("##Demuxer: ERROR--Unknown file type##\r\n");
        MediaFile_Close(param_1[1]);
        return 0;
      }
      MediaFile_SetReadMode(param_1[1],0);
    }
    else {
      (*g_medialib_printf)("##Demuxer: Input media type %d##\r\n",param_1[2]);
    }
    iVar3 = Demuxer_Init(param_2);
    if (iVar3 == 0) {
      MediaFile_Close(param_1[1]);
      iVar3 = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0x20) = param_1[1];
      *(undefined4 *)(iVar3 + 0x1c) = param_1[2];
      iVar2 = Demuxer_function_register(iVar3);
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      else {
        if (*(int *)(iVar3 + 0x94) == 0) {
          uVar1 = (**(code **)(*(int *)(iVar3 + 0x48) + 0x14))(0x420);
          *(undefined4 *)(iVar3 + 0x9c) = uVar1;
          if (*(int *)(iVar3 + 0x9c) == 0) {
            return 0;
          }
          memset(*(void **)(iVar3 + 0x9c),0,0x420);
        }
        uVar1 = (**(code **)(iVar3 + 0x4c))(*(undefined4 *)(iVar3 + 0x48));
        *(undefined4 *)(iVar3 + 0x2c) = uVar1;
        if (*(int *)(iVar3 + 0x2c) == 0) {
          Demuxer_Close(iVar3);
          iVar3 = 0;
        }
        else {
          MediaFile_SetPosition(*(undefined4 *)(iVar3 + 0x20),0);
          iVar2 = (**(code **)(iVar3 + 0x54))(*(undefined4 *)(iVar3 + 0x2c),param_1);
          if (iVar2 == 0) {
            if (*(int *)(iVar3 + 0x1c) != 0x10) {
              Demuxer_Close(iVar3);
              return 0;
            }
            (**(code **)(iVar3 + 0x58))(*(undefined4 *)(iVar3 + 0x2c));
            (**(code **)(iVar3 + 0x50))(*(undefined4 *)(iVar3 + 0x2c));
            *(undefined4 *)(iVar3 + 0x2c) = 0;
            uVar1 = MediaFile_CheckMediaType(*(undefined4 *)(iVar3 + 0x20),4);
            *(undefined4 *)(iVar3 + 0x1c) = uVar1;
            if (*(int *)(iVar3 + 0x1c) != 0xc) {
              Demuxer_Close(iVar3);
              return 0;
            }
            *(code **)(iVar3 + 0x4c) = AACDemuxer_Init;
            *(code **)(iVar3 + 0x50) = AACDemuxer_Destroy;
            *(code **)(iVar3 + 0x54) = AACDemuxer_Open;
            *(code **)(iVar3 + 0x58) = AACDemuxer_Close;
            *(code **)(iVar3 + 0x5c) = AACDemuxer_GetFileInfo;
            *(undefined4 *)(iVar3 + 100) = 0;
            *(code **)(iVar3 + 0x74) = AACDemuxer_Seek;
            *(undefined4 *)(iVar3 + 0x88) = 0;
            *(code **)(iVar3 + 0x90) = AACDemuxer_ReleaseInfoMem;
            *(undefined4 *)(iVar3 + 0x94) = 0;
            param_1[2] = *(undefined4 *)(iVar3 + 0x1c);
            uVar1 = (**(code **)(iVar3 + 0x4c))(*(undefined4 *)(iVar3 + 0x48));
            *(undefined4 *)(iVar3 + 0x2c) = uVar1;
            if (*(int *)(iVar3 + 0x2c) == 0) {
              Demuxer_Close(iVar3);
              return 0;
            }
            MediaFile_SetPosition(*(undefined4 *)(iVar3 + 0x20),0);
            iVar2 = (**(code **)(iVar3 + 0x54))(*(undefined4 *)(iVar3 + 0x2c),param_1);
            if (iVar2 == 0) {
              Demuxer_Close(iVar3);
              return 0;
            }
          }
          iVar2 = S_Demuxer_CheckFileInfo(iVar3);
          if (iVar2 == 0) {
            Demuxer_Close(iVar3);
            iVar3 = 0;
          }
          else {
            if (*(int *)(iVar3 + 0x18) != 0) {
              *(undefined4 *)(iVar3 + 0x34) = 0xc000;
            }
            *(undefined1 *)(iVar3 + 0x31) = 1;
            *(undefined4 *)(iVar3 + 0x38) = 0xffffffff;
            *(undefined4 *)(iVar3 + 0x3c) = 0xffffffff;
            if ((*(int *)(iVar3 + 0x88) == 0) && (*(int *)(iVar3 + 100) == 0)) {
              local_11 = 1;
            }
            MediaFile_SetReadMode(*(undefined4 *)(iVar3 + 0x20),local_11);
          }
        }
      }
    }
  }
  return iVar3;
}



undefined4 Demuxer_Close(int param_1)

{
  if (param_1 != 0) {
    Demuxer_Stop(param_1);
    if (*(int *)(param_1 + 0x9c) != 0) {
      (**(code **)(*(int *)(param_1 + 0x48) + 0x18))(*(undefined4 *)(param_1 + 0x9c));
      *(undefined4 *)(param_1 + 0x9c) = 0;
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      (**(code **)(param_1 + 0x58))(*(undefined4 *)(param_1 + 0x2c));
      (**(code **)(param_1 + 0x50))(*(undefined4 *)(param_1 + 0x2c));
    }
    MediaFile_Close(*(undefined4 *)(param_1 + 0x20));
    Demuxer_Destroy(param_1);
  }
  return 1;
}



undefined4 Demuxer_Start(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 8) != 7) && (*(int *)(param_1 + 8) != 6)) {
    if ((*(int *)(param_1 + 8) != 0) ||
       ((*(int *)(param_1 + 0x14) != 0 || (*(int *)(param_1 + 0x18) == 0)))) {
      (*g_medialib_printf)("##Demuxer: ERROR--start, status %d##\r\n",*(undefined4 *)(param_1 + 8));
      return 0;
    }
    *(undefined4 *)(param_1 + 8) = 7;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    if (*(uint *)(param_1 + 0x10) <= param_2) {
      (*g_medialib_printf)("#start_pos = %d#\r\n",param_2);
      (*g_medialib_printf)("##Demuxer: ERROR--no more to play##\r\n");
      return 3;
    }
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  else {
    if (*(uint *)(param_1 + 0x14) <= param_2) {
      (*g_medialib_printf)("#video_pos = %d#\r\n",param_2);
      (*g_medialib_printf)("##Demuxer: ERROR--no more frames to play##\r\n");
      return 3;
    }
    *(undefined1 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    *(undefined1 *)(param_1 + 0xd) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0xd) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 2;
  iVar1 = S_Demuxer_HandleStart(param_1,param_2);
  if (iVar1 == 0xb) {
    *(undefined4 *)(param_1 + 8) = 3;
    uVar2 = 2;
  }
  else if (iVar1 == 0xc) {
    *(undefined4 *)(param_1 + 8) = 3;
    uVar2 = 1;
  }
  else if (iVar1 == 8) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



bool Demuxer_Resume(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 8) == 6;
  if (bVar1) {
    *(undefined4 *)(param_1 + 8) = 3;
  }
  return bVar1;
}



undefined4 Demuxer_Stop(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 8) {
    (*g_medialib_printf)("##Demuxer: ERROR--stop, status %d##\r\n",*(undefined4 *)(param_1 + 8));
    uVar1 = 0;
  }
  else if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == 7)) {
    uVar1 = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x31) = 1;
    *(undefined4 *)(param_1 + 8) = 7;
    uVar1 = 1;
  }
  return uVar1;
}



undefined4 Demuxer_Pause(int param_1)

{
  switch(*(undefined4 *)(param_1 + 8)) {
  case 1:
    break;
  case 2:
  default:
switchD_00053fcc_default:
    (*g_medialib_printf)("##Demuxer: ERROR--pause, status %d##\r\n",*(undefined4 *)(param_1 + 8));
    return 0;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    return 1;
  case 7:
    goto switchD_00053fcc_default;
  case 8:
    goto switchD_00053fcc_default;
  case 9:
    *(undefined1 *)(param_1 + 0x31) = 0;
    goto LAB_00054050;
  }
  *(undefined1 *)(param_1 + 0x31) = 1;
LAB_00054050:
  *(undefined4 *)(param_1 + 8) = 6;
  return 1;
}



undefined4 Demuxer_FastForward(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((param_1[2] == 3) || (param_1[2] == 5)) || (param_1[2] == 6)) {
    *param_1 = param_2;
    *(undefined1 *)((int)param_1 + 0x31) = 1;
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[2] = 4;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0xd) = 1;
    FIFO_Reset(param_1[9]);
    uVar1 = 1;
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--ff, status %d##\r\n",param_1[2]);
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 Demuxer_FastRewind(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (((param_1[2] == 3) || (param_1[2] == 4)) || (param_1[2] == 6)) {
    *param_1 = param_2;
    *(undefined1 *)((int)param_1 + 0x31) = 1;
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[2] = 5;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0xd) = 1;
    FIFO_Reset(param_1[9]);
    uVar1 = 1;
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--fr, status %d##\r\n",param_1[2]);
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 Demuxer_GetInfo(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x5c) == 0) {
    (*g_medialib_printf)("##Demuxer: ERROR--GetFileInfo func##\r\n");
    uVar2 = 0;
  }
  else {
    ZeroMemory(param_2,0x68);
    cVar1 = (**(code **)(param_1 + 0x5c))(*(undefined4 *)(param_1 + 0x2c),param_2);
    if (cVar1 == '\0') {
      (*g_medialib_printf)("##Demuxer: ERROR--get file info##\r\n");
      uVar2 = 0;
    }
    else {
      if (*(int *)(param_2 + 0x28) != 0) {
        if (*(short *)(param_2 + 0x3a) == 0) {
          *(undefined2 *)(param_2 + 0x3a) = 0x10;
        }
        if (*(int *)(param_2 + 0x28) == 3) {
          *(undefined2 *)(param_2 + 0x2e) = 1;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined4 Demuxer_ReleaseInfoMem(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



undefined4 Demuxer_GetStatus(int param_1)

{
  if (((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0xc) != '\0')) &&
     (*(char *)(param_1 + 0xd) != '\0')) {
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return *(undefined4 *)(param_1 + 8);
}



undefined4 Demuxer_SetPos(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_1c;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_1c = 0;
  local_18 = 0;
  if ((param_1[2] != 6) && (param_1[2] != 7)) {
    (*g_medialib_printf)("##Demuxer: ERROR--Setpos, status %d##\r\n",param_1[2]);
    return 0xffffffff;
  }
  if (param_1[5] == 0) {
    *(undefined1 *)((int)param_1 + 0x31) = 0;
    uVar1 = S_Demuxer_SeekAudio(param_1,param_2);
    return uVar1;
  }
  switch(param_1[7]) {
  case 1:
    goto LAB_00054554;
  case 2:
    goto LAB_00054554;
  case 3:
    break;
  case 4:
    goto LAB_00054554;
  case 5:
    goto LAB_00054554;
  case 6:
    break;
  case 7:
    goto LAB_00054554;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    goto LAB_00054554;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    goto LAB_00054554;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
LAB_00054554:
    local_14 = param_2;
    if ((uint)param_1[5] <= param_2) {
      local_14 = param_1[5] - 1;
    }
    FIFO_Reset(param_1[9]);
    param_1[0x28] = param_3;
    iVar2 = S_Demuxer_SeekVideo(param_1,local_14);
    if (iVar2 == 0) {
      (*g_medialib_printf)("##Demuxer: ERROR--Setpos, Seek video##\r\n");
      return 0xffffffff;
    }
    if (param_1[9] == 0) {
      *(undefined1 *)((int)param_1 + 0x31) = 0;
      param_1[2] = 9;
      return *param_1;
    }
    local_1c = S_Demuxer_GetVideoFrameSize(param_1);
    if (local_1c == 0) {
      return 0xffffffff;
    }
    uVar3 = FIFO_FreeSpace(param_1[9]);
    if (uVar3 < local_1c) {
      return 0xffffffff;
    }
    local_18 = FIFO_Get_Inaddr(param_1[9],local_1c);
    iVar2 = S_Demuxer_GetVideoFrame(param_1,local_18,&local_1c);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar1 = str2ulong(local_18 + 4);
    *param_1 = uVar1;
    FIFO_Add(param_1[9],local_18,local_1c);
    *(undefined1 *)((int)param_1 + 0x31) = 0;
    param_1[2] = 9;
    return *param_1;
  }
  (*g_medialib_printf)("##Demuxer: ERROR--Setpos, Unsupported file type##\r\n");
  return 0xffffffff;
}



undefined4 Demuxer_GetAudioSeekInfo(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    **(undefined4 **)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 4);
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x94))(*(undefined4 *)(param_1 + 0x2c));
  }
  return uVar1;
}



undefined4 Demuxer_ResetAudioPos(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = S_Demuxer_SeekAudio(param_1,0);
  return uVar1;
}



undefined4 Demuxer_DisableAudio(int param_1)

{
  *(undefined1 *)(param_1 + 0xd) = 1;
  if ((*(int *)(param_1 + 8) == 0xb) || (*(int *)(param_1 + 8) == 10)) {
    *(undefined4 *)(param_1 + 8) = 3;
  }
  return 1;
}



undefined4 Demuxer_DisableVideo(int param_1)

{
  *(undefined1 *)(param_1 + 0xc) = 1;
  return 1;
}



undefined4 Demuxer_GetAudioPTS(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



undefined1 Demuxer_CheckAudioEnd(int param_1)

{
  return *(undefined1 *)(param_1 + 0xd);
}



undefined1 Demuxer_CheckVideoEnd(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc);
}



int Demuxer_GetVideoFrameSize(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    iVar1 = S_Demuxer_GetVideoFrameSize(param_1);
    if (iVar1 == 0) {
      (*g_medialib_printf)("##Demuxer: no more video data##\r\n");
      Demuxer_SetDataEnd(param_1,1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 Demuxer_GetVideoFrame(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    if (((*(int *)(param_1 + 0x3c) == -1) || (*(int *)(param_1 + 0x3c) == 0)) ||
       (*param_3 != *(int *)(param_1 + 0x3c))) {
      (*g_medialib_printf)
                ("##Demuxer: WARINIG--no v_last_size or size error %d##\r\n",
                 *(undefined4 *)(param_1 + 0x3c));
      uVar2 = 0;
    }
    else {
      iVar1 = S_Demuxer_GetVideoFrame(param_1,param_2,param_3);
      if (iVar1 == 0) {
        *param_3 = 0;
        if (*(char *)(param_1 + 0xc) == '\0') {
          *(undefined4 *)(param_1 + 8) = 8;
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



int Demuxer_GetFirstVideoSize(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 7) {
    if (*(int *)(param_1 + 0x14) != 0) {
      switch(*(undefined4 *)(param_1 + 0x1c)) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 0xb:
        break;
      case 0xc:
        break;
      case 0xd:
        break;
      case 0xe:
        break;
      case 0xf:
        break;
      case 0x10:
        break;
      case 0x11:
        break;
      case 0x12:
        break;
      case 0x13:
        break;
      case 0x14:
        break;
      case 0x15:
        break;
      case 0x16:
      }
    }
    iVar1 = S_Demuxer_GetFirstKeyframeSize(param_1);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--GetFirstSize, status is not STOP##\r\n");
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 Demuxer_GetFirstVideo(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int local_20;
  int local_1c;
  undefined4 local_18;
  char local_11;
  
  local_11 = 0;
  local_20 = 0;
  local_18 = 0;
  local_1c = param_2;
  if (*(int *)(param_1 + 8) == 7) {
    if (*(int *)(param_1 + 0x14) != 0) {
      switch(*(undefined4 *)(param_1 + 0x1c)) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 0xb:
        break;
      case 0xc:
        break;
      case 0xd:
        break;
      case 0xe:
        break;
      case 0xf:
        break;
      case 0x10:
        break;
      case 0x11:
        break;
      case 0x12:
        break;
      case 0x13:
        break;
      case 0x14:
        break;
      case 0x15:
        break;
      case 0x16:
      }
      local_18 = 0;
      local_20 = *param_3;
      local_11 = S_Demuxer_GetFirstKeyframe(param_1,param_2,&local_20);
      if ((local_11 == '\0') || (local_20 == 0)) {
        (*g_medialib_printf)("##Demuxer: ERROR--Read first key video data##\r\n");
        return 0;
      }
      ulong2str(param_2,local_18);
      ulong2str(param_2 + 4,local_20);
    }
    uVar1 = 1;
  }
  else {
    (*g_medialib_printf)("##Demuxer: ERROR--GetFirst, status is not STOP##\r\n");
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 Demuxer_GetNextBlockInfo(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x40) == 0) || (*(int *)(param_1 + 0x44) == -1)) {
    ZeroMemory(param_2,8);
    if ((*(char *)(param_1 + 0xc) == '\0') && (*(char *)(param_1 + 0xd) == '\0')) {
      if ((*(int *)(param_1 + 0x98) == 0) || (*(int *)(param_1 + 8) != 3)) {
        (*g_medialib_printf)
                  ("##Demuxer: ERROR--fDmxGetNextBlockInfo(0x%x) NULL or status(%d) error##\r\n",
                   *(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 8));
        uVar2 = 0;
      }
      else {
        iVar1 = (**(code **)(param_1 + 0x98))(*(undefined4 *)(param_1 + 0x2c),param_2);
        if (iVar1 == 0) {
          Demuxer_SetDataEnd(param_1,0);
          (*g_medialib_printf)("##Demuxer: data end##\r\n");
          uVar2 = 0;
        }
        else {
          if (*param_2 == 1) {
            *(int *)(param_1 + 0x3c) = param_2[1];
          }
          else if (*param_2 == 2) {
            *(int *)(param_1 + 0x38) = param_2[1];
          }
          memcpy((void *)(param_1 + 0x40),param_2,8);
          uVar2 = 1;
        }
      }
    }
    else {
      if (*(char *)(param_1 + 0xc) == '\0') {
        iVar1 = Demuxer_GetVideoFrameSize(param_1);
        param_2[1] = iVar1;
        if (param_2[1] != 0) {
          *param_2 = 1;
          return 1;
        }
        *param_2 = 0;
      }
      else {
        iVar1 = Demuxer_GetAudioDataSize(param_1);
        param_2[1] = iVar1;
        if (param_2[1] != 0) {
          *param_2 = 2;
          return 1;
        }
        *param_2 = 0;
      }
      uVar2 = 0;
    }
  }
  else {
    memcpy(param_2,(void *)(param_1 + 0x40),8);
    uVar2 = 1;
  }
  return uVar2;
}



int Demuxer_GetKeyframeSize(undefined4 *param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  if (*(char *)((int)param_1 + 0x31) != '\0') {
    param_1[0x28] = 1;
    iVar1 = S_Demuxer_SeekVideo(param_1,*param_1);
    if (iVar1 == 0) {
      param_1[2] = 8;
      return 0;
    }
    *(undefined1 *)((int)param_1 + 0x31) = 0;
    if (param_1[2] == 5) {
      iVar1 = S_Demuxer_GetVideoFrameSize(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      Demuxer_SetDataEnd(param_1,0);
      return 0;
    }
  }
  if (param_1[2] == 4) {
    local_c = S_Demuxer_GetNextKeyframeSize(param_1);
  }
  else if (param_1[2] == 5) {
    local_c = S_Demuxer_GetPrevKeyframeSize(param_1);
  }
  if (local_c == 0) {
    Demuxer_SetDataEnd(param_1,0);
  }
  return local_c;
}



int Muxer_Init(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x14))(0x40);
  if (iVar1 == 0) {
    (*g_medialib_printf)("##Muxer: ERROR--Handle malloc##\r\n");
    iVar1 = 0;
  }
  else {
    ZeroMemory(iVar1,0x40);
    *(int *)(iVar1 + 0x10) = param_1;
  }
  return iVar1;
}



undefined4 Muxer_Destroy(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 0x10) + 0x18))(param_1);
  return uVar1;
}



int * Muxer_Open(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if (((*(short *)(param_1 + 0x1b) == 0) || (*(short *)(param_1 + 0x1b) == 8)) &&
     ((*(short *)((int)param_1 + 0x6e) == 0 || (*(short *)((int)param_1 + 0x6e) == 8)))) {
    piVar2 = (int *)Muxer_Init(param_2);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2[2] = 1;
      *(undefined1 *)(piVar2 + 1) = *(undefined1 *)(param_1 + 0xd);
      if ((char)piVar2[1] == '\0') {
        (**(code **)(piVar2[4] + 0xc))(param_1[3],0,0);
      }
      if (param_1[2] == 0) {
        piVar2[5] = (int)AVIMuxer_Init;
        piVar2[6] = (int)AVIMuxer_Destroy;
        piVar2[7] = (int)AVIMuxer_Open;
        piVar2[8] = (int)AVIMuxer_Close;
        piVar2[9] = (int)AVIMuxer_Start;
        piVar2[10] = (int)AVIMuxer_Stop;
        piVar2[0xb] = (int)AVIMuxer_ProcessVideo;
        piVar2[0xc] = (int)AVIMuxer_ProcessAudio;
        piVar2[0xd] = (int)AVIMuxer_GetHeaderSize;
        piVar2[0xe] = (int)AVIMuxer_GetCurrFileSize;
        piVar2[0xf] = (int)AVIMuxer_Restart;
      }
      else {
        if (param_1[2] != 2) {
          (*g_medialib_printf)("##Muxer: ERROR--Muxer Unsupported##\r\n");
          return (int *)0x0;
        }
        piVar2[5] = (int)MP4Muxer_Init;
        piVar2[6] = (int)MP4Muxer_Destroy;
        piVar2[7] = (int)MP4Muxer_Open;
        piVar2[8] = (int)MP4Muxer_Close;
        piVar2[9] = (int)MP4Muxer_Start;
        piVar2[10] = (int)MP4Muxer_Stop;
        piVar2[0xb] = (int)MP4Muxer_ProcessVideo;
        piVar2[0xc] = (int)MP4Muxer_ProcessAudio;
        piVar2[0xd] = (int)MP4Muxer_GetHeaderSize;
        piVar2[0xe] = (int)MP4Muxer_GetCurrFileSize;
        piVar2[0xf] = (int)MP4Muxer_Restart;
      }
      iVar1 = MediaFile_Open(*param_1,1,piVar2[4]);
      *piVar2 = iVar1;
      if (*piVar2 == 0) {
        (*g_medialib_printf)("##Muxer: ERROR--malloc mediaFile##\r\n");
        Muxer_Close(piVar2);
        piVar2 = (int *)0x0;
      }
      else {
        param_1[1] = *piVar2;
        iVar1 = (*(code *)piVar2[5])(piVar2[4]);
        piVar2[3] = iVar1;
        if (piVar2[3] == 0) {
          Muxer_Close(piVar2);
          piVar2 = (int *)0x0;
        }
        else {
          iVar1 = (*(code *)piVar2[7])(piVar2[3],param_1);
          if (iVar1 == 0) {
            Muxer_Close(piVar2);
            piVar2 = (int *)0x0;
          }
        }
      }
    }
  }
  else {
    (*g_medialib_printf)("##Muxer: ERROR--StreamPos##\r\n");
    piVar2 = (int *)0x0;
  }
  return piVar2;
}



undefined4 Muxer_Close(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    if (param_1[3] != 0) {
      (*(code *)param_1[8])(param_1[3]);
      (*(code *)param_1[6])(param_1[3]);
    }
    MediaFile_Close(*param_1);
    Muxer_Destroy(param_1);
    uVar1 = 1;
  }
  return uVar1;
}



char Muxer_Start(int param_1)

{
  char local_9;
  
  local_9 = '\0';
  if (*(int *)(param_1 + 8) == 1) {
    if (*(int *)(param_1 + 0x24) != 0) {
      local_9 = (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0xc));
    }
    if (local_9 != '\0') {
      *(undefined4 *)(param_1 + 8) = 2;
    }
  }
  else {
    (*g_medialib_printf)("##Muxer: ERROR--start, status %d##\r\n",*(undefined4 *)(param_1 + 8));
    local_9 = '\0';
  }
  return local_9;
}



char Muxer_Restart(undefined4 *param_1,undefined4 *param_2)

{
  char local_9;
  
  local_9 = '\0';
  if (param_1[2] == 3) {
    if (param_1[0xf] != 0) {
      MediaFile_ReOpen(*param_1,*param_2);
      param_2[1] = *param_1;
      local_9 = (*(code *)param_1[0xf])(param_1[3],param_2);
    }
    if ((local_9 != '\0') && (param_1[2] = 2, *(char *)(param_1 + 1) == '\0')) {
      (**(code **)(param_1[4] + 0xc))(param_2[3],0,0);
    }
  }
  else {
    (*g_medialib_printf)("##Muxer: ERROR--restart, status %d##\r\n",param_1[2]);
    local_9 = '\0';
  }
  return local_9;
}



char Muxer_Stop(int param_1)

{
  undefined1 local_9;
  
  local_9 = '\0';
  if (*(int *)(param_1 + 8) == 3) {
    local_9 = '\x01';
  }
  else {
    if (*(int *)(param_1 + 0x28) != 0) {
      local_9 = (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0xc));
    }
    if (local_9 != '\0') {
      *(undefined4 *)(param_1 + 8) = 3;
    }
  }
  return local_9;
}



undefined4 Muxer_GetHeaderSize(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar1;
}



undefined4 Muxer_GetCurrFileSize(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar1;
}



undefined4 Muxer_GetStatus(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



undefined4 Muxer_ProcessAudio(int param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  local_c = 2;
  if (*(int *)(param_1 + 8) == 2) {
    if (*(int *)(param_1 + 0x30) != 0) {
      local_c = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0xc),param_2);
    }
    *(undefined4 *)(param_1 + 8) = local_c;
  }
  else {
    (*g_medialib_printf)
              ("##Muxer: ERROR--Process Audio status %d##\r\n",*(undefined4 *)(param_1 + 8));
    local_c = *(undefined4 *)(param_1 + 8);
  }
  return local_c;
}



undefined4 Muxer_ProcessVideo(int param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  local_c = 2;
  if (*(int *)(param_1 + 8) == 2) {
    if (*(int *)(param_1 + 0x2c) != 0) {
      local_c = (**(code **)(param_1 + 0x2c))(*(undefined4 *)(param_1 + 0xc),param_2);
    }
    *(undefined4 *)(param_1 + 8) = local_c;
  }
  else {
    (*g_medialib_printf)
              ("##Muxer: ERROR--Process Video status %d##\r\n",*(undefined4 *)(param_1 + 8));
    local_c = *(undefined4 *)(param_1 + 8);
  }
  return local_c;
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



undefined4 __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong local_8;
  
  if (param_4 != 0 || param_3 != 0) {
    lVar2 = __gnu_ldivmod_helper(CONCAT44(param_2,param_1),CONCAT44(param_4,param_3),&local_8);
    return (int)lVar2;
  }
  if (param_2 < 0) {
    param_2 = -0x80000000;
    param_1 = 0;
  }
  else if (param_2 != 0 || param_1 != 0) {
    param_2 = 0x7fffffff;
    param_1 = -1;
  }
  uVar1 = __aeabi_idiv0(param_1,param_2);
  return uVar1;
}



void __aeabi_idiv0(void)

{
  raise(8);
  return;
}



longlong __gnu_ldivmod_helper(longlong a,longlong b,longlong *remainder)

{
  uint uVar1;
  DItype DVar2;
  
                    // Unresolved local var: longlong quotient@[DW_OP_reg0(r0); DW_OP_piece: 4;
                    // DW_OP_reg1(r1); DW_OP_piece: 4]
  DVar2 = __divdi3(a,b);
  uVar1 = (uint)(DVar2 * b);
  *(uint *)remainder = (uint)a - uVar1;
  *(uint *)((int)remainder + 4) =
       (int)((ulonglong)a >> 0x20) -
       ((int)((ulonglong)(DVar2 * b) >> 0x20) + (uint)((uint)a < uVar1));
  return DVar2;
}



ulonglong __gnu_uldivmod_helper(ulonglong a,ulonglong b,ulonglong *remainder)

{
  uint uVar1;
  UDItype UVar2;
  
                    // Unresolved local var: ulonglong quotient@[DW_OP_reg0(r0); DW_OP_piece: 4;
                    // DW_OP_reg1(r1); DW_OP_piece: 4]
  UVar2 = __udivdi3(a,b);
  uVar1 = (uint)(UVar2 * b);
  *(uint *)remainder = (uint)a - uVar1;
  *(uint *)((int)remainder + 4) =
       (int)(a >> 0x20) - ((int)(UVar2 * b >> 0x20) + (uint)((uint)a < uVar1));
  return UVar2;
}



DItype __divdi3(DItype u,DItype v)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int extraout_r1;
  uint uVar8;
  int extraout_r1_00;
  uint uVar9;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  
                    // Unresolved local var: SItype c@[???]
                    // Unresolved local var: DWunion uu@[???]
                    // Unresolved local var: DWunion vv@[???]
                    // Unresolved local var: DItype w@[DW_OP_reg0(r0); DW_OP_piece: 4;
                    // DW_OP_reg1(r1); DW_OP_piece: 4]
  if (u < 0) {
    u = CONCAT44(-((int)((ulonglong)u >> 0x20) + (uint)((int)u != 0)),-(int)u);
    uVar11 = 0xffffffff;
  }
  else {
    uVar11 = 0;
  }
  uVar8 = (uint)((ulonglong)u >> 0x20);
  uVar9 = (uint)u;
  if (v < 0) {
    uVar11 = ~uVar11;
    v = CONCAT44(-((int)((ulonglong)v >> 0x20) + (uint)((int)v != 0)),-(int)v);
  }
  uVar13 = (uint)((ulonglong)v >> 0x20);
  uVar5 = (uint)v;
                    // Unresolved local var: DWunion nn@[???]
                    // Unresolved local var: DWunion dd@[???]
                    // Unresolved local var: DWunion rr@[???]
                    // Unresolved local var: USItype d0@[???]
                    // Unresolved local var: USItype d1@[???]
                    // Unresolved local var: USItype n0@[???]
                    // Unresolved local var: USItype n1@[???]
                    // Unresolved local var: USItype n2@[???]
                    // Unresolved local var: USItype q0@[???]
                    // Unresolved local var: USItype q1@[???]
                    // Unresolved local var: USItype b@[???]
                    // Unresolved local var: USItype bm@[???]
                    // Unresolved local var: DWunion ww@[???]
  if (uVar13 == 0) {
    if (uVar5 <= uVar8) {
      if (uVar5 == 0) {
        uVar5 = __aeabi_uidiv(1,0);
      }
      iVar10 = LZCOUNT(uVar5);
      if (iVar10 == 0) {
        iVar10 = uVar8 - uVar5;
        uVar4 = 1;
      }
      else {
        uVar5 = uVar5 << iVar10;
        uVar4 = uVar8 >> (0x20U - iVar10 & 0xff);
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
        uVar13 = uVar5 >> 0x10;
        uVar12 = uVar9 >> (0x20U - iVar10 & 0xff) | uVar8 << iVar10;
        uVar9 = uVar9 << iVar10;
        iVar10 = __aeabi_uidiv(uVar4,uVar13);
        uVar15 = (uVar5 & 0xffff) * iVar10;
        __aeabi_uidivmod(uVar4,uVar13);
        uVar8 = uVar12 >> 0x10 | extraout_r1_01 << 0x10;
        iVar3 = iVar10;
        if (uVar8 < uVar15) {
          bVar16 = CARRY4(uVar8,uVar5);
          uVar8 = uVar8 + uVar5;
          iVar3 = iVar10 + -1;
          if ((!bVar16) && (uVar8 < uVar15)) {
            uVar8 = uVar8 + uVar5;
            iVar3 = iVar10 + -2;
          }
        }
        uVar6 = __aeabi_uidiv(uVar8 - uVar15,uVar13);
        uVar14 = uVar6 * (uVar5 & 0xffff);
        __aeabi_uidivmod(uVar8 - uVar15,uVar13);
        uVar8 = uVar12 & 0xffff | extraout_r1_02 << 0x10;
        uVar4 = uVar6;
        if (uVar8 < uVar14) {
          bVar16 = CARRY4(uVar8,uVar5);
          uVar8 = uVar8 + uVar5;
          uVar4 = uVar6 - 1;
          if ((!bVar16) && (uVar8 < uVar14)) {
            uVar8 = uVar8 + uVar5;
            uVar4 = uVar6 - 2;
          }
        }
        iVar10 = uVar8 - uVar14;
        uVar4 = uVar4 | iVar3 << 0x10;
      }
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
      uVar8 = uVar5 >> 0x10;
      iVar3 = __aeabi_uidiv(iVar10,uVar8);
      uVar12 = (uVar5 & 0xffff) * iVar3;
      __aeabi_uidivmod(iVar10,uVar8);
      uVar13 = uVar9 >> 0x10 | extraout_r1_03 << 0x10;
      iVar10 = iVar3;
      if (uVar13 < uVar12) {
        bVar16 = CARRY4(uVar13,uVar5);
        uVar13 = uVar13 + uVar5;
        iVar10 = iVar3 + -1;
        if ((!bVar16) && (uVar13 < uVar12)) {
          uVar13 = uVar13 + uVar5;
          iVar10 = iVar3 + -2;
        }
      }
      uVar15 = __aeabi_uidiv(uVar13 - uVar12,uVar8);
      uVar6 = uVar15 * (uVar5 & 0xffff);
      __aeabi_uidivmod(uVar13 - uVar12,uVar8);
      uVar8 = uVar9 & 0xffff | extraout_r1_04 << 0x10;
      uVar9 = uVar15;
      if (uVar8 < uVar6) {
        uVar9 = uVar15 - 1;
        if ((!CARRY4(uVar8,uVar5)) && (uVar8 + uVar5 < uVar6)) {
          uVar9 = uVar15 - 2;
        }
      }
      uVar8 = uVar9 | iVar10 << 0x10;
      goto LAB_000561d8;
    }
    iVar10 = LZCOUNT(uVar5);
    if (iVar10 != 0) {
      uVar5 = uVar5 << iVar10;
      u = CONCAT44(uVar9 >> (0x20U - iVar10 & 0xff) | uVar8 << iVar10,uVar9 << iVar10);
    }
    uVar2 = (undefined4)((ulonglong)u >> 0x20);
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
    uVar9 = uVar5 >> 0x10;
    iVar3 = __aeabi_uidiv(uVar2,uVar9);
    uVar13 = (uVar5 & 0xffff) * iVar3;
    __aeabi_uidivmod(uVar2,uVar9);
    uVar8 = (uint)u >> 0x10 | extraout_r1 << 0x10;
    iVar10 = iVar3;
    if (uVar8 < uVar13) {
      bVar16 = CARRY4(uVar8,uVar5);
      uVar8 = uVar8 + uVar5;
      iVar10 = iVar3 + -1;
      if ((!bVar16) && (uVar8 < uVar13)) {
        uVar8 = uVar8 + uVar5;
        iVar10 = iVar3 + -2;
      }
    }
    uVar4 = __aeabi_uidiv(uVar8 - uVar13,uVar9);
    uVar12 = uVar4 * (uVar5 & 0xffff);
    __aeabi_uidivmod(uVar8 - uVar13,uVar9);
    uVar9 = (uint)u & 0xffff | extraout_r1_00 << 0x10;
    uVar8 = uVar4;
    if (uVar9 < uVar12) {
      uVar8 = uVar4 - 1;
      if ((!CARRY4(uVar9,uVar5)) && (uVar9 + uVar5 < uVar12)) {
        uVar8 = uVar4 - 2;
      }
    }
    uVar8 = uVar8 | iVar10 << 0x10;
LAB_000561c8:
    uVar4 = 0;
  }
  else {
    if (uVar13 <= uVar8) {
      iVar10 = LZCOUNT(uVar13);
      if (iVar10 != 0) {
                    // Unresolved local var: USItype m1@[???]
                    // Unresolved local var: USItype m0@[???]
        uVar12 = 0x20 - iVar10;
        uVar15 = uVar5 >> (uVar12 & 0xff) | uVar13 << iVar10;
        uVar4 = uVar8 >> (uVar12 & 0xff);
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
        uVar13 = uVar15 >> 0x10;
        uVar12 = uVar9 >> (uVar12 & 0xff) | uVar8 << iVar10;
        iVar7 = __aeabi_uidiv(uVar4,uVar13);
        uVar6 = (uVar15 & 0xffff) * iVar7;
        __aeabi_uidivmod(uVar4,uVar13);
        uVar8 = uVar12 >> 0x10 | extraout_r1_05 << 0x10;
        iVar3 = iVar7;
        if (uVar8 < uVar6) {
          bVar16 = CARRY4(uVar8,uVar15);
          uVar8 = uVar8 + uVar15;
          iVar3 = iVar7 + -1;
          if ((!bVar16) && (uVar8 < uVar6)) {
            uVar8 = uVar8 + uVar15;
            iVar3 = iVar7 + -2;
          }
        }
        uVar4 = __aeabi_uidiv(uVar8 - uVar6,uVar13);
        uVar14 = uVar4 * (uVar15 & 0xffff);
        __aeabi_uidivmod(uVar8 - uVar6,uVar13);
        uVar13 = uVar12 & 0xffff | extraout_r1_06 << 0x10;
        uVar8 = uVar4;
        if (uVar13 < uVar14) {
          bVar16 = CARRY4(uVar13,uVar15);
          uVar13 = uVar13 + uVar15;
          uVar8 = uVar4 - 1;
          if ((!bVar16) && (uVar13 < uVar14)) {
            uVar13 = uVar13 + uVar15;
            uVar8 = uVar4 - 2;
          }
        }
        uVar8 = uVar8 | iVar3 << 0x10;
                    // Unresolved local var: UDItype __t0@[???]
        lVar1 = (ulonglong)(uVar5 << iVar10) * (ulonglong)uVar8;
        uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
        uVar13 = uVar13 - uVar14;
        if ((uVar5 < uVar13 || uVar5 == uVar13) &&
           (uVar4 = 0, (uint)lVar1 <= uVar9 << iVar10 || uVar5 != uVar13)) goto LAB_000561d8;
        uVar8 = uVar8 - 1;
        goto LAB_000561c8;
      }
      bVar16 = uVar13 <= uVar8;
      if (uVar8 <= uVar13) {
        bVar16 = uVar5 <= uVar9;
      }
      if (bVar16) {
        uVar4 = 0;
        uVar8 = 1;
        goto LAB_000561d8;
      }
    }
    uVar4 = 0;
    uVar8 = uVar4;
  }
LAB_000561d8:
  if (uVar11 != 0) {
    bVar16 = uVar8 != 0;
    uVar8 = -uVar8;
    uVar4 = -(uVar4 + bVar16);
  }
  return CONCAT44(uVar4,uVar8);
}



UDItype __udivdi3(UDItype n,UDItype d)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int extraout_r1;
  uint uVar6;
  int extraout_r1_00;
  uint uVar7;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  uint extraout_r2;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  uVar4 = (uint)(d >> 0x20);
  uVar6 = (uint)d;
  uVar10 = (uint)(n >> 0x20);
  uVar7 = (uint)n;
                    // Unresolved local var: DWunion nn@[???]
                    // Unresolved local var: DWunion dd@[???]
                    // Unresolved local var: DWunion rr@[???]
                    // Unresolved local var: USItype d0@[???]
                    // Unresolved local var: USItype d1@[???]
                    // Unresolved local var: USItype n0@[???]
                    // Unresolved local var: USItype n1@[???]
                    // Unresolved local var: USItype n2@[???]
                    // Unresolved local var: USItype q0@[???]
                    // Unresolved local var: USItype q1@[???]
                    // Unresolved local var: USItype b@[???]
                    // Unresolved local var: USItype bm@[???]
                    // Unresolved local var: DWunion ww@[???]
  if (uVar4 == 0) {
    if (uVar6 <= uVar10) {
      uVar4 = uVar6;
      uVar9 = uVar6;
      if (uVar6 == 0) {
        uVar4 = __aeabi_uidiv(1,0,0,0,n,0);
        uVar6 = extraout_r2;
      }
      iVar8 = LZCOUNT(uVar4);
      if (iVar8 == 0) {
        iVar8 = uVar10 - uVar4;
        uVar9 = 1;
        uVar12 = uVar7;
      }
      else {
        uVar4 = uVar4 << iVar8;
        uVar11 = uVar10 >> (0x20U - iVar8 & 0xff);
        uVar12 = uVar7 << iVar8;
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
        uVar3 = uVar4 >> 0x10;
        uVar10 = uVar7 >> (0x20U - iVar8 & 0xff) | uVar10 << iVar8;
        iVar8 = __aeabi_uidiv(uVar11,uVar3,uVar6,iVar8,n,uVar9);
        uVar6 = (uVar4 & 0xffff) * iVar8;
        __aeabi_uidivmod(uVar11,uVar3);
        uVar7 = uVar10 >> 0x10 | extraout_r1_01 << 0x10;
        iVar2 = iVar8;
        if (uVar7 < uVar6) {
          bVar14 = CARRY4(uVar7,uVar4);
          uVar7 = uVar7 + uVar4;
          iVar2 = iVar8 + -1;
          if ((!bVar14) && (uVar7 < uVar6)) {
            uVar7 = uVar7 + uVar4;
            iVar2 = iVar8 + -2;
          }
        }
        uVar11 = __aeabi_uidiv(uVar7 - uVar6,uVar3);
        uVar13 = uVar11 * (uVar4 & 0xffff);
        __aeabi_uidivmod(uVar7 - uVar6,uVar3);
        uVar7 = uVar10 & 0xffff | extraout_r1_02 << 0x10;
        uVar9 = uVar11;
        if (uVar7 < uVar13) {
          bVar14 = CARRY4(uVar7,uVar4);
          uVar7 = uVar7 + uVar4;
          uVar9 = uVar11 - 1;
          if ((!bVar14) && (uVar7 < uVar13)) {
            uVar7 = uVar7 + uVar4;
            uVar9 = uVar11 - 2;
          }
        }
        iVar8 = uVar7 - uVar13;
        uVar9 = uVar9 | iVar2 << 0x10;
      }
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
      uVar7 = uVar4 >> 0x10;
      iVar2 = __aeabi_uidiv(iVar8,uVar7);
      uVar10 = (uVar4 & 0xffff) * iVar2;
      __aeabi_uidivmod(iVar8,uVar7);
      uVar6 = uVar12 >> 0x10 | extraout_r1_03 << 0x10;
      iVar8 = iVar2;
      if (uVar6 < uVar10) {
        bVar14 = CARRY4(uVar6,uVar4);
        uVar6 = uVar6 + uVar4;
        iVar8 = iVar2 + -1;
        if ((!bVar14) && (uVar6 < uVar10)) {
          uVar6 = uVar6 + uVar4;
          iVar8 = iVar2 + -2;
        }
      }
      uVar3 = __aeabi_uidiv(uVar6 - uVar10,uVar7);
      uVar11 = uVar3 * (uVar4 & 0xffff);
      __aeabi_uidivmod(uVar6 - uVar10,uVar7);
      uVar7 = uVar12 & 0xffff | extraout_r1_04 << 0x10;
      uVar10 = uVar3;
      if (uVar7 < uVar11) {
        uVar10 = uVar3 - 1;
        if ((!CARRY4(uVar7,uVar4)) && (uVar7 + uVar4 < uVar11)) {
          uVar10 = uVar3 - 2;
        }
      }
      uVar10 = uVar10 | iVar8 << 0x10;
      goto LAB_000565f0;
    }
    iVar8 = LZCOUNT(uVar6);
    uVar4 = uVar6;
    if (iVar8 != 0) {
      uVar4 = uVar6 << iVar8;
      uVar10 = uVar7 >> (0x20U - iVar8 & 0xff) | uVar10 << iVar8;
    }
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
    uVar9 = uVar4 >> 0x10;
    if (iVar8 != 0) {
      uVar7 = uVar7 << iVar8;
    }
    iVar2 = __aeabi_uidiv(uVar10,uVar9,uVar6,iVar8,n,uVar6);
    uVar12 = (uVar4 & 0xffff) * iVar2;
    __aeabi_uidivmod(uVar10,uVar9);
    uVar6 = uVar7 >> 0x10 | extraout_r1 << 0x10;
    iVar8 = iVar2;
    if (uVar6 < uVar12) {
      bVar14 = CARRY4(uVar6,uVar4);
      uVar6 = uVar6 + uVar4;
      iVar8 = iVar2 + -1;
      if ((!bVar14) && (uVar6 < uVar12)) {
        uVar6 = uVar6 + uVar4;
        iVar8 = iVar2 + -2;
      }
    }
    uVar3 = __aeabi_uidiv(uVar6 - uVar12,uVar9);
    uVar11 = uVar3 * (uVar4 & 0xffff);
    __aeabi_uidivmod(uVar6 - uVar12,uVar9);
    uVar7 = uVar7 & 0xffff | extraout_r1_00 << 0x10;
    uVar10 = uVar3;
    if (uVar7 < uVar11) {
      uVar10 = uVar3 - 1;
      if ((!CARRY4(uVar7,uVar4)) && (uVar7 + uVar4 < uVar11)) {
        uVar10 = uVar3 - 2;
      }
    }
    uVar10 = uVar10 | iVar8 << 0x10;
LAB_000565e0:
    uVar9 = 0;
  }
  else {
    if (uVar4 <= uVar10) {
      iVar8 = LZCOUNT(uVar4);
      if (iVar8 != 0) {
                    // Unresolved local var: USItype m1@[???]
                    // Unresolved local var: USItype m0@[???]
        uVar12 = 0x20 - iVar8;
        uVar3 = uVar6 >> (uVar12 & 0xff) | uVar4 << iVar8;
        uVar9 = uVar10 >> (uVar12 & 0xff);
                    // Unresolved local var: USItype __d1@[???]
                    // Unresolved local var: USItype __d0@[???]
                    // Unresolved local var: USItype __q1@[???]
                    // Unresolved local var: USItype __q0@[???]
                    // Unresolved local var: USItype __r1@[???]
                    // Unresolved local var: USItype __r0@[???]
                    // Unresolved local var: USItype __m@[???]
        uVar4 = uVar3 >> 0x10;
        uVar11 = uVar7 >> (uVar12 & 0xff) | uVar10 << iVar8;
        iVar5 = __aeabi_uidiv(uVar9,uVar4);
        uVar12 = (uVar3 & 0xffff) * iVar5;
        __aeabi_uidivmod(uVar9,uVar4);
        uVar10 = uVar11 >> 0x10 | extraout_r1_05 << 0x10;
        iVar2 = iVar5;
        if (uVar10 < uVar12) {
          bVar14 = CARRY4(uVar10,uVar3);
          uVar10 = uVar10 + uVar3;
          iVar2 = iVar5 + -1;
          if ((!bVar14) && (uVar10 < uVar12)) {
            uVar10 = uVar10 + uVar3;
            iVar2 = iVar5 + -2;
          }
        }
        iVar5 = uVar10 - uVar12;
        uVar9 = __aeabi_uidiv(iVar5,uVar4);
        uVar12 = uVar9 * (uVar3 & 0xffff);
        __aeabi_uidivmod(iVar5,uVar4);
        uVar4 = uVar11 & 0xffff | extraout_r1_06 << 0x10;
        uVar10 = uVar9;
        if (uVar4 < uVar12) {
          bVar14 = CARRY4(uVar4,uVar3);
          uVar4 = uVar4 + uVar3;
          uVar10 = uVar9 - 1;
          if ((!bVar14) && (uVar4 < uVar12)) {
            uVar4 = uVar4 + uVar3;
            uVar10 = uVar9 - 2;
          }
        }
        uVar10 = uVar10 | iVar2 << 0x10;
                    // Unresolved local var: UDItype __t0@[???]
        lVar1 = (ulonglong)(uVar6 << iVar8) * (ulonglong)uVar10;
        uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
        uVar4 = uVar4 - uVar12;
        if ((uVar6 < uVar4 || uVar6 == uVar4) &&
           (uVar9 = 0, (uint)lVar1 <= uVar7 << iVar8 || uVar6 != uVar4)) goto LAB_000565f0;
        uVar10 = uVar10 - 1;
        goto LAB_000565e0;
      }
      bVar14 = uVar4 <= uVar10;
      if (uVar10 <= uVar4) {
        bVar14 = uVar6 <= uVar7;
      }
      if (bVar14) {
        uVar10 = 1;
        uVar9 = 0;
        goto LAB_000565f0;
      }
    }
    uVar10 = 0;
    uVar9 = uVar10;
  }
LAB_000565f0:
  return CONCAT44(uVar9,uVar10);
}



void _fini(void)

{
  return;
}


