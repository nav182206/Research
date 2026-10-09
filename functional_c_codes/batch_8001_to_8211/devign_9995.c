/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9995
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void gic_dist_writew(void *opaque, target_phys_addr_t offset,

                            uint32_t value)

{

    gic_dist_writeb(opaque, offset, value & 0xff);

    gic_dist_writeb(opaque, offset + 1, value >> 8);

}
