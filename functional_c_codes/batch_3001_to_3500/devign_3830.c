/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3830
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a6baa60807f88ba7d97b1787797fb58882ccbfb9
 */

BlockStatsList *qmp_query_blockstats(bool has_query_nodes,

                                     bool query_nodes,

                                     Error **errp)

{

    BlockStatsList *head = NULL, **p_next = &head;

    BlockBackend *blk = NULL;

    BlockDriverState *bs = NULL;



    /* Just to be safe if query_nodes is not always initialized */

    query_nodes = has_query_nodes && query_nodes;



    while (next_query_bds(&blk, &bs, query_nodes)) {

        BlockStatsList *info = g_malloc0(sizeof(*info));

        AioContext *ctx = blk ? blk_get_aio_context(blk)

                              : bdrv_get_aio_context(bs);



        aio_context_acquire(ctx);

        info->value = bdrv_query_stats(blk, bs, !query_nodes);

        aio_context_release(ctx);



        *p_next = info;

        p_next = &info->next;

    }



    return head;

}
