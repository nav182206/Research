/* 
 * Benchmark Sample ID : devign_3691
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9fac18f03a9040b67ec38e14d3e1ed34db9c7e06
 */

void qemu_anon_ram_free(void *ptr, size_t size)

{

    trace_qemu_anon_ram_free(ptr, size);

    if (ptr) {

        munmap(ptr, size);

    }

}
