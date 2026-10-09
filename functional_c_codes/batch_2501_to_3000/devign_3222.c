/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3222
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f20b67173ca6a05b8c3dee02dad3b7243b96292b
 */

static int encode_individual_channel(AVCodecContext *avctx, AACEncContext *s,

                                     SingleChannelElement *sce,

                                     int common_window)

{

    put_bits(&s->pb, 8, sce->sf_idx[0]);

    if (!common_window) {

        put_ics_info(s, &sce->ics);

        if (s->coder->encode_main_pred)

            s->coder->encode_main_pred(s, sce);

    }

    encode_band_info(s, sce);

    encode_scale_factors(avctx, s, sce);

    encode_pulses(s, &sce->pulse);

    if (s->coder->encode_tns_info)

        s->coder->encode_tns_info(s, sce);

    else

        put_bits(&s->pb, 1, 0);

    put_bits(&s->pb, 1, 0); //ssr

    encode_spectral_coeffs(s, sce);

    return 0;

}
