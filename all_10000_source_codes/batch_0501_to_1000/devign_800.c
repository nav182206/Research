/* 
 * Benchmark Sample ID : devign_800
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b9ce1454e14ec918acb90d899ce7724f69682f45
 */

int qemu_get_byte(QEMUFile *f)

{

    if (f->is_write)

        abort();



    if (f->buf_index >= f->buf_size) {

        qemu_fill_buffer(f);

        if (f->buf_index >= f->buf_size)

            return 0;

    }

    return f->buf[f->buf_index++];

}
