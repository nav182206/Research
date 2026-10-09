/* 
 * Benchmark Sample ID : devign_6001
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b4049b74b97f30fe944c63b5f158ec9e87bd2593
 */

QEMUClock *qemu_clock_ptr(QEMUClockType type)

{

    return &qemu_clocks[type];

}
