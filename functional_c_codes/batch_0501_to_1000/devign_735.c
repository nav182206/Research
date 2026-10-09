/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_735
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void lan9118_16bit_mode_write(void *opaque, target_phys_addr_t offset,

                                     uint64_t val, unsigned size)

{

    switch (size) {

    case 2:

        lan9118_writew(opaque, offset, (uint32_t)val);

        return;

    case 4:

        lan9118_writel(opaque, offset, val, size);

        return;

    }



    hw_error("lan9118_write: Bad size 0x%x\n", size);

}
