/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4361
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void init_clocks(void)

{

    QEMUClockType type;

    for (type = 0; type < QEMU_CLOCK_MAX; type++) {

        qemu_clock_init(type);

    }



#ifdef CONFIG_PRCTL_PR_SET_TIMERSLACK

    prctl(PR_SET_TIMERSLACK, 1, 0, 0, 0);

#endif

}
