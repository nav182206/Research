/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4080
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de13d2161473d02ae97ec0f8e4503147554892dd
 */

void kvm_s390_interrupt(S390CPU *cpu, int type, uint32_t code)

{

    kvm_s390_interrupt_internal(cpu, type, code, 0, 0);

}
