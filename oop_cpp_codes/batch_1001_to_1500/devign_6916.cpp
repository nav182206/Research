/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6916
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=93c26503e01808bfb8cea3c25eae5be63147380e
 */

static int blk_root_inactivate(BdrvChild *child)

{

    BlockBackend *blk = child->opaque;



    if (blk->disable_perm) {

        return 0;

    }



    /* Only inactivate BlockBackends for guest devices (which are inactive at

     * this point because the VM is stopped) and unattached monitor-owned

     * BlockBackends. If there is still any other user like a block job, then

     * we simply can't inactivate the image. */

    if (!blk->dev && !blk->name[0]) {

        return -EPERM;

    }



    blk->disable_perm = true;

    if (blk->root) {

        bdrv_child_try_set_perm(blk->root, 0, BLK_PERM_ALL, &error_abort);

    }



    return 0;

}
