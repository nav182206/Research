/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7995
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=33a610c398603efafd954c706ba07850835a5098
 */

BdrvChild *bdrv_root_attach_child(BlockDriverState *child_bs,

                                  const char *child_name,

                                  const BdrvChildRole *child_role,

                                  uint64_t perm, uint64_t shared_perm,

                                  void *opaque, Error **errp)

{

    BdrvChild *child;

    int ret;



    ret = bdrv_check_update_perm(child_bs, perm, shared_perm, NULL, errp);

    if (ret < 0) {

        return NULL;

    }



    child = g_new(BdrvChild, 1);

    *child = (BdrvChild) {

        .bs             = NULL,

        .name           = g_strdup(child_name),

        .role           = child_role,

        .perm           = perm,

        .shared_perm    = shared_perm,

        .opaque         = opaque,

    };



    bdrv_replace_child(child, child_bs);



    return child;

}
