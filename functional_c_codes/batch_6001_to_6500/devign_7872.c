/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7872
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

static void q35_host_get_pci_hole64_end(Object *obj, Visitor *v,

                                        const char *name, void *opaque,

                                        Error **errp)

{

    PCIHostState *h = PCI_HOST_BRIDGE(obj);

    Range w64;



    pci_bus_get_w64_range(h->bus, &w64);



    visit_type_uint64(v, name, &w64.end, errp);

}
