/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8625
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a6191d098a03f94685ae4c072bfdf10afcd86223
 */

static void find_peaks(DCAEncContext *c)

{

    int band, ch;



    for (band = 0; band < 32; band++)

        for (ch = 0; ch < c->fullband_channels; ch++) {

            int sample;

            int32_t m = 0;



            for (sample = 0; sample < SUBBAND_SAMPLES; sample++) {

                int32_t s = abs(c->subband[sample][band][ch]);

                if (m < s)

                    m = s;

            }

            c->peak_cb[band][ch] = get_cb(m);

        }



    if (c->lfe_channel) {

        int sample;

        int32_t m = 0;



        for (sample = 0; sample < DCA_LFE_SAMPLES; sample++)

            if (m < abs(c->downsampled_lfe[sample]))

                m = abs(c->downsampled_lfe[sample]);

        c->lfe_peak_cb = get_cb(m);

    }

}
