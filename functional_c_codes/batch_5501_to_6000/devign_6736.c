/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6736
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fe52840c8760122257be7b7e4893dd951480a71f
 */

static void coroutine_enter_cb(void *opaque, int ret)

{

    Coroutine *co = opaque;

    qemu_coroutine_enter(co, NULL);

}
