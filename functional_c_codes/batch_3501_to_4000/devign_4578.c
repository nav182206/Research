/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4578
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=871d2f079661323a7645b388eb5ae8d7eeb3117c
 */

void qemu_put_buffer(QEMUFile *f, const uint8_t *buf, int size)

{

    int l;

    while (size > 0) {

        l = IO_BUF_SIZE - f->buf_index;

        if (l > size)

            l = size;

        memcpy(f->buf + f->buf_index, buf, l);

        f->buf_index += l;

        buf += l;

        size -= l;

        if (f->buf_index >= IO_BUF_SIZE)

            qemu_fflush(f);

    }

}
