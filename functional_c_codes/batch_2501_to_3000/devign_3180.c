/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3180
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad5afd07b628cd0610ea322ad60b5ad03aa250c8
 */

static void s390_cpu_model_initfn(Object *obj)
{
