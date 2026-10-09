/* 
 * Benchmark Sample ID : devign_4931
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=db12451decf7dfe0f083564183e135f2095228b9
 */

static int virtio_rng_load(QEMUFile *f, void *opaque, int version_id)

{

    if (version_id != 1) {

        return -EINVAL;

    }

    return virtio_load(VIRTIO_DEVICE(opaque), f, version_id);

}
