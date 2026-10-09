/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7120
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

static void poll_set_started(AioContext *ctx, bool started)

{

    AioHandler *node;



    if (started == ctx->poll_started) {

        return;

    }



    ctx->poll_started = started;



    qemu_lockcnt_inc(&ctx->list_lock);

    QLIST_FOREACH_RCU(node, &ctx->aio_handlers, node) {

        IOHandler *fn;



        if (node->deleted) {

            continue;

        }



        if (started) {

            fn = node->io_poll_begin;

        } else {

            fn = node->io_poll_end;

        }



        if (fn) {

            fn(node->opaque);

        }

    }

    qemu_lockcnt_dec(&ctx->list_lock);

}
