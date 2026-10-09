/* 
 * Benchmark Sample ID : devign_4619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f5b5942d56a138baad0ae01458d5d0e62d5be68
 */

static void unmanageable_intercept(S390CPU *cpu, const char *str, int pswoffset)

{

    CPUState *cs = CPU(cpu);



    error_report("Unmanageable %s! CPU%i new PSW: 0x%016lx:%016lx",

                 str, cs->cpu_index, ldq_phys(cs->as, cpu->env.psa + pswoffset),

                 ldq_phys(cs->as, cpu->env.psa + pswoffset + 8));

    s390_cpu_halt(cpu);

    guest_panicked();

}
