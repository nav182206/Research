/* 
 * Benchmark Sample ID : devign_897
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d918f23efaf486293b96418fe5deaff8a5583304
 */

int slirp_is_inited(void)

{

    return slirp_inited;

}
