/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1443
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3f2ca480eb872b4946baf77f756236b637a5b15a
 */

uint32_t kvmppc_get_vmx(void)

{

    return kvmppc_read_int_cpu_dt("ibm,vmx");

}
