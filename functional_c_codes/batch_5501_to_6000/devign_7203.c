/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7203
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=df3c286c53ac51e7267f2761c7a0c62e11b6e815
 */

int kvm_arch_irqchip_create(MachineState *ms, KVMState *s)

{

    int ret;

    if (machine_kernel_irqchip_split(ms)) {

        ret = kvm_vm_enable_cap(s, KVM_CAP_SPLIT_IRQCHIP, 0, 24);

        if (ret) {

            error_report("Could not enable split irqchip mode: %s\n",

                         strerror(-ret));

            exit(1);

        } else {

            DPRINTF("Enabled KVM_CAP_SPLIT_IRQCHIP\n");

            kvm_split_irqchip = true;

            return 1;

        }

    } else {

        return 0;

    }

}
