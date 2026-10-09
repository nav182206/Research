/* 
 * Benchmark Sample ID : devign_3711
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1964a397063967acc5ce71a2a24ed26e74824ee1
 */

int64_t qemu_file_set_rate_limit(QEMUFile *f, int64_t new_rate)

{

    /* any failed or completed migration keeps its state to allow probing of

     * migration data, but has no associated file anymore */

    if (f && f->ops->set_rate_limit)

        return f->ops->set_rate_limit(f->opaque, new_rate);



    return 0;

}
