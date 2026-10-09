/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void bdrv_sync_complete(void *opaque, int ret)

{

    /* do nothing. Masters do not directly interact with the backing store,

     * only the working copy so no mutexing required.

     */

}
