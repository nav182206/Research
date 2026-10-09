/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5729
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ba801af429aaa68f6cc03842c8b6be81a6ede65a
 */

void helper_mtc0_pagemask(CPUMIPSState *env, target_ulong arg1)

{

    /* 1k pages not implemented */

    env->CP0_PageMask = arg1 & (0x1FFFFFFF & (TARGET_PAGE_MASK << 1));

}
