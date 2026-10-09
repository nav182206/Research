/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6538
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d516f74c99b1a2c289cfba0bacf125cbc9b681e3
 */

void s390_sclp_extint(uint32_t parm)

{

    if (kvm_enabled()) {

        kvm_s390_service_interrupt(parm);

    } else {

        S390CPU *dummy_cpu = s390_cpu_addr2state(0);



        cpu_inject_ext(dummy_cpu, EXT_SERVICE, parm, 0);

    }

}
