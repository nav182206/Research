/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1631
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0cd09c3a6cc2230ba38c462fc410b4acce59eb6f
 */

static uint32_t virtio_net_bad_features(VirtIODevice *vdev)

{

    uint32_t features = 0;



    /* Linux kernel 2.6.25.  It understood MAC (as everyone must),

     * but also these: */

    features |= (1 << VIRTIO_NET_F_MAC);

    features |= (1 << VIRTIO_NET_F_CSUM);

    features |= (1 << VIRTIO_NET_F_HOST_TSO4);

    features |= (1 << VIRTIO_NET_F_HOST_TSO6);

    features |= (1 << VIRTIO_NET_F_HOST_ECN);



    return features;

}
