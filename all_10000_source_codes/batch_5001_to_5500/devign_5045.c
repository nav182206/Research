/* 
 * Benchmark Sample ID : devign_5045
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1833e1f96456fd8fc17463246fe0b2050e68efb
 */

static void spr_write_ibatu (void *opaque, int sprn)

{

    DisasContext *ctx = opaque;



    gen_op_store_ibatu((sprn - SPR_IBAT0U) / 2);

    RET_STOP(ctx);

}
