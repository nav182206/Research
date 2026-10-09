/* 
 * Benchmark Sample ID : devign_3853
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f4321c11ff6e98583846bfd6f0e81954924b003
 */

static void softusb_usbdev_datain(void *opaque)

{

    MilkymistSoftUsbState *s = opaque;



    USBPacket p;



    p.pid = USB_TOKEN_IN;

    p.devep = 1;

    p.data = s->kbd_usb_buffer;

    p.len = sizeof(s->kbd_usb_buffer);

    s->usbdev->info->handle_data(s->usbdev, &p);



    softusb_kbd_changed(s);

}
