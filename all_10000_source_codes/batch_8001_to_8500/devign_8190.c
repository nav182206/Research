/* 
 * Benchmark Sample ID : devign_8190
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void nvram_writel (void *opaque, target_phys_addr_t addr, uint32_t value)

{

    M48t59State *NVRAM = opaque;



    m48t59_write(NVRAM, addr, (value >> 24) & 0xff);

    m48t59_write(NVRAM, addr + 1, (value >> 16) & 0xff);

    m48t59_write(NVRAM, addr + 2, (value >> 8) & 0xff);

    m48t59_write(NVRAM, addr + 3, value & 0xff);

}
