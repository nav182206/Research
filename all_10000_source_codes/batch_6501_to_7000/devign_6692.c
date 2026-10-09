/* 
 * Benchmark Sample ID : devign_6692
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9c05e507f7a6647cd7b106c8784f1f15a0e4f5c
 */

static void test_uuid_unparse_strdup(void)

{

    int i;



    for (i = 0; i < ARRAY_SIZE(uuid_test_data); i++) {

        char *out;



        if (!uuid_test_data[i].check_unparse) {

            continue;

        }

        out = qemu_uuid_unparse_strdup(&uuid_test_data[i].uuid);

        g_assert_cmpstr(uuid_test_data[i].uuidstr, ==, out);


    }

}
