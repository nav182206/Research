/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4115
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0fdddf80a88ac2efe068990d1878f472bb6b95d9
 */

int64_t qemu_get_clock(QEMUClock *clock)

{

    switch(clock->type) {

    case QEMU_TIMER_REALTIME:

        return get_clock() / 1000000;

    default:

    case QEMU_TIMER_VIRTUAL:

        if (use_icount) {

            return cpu_get_icount();

        } else {

            return cpu_get_clock();

        }

    }

}
