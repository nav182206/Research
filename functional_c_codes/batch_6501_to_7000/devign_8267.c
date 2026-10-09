/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8267
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1964a397063967acc5ce71a2a24ed26e74824ee1
 */

static int migration_rate_limit(void *opaque)

{

    MigrationState *s = opaque;

    int ret;



    ret = qemu_file_get_error(s->file);

    if (ret) {

        return ret;

    }



    if (s->bytes_xfer >= s->xfer_limit) {

        return 1;

    }



    return 0;

}
