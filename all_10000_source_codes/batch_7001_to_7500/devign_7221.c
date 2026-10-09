/* 
 * Benchmark Sample ID : devign_7221
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1f0c461b82d5ec2664ca0cfc9548f80da87a8f8a
 */

static BlockBackend *bdrv_first_blk(BlockDriverState *bs)

{

    BdrvChild *child;

    QLIST_FOREACH(child, &bs->parents, next_parent) {

        if (child->role == &child_root) {

            assert(bs->blk);

            return child->opaque;

        }

    }



    assert(!bs->blk);

    return NULL;

}
