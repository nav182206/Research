/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9570
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

const char *bdrv_get_encrypted_filename(BlockDriverState *bs)

{

    if (bs->backing_hd && bs->backing_hd->encrypted)

        return bs->backing_file;

    else if (bs->encrypted)

        return bs->filename;

    else

        return NULL;

}
