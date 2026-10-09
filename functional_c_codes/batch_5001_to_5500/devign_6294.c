/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b5ec5ce0e39d6e7ea707d5604a5f6d567dfd2f48
 */

void x86_cpu_list (FILE *f, int (*cpu_fprintf)(FILE *f, const char *fmt, ...))

{

    unsigned int i;



    for (i = 0; i < ARRAY_SIZE(x86_defs); i++)

        (*cpu_fprintf)(f, "x86 %16s\n", x86_defs[i].name);

}
