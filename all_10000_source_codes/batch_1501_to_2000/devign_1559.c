/* 
 * Benchmark Sample ID : devign_1559
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f17fd4fdf0df3d2f3444399d04c38d22b9a3e1b7
 */

int64_t qemu_strtosz_MiB(const char *nptr, char **end)

{

    return do_strtosz(nptr, end, 'M', 1024);

}
