/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6023
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d5d1507b347b7cd6c3b82459b96f1889b29939ef
 */

static void monitor_readline_printf(void *opaque, const char *fmt, ...)

{

    va_list ap;

    va_start(ap, fmt);

    monitor_vprintf(opaque, fmt, ap);

    va_end(ap);

}
