/* 
 * Benchmark Sample ID : devign_2621
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1bfb4587a2e5b25ed15f742149e555efc8f305ae
 */

static void ERROR(const char *str)

{

        fprintf(stderr, "%s\n", str);

        exit(1);

}
