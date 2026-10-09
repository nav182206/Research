/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8562
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=02ce232c5051854bf49e6d2816c65e00f6d7e036
 */

static void qemu_clock_init(QEMUClockType type)
{
    QEMUClock *clock = qemu_clock_ptr(type);
    clock->type = type;
    clock->enabled = true;
    clock->last = INT64_MIN;
    QLIST_INIT(&clock->timerlists);
    notifier_list_init(&clock->reset_notifiers);
    main_loop_tlg.tl[type] = timerlist_new(type, NULL, NULL);
}
