/* 
 * Benchmark Sample ID : devign_4977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0fbc20740342713f282b118b4a446c4c43df3f4a
 */

int kvm_irqchip_update_msi_route(KVMState *s, int virq, MSIMessage msg)

{

    struct kvm_irq_routing_entry kroute;



    if (!kvm_irqchip_in_kernel()) {

        return -ENOSYS;

    }



    kroute.gsi = virq;

    kroute.type = KVM_IRQ_ROUTING_MSI;

    kroute.flags = 0;

    kroute.u.msi.address_lo = (uint32_t)msg.address;

    kroute.u.msi.address_hi = msg.address >> 32;

    kroute.u.msi.data = le32_to_cpu(msg.data);



    return kvm_update_routing_entry(s, &kroute);

}
