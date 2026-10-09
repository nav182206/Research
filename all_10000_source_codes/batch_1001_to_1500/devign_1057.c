/* 
 * Benchmark Sample ID : devign_1057
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d95704341280fc521dc2b16bbbc5858f6647e2c3
 */

processed(OptsVisitor *ov, const char *name)

{

    if (ov->repeated_opts == NULL) {

        g_hash_table_remove(ov->unprocessed_opts, name);

    }

}
