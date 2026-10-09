/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_839
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e5c67ab552fb056827b5b40356c0ef235e975e7e
 */

static void error_callback_bh(void *opaque)

{

    Coroutine *co = opaque;

    qemu_coroutine_enter(co);

}
