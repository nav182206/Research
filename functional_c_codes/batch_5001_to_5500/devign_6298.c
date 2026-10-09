/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6298
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d63cb48db9016328a7a69f3a1c2938cd3dfc9d1a
 */

CPUState *ppc4xx_init (const char *cpu_model,

                       clk_setup_t *cpu_clk, clk_setup_t *tb_clk,

                       uint32_t sysclk)

{

    CPUState *env;



    /* init CPUs */

    env = cpu_init(cpu_model);

    if (!env) {

        fprintf(stderr, "Unable to find PowerPC %s CPU definition\n",

                cpu_model);

        exit(1);

    }

    cpu_clk->cb = NULL; /* We don't care about CPU clock frequency changes */

    cpu_clk->opaque = env;

    /* Set time-base frequency to sysclk */

    tb_clk->cb = ppc_emb_timers_init(env, sysclk);

    tb_clk->opaque = env;

    ppc_dcr_init(env, NULL, NULL);

    /* Register qemu callbacks */

    qemu_register_reset((QEMUResetHandler*)&cpu_reset, env);



    return env;

}
