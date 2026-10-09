/* 
 * Benchmark Sample ID : devign_3412
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d63cb48db9016328a7a69f3a1c2938cd3dfc9d1a
 */

clk_setup_cb ppc_emb_timers_init (CPUState *env, uint32_t freq)

{

    ppc_tb_t *tb_env;

    ppcemb_timer_t *ppcemb_timer;



    tb_env = qemu_mallocz(sizeof(ppc_tb_t));

    env->tb_env = tb_env;

    ppcemb_timer = qemu_mallocz(sizeof(ppcemb_timer_t));

    tb_env->tb_freq = freq;

    tb_env->decr_freq = freq;

    tb_env->opaque = ppcemb_timer;

    LOG_TB("%s freq %" PRIu32 "\n", __func__, freq);

    if (ppcemb_timer != NULL) {

        /* We use decr timer for PIT */

        tb_env->decr_timer = qemu_new_timer(vm_clock, &cpu_4xx_pit_cb, env);

        ppcemb_timer->fit_timer =

            qemu_new_timer(vm_clock, &cpu_4xx_fit_cb, env);

        ppcemb_timer->wdt_timer =

            qemu_new_timer(vm_clock, &cpu_4xx_wdt_cb, env);

    }



    return &ppc_emb_set_tb_clk;

}
