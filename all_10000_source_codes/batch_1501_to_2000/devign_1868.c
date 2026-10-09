/* 
 * Benchmark Sample ID : devign_1868
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void empty_slot_write(void *opaque, target_phys_addr_t addr,

                             uint64_t val, unsigned size)

{

    DPRINTF("write 0x%x to " TARGET_FMT_plx "\n", (unsigned)val, addr);

}
