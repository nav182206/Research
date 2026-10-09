/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7019
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a718978ed58abc1ad92567a9c17525136be02a71
 */

static int32_t ahci_dma_prepare_buf(IDEDMA *dma, int is_write)

{

    AHCIDevice *ad = DO_UPCAST(AHCIDevice, dma, dma);

    IDEState *s = &ad->port.ifs[0];



    if (ahci_populate_sglist(ad, &s->sg, s->io_buffer_offset) == -1) {

        DPRINTF(ad->port_no, "ahci_dma_prepare_buf failed.\n");

        return -1;

    }

    s->io_buffer_size = s->sg.size;



    DPRINTF(ad->port_no, "len=%#x\n", s->io_buffer_size);

    return s->io_buffer_size;

}
