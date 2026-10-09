/* 
 * Benchmark Sample ID : devign_6804
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void qemu_file_skip(QEMUFile *f, int size)

{

    if (f->buf_index + size <= f->buf_size) {

        f->buf_index += size;

    }

}
