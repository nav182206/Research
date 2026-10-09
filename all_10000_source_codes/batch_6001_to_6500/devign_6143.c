/* 
 * Benchmark Sample ID : devign_6143
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bf25983345ca44aec3dd92c57142be45452bd38a
 */

static bool blit_is_unsafe(struct CirrusVGAState *s)
{
    /* should be the case, see cirrus_bitblt_start */
    assert(s->cirrus_blt_width > 0);
    assert(s->cirrus_blt_height > 0);
    if (blit_region_is_unsafe(s, s->cirrus_blt_dstpitch,
                              s->cirrus_blt_dstaddr & s->cirrus_addr_mask)) {
    if (blit_region_is_unsafe(s, s->cirrus_blt_srcpitch,
                              s->cirrus_blt_srcaddr & s->cirrus_addr_mask)) {
    return false;
