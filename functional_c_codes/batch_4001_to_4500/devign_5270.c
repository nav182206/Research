/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5270
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5dafc53f1fb091d242f2179ffcb43bb28af36d1e
 */

void qemu_fflush(QEMUFile *f)

{

    if (!f->is_writable)

        return;

    if (f->buf_index > 0) {

        if (f->is_file) {

            fseek(f->outfile, f->buf_offset, SEEK_SET);

            fwrite(f->buf, 1, f->buf_index, f->outfile);

        } else {

            bdrv_pwrite(f->bs, f->base_offset + f->buf_offset,

                        f->buf, f->buf_index);

        }

        f->buf_offset += f->buf_index;

        f->buf_index = 0;

    }

}
