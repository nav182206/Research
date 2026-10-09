/* 
 * Benchmark Sample ID : devign_9836
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f53c398aa603cea135ee58fd15249aeff7b9c7ea
 */

static void musb_async_cancel_device(MUSBState *s, USBDevice *dev)

{

    int ep, dir;



    for (ep = 0; ep < 16; ep++) {

        for (dir = 0; dir < 2; dir++) {

            if (s->ep[ep].packey[dir].p.owner == NULL ||

                s->ep[ep].packey[dir].p.owner->dev != dev) {

                continue;

            }

            usb_cancel_packet(&s->ep[ep].packey[dir].p);

            /* status updates needed here? */

        }

    }

}
