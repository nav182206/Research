/* 
 * Benchmark Sample ID : devign_6535
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t nvic_sysreg_read(void *opaque, target_phys_addr_t addr,

                                 unsigned size)

{

    /* At the moment we only support the ID registers for byte/word access.

     * This is not strictly correct as a few of the other registers also

     * allow byte access.

     */

    uint32_t offset = addr;

    if (offset >= 0xfe0) {

        if (offset & 3) {

            return 0;

        }

        return nvic_id[(offset - 0xfe0) >> 2];

    }

    if (size == 4) {

        return nvic_readl(opaque, offset);

    }

    hw_error("NVIC: Bad read of size %d at offset 0x%x\n", size, offset);

}
