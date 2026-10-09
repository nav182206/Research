/* 
 * Benchmark Sample ID : devign_7280
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a153bf52b37e148f052b0869600877130671a03d
 */

static bool aio_dispatch_handlers(AioContext *ctx)

{

    AioHandler *node, *tmp;

    bool progress = false;



    /*

     * We have to walk very carefully in case aio_set_fd_handler is

     * called while we're walking.

     */

    qemu_lockcnt_inc(&ctx->list_lock);



    QLIST_FOREACH_SAFE_RCU(node, &ctx->aio_handlers, node, tmp) {

        int revents;



        revents = node->pfd.revents & node->pfd.events;

        node->pfd.revents = 0;



        if (!node->deleted &&

            (revents & (G_IO_IN | G_IO_HUP | G_IO_ERR)) &&

            aio_node_check(ctx, node->is_external) &&

            node->io_read) {

            node->io_read(node->opaque);



            /* aio_notify() does not count as progress */

            if (node->opaque != &ctx->notifier) {

                progress = true;

            }

        }

        if (!node->deleted &&

            (revents & (G_IO_OUT | G_IO_ERR)) &&

            aio_node_check(ctx, node->is_external) &&

            node->io_write) {

            node->io_write(node->opaque);

            progress = true;

        }



        if (node->deleted) {

            if (qemu_lockcnt_dec_if_lock(&ctx->list_lock)) {

                QLIST_REMOVE(node, node);

                g_free(node);

                qemu_lockcnt_inc_and_unlock(&ctx->list_lock);

            }

        }

    }



    qemu_lockcnt_dec(&ctx->list_lock);

    return progress;

}
