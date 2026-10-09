/* 
 * Benchmark Sample ID : devign_2809
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aea390e4be652d5b5457771d25eded0dba14fe37
 */

static bool pte32_match(target_ulong pte0, target_ulong pte1,

                        bool secondary, target_ulong ptem)

{

    return (pte0 & HPTE32_V_VALID)

        && (secondary == !!(pte0 & HPTE32_V_SECONDARY))

        && HPTE32_V_COMPARE(pte0, ptem);

}
