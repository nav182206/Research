/* 
 * Benchmark Sample ID : devign_5163
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static void bt_dummy_lmp_acl_resp(struct bt_link_s *link,

                const uint8_t *data, int start, int len)

{

    fprintf(stderr, "%s: stray ACL response PDU, fixme\n", __FUNCTION__);

    exit(-1);

}
