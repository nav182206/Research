/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_409
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

uint32_t ldl_be_phys(target_phys_addr_t addr)

{

    return ldl_phys_internal(addr, DEVICE_BIG_ENDIAN);

}
