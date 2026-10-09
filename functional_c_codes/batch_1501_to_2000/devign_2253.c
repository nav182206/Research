/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2253
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9e1c28ddaae5a48415fec1f336b5560eb85d3e1
 */

static Suite *qfloat_suite(void)

{

    Suite *s;

    TCase *qfloat_public_tcase;



    s = suite_create("QFloat test-suite");



    qfloat_public_tcase = tcase_create("Public Interface");

    suite_add_tcase(s, qfloat_public_tcase);

    tcase_add_test(qfloat_public_tcase, qfloat_from_double_test);

    tcase_add_test(qfloat_public_tcase, qfloat_destroy_test);



    return s;

}
