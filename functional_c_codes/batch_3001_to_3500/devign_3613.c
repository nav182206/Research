/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3613
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=891fb2cd4592b6fe76106a69e0ca40efbf82726a
 */

static void usb_hub_handle_attach(USBDevice *dev)

{

    USBHubState *s = DO_UPCAST(USBHubState, dev, dev);

    int i;



    for (i = 0; i < NUM_PORTS; i++) {

        usb_port_location(&s->ports[i].port, dev->port, i+1);

    }

}
