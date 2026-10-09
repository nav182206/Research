/* 
 * Benchmark Sample ID : devign_200
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

static int vm_request_pending(void)

{

    return powerdown_requested ||

           reset_requested ||

           shutdown_requested ||

           debug_requested ||

           vmstop_requested;

}
