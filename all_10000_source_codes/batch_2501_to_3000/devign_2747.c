/* 
 * Benchmark Sample ID : devign_2747
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

int qemu_add_child_watch(pid_t pid)

{

    ChildProcessRecord *rec;



    if (!sigchld_bh) {

        qemu_init_child_watch();

    }



    QLIST_FOREACH(rec, &child_watches, next) {

        if (rec->pid == pid) {

            return 1;

        }

    }

    rec = g_malloc0(sizeof(ChildProcessRecord));

    rec->pid = pid;

    QLIST_INSERT_HEAD(&child_watches, rec, next);

    return 0;

}
