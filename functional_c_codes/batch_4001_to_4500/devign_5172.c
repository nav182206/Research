/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5172
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

int qemu_file_rate_limit(QEMUFile *f)

{

    if (qemu_file_get_error(f)) {

        return 1;

    }

    if (f->xfer_limit > 0 && f->bytes_xfer > f->xfer_limit) {

        return 1;

    }

    return 0;

}
