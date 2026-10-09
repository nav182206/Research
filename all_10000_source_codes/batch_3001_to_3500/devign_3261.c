/* 
 * Benchmark Sample ID : devign_3261
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=83f7f32901c630f4fc01acd0d9082da466b17102
 */

void load_psw(CPUS390XState *env, uint64_t mask, uint64_t addr)

{

    uint64_t old_mask = env->psw.mask;



    env->psw.addr = addr;

    env->psw.mask = mask;

    if (tcg_enabled()) {

        env->cc_op = (mask >> 44) & 3;

    }



    if ((old_mask ^ mask) & PSW_MASK_PER) {

        s390_cpu_recompute_watchpoints(CPU(s390_env_get_cpu(env)));

    }



    if (mask & PSW_MASK_WAIT) {

        S390CPU *cpu = s390_env_get_cpu(env);

        if (s390_cpu_halt(cpu) == 0) {

#ifndef CONFIG_USER_ONLY

            qemu_system_shutdown_request(SHUTDOWN_CAUSE_GUEST_SHUTDOWN);

#endif

        }

    }

}
