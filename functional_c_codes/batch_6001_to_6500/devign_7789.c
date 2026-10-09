/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7789
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=daa7a1d4431b6acf1f93c4a98b3de123abf4ca18
 */

static int thread_execute2(AVCodecContext *avctx, action_func2* func2, void *arg, int *ret, int job_count)

{

    ThreadContext *c= avctx->thread_opaque;

    c->func2 = func2;

    return thread_execute(avctx, NULL, arg, ret, job_count, 0);

}
