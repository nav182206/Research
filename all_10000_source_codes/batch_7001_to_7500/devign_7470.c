/* 
 * Benchmark Sample ID : devign_7470
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0e2d644096c79a71099b176d08f465f6803a8b1
 */

static inline void vring_used_idx_set(VirtQueue *vq, uint16_t val)

{

    VRingMemoryRegionCaches *caches = atomic_rcu_read(&vq->vring.caches);

    hwaddr pa = offsetof(VRingUsed, idx);

    virtio_stw_phys_cached(vq->vdev, &caches->used, pa, val);

    address_space_cache_invalidate(&caches->used, pa, sizeof(val));

    vq->used_idx = val;

}
