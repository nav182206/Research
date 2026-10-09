/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1405
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca488ad480360dfafcb5766f7bfbb567a0638979
 */

static int decode_block(ALSDecContext *ctx, ALSBlockData *bd)

{

    unsigned int smp;



    // read block type flag and read the samples accordingly

    if (*bd->const_block)

        decode_const_block_data(ctx, bd);

    else if (decode_var_block_data(ctx, bd))

        return -1;



    // TODO: read RLSLMS extension data



    if (*bd->shift_lsbs)

        for (smp = 0; smp < bd->block_length; smp++)

            bd->raw_samples[smp] <<= *bd->shift_lsbs;



    return 0;

}
