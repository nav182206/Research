/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5076
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=22f15f5735389e992ec9aed43b0680e75746b3a1
 */

static int on2avc_decode_band_types(On2AVCContext *c, GetBitContext *gb)

{

    int bits_per_sect = c->is_long ? 5 : 3;

    int esc_val = (1 << bits_per_sect) - 1;

    int num_bands = c->num_bands * c->num_windows;

    int band = 0, i, band_type, run_len, run;



    while (band < num_bands) {

        band_type = get_bits(gb, 4);

        run_len   = 1;

        do {

            run = get_bits(gb, bits_per_sect);

            run_len += run;

        } while (run == esc_val);

        if (band + run_len > num_bands) {

            av_log(c->avctx, AV_LOG_ERROR, "Invalid band type run\n");

            return AVERROR_INVALIDDATA;

        }

        for (i = band; i < band + run_len; i++) {

            c->band_type[i]    = band_type;

            c->band_run_end[i] = band + run_len;

        }

        band += run_len;

    }



    return 0;

}
