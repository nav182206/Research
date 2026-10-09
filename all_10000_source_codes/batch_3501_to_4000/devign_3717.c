/* 
 * Benchmark Sample ID : devign_3717
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5dafc53f1fb091d242f2179ffcb43bb28af36d1e
 */

static QEMUFile *qemu_fopen_bdrv(BlockDriverState *bs, int64_t offset, int is_writable)

{

    QEMUFile *f;



    f = qemu_mallocz(sizeof(QEMUFile));

    if (!f)

        return NULL;

    f->is_file = 0;

    f->bs = bs;

    f->is_writable = is_writable;

    f->base_offset = offset;

    return f;

}
