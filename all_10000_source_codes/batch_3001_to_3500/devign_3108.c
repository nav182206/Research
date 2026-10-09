/* 
 * Benchmark Sample ID : devign_3108
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=91479dd0b5bd3b087b92ddd7bc3f2c54982cfe17
 */

static void iter_func(QObject *obj, void *opaque)

{

    QInt *qi;



    fail_unless(opaque == NULL);



    qi = qobject_to_qint(obj);

    fail_unless(qi != NULL);

    fail_unless((qint_get_int(qi) >= 0) && (qint_get_int(qi) <= iter_max));



    iter_called++;

}
