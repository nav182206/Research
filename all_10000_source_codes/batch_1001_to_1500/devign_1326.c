/* 
 * Benchmark Sample ID : devign_1326
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

uint32_t lduw_phys(target_phys_addr_t addr)

{

    return lduw_phys_internal(addr, DEVICE_NATIVE_ENDIAN);

}
