/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4849
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a78eead0c74333a394c0f7bbfc4423ac746fcd5
 */

void mips_cpu_list (FILE *f, int (*cpu_fprintf)(FILE *f, const char *fmt, ...))

{

    int i;



    for (i = 0; i < ARRAY_SIZE(mips_defs); i++) {

        (*cpu_fprintf)(f, "MIPS '%s'\n",

                       mips_defs[i].name);

    }

}
