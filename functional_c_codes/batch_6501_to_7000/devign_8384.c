/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8384
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0dadc1e9ef1f35208e5d2af9c7740c18a0b769f
 */

static void aux_bus_map_device(AUXBus *bus, AUXSlave *dev, hwaddr addr)

{

    memory_region_add_subregion(bus->aux_io, addr, dev->mmio);

}
