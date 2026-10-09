/* 
 * Benchmark Sample ID : devign_3891
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f3b2bea3c76ba9283b957f1373e7cebdbf863059
 */

static USBDevice *usb_try_create_simple(USBBus *bus, const char *name,

                                        Error **errp)

{

    Error *err = NULL;

    USBDevice *dev;



    dev = USB_DEVICE(qdev_try_create(&bus->qbus, name));

    if (!dev) {

        error_setg(errp, "Failed to create USB device '%s'", name);

        return NULL;

    }

    object_property_set_bool(OBJECT(dev), true, "realized", &err);

    if (err) {

        error_propagate(errp, err);

        error_prepend(errp, "Failed to initialize USB device '%s': ",

                      name);

        object_unparent(OBJECT(dev));

        return NULL;

    }

    return dev;

}
