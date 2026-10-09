/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9420
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15c2f669e3fb2bc97f7b42d1871f595c0ac24af8
 */

static void test_visitor_out_null(TestOutputVisitorData *data,

                                  const void *unused)

{

    QObject *arg;

    QDict *qdict;

    QObject *nil;



    visit_start_struct(data->ov, NULL, NULL, 0, &error_abort);

    visit_type_null(data->ov, "a", &error_abort);

    visit_end_struct(data->ov, &error_abort);

    arg = qmp_output_get_qobject(data->qov);

    g_assert(qobject_type(arg) == QTYPE_QDICT);

    qdict = qobject_to_qdict(arg);

    g_assert_cmpint(qdict_size(qdict), ==, 1);

    nil = qdict_get(qdict, "a");

    g_assert(nil);

    g_assert(qobject_type(nil) == QTYPE_QNULL);

    qobject_decref(arg);

}
