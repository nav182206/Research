/* 
 * Benchmark Sample ID : devign_4284
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a6191d098a03f94685ae4c072bfdf10afcd86223
 */

static void calc_scales(DCAEncContext *c)

{

    int band, ch;



    for (band = 0; band < 32; band++)

        for (ch = 0; ch < c->fullband_channels; ch++)

            c->scale_factor[band][ch] = calc_one_scale(c->peak_cb[band][ch],

                                                       c->abits[band][ch],

                                                       &c->quant[band][ch]);



    if (c->lfe_channel)

        c->lfe_scale_factor = calc_one_scale(c->lfe_peak_cb, 11, &c->lfe_quant);

}
