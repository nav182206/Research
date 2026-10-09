/* 
 * Benchmark Sample ID : devign_5936
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3902d49e13c2428bd6381cfdf183103ca4477c1f
 */

static int virtio_rng_load(QEMUFile *f, void *opaque, int version_id)

{

    VirtIORNG *vrng = opaque;

    VirtIODevice *vdev = VIRTIO_DEVICE(vrng);



    if (version_id != 1) {

        return -EINVAL;

    }

    virtio_load(vdev, f, version_id);



    /* We may have an element ready but couldn't process it due to a quota

     * limit.  Make sure to try again after live migration when the quota may

     * have been reset.

     */

    virtio_rng_process(vrng);



    return 0;

}
