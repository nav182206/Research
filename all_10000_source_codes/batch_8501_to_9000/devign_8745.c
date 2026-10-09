/* 
 * Benchmark Sample ID : devign_8745
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d5b68844e6f7c13d30b46cc92ba468e5f92119a6
 */

BlockInfoList *qmp_query_block(Error **errp)

{

    BlockInfoList *head = NULL, **p_next = &head;

    BlockBackend *blk;

    Error *local_err = NULL;



    for (blk = blk_next(NULL); blk; blk = blk_next(blk)) {

        BlockInfoList *info = g_malloc0(sizeof(*info));

        bdrv_query_info(blk, &info->value, &local_err);

        if (local_err) {

            error_propagate(errp, local_err);

            g_free(info);

            qapi_free_BlockInfoList(head);

            return NULL;

        }



        *p_next = info;

        p_next = &info->next;

    }



    return head;

}
