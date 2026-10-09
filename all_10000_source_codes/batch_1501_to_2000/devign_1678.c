/* 
 * Benchmark Sample ID : devign_1678
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb700029c7836798046191d62d595363d92c84d4
 */

static bool net_tx_pkt_rebuild_payload(struct NetTxPkt *pkt)

{

    size_t payload_len = iov_size(pkt->raw, pkt->raw_frags) - pkt->hdr_len;



    pkt->payload_frags = iov_copy(&pkt->vec[NET_TX_PKT_PL_START_FRAG],

                                pkt->max_payload_frags,

                                pkt->raw, pkt->raw_frags,

                                pkt->hdr_len, payload_len);



    if (pkt->payload_frags != (uint32_t) -1) {

        pkt->payload_len = payload_len;

        return true;

    } else {

        return false;

    }

}
