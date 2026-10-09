/* 
 * Benchmark Sample ID : devign_8755
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f0278435df1fa845b3bd9556942f89296d4246b
 */

QString *qobject_to_qstring(const QObject *obj)

{

    if (qobject_type(obj) != QTYPE_QSTRING)

        return NULL;



    return container_of(obj, QString, base);

}
