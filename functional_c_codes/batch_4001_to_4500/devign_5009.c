/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5009
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=95129d6fc9ead97155627a4ca0cfd37282883658
 */

static bool virtio_device_endian_needed(void *opaque)

{

    VirtIODevice *vdev = opaque;



    assert(vdev->device_endian != VIRTIO_DEVICE_ENDIAN_UNKNOWN);

    if (!virtio_has_feature(vdev, VIRTIO_F_VERSION_1)) {

        return vdev->device_endian != virtio_default_endian();

    }

    /* Devices conforming to VIRTIO 1.0 or later are always LE. */

    return vdev->device_endian != VIRTIO_DEVICE_ENDIAN_LITTLE;

}
