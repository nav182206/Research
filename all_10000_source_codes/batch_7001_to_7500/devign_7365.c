/* 
 * Benchmark Sample ID : devign_7365
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2eb849d4b1fdb6f35d5c46958c7f703cf64cfef
 */

static int cirrus_bitblt_videotovideo_patterncopy(CirrusVGAState * s)

{

    return cirrus_bitblt_common_patterncopy(s,

					    s->vram_ptr +

                                            (s->cirrus_blt_srcaddr & ~7));

}
