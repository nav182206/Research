/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2418
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

void vm_stop(int reason)

{

    do_vm_stop(reason);

}
