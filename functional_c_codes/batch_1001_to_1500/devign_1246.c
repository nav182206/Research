/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1246
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e973051b96bac5eef46393eec15b68796e7c7d3
 */

static int buffered_rate_limit(void *opaque)

{

    MigrationState *s = opaque;

    int ret;



    ret = qemu_file_get_error(s->file);

    if (ret) {

        return ret;

    }



    if (s->bytes_xfer > s->xfer_limit) {

        return 1;

    }



    return 0;

}
