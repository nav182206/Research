/* 
 * Benchmark Sample ID : devign_1274
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_visitor_in_errors(TestInputVisitorData *data,

                                   const void *unused)

{

    TestStruct *p = NULL;

    Error *err = NULL;

    Visitor *v;

    strList *q = NULL;

    UserDefTwo *r = NULL;

    WrapAlternate *s = NULL;



    v = visitor_input_test_init(data, "{ 'integer': false, 'boolean': 'foo', "

                                "'string': -42 }");



    visit_type_TestStruct(v, NULL, &p, &err);

    error_free_or_abort(&err);

    g_assert(!p);



    v = visitor_input_test_init(data, "[ '1', '2', false, '3' ]");

    visit_type_strList(v, NULL, &q, &err);

    error_free_or_abort(&err);

    assert(!q);



    v = visitor_input_test_init(data, "{ 'str':'hi' }");

    visit_type_UserDefTwo(v, NULL, &r, &err);

    error_free_or_abort(&err);

    assert(!r);



    v = visitor_input_test_init(data, "{ }");

    visit_type_WrapAlternate(v, NULL, &s, &err);

    error_free_or_abort(&err);

    assert(!s);

}
