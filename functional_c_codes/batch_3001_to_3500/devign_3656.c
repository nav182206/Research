/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3656
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t esp_pci_io_read(void *opaque, target_phys_addr_t addr,

                                unsigned int size)

{

    PCIESPState *pci = opaque;

    uint32_t ret;



    if (addr < 0x40) {

        /* SCSI core reg */

        ret = esp_reg_read(&pci->esp, addr >> 2);

    } else if (addr < 0x60) {

        /* PCI DMA CCB */

        ret = esp_pci_dma_read(pci, (addr - 0x40) >> 2);

    } else if (addr == 0x70) {

        /* DMA SCSI Bus and control */

        trace_esp_pci_sbac_read(pci->sbac);

        ret = pci->sbac;

    } else {

        /* Invalid region */

        trace_esp_pci_error_invalid_read((int)addr);

        ret = 0;

    }



    /* give only requested data */

    ret >>= (addr & 3) * 8;

    ret &= ~(~(uint64_t)0 << (8 * size));



    return ret;

}
