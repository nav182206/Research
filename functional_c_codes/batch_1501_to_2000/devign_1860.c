/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1860
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1f0c461b82d5ec2664ca0cfc9548f80da87a8f8a
 */

BlockBackend *blk_new_with_bs(Error **errp)

{

    BlockBackend *blk;

    BlockDriverState *bs;



    blk = blk_new(errp);

    if (!blk) {

        return NULL;

    }



    bs = bdrv_new_root();

    blk->root = bdrv_root_attach_child(bs, "root", &child_root);

    blk->root->opaque = blk;

    bs->blk = blk;

    return blk;

}
