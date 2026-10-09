/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7525
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3dd1b8c295636e64ceb14cdc4db6420d7319e38
 */

int monitor_fdset_dup_fd_remove(int dup_fd)

{

    return monitor_fdset_dup_fd_find_remove(dup_fd, true);

}
