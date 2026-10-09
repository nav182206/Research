/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8936
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void do_closefd(Monitor *mon, const QDict *qdict)

{

    const char *fdname = qdict_get_str(qdict, "fdname");

    mon_fd_t *monfd;



    LIST_FOREACH(monfd, &mon->fds, next) {

        if (strcmp(monfd->name, fdname) != 0) {

            continue;

        }



        LIST_REMOVE(monfd, next);

        close(monfd->fd);

        qemu_free(monfd->name);

        qemu_free(monfd);

        return;

    }



    monitor_printf(mon, "Failed to find file descriptor named %s\n",

                   fdname);

}
