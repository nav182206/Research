/* 
 * Benchmark Sample ID : devign_5600
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f3ed190a673c0020c3ccebb4882ae4675cb5f4d
 */

static void trigger_console_data(void *opaque, int n, int level)

{

    sclp_service_interrupt(0);

}
