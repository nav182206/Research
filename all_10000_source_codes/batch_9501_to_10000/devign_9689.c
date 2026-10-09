/* 
 * Benchmark Sample ID : devign_9689
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca488ad480360dfafcb5766f7bfbb567a0638979
 */

static int read_block(ALSDecContext *ctx, ALSBlockData *bd)

{

    GetBitContext *gb        = &ctx->gb;



    *bd->shift_lsbs = 0;

    // read block type flag and read the samples accordingly

    if (get_bits1(gb)) {

        if (read_var_block_data(ctx, bd))

            return -1;

    } else {

        read_const_block_data(ctx, bd);

    }



    return 0;

}
