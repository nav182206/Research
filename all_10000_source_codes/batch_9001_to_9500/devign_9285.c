/* 
 * Benchmark Sample ID : devign_9285
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c63807244fb55071675907460a0ecf228c1766c8
 */

static int qemu_peek_byte(QEMUFile *f)

{

    if (f->is_write) {

        abort();

    }



    if (f->buf_index >= f->buf_size) {

        qemu_fill_buffer(f);

        if (f->buf_index >= f->buf_size) {

            return 0;

        }

    }

    return f->buf[f->buf_index];

}
