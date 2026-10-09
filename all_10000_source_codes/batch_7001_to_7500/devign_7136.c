/* 
 * Benchmark Sample ID : devign_7136
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9e2dabed4a7bf21e3e0c0f4ddc895f8ed90fa839
 */

AVIOContext *avio_alloc_context(

                  unsigned char *buffer,

                  int buffer_size,

                  int write_flag,

                  void *opaque,

                  int (*read_packet)(void *opaque, uint8_t *buf, int buf_size),

                  int (*write_packet)(void *opaque, uint8_t *buf, int buf_size),

                  int64_t (*seek)(void *opaque, int64_t offset, int whence))

{

    AVIOContext *s = av_mallocz(sizeof(AVIOContext));



    ffio_init_context(s, buffer, buffer_size, write_flag, opaque,

                  read_packet, write_packet, seek);

    return s;

}
