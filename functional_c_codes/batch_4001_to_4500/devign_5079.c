/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5079
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6d5b0092678b2a95dfe209a207550bd2fe9ef646
 */

static void apply_tns(float coef[1024], TemporalNoiseShaping *tns,

                      IndividualChannelStream *ics, int decode)

{

    const int mmm = FFMIN(ics->tns_max_bands, ics->max_sfb);

    int w, filt, m, i;

    int bottom, top, order, start, end, size, inc;

    float lpc[TNS_MAX_ORDER];

    float tmp[TNS_MAX_ORDER];



    for (w = 0; w < ics->num_windows; w++) {

        bottom = ics->num_swb;

        for (filt = 0; filt < tns->n_filt[w]; filt++) {

            top    = bottom;

            bottom = FFMAX(0, top - tns->length[w][filt]);

            order  = tns->order[w][filt];

            if (order == 0)

                continue;



            // tns_decode_coef

            compute_lpc_coefs(tns->coef[w][filt], order, lpc, 0, 0, 0);



            start = ics->swb_offset[FFMIN(bottom, mmm)];

            end   = ics->swb_offset[FFMIN(   top, mmm)];

            if ((size = end - start) <= 0)

                continue;

            if (tns->direction[w][filt]) {

                inc = -1;

                start = end - 1;

            } else {

                inc = 1;

            }

            start += w * 128;



            if (decode) {

                // ar filter

                for (m = 0; m < size; m++, start += inc)

                    for (i = 1; i <= FFMIN(m, order); i++)

                        coef[start] -= coef[start - i * inc] * lpc[i - 1];

            } else {

                // ma filter

                for (m = 0; m < size; m++, start += inc) {

                    tmp[0] = coef[start];

                    for (i = 1; i <= FFMIN(m, order); i++)

                        coef[start] += tmp[i] * lpc[i - 1];

                    for (i = order; i > 0; i--)

                        tmp[i] = tmp[i - 1];

                }

            }

        }

    }

}
