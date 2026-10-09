/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9837
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aedbe19297907143f17b733a7ff0e0534377bed1
 */

int qemu_reset_requested_get(void)

{

    return reset_requested;

}
