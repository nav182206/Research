/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1435
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bef1301acb74d177b42890116e4eeaf26047b9e3
 */

static int ahci_dma_prepare_buf(IDEDMA *dma, int is_write)

{

    AHCIDevice *ad = DO_UPCAST(AHCIDevice, dma, dma);

    IDEState *s = &ad->port.ifs[0];



    ahci_populate_sglist(ad, &s->sg, 0);

    s->io_buffer_size = s->sg.size;



    DPRINTF(ad->port_no, "len=%#x\n", s->io_buffer_size);

    return s->io_buffer_size != 0;

}
