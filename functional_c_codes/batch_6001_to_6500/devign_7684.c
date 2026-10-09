/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7684
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void bw_io_write(void *opaque, target_phys_addr_t addr,

                        uint64_t val, unsigned size)

{

    switch (size) {

    case 1:

        cpu_outb(addr, val);

        break;

    case 2:

        cpu_outw(addr, val);

        break;

    case 4:

        cpu_outl(addr, val);

        break;

    default:

        abort();

    }

}
