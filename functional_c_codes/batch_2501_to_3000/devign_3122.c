/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3122
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cd1bd53a669c88f219ca47b538889cd918605fea
 */

void timer_del(QEMUTimer *ts)

{

    QEMUTimerList *timer_list = ts->timer_list;



    qemu_mutex_lock(&timer_list->active_timers_lock);

    timer_del_locked(timer_list, ts);

    qemu_mutex_unlock(&timer_list->active_timers_lock);

}
