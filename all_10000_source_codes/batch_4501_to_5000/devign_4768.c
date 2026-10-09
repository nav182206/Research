/* 
 * Benchmark Sample ID : devign_4768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f53c398aa603cea135ee58fd15249aeff7b9c7ea
 */

int usb_handle_packet(USBDevice *dev, USBPacket *p)

{

    int ret;



    if (dev == NULL) {

        return USB_RET_NODEV;

    }

    assert(dev->addr == p->devaddr);

    assert(dev->state == USB_STATE_DEFAULT);

    assert(p->owner == NULL);



    if (p->devep == 0) {

        /* control pipe */

        switch (p->pid) {

        case USB_TOKEN_SETUP:

            ret = do_token_setup(dev, p);

            break;

        case USB_TOKEN_IN:

            ret = do_token_in(dev, p);

            break;

        case USB_TOKEN_OUT:

            ret = do_token_out(dev, p);

            break;

        default:

            ret = USB_RET_STALL;

            break;

        }

    } else {

        /* data pipe */

        ret = usb_device_handle_data(dev, p);

    }



    if (ret == USB_RET_ASYNC) {

        p->owner = usb_ep_get(dev, p->pid, p->devep);

    }

    return ret;

}
