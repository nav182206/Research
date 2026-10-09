/* 
 * Benchmark Sample ID : devign_8215
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc84de9570ffe01a9c3c169bd62ab9586a9a080c
 */

static void qemu_signal_lock(unsigned int msecs)

{

    qemu_mutex_lock(&qemu_fair_mutex);



    while (qemu_mutex_trylock(&qemu_global_mutex)) {

        qemu_thread_signal(tcg_cpu_thread, SIGUSR1);

        if (!qemu_mutex_timedlock(&qemu_global_mutex, msecs))

            break;

    }

    qemu_mutex_unlock(&qemu_fair_mutex);

}
