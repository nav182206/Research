/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b8b08266bd58d26e9c6b529ab4130c13eaed3406
 */

static void monitor_json_emitter(Monitor *mon, const QObject *data)

{

    QString *json;



    json = qobject_to_json(data);

    assert(json != NULL);



    mon->mc->print_enabled = 1;

    monitor_printf(mon, "%s\n", qstring_get_str(json));

    mon->mc->print_enabled = 0;



    QDECREF(json);

}
