/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6630
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4e588a4d0e1683488282658c057d4b44976d77d8
 */

uint32_t cpu_ppc_load_decr (CPUState *env)

{

    ppc_tb_t *tb_env = env->tb_env;

    uint32_t decr;



    decr = muldiv64(tb_env->decr_next - qemu_get_clock(vm_clock),

                    tb_env->tb_freq, ticks_per_sec);

#if defined(DEBUG_TB)

    printf("%s: 0x%08x\n", __func__, decr);

#endif



    return decr;

}
