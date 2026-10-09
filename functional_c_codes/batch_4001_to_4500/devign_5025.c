/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5025
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=66453cff9e5e75344c601cd7674c8ef5fefee8a6
 */

void GCC_FMT_ATTR(2, 3) virtio_error(VirtIODevice *vdev, const char *fmt, ...)

{

    va_list ap;



    va_start(ap, fmt);

    error_vreport(fmt, ap);

    va_end(ap);



    vdev->broken = true;



    if (virtio_vdev_has_feature(vdev, VIRTIO_F_VERSION_1)) {

        virtio_set_status(vdev, vdev->status | VIRTIO_CONFIG_S_NEEDS_RESET);

        virtio_notify_config(vdev);

    }

}
