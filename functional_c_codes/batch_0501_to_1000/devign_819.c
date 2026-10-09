/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_819
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=58b1cba0c9173741cf769117a735b429356d83c0
 */

static void read_sbr_single_channel_element(AACContext *ac,

                                            SpectralBandReplication *sbr,

                                            GetBitContext *gb)

{

    if (get_bits1(gb)) // bs_data_extra

        skip_bits(gb, 4); // bs_reserved



    read_sbr_grid(ac, sbr, gb, &sbr->data[0]);

    read_sbr_dtdf(sbr, gb, &sbr->data[0]);

    read_sbr_invf(sbr, gb, &sbr->data[0]);

    read_sbr_envelope(sbr, gb, &sbr->data[0], 0);

    read_sbr_noise(sbr, gb, &sbr->data[0], 0);



    if ((sbr->data[0].bs_add_harmonic_flag = get_bits1(gb)))

        get_bits1_vector(gb, sbr->data[0].bs_add_harmonic, sbr->n[1]);

}
