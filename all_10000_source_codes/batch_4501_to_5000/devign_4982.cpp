/* 
 * Benchmark Sample ID : devign_4982
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7f595609b49615b07c50b7182c4ef125c39cb5da
 */

static void usb_mouse_class_initfn(ObjectClass *klass, void *data)

{

    USBDeviceClass *uc = USB_DEVICE_CLASS(klass);



    uc->init           = usb_mouse_initfn;

    uc->product_desc   = "QEMU USB Mouse";

    uc->usb_desc       = &desc_mouse;

    uc->handle_packet  = usb_generic_handle_packet;

    uc->handle_reset   = usb_hid_handle_reset;

    uc->handle_control = usb_hid_handle_control;

    uc->handle_data    = usb_hid_handle_data;

    uc->handle_destroy = usb_hid_handle_destroy;

}
