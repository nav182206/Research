/* 
 * Benchmark Sample ID : devign_3970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t bmdma_read(void *opaque, target_phys_addr_t addr,

                           unsigned size)

{

    BMDMAState *bm = opaque;

    PCIIDEState *pci_dev = bm->pci_dev;

    uint32_t val;



    if (size != 1) {

        return ((uint64_t)1 << (size * 8)) - 1;

    }



    switch(addr & 3) {

    case 0:

        val = bm->cmd;

        break;

    case 1:

        val = pci_dev->dev.config[MRDMODE];

        break;

    case 2:

        val = bm->status;

        break;

    case 3:

        if (bm == &pci_dev->bmdma[0]) {

            val = pci_dev->dev.config[UDIDETCR0];

        } else {

            val = pci_dev->dev.config[UDIDETCR1];

        }

        break;

    default:

        val = 0xff;

        break;

    }

#ifdef DEBUG_IDE

    printf("bmdma: readb 0x%02x : 0x%02x\n", addr, val);

#endif

    return val;

}
