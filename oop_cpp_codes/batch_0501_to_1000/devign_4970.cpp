/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e9af2fef242ce92f86d3d5c1a94c3199ff1e24c9
 */

int kvm_irqchip_add_adapter_route(KVMState *s, AdapterInfo *adapter)

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

    kroute.type = KVM_IRQ_ROUTING_S390_ADAPTER;

    kroute.flags = 0;

    kroute.u.adapter.summary_addr = adapter->summary_addr;

    kroute.u.adapter.ind_addr = adapter->ind_addr;

    kroute.u.adapter.summary_offset = adapter->summary_offset;

    kroute.u.adapter.ind_offset = adapter->ind_offset;

    kroute.u.adapter.adapter_id = adapter->adapter_id;



    kvm_add_routing_entry(s, &kroute);

    kvm_irqchip_commit_routes(s);



    return virq;

}
