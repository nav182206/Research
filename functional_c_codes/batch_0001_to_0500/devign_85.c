/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_85
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8607f5c3072caeebbe0217df28651fffd3a79fd9
 */

static void vring_desc_read(VirtIODevice *vdev, VRingDesc *desc,

                            hwaddr desc_pa, int i)

{

    address_space_read(&address_space_memory, desc_pa + i * sizeof(VRingDesc),

                       MEMTXATTRS_UNSPECIFIED, (void *)desc, sizeof(VRingDesc));

    virtio_tswap64s(vdev, &desc->addr);

    virtio_tswap32s(vdev, &desc->len);

    virtio_tswap16s(vdev, &desc->flags);

    virtio_tswap16s(vdev, &desc->next);

}
