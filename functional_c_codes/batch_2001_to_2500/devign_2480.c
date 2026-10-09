/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2480
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

float64 helper_fitod(CPUSPARCState *env, int32_t src)

{

    /* No possible exceptions converting int to double.  */

    return int32_to_float64(src, &env->fp_status);

}
