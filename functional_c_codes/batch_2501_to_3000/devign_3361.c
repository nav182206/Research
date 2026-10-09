/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3361
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a2b257d6212ade772473f86bf0637480b2578a7e
 */

void phys_mem_set_alloc(void *(*alloc)(size_t))

{

    phys_mem_alloc = alloc;

}
