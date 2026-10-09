/* 
 * Benchmark Sample ID : devign_3029
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d549db5a732ef2ec145b84c5008a7585cf17cf67
 */

static void qemu_mutex_unlock_iothread(void)

{

    qemu_mutex_unlock(&qemu_global_mutex);

}
