/* 
 * Benchmark Sample ID : devign_2692
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=486637af8ef29ec215e0e0b7ecd3b5470f0e04e5
 */

static void uncouple_channels(AC3DecodeContext * ctx)

{

    ac3_audio_block *ab = &ctx->audio_block;

    int ch, sbnd, bin;

    int index;

    int16_t mantissa;



    /* uncouple channels */

    for (ch = 0; ch < ctx->bsi.nfchans; ch++)

        if (ab->chincpl & (1 << ch))

            for (sbnd = ab->cplbegf; sbnd < 3 + ab->cplendf; sbnd++)

                for (bin = 0; bin < 12; bin++) {

                    index = sbnd * 12 + bin + 37;

                    ab->transform_coeffs[ch + 1][index] = ab->cplcoeffs[index] * ab->cplco[ch][sbnd] * ab->chcoeffs[ch];

                    /* generate dither if required */

                    if (!ab->bap[ch][index] && (ab->chincpl & (1 << ch)) && (ab->dithflag & (1 << ch))) {

                        mantissa = dither_int16(&ctx->state);

                        ab->transform_coeffs[ch + 1][index] = to_float(ab->dexps[ch][index], mantissa) * ab->chcoeffs[ch];

                    }

                }

}
