/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3315
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6735d433729f80fab80c0a1f70ae131398645613
 */

USBPacket *usb_ep_find_packet_by_id(USBDevice *dev, int pid, int ep,

                                    uint64_t id)

{

    struct USBEndpoint *uep = usb_ep_get(dev, pid, ep);

    USBPacket *p;



    while ((p = QTAILQ_FIRST(&uep->queue)) != NULL) {

        if (p->id == id) {

            return p;

        }

    }



    return NULL;

}
