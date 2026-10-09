/* 
 * Benchmark Sample ID : devign_9879
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ab07c623c629acfbc792e5a174129c19faefbb7
 */

static void *qemu_kvm_cpu_thread_fn(void *arg)

{

    CPUState *env = arg;

    int r;



    qemu_mutex_lock(&qemu_global_mutex);

    qemu_thread_self(env->thread);



    r = kvm_init_vcpu(env);

    if (r < 0) {

        fprintf(stderr, "kvm_init_vcpu failed: %s\n", strerror(-r));

        exit(1);

    }



    qemu_kvm_init_cpu_signals(env);



    /* signal CPU creation */

    env->created = 1;

    qemu_cond_signal(&qemu_cpu_cond);



    /* and wait for machine initialization */

    while (!qemu_system_ready)

        qemu_cond_timedwait(&qemu_system_cond, &qemu_global_mutex, 100);



    while (1) {

        if (cpu_can_run(env))

            qemu_cpu_exec(env);

        qemu_kvm_wait_io_event(env);

    }



    return NULL;

}
