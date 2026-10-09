/* 
 * Benchmark Sample ID : devign_8605
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980a065fb5e86d6dec337e6cb6ff432f1a143c9
 */

static int usb_bt_initfn(USBDevice *dev)

{

    struct USBBtState *s = DO_UPCAST(struct USBBtState, dev, dev);

    s->dev.speed = USB_SPEED_HIGH;

    return 0;

}
