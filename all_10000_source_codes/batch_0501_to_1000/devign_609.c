/* 
 * Benchmark Sample ID : devign_609
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2eb849d4b1fdb6f35d5c46958c7f703cf64cfef
 */

static void cirrus_mem_writeb_mode4and5_8bpp(CirrusVGAState * s,

					     unsigned mode,

					     unsigned offset,

					     uint32_t mem_value)

{

    int x;

    unsigned val = mem_value;

    uint8_t *dst;



    dst = s->vram_ptr + offset;

    for (x = 0; x < 8; x++) {

	if (val & 0x80) {

	    *dst = s->cirrus_shadow_gr1;

	} else if (mode == 5) {

	    *dst = s->cirrus_shadow_gr0;

	}

	val <<= 1;

	dst++;

    }

    cpu_physical_memory_set_dirty(s->vram_offset + offset);

    cpu_physical_memory_set_dirty(s->vram_offset + offset + 7);

}
