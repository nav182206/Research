/* 
 * Benchmark Sample ID : devign_886
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8b7968f7c4ac8c07cad6a1a0891d38cf239a2839
 */

static int monitor_fprintf(FILE *stream, const char *fmt, ...)

{

    va_list ap;

    va_start(ap, fmt);

    monitor_vprintf((Monitor *)stream, fmt, ap);

    va_end(ap);

    return 0;

}
