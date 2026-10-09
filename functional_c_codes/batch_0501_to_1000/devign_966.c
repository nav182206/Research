/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

uint64_t timer_expire_time_ns(QEMUTimer *ts)

{

    return timer_pending(ts) ? ts->expire_time : -1;

}
