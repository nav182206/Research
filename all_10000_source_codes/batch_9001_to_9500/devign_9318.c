/* 
 * Benchmark Sample ID : devign_9318
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d34e8f6e9d3a396c3327aa9807c83f9e1f4a7bd7
 */

static void __attribute__((constructor)) init_main_loop(void)

{

    init_clocks();

    init_timer_alarm();

    qemu_clock_enable(vm_clock, false);

}
