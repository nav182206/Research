/* 
 * Benchmark Sample ID : devign_8547
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=97437bd17a8c5d4135b2f3b1b299bd7bb72ce02c
 */

void ff_aac_coder_init_mips(AACEncContext *c) {

#if HAVE_INLINE_ASM

    AACCoefficientsEncoder *e = c->coder;

    int option = c->options.aac_coder;



    if (option == 2) {

        e->quantize_and_encode_band = quantize_and_encode_band_mips;

        e->encode_window_bands_info = codebook_trellis_rate;

#if HAVE_MIPSFPU

        e->search_for_quantizers    = search_for_quantizers_twoloop;

#endif /* HAVE_MIPSFPU */

    }

#if HAVE_MIPSFPU

    e->search_for_ms            = search_for_ms_mips;

#endif /* HAVE_MIPSFPU */

#endif /* HAVE_INLINE_ASM */

}
