/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6872
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bf937a7965c1d1a6dce4f615d0ead2e2ab505004
 */

static void bt_dummy_lmp_connection_complete(struct bt_link_s *link)

{

    if (link->slave->reject_reason)

        fprintf(stderr, "%s: stray LMP_not_accepted received, fixme\n",

                        __func__);

    else

        fprintf(stderr, "%s: stray LMP_accepted received, fixme\n",

                        __func__);

    exit(-1);

}
