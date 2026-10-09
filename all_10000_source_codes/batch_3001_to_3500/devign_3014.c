/* 
 * Benchmark Sample ID : devign_3014
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a12a5a1a0132527afe87c079e4aae4aad372bd94
 */

static void test_validate_fail_union_flat_no_discrim(TestInputVisitorData *data,

                                                     const void *unused)

{

    UserDefFlatUnion2 *tmp = NULL;

    Error *err = NULL;

    Visitor *v;



    /* test situation where discriminator field ('enum1' here) is missing */

    v = validate_test_init(data, "{ 'integer': 42, 'string': 'c', 'string1': 'd', 'string2': 'e' }");



    visit_type_UserDefFlatUnion2(v, &tmp, NULL, &err);

    g_assert(err);

    error_free(err);

    qapi_free_UserDefFlatUnion2(tmp);

}
