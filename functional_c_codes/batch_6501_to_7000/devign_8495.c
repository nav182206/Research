/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8495
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1f01e50b8330c24714ddca5841fdbb703076b121
 */

void qed_release(BDRVQEDState *s)

{

    aio_context_release(bdrv_get_aio_context(s->bs));

}
