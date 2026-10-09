/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3290
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

static void cpu_handle_guest_debug(CPUState *env)

{

    gdb_set_stop_cpu(env);

    qemu_system_debug_request();

#ifdef CONFIG_IOTHREAD

    env->stopped = 1;

#endif

}
