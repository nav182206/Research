/* 
 * Benchmark Sample ID : devign_8861
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=26227d91865ddfbfe35c9ff84853cc469e1c7daf
 */

static inline int *DEC_UPAIR(int *dst, unsigned idx, unsigned sign)

{

    dst[0] = (idx & 15) * (1 - (sign & 0xFFFFFFFE));

    dst[1] = (idx >> 4 & 15) * (1 - ((sign & 1) << 1));



    return dst + 2;

}
