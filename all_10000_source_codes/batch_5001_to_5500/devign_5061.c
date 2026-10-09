/* 
 * Benchmark Sample ID : devign_5061
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t icp_control_read(void *opaque, target_phys_addr_t offset,

                                 unsigned size)

{

    switch (offset >> 2) {

    case 0: /* CP_IDFIELD */

        return 0x41034003;

    case 1: /* CP_FLASHPROG */

        return 0;

    case 2: /* CP_INTREG */

        return 0;

    case 3: /* CP_DECODE */

        return 0x11;

    default:

        hw_error("icp_control_read: Bad offset %x\n", (int)offset);

        return 0;

    }

}
