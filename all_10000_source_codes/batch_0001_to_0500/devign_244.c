/* 
 * Benchmark Sample ID : devign_244
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4b0e0f31bf0f618a634dcfdca45e72cdfb0b48b5
 */

av_cold int ff_lpc_init(LPCContext *s, int blocksize, int max_order,

                        enum FFLPCType lpc_type)

{

    s->blocksize = blocksize;

    s->max_order = max_order;

    s->lpc_type  = lpc_type;



    if (lpc_type == FF_LPC_TYPE_LEVINSON) {

        s->windowed_samples = av_mallocz((blocksize + max_order + 2) *

                                         sizeof(*s->windowed_samples));

        if (!s->windowed_samples)

            return AVERROR(ENOMEM);

    } else {

        s->windowed_samples = NULL;

    }



    s->lpc_apply_welch_window = lpc_apply_welch_window_c;

    s->lpc_compute_autocorr   = lpc_compute_autocorr_c;



    if (HAVE_MMX)

        ff_lpc_init_x86(s);



    return 0;

}
