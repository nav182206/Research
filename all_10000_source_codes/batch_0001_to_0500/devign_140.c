/* 
 * Benchmark Sample ID : devign_140
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7a6ab45e19b615b9285b9cfa2bbc1fee012bc8d7
 */

void nonono(const char* file, int line, const char* msg) {

    fprintf(stderr, "Nonono! %s:%d %s\n", file, line, msg);

    exit(-5);

}
