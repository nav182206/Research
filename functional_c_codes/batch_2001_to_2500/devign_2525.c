/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2525
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b3a7e1f42c3d89253e9837ada98e6bfb0cbab2f
 */

static av_noinline void emulated_edge_mc_sse(uint8_t *buf, ptrdiff_t buf_stride,

                                             const uint8_t *src, ptrdiff_t src_stride,

                                             int block_w, int block_h,

                                             int src_x, int src_y, int w, int h)

{

    emulated_edge_mc(buf, buf_stride, src, src_stride, block_w, block_h, src_x,

                     src_y, w, h, vfixtbl_sse, &ff_emu_edge_vvar_sse, hfixtbl_sse,

#if ARCH_X86_64

                     &ff_emu_edge_hvar_sse

#else

                     &ff_emu_edge_hvar_mmx

#endif

                     );

}
