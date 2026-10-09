/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5724
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d2eae20790e825656b205dbe347826ff991fb3d8
 */

void s390_init_cpus(const char *cpu_model)

{

    int i;



    if (cpu_model == NULL) {

        cpu_model = "host";

    }



    ipi_states = g_malloc(sizeof(S390CPU *) * smp_cpus);



    for (i = 0; i < smp_cpus; i++) {

        S390CPU *cpu;

        CPUState *cs;



        cpu = cpu_s390x_init(cpu_model);

        cs = CPU(cpu);



        ipi_states[i] = cpu;

        cs->halted = 1;

        cs->exception_index = EXCP_HLT;

    }

}
