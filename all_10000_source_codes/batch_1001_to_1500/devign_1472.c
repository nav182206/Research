/* 
 * Benchmark Sample ID : devign_1472
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4c2e5f8f46a17966dc45b5a3e07b97434c0eabdf
 */

static int qcow2_mark_clean(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;



    if (s->incompatible_features & QCOW2_INCOMPAT_DIRTY) {

        int ret = bdrv_flush(bs);

        if (ret < 0) {

            return ret;

        }



        s->incompatible_features &= ~QCOW2_INCOMPAT_DIRTY;

        return qcow2_update_header(bs);

    }

    return 0;

}
