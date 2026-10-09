/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8620
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ad645d2854746b55ddfd1d8e951f689cca5d78f
 */

static int setup_common(char *argv[], int argv_sz)

{

    memset(cur_ide, 0, sizeof(cur_ide));

    return append_arg(0, argv, argv_sz,

                      g_strdup("-nodefaults -display none"));

}
