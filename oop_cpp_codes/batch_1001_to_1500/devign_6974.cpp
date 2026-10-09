/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6974
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=51d7c00c14550334ec140ce8f40e04ed4c88de57
 */

int bdrv_file_open(BlockDriverState **pbs, const char *filename, int flags)

{

    BlockDriverState *bs;

    int ret;



    bs = bdrv_new("");

    if (!bs)

        return -ENOMEM;

    ret = bdrv_open2(bs, filename, flags | BDRV_O_FILE, NULL);

    if (ret < 0) {

        bdrv_delete(bs);

        return ret;

    }

    bs->growable = 1;

    *pbs = bs;

    return 0;

}
