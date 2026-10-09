/* 
 * Benchmark Sample ID : devign_187
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eae74cf906942999bf70e94f034f95c7f831ec63
 */

void qemu_cpu_kick(void *_env)

{

    CPUState *env = _env;



    qemu_cond_broadcast(env->halt_cond);

    if (!env->thread_kicked) {

        qemu_cpu_kick_thread(env);

        env->thread_kicked = true;

    }

}
