/* 
 * Benchmark Sample ID : devign_8370
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d00e6923b1e2c1bec7840b0a0706764493648527
 */

static void test_enabled(void)

{

    int i;



    throttle_config_init(&cfg);

    g_assert(!throttle_enabled(&cfg));



    for (i = 0; i < BUCKETS_COUNT; i++) {

        throttle_config_init(&cfg);

        set_cfg_value(false, i, 150);

        g_assert(throttle_enabled(&cfg));

    }



    for (i = 0; i < BUCKETS_COUNT; i++) {

        throttle_config_init(&cfg);

        set_cfg_value(false, i, -150);

        g_assert(!throttle_enabled(&cfg));

    }

}
