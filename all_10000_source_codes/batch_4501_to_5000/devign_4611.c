/* 
 * Benchmark Sample ID : devign_4611
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6085e3ace20bc9b0fa625d8d79b22668710e217
 */

bool qemu_peer_has_vnet_hdr_len(NetClientState *nc, int len)

{

    if (!nc->peer || !nc->peer->info->has_vnet_hdr_len) {

        return false;

    }



    return nc->peer->info->has_vnet_hdr_len(nc->peer, len);

}
