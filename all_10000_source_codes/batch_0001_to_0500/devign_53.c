/* 
 * Benchmark Sample ID : devign_53
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5858dd1801883309bdd208d72ddb81c4e9fee30c
 */

static int cirrus_bitblt_common_patterncopy(CirrusVGAState * s,

					    const uint8_t * src)

{

    uint8_t *dst;



    dst = s->vga.vram_ptr + (s->cirrus_blt_dstaddr & s->cirrus_addr_mask);



    if (blit_is_unsafe(s, false))

        return 0;



    (*s->cirrus_rop) (s, dst, src,

                      s->cirrus_blt_dstpitch, 0,

                      s->cirrus_blt_width, s->cirrus_blt_height);

    cirrus_invalidate_region(s, s->cirrus_blt_dstaddr,

                             s->cirrus_blt_dstpitch, s->cirrus_blt_width,

                             s->cirrus_blt_height);

    return 1;

}
