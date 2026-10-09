/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6642
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void timer_mod(QEMUTimer *ts, int64_t expire_time)

{

    timer_mod_ns(ts, expire_time * ts->scale);

}
