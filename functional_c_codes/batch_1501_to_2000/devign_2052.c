/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bc9b78debf63c9be051abe51403736d386092d09
 */

static void do_dma_memory_set(dma_addr_t addr, uint8_t c, dma_addr_t len)

{

#define FILLBUF_SIZE 512

    uint8_t fillbuf[FILLBUF_SIZE];

    int l;



    memset(fillbuf, c, FILLBUF_SIZE);

    while (len > 0) {

        l = len < FILLBUF_SIZE ? len : FILLBUF_SIZE;

        cpu_physical_memory_rw(addr, fillbuf, l, true);

        len -= len;

        addr += len;

    }

}
