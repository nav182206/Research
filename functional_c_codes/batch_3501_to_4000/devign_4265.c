/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4265
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b25f23e7dbc6bc0dcda010222a4f178669d1aedc
 */

QList *qdict_get_qlist(const QDict *qdict, const char *key)

{

    return qobject_to_qlist(qdict_get_obj(qdict, key, QTYPE_QLIST));

}
