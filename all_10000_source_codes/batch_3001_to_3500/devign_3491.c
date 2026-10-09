/* 
 * Benchmark Sample ID : devign_3491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5dafc53f1fb091d242f2179ffcb43bb28af36d1e
 */

void qemu_fclose(QEMUFile *f)

{

    if (f->is_writable)

        qemu_fflush(f);

    if (f->is_file) {

        fclose(f->outfile);

    }

    qemu_free(f);

}
