/* 
 * Benchmark Sample ID : devign_3889
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cd7bc87868d534f95e928cad98e2a52df7695771
 */

static void usb_msd_class_initfn_bot(ObjectClass *klass, void *data)

{

    USBDeviceClass *uc = USB_DEVICE_CLASS(klass);



    uc->realize = usb_msd_realize_bot;


    uc->attached_settable = true;

}
