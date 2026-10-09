/* 
 * Benchmark Sample ID : devign_1214
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8978b34af3250354e0b67340a7e920f909beda13
 */

static void test_visitor_out_number(TestOutputVisitorData *data,

                                    const void *unused)

{

    double value = 3.14;

    QObject *obj;



    visit_type_number(data->ov, NULL, &value, &error_abort);



    obj = visitor_get(data);

    g_assert(qobject_type(obj) == QTYPE_QFLOAT);

    g_assert(qfloat_get_double(qobject_to_qfloat(obj)) == value);

}
