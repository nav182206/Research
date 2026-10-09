/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8551
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fcf73f66a67f5e58c18216f8c8651e38cf4d90af
 */

QFloat *qobject_to_qfloat(const QObject *obj)

{

    if (qobject_type(obj) != QTYPE_QFLOAT)

        return NULL;



    return container_of(obj, QFloat, base);

}
