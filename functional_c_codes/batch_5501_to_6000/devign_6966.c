/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1833e1f96456fd8fc17463246fe0b2050e68efb
 */

static void spr_write_dbatl (void *opaque, int sprn)

{

    DisasContext *ctx = opaque;



    gen_op_store_dbatl((sprn - SPR_DBAT0L) / 2);

    RET_STOP(ctx);

}
