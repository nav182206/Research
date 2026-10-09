/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1935
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=788cf9f8c8cbda53843e060540f3e91a060eb744
 */

static bool key_is_missing(const BlockInfo *bdev)

{

    return (bdev->inserted && bdev->inserted->encryption_key_missing);

}
