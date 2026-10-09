/* 
 * Benchmark Sample ID : devign_3209
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static int ide_qdev_init(DeviceState *qdev)

{

    IDEDevice *dev = IDE_DEVICE(qdev);

    IDEDeviceClass *dc = IDE_DEVICE_GET_CLASS(dev);

    IDEBus *bus = DO_UPCAST(IDEBus, qbus, qdev->parent_bus);



    if (!dev->conf.bs) {

        error_report("No drive specified");

        goto err;

    }

    if (dev->unit == -1) {

        dev->unit = bus->master ? 1 : 0;

    }



    if (dev->unit >= bus->max_units) {

        error_report("Can't create IDE unit %d, bus supports only %d units",

                     dev->unit, bus->max_units);

        goto err;

    }



    switch (dev->unit) {

    case 0:

        if (bus->master) {

            error_report("IDE unit %d is in use", dev->unit);

            goto err;

        }

        bus->master = dev;

        break;

    case 1:

        if (bus->slave) {

            error_report("IDE unit %d is in use", dev->unit);

            goto err;

        }

        bus->slave = dev;

        break;

    default:

        error_report("Invalid IDE unit %d", dev->unit);

        goto err;

    }

    return dc->init(dev);



err:

    return -1;

}
