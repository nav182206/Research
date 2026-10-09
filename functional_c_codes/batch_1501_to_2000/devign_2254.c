/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2254
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b4049b74b97f30fe944c63b5f158ec9e87bd2593
 */

void qemu_unregister_clock_reset_notifier(QEMUClock *clock,

                                          Notifier *notifier)

{

    qemu_clock_unregister_reset_notifier(clock->type, notifier);

}
