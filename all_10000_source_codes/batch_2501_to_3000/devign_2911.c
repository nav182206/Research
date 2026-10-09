/* 
 * Benchmark Sample ID : devign_2911
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ab33fcda9f96b9195dfb3fcf5bd9bb5383caeaea
 */

static void qemu_mod_timer_ns(QEMUTimer *ts, int64_t expire_time)

{

    QEMUTimer **pt, *t;



    qemu_del_timer(ts);



    /* add the timer in the sorted list */

    /* NOTE: this code must be signal safe because

       qemu_timer_expired() can be called from a signal. */

    pt = &active_timers[ts->clock->type];

    for(;;) {

        t = *pt;

        if (!t)

            break;

        if (t->expire_time > expire_time)

            break;

        pt = &t->next;

    }

    ts->expire_time = expire_time;

    ts->next = *pt;

    *pt = ts;



    /* Rearm if necessary  */

    if (pt == &active_timers[ts->clock->type]) {

        if (!alarm_timer->pending) {

            qemu_rearm_alarm_timer(alarm_timer);

        }

        /* Interrupt execution to force deadline recalculation.  */

        if (use_icount)

            qemu_notify_event();

    }

}
