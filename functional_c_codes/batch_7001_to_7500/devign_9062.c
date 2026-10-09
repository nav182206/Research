/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qdict_destroy_simple_test)

{

    QDict *qdict;



    qdict = qdict_new();

    qdict_put_obj(qdict, "num", QOBJECT(qint_from_int(0)));

    qdict_put_obj(qdict, "str", QOBJECT(qstring_from_str("foo")));



    QDECREF(qdict);

}
