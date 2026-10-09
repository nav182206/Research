/* 
 * Benchmark Sample ID : devign_1181
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9416dc62c36079b93b4951c894a0b15e53bb38c
 */

static void test_visitor_in_fail_list(TestInputVisitorData *data,
                                      const void *unused)
{
    int64_t i64 = -1;
    Error *err = NULL;
    Visitor *v;
    /* Unvisited list tail */
    v = visitor_input_test_init(data, "[ 1, 2, 3 ]");
    visit_type_int(v, NULL, &i64, &error_abort);
    g_assert_cmpint(i64, ==, 1);
    visit_type_int(v, NULL, &i64, &error_abort);
    g_assert_cmpint(i64, ==, 2);
    visit_check_list(v, &err);
}
