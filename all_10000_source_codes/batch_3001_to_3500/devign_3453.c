/* 
 * Benchmark Sample ID : devign_3453
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=178bd438af5c95deef5073416c60396f88e97ec9
 */

static bool bdrv_drain_recurse(BlockDriverState *bs)

{

    BdrvChild *child;

    bool waited;



    waited = BDRV_POLL_WHILE(bs, atomic_read(&bs->in_flight) > 0);



    if (bs->drv && bs->drv->bdrv_drain) {

        bs->drv->bdrv_drain(bs);

    }



    QLIST_FOREACH(child, &bs->children, next) {

        waited |= bdrv_drain_recurse(child->bs);

    }



    return waited;

}
