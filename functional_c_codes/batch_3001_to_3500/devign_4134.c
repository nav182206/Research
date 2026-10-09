/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a153bf52b37e148f052b0869600877130671a03d
 */

bool aio_dispatch(AioContext *ctx, bool dispatch_fds)

{

    bool progress;



    progress = aio_bh_poll(ctx);

    if (dispatch_fds) {

        progress |= aio_dispatch_handlers(ctx, INVALID_HANDLE_VALUE);

    }

    progress |= timerlistgroup_run_timers(&ctx->tlg);

    return progress;

}
