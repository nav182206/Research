/* 
 * Benchmark Sample ID : devign_8066
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=74b4c74d5efb0a489bdf0acc5b5d0197167e7649
 */

int s390_cpu_restart(S390CPU *cpu)

{

    if (kvm_enabled()) {

        return kvm_s390_cpu_restart(cpu);

    }

    return -ENOSYS;

}
