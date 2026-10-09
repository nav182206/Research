/* 
 * Benchmark Sample ID : devign_600
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void qemu_fflush(QEMUFile *f)

{

    ssize_t ret = 0;



    if (!qemu_file_is_writable(f)) {

        return;

    }



    if (f->ops->writev_buffer) {

        if (f->iovcnt > 0) {

            ret = f->ops->writev_buffer(f->opaque, f->iov, f->iovcnt, f->pos);

        }

    } else {

        if (f->buf_index > 0) {

            ret = f->ops->put_buffer(f->opaque, f->buf, f->pos, f->buf_index);

        }

    }

    if (ret >= 0) {

        f->pos += ret;

    }

    f->buf_index = 0;

    f->iovcnt = 0;

    if (ret < 0) {

        qemu_file_set_error(f, ret);

    }

}
