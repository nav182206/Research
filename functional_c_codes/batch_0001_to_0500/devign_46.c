/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_46
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=38931fa8cfb074a08ce65fd1982bd4a5bef9d6fb
 */

static void usb_hid_changed(HIDState *hs)

{

    USBHIDState *us = container_of(hs, USBHIDState, hid);



    us->changed = 1;



    if (us->datain) {

        us->datain(us->datain_opaque);

    }



    usb_wakeup(&us->dev);

}
