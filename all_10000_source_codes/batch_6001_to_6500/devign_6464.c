/* 
 * Benchmark Sample ID : devign_6464
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

bool qemu_clock_has_timers(QEMUClockType type)

{

    return timerlist_has_timers(

        main_loop_tlg.tl[type]);

}
