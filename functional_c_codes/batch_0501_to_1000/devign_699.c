/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_699
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=23994a5f524aa575c7a4b2e5250f17b127d2cf2f
 */

static void termsig_handler(int signum)

{

    state = TERMINATE;

    qemu_notify_event();

}
