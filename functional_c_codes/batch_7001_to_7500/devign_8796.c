/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8796
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void timerlist_free(QEMUTimerList *timer_list)

{

    assert(!timerlist_has_timers(timer_list));

    if (timer_list->clock) {

        QLIST_REMOVE(timer_list, list);

    }

    qemu_mutex_destroy(&timer_list->active_timers_lock);

    g_free(timer_list);

}
