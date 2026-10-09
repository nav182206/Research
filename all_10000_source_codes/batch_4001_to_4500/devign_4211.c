/* 
 * Benchmark Sample ID : devign_4211
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ec53b45bcd1f74f7a4c31331fa6d50b402cd6d26
 */

void cpu_single_step(CPUState *cpu, int enabled)

{

#if defined(TARGET_HAS_ICE)

    if (cpu->singlestep_enabled != enabled) {

        cpu->singlestep_enabled = enabled;

        if (kvm_enabled()) {

            kvm_update_guest_debug(cpu, 0);

        } else {

            /* must flush all the translated code to avoid inconsistencies */

            /* XXX: only flush what is necessary */

            CPUArchState *env = cpu->env_ptr;

            tb_flush(env);

        }

    }

#endif

}
