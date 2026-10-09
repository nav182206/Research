/* 
 * Benchmark Sample ID : devign_1672
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

static void i440fx_pcihost_get_pci_hole64_start(Object *obj, Visitor *v,

                                                const char *name,

                                                void *opaque, Error **errp)

{

    PCIHostState *h = PCI_HOST_BRIDGE(obj);

    Range w64;



    pci_bus_get_w64_range(h->bus, &w64);



    visit_type_uint64(v, name, &w64.begin, errp);

}
