/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7372
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60f10e0ad37418cc697765d85b0bc22db70f726a
 */

static void pred4x4_horizontal_vp8_c(uint8_t *src, const uint8_t *topright, int stride){

    const int lt= src[-1-1*stride];

    LOAD_LEFT_EDGE



    AV_WN32A(src+0*stride, ((lt + 2*l0 + l1 + 2) >> 2)*0x01010101);

    AV_WN32A(src+1*stride, ((l0 + 2*l1 + l2 + 2) >> 2)*0x01010101);

    AV_WN32A(src+2*stride, ((l1 + 2*l2 + l3 + 2) >> 2)*0x01010101);

    AV_WN32A(src+3*stride, ((l2 + 2*l3 + l3 + 2) >> 2)*0x01010101);

}
