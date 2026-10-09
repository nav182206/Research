/* 
 * Benchmark Sample ID : devign_7389
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c89bcf3af01e7a8834cca5344e098bf879e99999
 */

int blk_insert_bs(BlockBackend *blk, BlockDriverState *bs, Error **errp)

{

    blk->root = bdrv_root_attach_child(bs, "root", &child_root,

                                       blk->perm, blk->shared_perm, blk, errp);

    if (blk->root == NULL) {

        return -EPERM;

    }

    bdrv_ref(bs);



    notifier_list_notify(&blk->insert_bs_notifiers, blk);

    if (blk->public.throttle_group_member.throttle_state) {

        throttle_timers_attach_aio_context(

            &blk->public.throttle_group_member.throttle_timers,

            bdrv_get_aio_context(bs));

    }



    return 0;

}
