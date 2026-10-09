/* 
 * Benchmark Sample ID : devign_8622
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0bb05eaff04d30609a98c0dae80bb5dba3e4e799
 */

size_t qemu_file_set_rate_limit(QEMUFile *f, size_t new_rate)

{

    if (f->set_rate_limit)

        return f->set_rate_limit(f->opaque, new_rate);



    return 0;

}
