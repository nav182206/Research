/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3409
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=38931fa8cfb074a08ce65fd1982bd4a5bef9d6fb
 */

static int usb_hid_initfn(USBDevice *dev, int kind)

{

    USBHIDState *us = DO_UPCAST(USBHIDState, dev, dev);



    usb_desc_init(dev);

    hid_init(&us->hid, kind, usb_hid_changed);



    /* Force poll routine to be run and grab input the first time.  */

    us->changed = 1;

    return 0;

}
