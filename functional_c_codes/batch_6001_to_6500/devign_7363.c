/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7363
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a4496903795e05c1e8367bb4c9862d5670f48d7
 */

static void panicked_mon_event(const char *action)

{

    QObject *data;



    data = qobject_from_jsonf("{ 'action': %s }", action);

    monitor_protocol_event(QEVENT_GUEST_PANICKED, data);

    qobject_decref(data);

}
