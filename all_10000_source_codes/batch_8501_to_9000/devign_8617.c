/* 
 * Benchmark Sample ID : devign_8617
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=891fb2cd4592b6fe76106a69e0ca40efbf82726a
 */

static void ehci_reset(void *opaque)

{

    EHCIState *s = opaque;

    int i;

    USBDevice *devs[NB_PORTS];



    trace_usb_ehci_reset();



    /*

     * Do the detach before touching portsc, so that it correctly gets send to

     * us or to our companion based on PORTSC_POWNER before the reset.

     */

    for(i = 0; i < NB_PORTS; i++) {

        devs[i] = s->ports[i].dev;

        if (devs[i]) {

            usb_attach(&s->ports[i], NULL);

        }

    }



    memset(&s->mmio[OPREGBASE], 0x00, MMIO_SIZE - OPREGBASE);



    s->usbcmd = NB_MAXINTRATE << USBCMD_ITC_SH;

    s->usbsts = USBSTS_HALT;



    s->astate = EST_INACTIVE;

    s->pstate = EST_INACTIVE;

    s->isoch_pause = -1;

    s->attach_poll_counter = 0;



    for(i = 0; i < NB_PORTS; i++) {

        if (s->companion_ports[i]) {

            s->portsc[i] = PORTSC_POWNER | PORTSC_PPOWER;

        } else {

            s->portsc[i] = PORTSC_PPOWER;

        }

        if (devs[i]) {

            usb_attach(&s->ports[i], devs[i]);

        }

    }

    ehci_queues_rip_all(s);

}
