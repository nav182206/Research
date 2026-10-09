/* 
 * Benchmark Sample ID : devign_4590
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=45416789e8ccced568a4984af61974adfbfa0f62
 */

static void sm501_palette_write(void *opaque,

				target_phys_addr_t addr, uint32_t value)

{

    SM501State * s = (SM501State *)opaque;

    SM501_DPRINTF("sm501 palette write addr=%x, val=%x\n",

		  (int)addr, value);



    /* TODO : consider BYTE/WORD access */

    /* TODO : consider endian */



    assert(0 <= addr && addr < 0x400 * 3);

    *(uint32_t*)&s->dc_palette[addr] = value;

}
