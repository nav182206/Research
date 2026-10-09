/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3607
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bf937a7965c1d1a6dce4f615d0ead2e2ab505004
 */

static void bt_dummy_lmp_disconnect_master(struct bt_link_s *link)

{

    fprintf(stderr, "%s: stray LMP_detach received, fixme\n", __func__);

    exit(-1);

}
