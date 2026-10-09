/* 
 * Benchmark Sample ID : devign_6477
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=280d373579558f73a8b70e329d9a6206933d3809
 */

static int qcow2_mark_dirty(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;

    uint64_t val;

    int ret;



    assert(s->qcow_version >= 3);



    if (s->incompatible_features & QCOW2_INCOMPAT_DIRTY) {

        return 0; /* already dirty */

    }



    val = cpu_to_be64(s->incompatible_features | QCOW2_INCOMPAT_DIRTY);

    ret = bdrv_pwrite(bs->file, offsetof(QCowHeader, incompatible_features),

                      &val, sizeof(val));

    if (ret < 0) {

        return ret;

    }

    ret = bdrv_flush(bs->file);

    if (ret < 0) {

        return ret;

    }



    /* Only treat image as dirty if the header was updated successfully */

    s->incompatible_features |= QCOW2_INCOMPAT_DIRTY;

    return 0;

}
