/* 
 * Benchmark Sample ID : devign_1941
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=372579427a5040a26dfee78464b50e2bdf27ef26
 */

static void start_tcg_kick_timer(void)

{

    if (!tcg_kick_vcpu_timer && CPU_NEXT(first_cpu)) {

        tcg_kick_vcpu_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL,

                                           kick_tcg_thread, NULL);

        timer_mod(tcg_kick_vcpu_timer, qemu_tcg_next_kick());

    }

}
