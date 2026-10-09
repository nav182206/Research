/* 
 * Benchmark Sample ID : devign_5327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5f3777945d22248d805fb7c134e206c2d943b77b
 */

static int qcow2_change_backing_file(BlockDriverState *bs,

    const char *backing_file, const char *backing_fmt)

{

    /* Backing file format doesn't make sense without a backing file */

    if (backing_fmt && !backing_file) {

        return -EINVAL;

    }



    pstrcpy(bs->backing_file, sizeof(bs->backing_file), backing_file ?: "");

    pstrcpy(bs->backing_format, sizeof(bs->backing_format), backing_fmt ?: "");



    return qcow2_update_header(bs);

}
