/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1705
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3c529d935923a70519557d420db1d5a09a65086a
 */

static void raw_close_fd_pool(BDRVRawState *s)

{

    int i;



    for (i = 0; i < RAW_FD_POOL_SIZE; i++) {

        if (s->fd_pool[i] != -1) {

            close(s->fd_pool[i]);

            s->fd_pool[i] = -1;

        }

    }

}
