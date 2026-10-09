/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7595
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce5b1bbf624b977a55ff7f85bb3871682d03baff
 */

static void uc32_cpu_initfn(Object *obj)

{

    CPUState *cs = CPU(obj);

    UniCore32CPU *cpu = UNICORE32_CPU(obj);

    CPUUniCore32State *env = &cpu->env;

    static bool inited;



    cs->env_ptr = env;

    cpu_exec_init(cs, &error_abort);



#ifdef CONFIG_USER_ONLY

    env->uncached_asr = ASR_MODE_USER;

    env->regs[31] = 0;

#else

    env->uncached_asr = ASR_MODE_PRIV;

    env->regs[31] = 0x03000000;

#endif



    tlb_flush(cs, 1);



    if (tcg_enabled() && !inited) {

        inited = true;

        uc32_translate_init();

    }

}
