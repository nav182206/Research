/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5058
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6085e3ace20bc9b0fa625d8d79b22668710e217
 */

static void virtio_net_apply_guest_offloads(VirtIONet *n)

{

    qemu_peer_set_offload(qemu_get_subqueue(n->nic, 0),

            !!(n->curr_guest_offloads & (1ULL << VIRTIO_NET_F_GUEST_CSUM)),

            !!(n->curr_guest_offloads & (1ULL << VIRTIO_NET_F_GUEST_TSO4)),

            !!(n->curr_guest_offloads & (1ULL << VIRTIO_NET_F_GUEST_TSO6)),

            !!(n->curr_guest_offloads & (1ULL << VIRTIO_NET_F_GUEST_ECN)),

            !!(n->curr_guest_offloads & (1ULL << VIRTIO_NET_F_GUEST_UFO)));

}
