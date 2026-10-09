/* 
 * Benchmark Sample ID : devign_4414
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da3e8a23492dbc13c4b70d90b6ae42970624e63a
 */

static void s390_virtio_net_realize(VirtIOS390Device *s390_dev, Error **errp)

{

    DeviceState *qdev = DEVICE(s390_dev);

    VirtIONetS390 *dev = VIRTIO_NET_S390(s390_dev);

    DeviceState *vdev = DEVICE(&dev->vdev);

    Error *err = NULL;



    virtio_net_set_config_size(&dev->vdev, s390_dev->host_features);

    virtio_net_set_netclient_name(&dev->vdev, qdev->id,

                                  object_get_typename(OBJECT(qdev)));

    qdev_set_parent_bus(vdev, BUS(&s390_dev->bus));

    object_property_set_bool(OBJECT(vdev), true, "realized", &err);

    if (err) {

        error_propagate(errp, err);

        return;

    }



    s390_virtio_device_init(s390_dev, VIRTIO_DEVICE(vdev));

}
