/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d07cc1f12d8e15c167857852c39190d770763824
 */

int kvm_irqchip_add_msi_route(KVMState *s, MSIMessage msg)

{

    struct kvm_irq_routing_entry kroute;

    int virq;



    if (!kvm_gsi_routing_enabled()) {

        return -ENOSYS;

    }



    virq = kvm_irqchip_get_virq(s);

    if (virq < 0) {

        return virq;

    }



    kroute.gsi = virq;

    kroute.type = KVM_IRQ_ROUTING_MSI;

    kroute.flags = 0;

    kroute.u.msi.address_lo = (uint32_t)msg.address;

    kroute.u.msi.address_hi = msg.address >> 32;

    kroute.u.msi.data = msg.data;



    kvm_add_routing_entry(s, &kroute);



    return virq;

}
