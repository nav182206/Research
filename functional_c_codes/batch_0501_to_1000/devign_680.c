/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_680
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e0c6cce44729d94e2a5507a4b6d031f23e8bd7b6
 */

void ff_sbrdsp_init_x86(SBRDSPContext *s)

{

    if (HAVE_YASM) {

        int mm_flags = av_get_cpu_flags();



        if (mm_flags & AV_CPU_FLAG_SSE) {

            s->sum_square = ff_sbr_sum_square_sse;

            s->hf_g_filt = ff_sbr_hf_g_filt_sse;

        }

    }

}
