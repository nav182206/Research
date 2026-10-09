/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8697
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a59505ca76718549dfc51b9622e2d88cb60f33b5
 */

static inline int gsm_mult(int a, int b)

{

    return (a * b + (1 << 14)) >> 15;

}
