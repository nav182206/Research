/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3963
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3dc6f8693694a649a9c83f1e2746565b47683923
 */

static void i440fx_realize(PCIDevice *dev, Error **errp)

{

    dev->config[I440FX_SMRAM] = 0x02;



    if (object_property_get_bool(qdev_get_machine(), "iommu", NULL)) {

        error_report("warning: i440fx doesn't support emulated iommu");

    }

}
