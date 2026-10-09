/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f0495f56c9f4574140c392bdbad42721ba692d19
 */

static void tm_put(QEMUFile *f, struct tm *tm) {

    qemu_put_be16(f, tm->tm_sec);

    qemu_put_be16(f, tm->tm_min);

    qemu_put_be16(f, tm->tm_hour);

    qemu_put_be16(f, tm->tm_mday);

    qemu_put_be16(f, tm->tm_min);

    qemu_put_be16(f, tm->tm_year);

}
