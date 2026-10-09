/* 
 * Benchmark Sample ID : devign_854
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=39f72ef94ba74701d18daf82b44c18a60f94eb60
 */

static void s390_virtio_rng_instance_init(Object *obj)

{

    VirtIORNGS390 *dev = VIRTIO_RNG_S390(obj);

    object_initialize(&dev->vdev, sizeof(dev->vdev), TYPE_VIRTIO_RNG);

    object_property_add_child(obj, "virtio-backend", OBJECT(&dev->vdev), NULL);

    object_property_add_link(obj, "rng", TYPE_RNG_BACKEND,

                             (Object **)&dev->vdev.conf.rng,


                             OBJ_PROP_LINK_UNREF_ON_RELEASE, NULL);

}
