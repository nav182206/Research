/* 
 * Benchmark Sample ID : devign_5646
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2d1fd2613769d99e5fad1f57ab8466434e2079fd
 */

SCSIDevice *scsi_bus_legacy_add_drive(SCSIBus *bus, BlockDriverState *bdrv, int unit)

{

    const char *driver;

    DeviceState *dev;



    driver = bdrv_is_sg(bdrv) ? "scsi-generic" : "scsi-disk";

    dev = qdev_create(&bus->qbus, driver);

    qdev_prop_set_uint32(dev, "scsi-id", unit);

    if (qdev_prop_set_drive(dev, "drive", bdrv) < 0) {

        qdev_free(dev);

        return NULL;

    }

    if (qdev_init(dev) < 0)

        return NULL;

    return DO_UPCAST(SCSIDevice, qdev, dev);

}
