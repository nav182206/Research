/* 
 * Benchmark Sample ID : devign_6913
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8160bfbc4d5d0abf78afa557f2d5832dc11cd690
 */

static int unix_close(MigrationState *s)

{

    DPRINTF("unix_close\n");

    if (s->fd != -1) {

        close(s->fd);

        s->fd = -1;

    }

    return 0;

}
