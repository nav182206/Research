/* 
 * Benchmark Sample ID : devign_1937
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3bc36a401e0f33e63a4d2c58b646ddf78efb567c
 */

static USBDevice *usb_bt_init(USBBus *bus, const char *cmdline)

{

    USBDevice *dev;

    struct USBBtState *s;

    HCIInfo *hci;

    const char *name = "usb-bt-dongle";



    if (*cmdline) {

        hci = hci_init(cmdline);

    } else {

        hci = bt_new_hci(qemu_find_bt_vlan(0));

    }

    if (!hci)

        return NULL;



    dev = usb_create(bus, name);

    s = DO_UPCAST(struct USBBtState, dev, dev);

    s->hci = hci;

    if (qdev_init(&dev->qdev) < 0) {

        error_report("Failed to initialize USB device '%s'", name);

        return NULL;

    }



    return dev;

}
