/* 
 * Benchmark Sample ID : devign_1698
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=58ac56b9ad53b006396523639bb7d7043edc56bf
 */

static QEMUClock *qemu_new_clock(int type)

{

    QEMUClock *clock;



    clock = g_malloc0(sizeof(QEMUClock));

    clock->type = type;

    clock->enabled = true;

    clock->last = INT64_MIN;

    notifier_list_init(&clock->reset_notifiers);

    return clock;

}
