/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2501
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=55e1819c509b3d9c10a54678b9c585bbda13889e
 */

QInt *qint_from_int(int64_t value)

{

    QInt *qi;



    qi = g_malloc(sizeof(*qi));

    qi->value = value;

    QOBJECT_INIT(qi, &qint_type);



    return qi;

}
