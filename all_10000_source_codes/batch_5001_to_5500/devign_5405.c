/* 
 * Benchmark Sample ID : devign_5405
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b12d92efd6c0d48665383a9baecc13e7ebbd8a22
 */

static int mm_decode_pal(MmContext *s)

{

    int i;



    bytestream2_skip(&s->gb, 4);

    for (i = 0; i < 128; i++) {

        s->palette[i] = 0xFF << 24 | bytestream2_get_be24(&s->gb);

        s->palette[i+128] = s->palette[i]<<2;

    }



    return 0;

}
