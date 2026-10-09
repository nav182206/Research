/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9557
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0e2d644096c79a71099b176d08f465f6803a8b1
 */

static inline void vring_used_flags_unset_bit(VirtQueue *vq, int mask)

{

    VRingMemoryRegionCaches *caches = atomic_rcu_read(&vq->vring.caches);

    VirtIODevice *vdev = vq->vdev;

    hwaddr pa = offsetof(VRingUsed, flags);

    uint16_t flags = virtio_lduw_phys_cached(vq->vdev, &caches->used, pa);



    virtio_stw_phys_cached(vdev, &caches->used, pa, flags & ~mask);

    address_space_cache_invalidate(&caches->used, pa, sizeof(flags));

}
