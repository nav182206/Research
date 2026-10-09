/* 
 * Benchmark Sample ID : devign_8494
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bff384a4fbd5d0e86939092e74e766ef0f5f592c
 */

static void create_cpu(const char *cpu_model,

                       qemu_irq *cbus_irq, qemu_irq *i8259_irq)

{

    CPUMIPSState *env;

    MIPSCPU *cpu;

    int i;

    if (cpu_model == NULL) {

#ifdef TARGET_MIPS64

        cpu_model = "20Kc";

#else

        cpu_model = "24Kf";

#endif

    }



    for (i = 0; i < smp_cpus; i++) {

        cpu = cpu_mips_init(cpu_model);

        if (cpu == NULL) {

            fprintf(stderr, "Unable to find CPU definition\n");

            exit(1);

        }

        env = &cpu->env;



        /* Init internal devices */

        cpu_mips_irq_init_cpu(env);

        cpu_mips_clock_init(env);

        qemu_register_reset(main_cpu_reset, cpu);

    }



    cpu = MIPS_CPU(first_cpu);

    env = &cpu->env;

    *i8259_irq = env->irq[2];

    *cbus_irq = env->irq[4];

}
