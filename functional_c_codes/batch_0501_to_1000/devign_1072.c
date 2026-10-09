/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1072
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3bc36a401e0f33e63a4d2c58b646ddf78efb567c
 */

static USBDevice *usb_braille_init(USBBus *bus, const char *unused)

{

    USBDevice *dev;

    CharDriverState *cdrv;



    cdrv = qemu_chr_new("braille", "braille", NULL);

    if (!cdrv)

        return NULL;



    dev = usb_create(bus, "usb-braille");

    qdev_prop_set_chr(&dev->qdev, "chardev", cdrv);

    qdev_init_nofail(&dev->qdev);



    return dev;

}
