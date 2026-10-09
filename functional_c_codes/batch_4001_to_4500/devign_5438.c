/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5438
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

void address_space_read(AddressSpace *as, target_phys_addr_t addr, uint8_t *buf, int len)

{

    address_space_rw(as, addr, buf, len, false);

}
