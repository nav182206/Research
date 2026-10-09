/* 
 * Benchmark Sample ID : devign_5124
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=265804b5d755502438b4d42a3682f54e03ea4d32
 */

static void test_interface_impl(const char *type)

{

    Object *obj = object_new(type);

    TestIf *iobj = TEST_IF(obj);

    TestIfClass *ioc = TEST_IF_GET_CLASS(iobj);



    g_assert(iobj);

    g_assert(ioc->test == PATTERN);


}
