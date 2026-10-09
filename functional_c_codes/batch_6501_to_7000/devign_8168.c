/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8168
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=294bbbb4252ab5ff42d0e2c09f209c0bd7eb9748
 */

void qio_channel_test_validate(QIOChannelTest *test)

{

    g_assert_cmpint(memcmp(test->input,

                           test->output,

                           test->len), ==, 0);

    g_assert(test->readerr == NULL);

    g_assert(test->writeerr == NULL);



    g_free(test->inputv);

    g_free(test->outputv);

    g_free(test->input);

    g_free(test->output);

    g_free(test);

}
