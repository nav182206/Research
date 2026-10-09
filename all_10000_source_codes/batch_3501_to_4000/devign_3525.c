/* 
 * Benchmark Sample ID : devign_3525
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

void kqemu_cpu_interrupt(CPUState *env)

{

#if defined(_WIN32)

    /* cancelling the I/O request causes KQEMU to finish executing the

       current block and successfully returning. */

    CancelIo(kqemu_fd);

#endif

}
