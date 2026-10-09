/* 
 * Benchmark Sample ID : devign_2411
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b77e26b28525f366c5f978214b230a5324bedf81
 */

static void hevc_await_progress(HEVCContext *s, HEVCFrame *ref,

                                const Mv *mv, int y0, int height)

{

    int y = FFMAX(0, (mv->y >> 2) + y0 + height + 9);



    if (s->threads_type == FF_THREAD_FRAME )

        ff_thread_await_progress(&ref->tf, y, 0);

}
