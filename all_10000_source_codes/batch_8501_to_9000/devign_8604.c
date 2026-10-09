/* 
 * Benchmark Sample ID : devign_8604
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6369ba3c9cc74becfaad2a8882dff3dd3e7ae3c0
 */

av_cold void ff_dnxhdenc_init_x86(DNXHDEncContext *ctx)

{

#if HAVE_SSE2_INLINE

    if (av_get_cpu_flags() & AV_CPU_FLAG_SSE2) {

        if (ctx->cid_table->bit_depth == 8)

            ctx->get_pixels_8x4_sym = get_pixels_8x4_sym_sse2;

    }

#endif /* HAVE_SSE2_INLINE */

}
