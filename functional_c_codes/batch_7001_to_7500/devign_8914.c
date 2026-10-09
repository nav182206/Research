/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8914
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4482e05cbbb7e50e476f6a9500cf0b38913bd939
 */

static void create_cpu_without_cps(const char *cpu_model,

                                   qemu_irq *cbus_irq, qemu_irq *i8259_irq)

{

    CPUMIPSState *env;

    MIPSCPU *cpu;

    int i;



    for (i = 0; i < smp_cpus; i++) {

        cpu = cpu_mips_init(cpu_model);

        if (cpu == NULL) {

            fprintf(stderr, "Unable to find CPU definition\n");

            exit(1);

        }



        /* Init internal devices */

        cpu_mips_irq_init_cpu(cpu);

        cpu_mips_clock_init(cpu);

        qemu_register_reset(main_cpu_reset, cpu);

    }



    cpu = MIPS_CPU(first_cpu);

    env = &cpu->env;

    *i8259_irq = env->irq[2];

    *cbus_irq = env->irq[4];

}
