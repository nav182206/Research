/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1508
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980a065fb5e86d6dec337e6cb6ff432f1a143c9
 */

static int usb_wacom_initfn(USBDevice *dev)

{

    USBWacomState *s = DO_UPCAST(USBWacomState, dev, dev);

    s->dev.speed = USB_SPEED_FULL;

    s->changed = 1;

    return 0;

}
