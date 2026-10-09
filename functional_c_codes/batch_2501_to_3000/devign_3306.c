/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3306
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=665f119fbad97c05c2603673ac6b2dcbf0d0e9e1
 */

static bool check_irqchip_in_kernel(void)

{

    if (kvm_irqchip_in_kernel()) {

        return true;

    }

    error_report("pci-assign: error: requires KVM with in-kernel irqchip "

                 "enabled");

    return false;

}
