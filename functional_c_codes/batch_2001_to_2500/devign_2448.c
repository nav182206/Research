/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2448
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2ad7ca4c81733cba5c5c464078a643aba61044f8
 */

static int colo_packet_compare_other(Packet *spkt, Packet *ppkt)

{

    trace_colo_compare_main("compare other");

    trace_colo_compare_ip_info(ppkt->size, inet_ntoa(ppkt->ip->ip_src),

                               inet_ntoa(ppkt->ip->ip_dst), spkt->size,

                               inet_ntoa(spkt->ip->ip_src),

                               inet_ntoa(spkt->ip->ip_dst));

    return colo_packet_compare(ppkt, spkt);

}
