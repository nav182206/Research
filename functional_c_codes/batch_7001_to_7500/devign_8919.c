/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8919
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b6c5ad2f67cc8eeeec89fb9d497ec79c1f3948a
 */

static void calc_transform_coeffs_cpl(AC3DecodeContext *s)

{

    int bin, band, ch, band_end;



    bin = s->start_freq[CPL_CH];

    for (band = 0; band < s->num_cpl_bands; band++) {

        band_end = bin + s->cpl_band_sizes[band];

        for (; bin < band_end; bin++) {

            for (ch = 1; ch <= s->fbw_channels; ch++) {

                if (s->channel_in_cpl[ch]) {

                    s->fixed_coeffs[ch][bin] = ((int64_t)s->fixed_coeffs[CPL_CH][bin] *

                                                (int64_t)s->cpl_coords[ch][band]) >> 23;

                    if (ch == 2 && s->phase_flags[band])

                        s->fixed_coeffs[ch][bin] = -s->fixed_coeffs[ch][bin];

                }

            }

        }

    }

}
