/* 
 * Benchmark Sample ID : devign_2957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void qemu_put_byte(QEMUFile *f, int v)

{

    if (f->last_error) {

        return;

    }



    f->buf[f->buf_index] = v;

    f->bytes_xfer++;

    if (f->ops->writev_buffer) {

        add_to_iovec(f, f->buf + f->buf_index, 1);

    }

    f->buf_index++;

    if (f->buf_index == IO_BUF_SIZE) {

        qemu_fflush(f);

    }

}
