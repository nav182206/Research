/* 
 * Benchmark Sample ID : devign_5024
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a78eead0c74333a394c0f7bbfc4423ac746fcd5
 */

void cris_cpu_list(FILE *f, int (*cpu_fprintf)(FILE *f, const char *fmt, ...))

{

    unsigned int i;



    (*cpu_fprintf)(f, "Available CPUs:\n");

    for (i = 0; i < ARRAY_SIZE(cris_cores); i++) {

        (*cpu_fprintf)(f, "  %s\n", cris_cores[i].name);

    }

}
