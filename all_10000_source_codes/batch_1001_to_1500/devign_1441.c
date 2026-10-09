/* 
 * Benchmark Sample ID : devign_1441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0c16c056a4f9dec18fdd56feec82a5db9ff3c15e
 */

static void test_hash_base64(void)

{

    size_t i;



    g_assert(qcrypto_init(NULL) == 0);



    for (i = 0; i < G_N_ELEMENTS(expected_outputs) ; i++) {

        int ret;

        char *digest;



        ret = qcrypto_hash_base64(i,

                                  INPUT_TEXT,

                                  strlen(INPUT_TEXT),

                                  &digest,

                                  NULL);

        g_assert(ret == 0);

        g_assert(g_str_equal(digest, expected_outputs_b64[i]));

        g_free(digest);

    }

}
