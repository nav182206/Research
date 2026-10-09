/* 
 * Benchmark Sample ID : devign_2403
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d82ca915875ac55ba291435f7eb4fe7bfcb2cecb
 */

int qemu_fclose(QEMUFile *f)

{

    int ret = 0;

    qemu_fflush(f);

    if (f->close)

        ret = f->close(f->opaque);

    g_free(f);

    return ret;

}
