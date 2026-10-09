/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_289
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=88be7b4be4aa17c88247e162bdd7577ea79db94f
 */

BlockJobInfoList *qmp_query_block_jobs(Error **errp)

{

    BlockJobInfoList *head = NULL, **p_next = &head;

    BlockDriverState *bs;

    BdrvNextIterator *it = NULL;



    while ((it = bdrv_next(it, &bs))) {

        AioContext *aio_context = bdrv_get_aio_context(bs);



        aio_context_acquire(aio_context);



        if (bs->job) {

            BlockJobInfoList *elem = g_new0(BlockJobInfoList, 1);

            elem->value = block_job_query(bs->job);

            *p_next = elem;

            p_next = &elem->next;

        }



        aio_context_release(aio_context);

    }



    return head;

}
