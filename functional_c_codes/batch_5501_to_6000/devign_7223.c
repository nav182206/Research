/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7223
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9eaaf971683c99ed197fa1b7d1a3ca9baabfb3ee
 */

static void simple_varargs(void)

{

    QObject *embedded_obj;

    QObject *obj;

    LiteralQObject decoded = QLIT_QLIST(((LiteralQObject[]){

            QLIT_QINT(1),

            QLIT_QINT(2),

            QLIT_QLIST(((LiteralQObject[]){

                        QLIT_QINT(32),

                        QLIT_QINT(42),

                        {}})),

            {}}));



    embedded_obj = qobject_from_json("[32, 42]");

    g_assert(embedded_obj != NULL);



    obj = qobject_from_jsonf("[%d, 2, %p]", 1, embedded_obj);

    g_assert(obj != NULL);



    g_assert(compare_litqobj_to_qobj(&decoded, obj) == 1);



    qobject_decref(obj);

}
