/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4177
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5cbdd273fbf5e977d14b1f06976489d8e4625a68
 */

static void vmdk_close(BlockDriverState *bs)

{

    BDRVVmdkState *s = bs->opaque;



    qemu_free(s->l1_table);

    qemu_free(s->l2_cache);

    bdrv_delete(s->hd);

    // try to close parent image, if exist

    vmdk_parent_close(s->hd);

}
