/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1574
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0fc0f1fa7f86e9f1d480c6508191ca90ac10b32c
 */

void blockdev_auto_del(BlockDriverState *bs)

{

    DriveInfo *dinfo = drive_get_by_blockdev(bs);



    if (dinfo->auto_del) {

        drive_uninit(dinfo);

    }

}
