/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_226
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=89cad9f3ec6b30d7550fb5704475fc9c3393a066
 */

QDict *qdict_get_qdict(const QDict *qdict, const char *key)

{

    return qobject_to_qdict(qdict_get_obj(qdict, key, QTYPE_QDICT));

}
