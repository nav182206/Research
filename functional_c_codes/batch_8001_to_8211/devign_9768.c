/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=393c13b940be8f2e5b126cd9f442c12e7ecb4cac
 */

static void bt_l2cap_sdp_close_ch(void *opaque)

{

    struct bt_l2cap_sdp_state_s *sdp = opaque;

    int i;



    for (i = 0; i < sdp->services; i ++) {

        g_free(sdp->service_list[i].attribute_list->pair);

        g_free(sdp->service_list[i].attribute_list);

        g_free(sdp->service_list[i].uuid);

    }

    g_free(sdp->service_list);

    g_free(sdp);

}
