/* 
 * Benchmark Sample ID : devign_3704
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e81a982aa5398269a2cc344091ffa4930bdd242f
 */

static inline void _cpu_ppc_store_hdecr(PowerPCCPU *cpu, uint32_t hdecr,

                                        uint32_t value, int is_excp)

{

    ppc_tb_t *tb_env = cpu->env.tb_env;



    if (tb_env->hdecr_timer != NULL) {

        __cpu_ppc_store_decr(cpu, &tb_env->hdecr_next, tb_env->hdecr_timer,

                             &cpu_ppc_hdecr_excp, hdecr, value, is_excp);

    }

}
