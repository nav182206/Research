/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4760
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=49bf712a892901bd6a2e8815d085487180894d8c
 */

static void revert_cdlms(WmallDecodeCtx *s, int ch,

                         int coef_begin, int coef_end)

{

    int icoef, pred, ilms, num_lms, residue, input;



    num_lms = s->cdlms_ttl[ch];

    for (ilms = num_lms - 1; ilms >= 0; ilms--) {

        for (icoef = coef_begin; icoef < coef_end; icoef++) {

            pred = 1 << (s->cdlms[ch][ilms].scaling - 1);

            residue = s->channel_residues[ch][icoef];

            pred += s->dsp.scalarproduct_and_madd_int16(s->cdlms[ch][ilms].coefs,

                                                        s->cdlms[ch][ilms].lms_prevvalues

                                                            + s->cdlms[ch][ilms].recent,

                                                        s->cdlms[ch][ilms].lms_updates

                                                            + s->cdlms[ch][ilms].recent,

                                                        s->cdlms[ch][ilms].order,

                                                        WMASIGN(residue));

            input = residue + (pred >> s->cdlms[ch][ilms].scaling);

            lms_update(s, ch, ilms, input);

            s->channel_residues[ch][icoef] = input;

        }

    }


}
