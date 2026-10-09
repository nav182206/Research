/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4116
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7d553f27fce284805d7f94603932045ee3bbb979
 */

static int usb_qdev_exit(DeviceState *qdev)

{

    USBDevice *dev = USB_DEVICE(qdev);



    if (dev->attached) {

        usb_device_detach(dev);

    }

    usb_device_handle_destroy(dev);

    if (dev->port) {

        usb_release_port(dev);

    }

    return 0;

}
