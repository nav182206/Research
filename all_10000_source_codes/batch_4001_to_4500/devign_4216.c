/* 
 * Benchmark Sample ID : devign_4216
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bd7854e1e5d6f4cfe4558090bbd9493c12bf846
 */

void qemu_chr_printf(CharDriverState *s, const char *fmt, ...)

{

    char buf[4096];

    va_list ap;

    va_start(ap, fmt);

    vsnprintf(buf, sizeof(buf), fmt, ap);

    qemu_chr_write(s, (uint8_t *)buf, strlen(buf));

    va_end(ap);

}
