/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4912
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc84de9570ffe01a9c3c169bd62ab9586a9a080c
 */

static void resume_all_vcpus(void)

{

    CPUState *penv = first_cpu;



    while (penv) {

        penv->stop = 0;

        penv->stopped = 0;

        qemu_thread_signal(penv->thread, SIGUSR1);

        qemu_cpu_kick(penv);

        penv = (CPUState *)penv->next_cpu;

    }

}
