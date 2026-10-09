/* 
 * Benchmark Sample ID : devign_6988
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f65ed4c1529f29a7d62d6733eaa50bed24a4b2ed
 */

e1000_mmio_map(PCIDevice *pci_dev, int region_num,
                uint32_t addr, uint32_t size, int type)
{
    E1000State *d = (E1000State *)pci_dev;
    DBGOUT(MMIO, "e1000_mmio_map addr=0x%08x 0x%08x\n", addr, size);
    cpu_register_physical_memory(addr, PNPMMIO_SIZE, d->mmio_index);
}
