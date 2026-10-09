/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9260
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca2edcd35cd1a8589dfa0533c19ff232fec7b4b5
 */

static void kvmclock_realize(DeviceState *dev, Error **errp)
{
    KVMClockState *s = KVM_CLOCK(dev);
    kvm_update_clock(s);
    qemu_add_vm_change_state_handler(kvmclock_vm_state_change, s);
