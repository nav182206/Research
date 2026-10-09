/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3701
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void isa_mmio_writeb (void *opaque, target_phys_addr_t addr,

                                  uint32_t val)

{

    cpu_outb(addr & IOPORTS_MASK, val);

}
