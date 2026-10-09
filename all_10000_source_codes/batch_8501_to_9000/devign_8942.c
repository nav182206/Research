/* 
 * Benchmark Sample ID : devign_8942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=45416789e8ccced568a4984af61974adfbfa0f62
 */

static uint32_t sm501_palette_read(void *opaque, target_phys_addr_t addr)

{

    SM501State * s = (SM501State *)opaque;

    SM501_DPRINTF("sm501 palette read addr=%x\n", (int)addr);



    /* TODO : consider BYTE/WORD access */

    /* TODO : consider endian */



    assert(0 <= addr && addr < 0x400 * 3);

    return *(uint32_t*)&s->dc_palette[addr];

}
