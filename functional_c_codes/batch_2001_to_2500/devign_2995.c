/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2995
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

int64_t qemu_file_get_rate_limit(QEMUFile *f)

{

    return f->xfer_limit;

}
