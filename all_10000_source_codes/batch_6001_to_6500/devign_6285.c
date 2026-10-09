/* 
 * Benchmark Sample ID : devign_6285
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a998740b22aa673ea475060c787da7c545588cf
 */

QEMUTimer *qemu_new_timer(QEMUClock *clock, QEMUTimerCB *cb, void *opaque)

{

    QEMUTimer *ts;



    ts = qemu_mallocz(sizeof(QEMUTimer));

    ts->clock = clock;

    ts->cb = cb;

    ts->opaque = opaque;

    return ts;

}
