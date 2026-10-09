/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7034
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=621ff94d5074d88253a5818c6b9c4db718fbfc65
 */

static void virtio_ccw_balloon_realize(VirtioCcwDevice *ccw_dev, Error **errp)

{

    VirtIOBalloonCcw *dev = VIRTIO_BALLOON_CCW(ccw_dev);

    DeviceState *vdev = DEVICE(&dev->vdev);

    Error *err = NULL;



    qdev_set_parent_bus(vdev, BUS(&ccw_dev->bus));

    object_property_set_bool(OBJECT(vdev), true, "realized", &err);

    if (err) {

        error_propagate(errp, err);

    }

}
