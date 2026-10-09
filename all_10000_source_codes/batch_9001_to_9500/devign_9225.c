/* 
 * Benchmark Sample ID : devign_9225
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ceca269b66ec12a23bf0907bd2c220513cdbf16
 */

static void read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)

{

    ALSSpecificConfig *sconf = &ctx->sconf;

    AVCodecContext *avctx    = ctx->avctx;

    GetBitContext *gb        = &ctx->gb;



    *bd->raw_samples = 0;

    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)

    bd->js_blocks    = get_bits1(gb);



    // skip 5 reserved bits

    skip_bits(gb, 5);



    if (*bd->const_block) {

        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;

        *bd->raw_samples = get_sbits_long(gb, const_val_bits);

    }



    // ensure constant block decoding by reusing this field

    *bd->const_block = 1;

}
