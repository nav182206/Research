/* 
 * Benchmark Sample ID : devign_4006
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void mmio_ide_cmd_write(void *opaque, target_phys_addr_t addr,

                               uint64_t val, unsigned size)

{

    MMIOState *s = opaque;

    ide_cmd_write(&s->bus, 0, val);

}
