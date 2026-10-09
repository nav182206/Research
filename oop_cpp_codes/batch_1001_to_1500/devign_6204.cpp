/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=caffdac363801cd2cf2bf01ad013a8c1e1e43800
 */

static void s390_virtio_blk_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    VirtIOS390DeviceClass *k = VIRTIO_S390_DEVICE_CLASS(klass);



    k->init = s390_virtio_blk_init;

    dc->props = s390_virtio_blk_properties;

}
