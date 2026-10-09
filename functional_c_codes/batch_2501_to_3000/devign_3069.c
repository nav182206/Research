/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3069
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

static void i440fx_pcihost_get_pci_hole_start(Object *obj, Visitor *v,

                                              const char *name, void *opaque,

                                              Error **errp)

{

    I440FXState *s = I440FX_PCI_HOST_BRIDGE(obj);

    uint32_t value = s->pci_hole.begin;



    visit_type_uint32(v, name, &value, errp);

}
