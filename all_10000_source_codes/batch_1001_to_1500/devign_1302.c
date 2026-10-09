/* 
 * Benchmark Sample ID : devign_1302
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7005f7f81cef31bda895d3274c13854c143d3d8d
 */

void kvm_irqchip_commit_routes(KVMState *s)
{
    int ret;
    s->irq_routes->flags = 0;
    trace_kvm_irqchip_commit_routes();
    ret = kvm_vm_ioctl(s, KVM_SET_GSI_ROUTING, s->irq_routes);
    assert(ret == 0);
