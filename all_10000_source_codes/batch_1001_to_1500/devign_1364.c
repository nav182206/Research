/* 
 * Benchmark Sample ID : devign_1364
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cd245a19329edfcd968b00d05ad92de7a0e2daa1
 */

void *qemu_realloc(void *ptr, size_t size)

{

    if (!size && !allow_zero_malloc()) {

        abort();

    }

    return oom_check(realloc(ptr, size ? size : 1));

}
