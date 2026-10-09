/* 
 * Benchmark Sample ID : devign_9977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

static inline void clear_float_exceptions(CPUSPARCState *env)

{

    set_float_exception_flags(0, &env->fp_status);

}
