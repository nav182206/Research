/* 
 * Benchmark Sample ID : devign_5109
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f0278435df1fa845b3bd9556942f89296d4246b
 */

const char *qdict_get_str(const QDict *qdict, const char *key)

{

    QObject *obj = qdict_get_obj(qdict, key, QTYPE_QSTRING);

    return qstring_get_str(qobject_to_qstring(obj));

}
