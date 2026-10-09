/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4359
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t iack_read(void *opaque, target_phys_addr_t addr, unsigned size)

{

    return pic_read_irq(isa_pic);

}
