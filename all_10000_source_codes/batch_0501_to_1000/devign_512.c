/* 
 * Benchmark Sample ID : devign_512
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b783e409bf17b92f4af8dc5d6bd040d0092f33e0
 */

void bdrv_get_backing_filename(BlockDriverState *bs,

                               char *filename, int filename_size)

{

    if (!bs->backing_hd) {

        pstrcpy(filename, filename_size, "");

    } else {

        pstrcpy(filename, filename_size, bs->backing_file);

    }

}
