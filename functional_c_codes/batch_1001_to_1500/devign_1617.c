/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1617
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=805017b7791200f1b72deef17dc98fd272b941eb
 */

int main(int argc, char **argv)

{

    TestInputVisitorData testdata;



    g_test_init(&argc, &argv, NULL);



    validate_test_add("/visitor/input-strict/pass/struct",

                       &testdata, test_validate_struct);

    validate_test_add("/visitor/input-strict/pass/struct-nested",

                       &testdata, test_validate_struct_nested);

    validate_test_add("/visitor/input-strict/pass/list",

                       &testdata, test_validate_list);

    validate_test_add("/visitor/input-strict/pass/union",

                       &testdata, test_validate_union);

    validate_test_add("/visitor/input-strict/pass/union-flat",

                       &testdata, test_validate_union_flat);

    validate_test_add("/visitor/input-strict/pass/union-anon",

                       &testdata, test_validate_union_anon);

    validate_test_add("/visitor/input-strict/fail/struct",

                       &testdata, test_validate_fail_struct);

    validate_test_add("/visitor/input-strict/fail/struct-nested",

                       &testdata, test_validate_fail_struct_nested);

    validate_test_add("/visitor/input-strict/fail/list",

                       &testdata, test_validate_fail_list);

    validate_test_add("/visitor/input-strict/fail/union",

                       &testdata, test_validate_fail_union);

    validate_test_add("/visitor/input-strict/fail/union-flat",

                       &testdata, test_validate_fail_union_flat);

    validate_test_add("/visitor/input-strict/fail/union-flat-no-discriminator",

                       &testdata, test_validate_fail_union_flat_no_discrim);

    validate_test_add("/visitor/input-strict/fail/union-anon",

                       &testdata, test_validate_fail_union_anon);



    g_test_run();



    return 0;

}
