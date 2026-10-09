/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1227
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

void qemu_notify_event(void)

{

    CPUState *env = cpu_single_env;



    qemu_event_increment ();

    if (env) {

        cpu_exit(env);

    }

    if (next_cpu && env != next_cpu) {

        cpu_exit(next_cpu);

    }

    exit_request = 1;

}
