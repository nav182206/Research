/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4366
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60f10e0ad37418cc697765d85b0bc22db70f726a
 */

static void pred4x4_vertical_vp8_c(uint8_t *src, const uint8_t *topright, int stride){

    const int lt= src[-1-1*stride];

    LOAD_TOP_EDGE

    LOAD_TOP_RIGHT_EDGE

    uint32_t v = PACK_4U8((lt + 2*t0 + t1 + 2) >> 2,

                          (t0 + 2*t1 + t2 + 2) >> 2,

                          (t1 + 2*t2 + t3 + 2) >> 2,

                          (t2 + 2*t3 + t4 + 2) >> 2);



    AV_WN32A(src+0*stride, v);

    AV_WN32A(src+1*stride, v);

    AV_WN32A(src+2*stride, v);

    AV_WN32A(src+3*stride, v);

}
