/* 
 * Benchmark Sample ID : devign_5342
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d96391c1ffeb30a0afa695c86579517c69d9a889
 */

static inline void check_hwrena(CPUMIPSState *env, int reg)

{

    if ((env->hflags & MIPS_HFLAG_CP0) || (env->CP0_HWREna & (1 << reg))) {

        return;

    }

    do_raise_exception(env, EXCP_RI, GETPC());

}
