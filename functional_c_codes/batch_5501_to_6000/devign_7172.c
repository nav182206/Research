/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7172
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void qemu_file_reset_rate_limit(QEMUFile *f)

{

    f->bytes_xfer = 0;

}
