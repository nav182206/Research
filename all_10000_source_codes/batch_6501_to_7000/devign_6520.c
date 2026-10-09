/* 
 * Benchmark Sample ID : devign_6520
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fcf73f66a67f5e58c18216f8c8651e38cf4d90af
 */

int64_t qdict_get_int(const QDict *qdict, const char *key)

{

    QObject *obj = qdict_get_obj(qdict, key, QTYPE_QINT);

    return qint_get_int(qobject_to_qint(obj));

}
