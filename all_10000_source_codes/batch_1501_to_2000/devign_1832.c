/* 
 * Benchmark Sample ID : devign_1832
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5af35d7feccaa7d26b72c6c3d14116421d736b36
 */

static void usb_host_handle_reset(USBDevice *udev)

{

    USBHostDevice *s = USB_HOST_DEVICE(udev);



    trace_usb_host_reset(s->bus_num, s->addr);



    if (udev->configuration == 0) {

        return;

    }

    usb_host_release_interfaces(s);

    libusb_reset_device(s->dh);

    usb_host_claim_interfaces(s, 0);

    usb_host_ep_update(s);

}
