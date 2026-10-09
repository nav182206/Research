/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6318
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t lan9118_16bit_mode_read(void *opaque, target_phys_addr_t offset,

                                        unsigned size)

{

    switch (size) {

    case 2:

        return lan9118_readw(opaque, offset);

    case 4:

        return lan9118_readl(opaque, offset, size);

    }



    hw_error("lan9118_read: Bad size 0x%x\n", size);

    return 0;

}
