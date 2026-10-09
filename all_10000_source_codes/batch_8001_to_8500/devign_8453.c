/* 
 * Benchmark Sample ID : devign_8453
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

static bool timer_expired_ns(QEMUTimer *timer_head, int64_t current_time)

{

    return timer_head && (timer_head->expire_time <= current_time);

}
