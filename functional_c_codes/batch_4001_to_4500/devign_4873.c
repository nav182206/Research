/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4873
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void mips_qemu_write (void *opaque, target_phys_addr_t addr,

                             uint64_t val, unsigned size)

{

    if ((addr & 0xffff) == 0 && val == 42)

        qemu_system_reset_request ();

    else if ((addr & 0xffff) == 4 && val == 42)

        qemu_system_shutdown_request ();

}
