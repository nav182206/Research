/* 
 * Benchmark Sample ID : devign_1397
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83f338f73ecb88cc6f85d6e7b81ebef112ce07be
 */

CPUDebugExcpHandler *cpu_set_debug_excp_handler(CPUDebugExcpHandler *handler)

{

    CPUDebugExcpHandler *old_handler = debug_excp_handler;



    debug_excp_handler = handler;

    return old_handler;

}
