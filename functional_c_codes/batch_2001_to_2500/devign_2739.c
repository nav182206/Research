/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2739
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8172539d21a03e982aa7f139ddc1607dc1422045
 */

static unsigned syborg_virtio_get_features(void *opaque)

{

    unsigned ret = 0;

    ret |= (1 << VIRTIO_F_NOTIFY_ON_EMPTY);

    return ret;

}
