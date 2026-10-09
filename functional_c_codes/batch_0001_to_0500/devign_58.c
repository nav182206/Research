/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_58
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=46f70ff148ae01e2dc96e64c393e295a0092555d
 */

static inline bool vhost_needs_vring_endian(VirtIODevice *vdev)

{

    if (virtio_vdev_has_feature(vdev, VIRTIO_F_VERSION_1)) {

        return false;

    }

#ifdef TARGET_IS_BIENDIAN

#ifdef HOST_WORDS_BIGENDIAN

    return !virtio_is_big_endian(vdev);

#else

    return virtio_is_big_endian(vdev);

#endif

#else

    return false;

#endif

}
