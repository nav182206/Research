/* 
 * Benchmark Sample ID : devign_7545
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a78eead0c74333a394c0f7bbfc4423ac746fcd5
 */

void arm_cpu_list(FILE *f, int (*cpu_fprintf)(FILE *f, const char *fmt, ...))

{

    int i;



    (*cpu_fprintf)(f, "Available CPUs:\n");

    for (i = 0; arm_cpu_names[i].name; i++) {

        (*cpu_fprintf)(f, "  %s\n", arm_cpu_names[i].name);

    }

}
