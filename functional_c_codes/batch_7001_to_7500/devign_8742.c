/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8742
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1964a397063967acc5ce71a2a24ed26e74824ee1
 */

static int64_t migration_get_rate_limit(void *opaque)

{

    MigrationState *s = opaque;



    return s->xfer_limit;

}
