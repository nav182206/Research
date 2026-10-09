/* 
 * Benchmark Sample ID : devign_4089
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

static void sigchld_bh_handler(void *opaque)

{

    ChildProcessRecord *rec, *next;



    QLIST_FOREACH_SAFE(rec, &child_watches, next, next) {

        if (waitpid(rec->pid, NULL, WNOHANG) == rec->pid) {

            QLIST_REMOVE(rec, next);

            g_free(rec);

        }

    }

}
