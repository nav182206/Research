/* 
 * Benchmark Sample ID : devign_6240
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3c638d0690a0b21c6acef7ce3132f821d8c1e25d
 */

bool cpu_exec_all(void)

{

    int ret = 0;



    if (next_cpu == NULL)

        next_cpu = first_cpu;

    for (; next_cpu != NULL && !exit_request; next_cpu = next_cpu->next_cpu) {

        CPUState *env = next_cpu;



        qemu_clock_enable(vm_clock,

                          (env->singlestep_enabled & SSTEP_NOTIMER) == 0);



        if (qemu_alarm_pending())

            break;

        if (cpu_can_run(env))

            ret = qemu_cpu_exec(env);

        else if (env->stop)

            break;



        if (ret == EXCP_DEBUG) {

            gdb_set_stop_cpu(env);

            debug_requested = EXCP_DEBUG;

            break;

        }

    }

    exit_request = 0;

    return any_cpu_has_work();

}
