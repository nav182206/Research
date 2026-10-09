/* 
 * Benchmark Sample ID : devign_5957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=51dcdbd319f8d46834d8155defc8d384a9958a73
 */

void s390_program_interrupt(CPUS390XState *env, uint32_t code, int ilen,

                            uintptr_t ra)

{

#ifdef CONFIG_TCG

    S390CPU *cpu = s390_env_get_cpu(env);



    if (tcg_enabled()) {

        cpu_restore_state(CPU(cpu), ra);

    }

#endif

    program_interrupt(env, code, ilen);

}
