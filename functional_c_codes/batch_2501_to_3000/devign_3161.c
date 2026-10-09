/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3161
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14b6160099f0caf5dc9d62e637b007bc5d719a96
 */

bool qdict_get_bool(const QDict *qdict, const char *key)

{

    QObject *obj = qdict_get_obj(qdict, key, QTYPE_QBOOL);

    return qbool_get_bool(qobject_to_qbool(obj));

}
