/* 
 * Benchmark Sample ID : devign_1912
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6cf31ef263d36f6b89d9b64f15ca81cef4f24901
 */

static void revert_cdlms(WmallDecodeCtx *s, int tile_size)

{

    int icoef, ich;

    int32_t pred, channel_coeff;

    int ilms, num_lms;



    for (ich = 0; ich < s->num_channels; ich++) {

        if (!s->is_channel_coded[ich])

            continue;

        for (icoef = 0; icoef < tile_size; icoef++) {

            num_lms = s->cdlms_ttl[ich];

            channel_coeff = s->channel_residues[ich][icoef];

            if (icoef == s->transient_pos[ich]) {

                s->transient[ich] = 1;

                use_high_update_speed(s, ich);

            }

            for (ilms = num_lms; ilms >= 0; ilms--) {

                pred = lms_predict(s, ich, ilms);

                channel_coeff += pred;

                lms_update(s, ich, ilms, channel_coeff, pred);

            }

            if (s->transient[ich]) {

                --s->channel[ich].transient_counter;

                if(!s->channel[ich].transient_counter)

                    use_normal_update_speed(s, ich);

            }

            s->channel_coeffs[ich][icoef] = channel_coeff;

        }

    }

}
