/* 
 * Benchmark Sample ID : devign_7983
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a1ff8ae0666ffcbe78ae7e28812dd30db6bb7131
 */

void sysbus_mmio_map_overlap(SysBusDevice *dev, int n, hwaddr addr,

                             unsigned priority)

{

    sysbus_mmio_map_common(dev, n, addr, true, priority);

}
