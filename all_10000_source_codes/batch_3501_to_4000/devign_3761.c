/* 
 * Benchmark Sample ID : devign_3761
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c10682cb031525a8bdf3999ef6a033777929d304
 */

void qemu_put_byte(QEMUFile *f, int v)

{

    if (!f->last_error && f->is_write == 0 && f->buf_index > 0) {

        fprintf(stderr,

                "Attempted to write to buffer while read buffer is not empty\n");

        abort();

    }



    f->buf[f->buf_index++] = v;

    f->is_write = 1;

    if (f->buf_index >= IO_BUF_SIZE) {

        int ret = qemu_fflush(f);

        qemu_file_set_if_error(f, ret);

    }

}
