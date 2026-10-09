/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_557
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8bf6cbaf396a8b54b138bb8a7c3377f2868ed16e
 */

static void m68060_cpu_initfn(Object *obj)

{

    M68kCPU *cpu = M68K_CPU(obj);

    CPUM68KState *env = &cpu->env;



    m68k_set_feature(env, M68K_FEATURE_M68000);

    m68k_set_feature(env, M68K_FEATURE_USP);

    m68k_set_feature(env, M68K_FEATURE_WORD_INDEX);

    m68k_set_feature(env, M68K_FEATURE_BRAL);

    m68k_set_feature(env, M68K_FEATURE_BCCL);

    m68k_set_feature(env, M68K_FEATURE_BITFIELD);

    m68k_set_feature(env, M68K_FEATURE_EXT_FULL);

    m68k_set_feature(env, M68K_FEATURE_SCALED_INDEX);

    m68k_set_feature(env, M68K_FEATURE_LONG_MULDIV);

    m68k_set_feature(env, M68K_FEATURE_FPU);

    m68k_set_feature(env, M68K_FEATURE_CAS);

    m68k_set_feature(env, M68K_FEATURE_BKPT);

    m68k_set_feature(env, M68K_FEATURE_RTD);


}
