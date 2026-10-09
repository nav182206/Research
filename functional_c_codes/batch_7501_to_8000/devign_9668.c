/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9668
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void hb_regs_write(void *opaque, target_phys_addr_t offset,

                          uint64_t value, unsigned size)

{

    uint32_t *regs = opaque;



    if (offset == 0xf00) {

        if (value == 1 || value == 2) {

            qemu_system_reset_request();

        } else if (value == 3) {

            qemu_system_shutdown_request();

        }

    }



    regs[offset/4] = value;

}
