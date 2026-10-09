/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4154
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=32be264cea542b4dc721b10092bf1dfe511a28ee
 */

static void avoid_clipping(AACEncContext *s, SingleChannelElement *sce)

{

    int start, i, j, w;



    if (sce->ics.clip_avoidance_factor < 1.0f) {

        for (w = 0; w < sce->ics.num_windows; w++) {

            start = 0;

            for (i = 0; i < sce->ics.max_sfb; i++) {

                float *swb_coeffs = sce->coeffs + start + w*128;

                for (j = 0; j < sce->ics.swb_sizes[i]; j++)

                    swb_coeffs[j] *= sce->ics.clip_avoidance_factor;

                start += sce->ics.swb_sizes[i];

            }

        }

    }

}
