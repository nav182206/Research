/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5523
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5669b44de5b3b607a3a4749e0c8c5ddfd723e76b
 */

static int bdrv_inherited_flags(int flags)

{

    /* Enable protocol handling, disable format probing for bs->file */

    flags |= BDRV_O_PROTOCOL;



    /* Our block drivers take care to send flushes and respect unmap policy,

     * so we can enable both unconditionally on lower layers. */

    flags |= BDRV_O_CACHE_WB | BDRV_O_UNMAP;



    /* The backing file of a temporary snapshot is read-only */

    if (flags & BDRV_O_SNAPSHOT) {

        flags &= ~BDRV_O_RDWR;

    }



    /* Clear flags that only apply to the top layer */

    flags &= ~(BDRV_O_SNAPSHOT | BDRV_O_NO_BACKING);



    return flags;

}
