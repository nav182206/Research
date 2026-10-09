/* 
 * Benchmark Sample ID : devign_2985
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5dafc53f1fb091d242f2179ffcb43bb28af36d1e
 */

int64_t qemu_fseek(QEMUFile *f, int64_t pos, int whence)

{

    if (whence == SEEK_SET) {

        /* nothing to do */

    } else if (whence == SEEK_CUR) {

        pos += qemu_ftell(f);

    } else {

        /* SEEK_END not supported */

        return -1;

    }

    if (f->is_writable) {

        qemu_fflush(f);

        f->buf_offset = pos;

    } else {

        f->buf_offset = pos;

        f->buf_index = 0;

        f->buf_size = 0;

    }

    return pos;

}
