/* 
 * Benchmark Sample ID : devign_3052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6b728b31163bbd0788fe7d537931c4624cd24215
 */

static void verify_irqchip_in_kernel(Error **errp)

{

    if (kvm_irqchip_in_kernel()) {

        return;

    }

    error_setg(errp, "pci-assign requires KVM with in-kernel irqchip enabled");

}
