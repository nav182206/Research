/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9723
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1828be316f6637d43dd4c4f5f32925b17fb8107f
 */

static void tcg_cpu_exec(void)

{

    int ret = 0;



    if (next_cpu == NULL)

        next_cpu = first_cpu;

    for (; next_cpu != NULL; next_cpu = next_cpu->next_cpu) {

        CPUState *env = cur_cpu = next_cpu;



        if (timer_alarm_pending) {

            timer_alarm_pending = 0;

            break;

        }

        if (cpu_can_run(env))

            ret = qemu_cpu_exec(env);

        else if (env->stop)

            break;



        if (ret == EXCP_DEBUG) {

            gdb_set_stop_cpu(env);

            debug_requested = 1;

            break;

        }

    }

}
