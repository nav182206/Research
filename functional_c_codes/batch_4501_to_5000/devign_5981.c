/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5981
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=861d72cd28b5793fc367c46b7821a5372b66e3f4
 */

static TargetFdDataFunc fd_trans_host_to_target_data(int fd)

{

    if (fd < target_fd_max && target_fd_trans[fd]) {

        return target_fd_trans[fd]->host_to_target_data;

    }

    return NULL;

}
