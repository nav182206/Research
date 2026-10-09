/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8457
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ac7cc2af500b948510f2481c22e84a57b0a2447
 */

START_TEST(qstring_destroy_test)

{

    QString *qstring = qstring_from_str("destroy test");

    QDECREF(qstring);

}
