/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7507
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=026aeffcb4752054830ba203020ed6eb05bcaba8
 */

static int cirrus_bitblt_solidfill(CirrusVGAState *s, int blt_rop)

{

    cirrus_fill_t rop_func;



    if (blit_is_unsafe(s, true)) {

        return 0;

    }

    rop_func = cirrus_fill[rop_to_index[blt_rop]][s->cirrus_blt_pixelwidth - 1];

    rop_func(s, s->vga.vram_ptr + s->cirrus_blt_dstaddr,

             s->cirrus_blt_dstpitch,

             s->cirrus_blt_width, s->cirrus_blt_height);

    cirrus_invalidate_region(s, s->cirrus_blt_dstaddr,

			     s->cirrus_blt_dstpitch, s->cirrus_blt_width,

			     s->cirrus_blt_height);

    cirrus_bitblt_reset(s);

    return 1;

}
