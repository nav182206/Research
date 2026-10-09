/* 
 * Benchmark Sample ID : devign_5652
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cbcfa0418f0c196afa765f5c9837b9344d1adcf3
 */

QEMUTimer *qemu_new_timer(QEMUClock *clock, int scale,

                          QEMUTimerCB *cb, void *opaque)

{

    return g_malloc(1);

}
