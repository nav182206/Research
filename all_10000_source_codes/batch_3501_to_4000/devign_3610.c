/* 
 * Benchmark Sample ID : devign_3610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static void piix3_update_irq_levels(PIIX3State *piix3)

{

    int pirq;



    piix3->pic_levels = 0;

    for (pirq = 0; pirq < PIIX_NUM_PIRQS; pirq++) {

        piix3_set_irq_level(piix3, pirq,

                            pci_bus_get_irq_level(piix3->dev.bus, pirq));

    }

}
