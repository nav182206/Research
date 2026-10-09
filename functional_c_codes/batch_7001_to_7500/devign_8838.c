/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8838
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5255fcf8e47acd059e2f0d414841c40231c1bd22
 */

static int nvic_pending_prio(NVICState *s)

{

    /* return the priority of the current pending interrupt,

     * or NVIC_NOEXC_PRIO if no interrupt is pending

     */

    return s->vectpending ? s->vectors[s->vectpending].prio : NVIC_NOEXC_PRIO;

}
