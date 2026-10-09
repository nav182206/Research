/* 
 * Benchmark Sample ID : devign_2511
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0fdddf80a88ac2efe068990d1878f472bb6b95d9
 */

static void init_timers(void)

{

    init_get_clock();

    rt_clock = qemu_new_clock(QEMU_TIMER_REALTIME);

    vm_clock = qemu_new_clock(QEMU_TIMER_VIRTUAL);

}
