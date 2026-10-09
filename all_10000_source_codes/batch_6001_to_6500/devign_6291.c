/* 
 * Benchmark Sample ID : devign_6291
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef76dc59fa5203d146a2acf85a0ad5a5971a4824
 */

START_TEST(simple_varargs)

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

    fail_unless(embedded_obj != NULL);



    obj = qobject_from_jsonf("[%d, 2, %p]", 1, embedded_obj);

    fail_unless(obj != NULL);



    fail_unless(compare_litqobj_to_qobj(&decoded, obj) == 1);



    qobject_decref(obj);

}
