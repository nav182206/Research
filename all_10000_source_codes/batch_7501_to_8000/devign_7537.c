/* 
 * Benchmark Sample ID : devign_7537
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3f1c8c413bc83e4a2cc7a63e4eddf9fe6449052
 */

static void multipath_pr_init(void)

{

    static struct udev *udev;



    udev = udev_new();

    mpath_lib_init(udev);

}
