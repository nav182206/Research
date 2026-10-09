/* 
 * Benchmark Sample ID : devign_6081
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185b43386ad999c80bdc58e41b87f05e5b3e8463
 */

int nbd_disconnect(int fd)

{

    errno = ENOTSUP;

    return -1;

}
