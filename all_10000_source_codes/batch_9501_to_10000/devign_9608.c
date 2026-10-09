/* 
 * Benchmark Sample ID : devign_9608
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

bool qemu_clock_run_all_timers(void)

{

    bool progress = false;

    QEMUClockType type;



    for (type = 0; type < QEMU_CLOCK_MAX; type++) {

        progress |= qemu_clock_run_timers(type);

    }



    return progress;

}
