/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6381
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de00982e9e14e2d6ba3d148f02c5a1e94deaa985
 */

static void platform_mmio_write(ReadWriteHandler *handler, pcibus_t addr,

                                uint32_t val, int len)

{

    DPRINTF("Warning: attempted write of 0x%x to physical "

            "address 0x" TARGET_FMT_plx " in xen platform mmio space\n",

            val, addr);

}
