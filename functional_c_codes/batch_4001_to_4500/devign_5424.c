/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static bool sys_ops_accepts(void *opaque, target_phys_addr_t addr,

                            unsigned size, bool is_write)

{

    return is_write && size == 4;

}
