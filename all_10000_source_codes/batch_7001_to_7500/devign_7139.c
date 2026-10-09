/* 
 * Benchmark Sample ID : devign_7139
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7797a73947d5c0e63dd5552b348cf66c384b4555
 */

PXA2xxPCMCIAState *pxa2xx_pcmcia_init(MemoryRegion *sysmem,

                                      hwaddr base)

{

    DeviceState *dev;

    PXA2xxPCMCIAState *s;



    dev = qdev_create(NULL, TYPE_PXA2XX_PCMCIA);

    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, base);

    s = PXA2XX_PCMCIA(dev);



    if (base == 0x30000000) {

        s->slot.slot_string = "PXA PC Card Socket 1";

    } else {

        s->slot.slot_string = "PXA PC Card Socket 0";

    }



    qdev_init_nofail(dev);



    return s;

}
