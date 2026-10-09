/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9769
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0e2d644096c79a71099b176d08f465f6803a8b1
 */

static uint16_t vring_used_idx(VirtQueue *vq)

{

    VRingMemoryRegionCaches *caches = atomic_rcu_read(&vq->vring.caches);

    hwaddr pa = offsetof(VRingUsed, idx);

    return virtio_lduw_phys_cached(vq->vdev, &caches->used, pa);

}
