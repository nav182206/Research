/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7557
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1aaee43cf7a43ca8e7f12883ee7e3a35fe5eb84c
 */

static void info_mice_iter(QObject *data, void *opaque)

{

    QDict *mouse;

    Monitor *mon = opaque;



    mouse = qobject_to_qdict(data);

    monitor_printf(mon, "%c Mouse #%" PRId64 ": %s\n",

                  (qdict_get_bool(mouse, "current") ? '*' : ' '),

                  qdict_get_int(mouse, "index"), qdict_get_str(mouse, "name"));

}
