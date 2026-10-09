/* 
 * Benchmark Sample ID : devign_6760
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=61f52e06f0a21bab782f98ef3ea789aa6d0aa046
 */

static int ahci_dma_prepare_buf(IDEDMA *dma, int is_write)

{

    AHCIDevice *ad = DO_UPCAST(AHCIDevice, dma, dma);

    IDEState *s = &ad->port.ifs[0];



    ahci_populate_sglist(ad, &s->sg);

    s->io_buffer_size = s->sg.size;



    DPRINTF(ad->port_no, "len=%#x\n", s->io_buffer_size);

    return s->io_buffer_size != 0;

}
