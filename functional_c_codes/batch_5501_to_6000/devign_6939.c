/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6939
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4299b90e9ba9ce5ca9024572804ba751aa1a7e70
 */

static int cirrus_bitblt_videotovideo_copy(CirrusVGAState * s)

{

    if (blit_is_unsafe(s))

        return 0;



    cirrus_do_copy(s, s->cirrus_blt_dstaddr - s->vga.start_addr,

            s->cirrus_blt_srcaddr - s->vga.start_addr,

            s->cirrus_blt_width, s->cirrus_blt_height);



    return 1;

}
