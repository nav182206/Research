/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9955
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cccb45751e93142d71be78f6bb90bbfb50ee13be
 */

static void fill_gv_table(int table[256 + 2*YUVRGB_TABLE_HEADROOM], const int elemsize, const int inc)

{

    int i;

    int off    = -(inc >> 9);



    for (i = 0; i < 256 + 2*YUVRGB_TABLE_HEADROOM; i++) {

        int64_t cb = av_clip(i-YUVRGB_TABLE_HEADROOM, 0, 255)*inc;

        table[i] = elemsize * (off + (cb >> 16));

    }

}
