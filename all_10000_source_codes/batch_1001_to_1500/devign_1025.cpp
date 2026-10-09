/* 
 * Benchmark Sample ID : devign_1025
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ac7cc2af500b948510f2481c22e84a57b0a2447
 */

START_TEST(qstring_from_substr_test)

{

    QString *qs;



    qs = qstring_from_substr("virtualization", 3, 9);

    fail_unless(qs != NULL);

    fail_unless(strcmp(qstring_get_str(qs), "tualiza") == 0);



    QDECREF(qs);

}
