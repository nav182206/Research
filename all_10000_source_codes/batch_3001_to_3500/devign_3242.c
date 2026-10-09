/* 
 * Benchmark Sample ID : devign_3242
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2eb849d4b1fdb6f35d5c46958c7f703cf64cfef
 */

static void cirrus_invalidate_region(CirrusVGAState * s, int off_begin,

				     int off_pitch, int bytesperline,

				     int lines)

{

    int y;

    int off_cur;

    int off_cur_end;



    for (y = 0; y < lines; y++) {

	off_cur = off_begin;

	off_cur_end = off_cur + bytesperline;

	off_cur &= TARGET_PAGE_MASK;

	while (off_cur < off_cur_end) {

	    cpu_physical_memory_set_dirty(s->vram_offset + off_cur);

	    off_cur += TARGET_PAGE_SIZE;

	}

	off_begin += off_pitch;

    }

}
