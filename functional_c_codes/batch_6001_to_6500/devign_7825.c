/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7825
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t hb_regs_read(void *opaque, target_phys_addr_t offset,

                             unsigned size)

{

    uint32_t *regs = opaque;

    uint32_t value = regs[offset/4];



    if ((offset == 0x100) || (offset == 0x108) || (offset == 0x10C)) {

        value |= 0x30000000;

    }



    return value;

}
