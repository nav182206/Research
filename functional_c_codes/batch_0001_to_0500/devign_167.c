/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_167
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b9f0e2fd7c5070fa06cd6bd5ec69055e3a7d2b1
 */

void qmp_getfd(const char *fdname, Error **errp)

{

    mon_fd_t *monfd;

    int fd;



    fd = qemu_chr_fe_get_msgfd(cur_mon->chr);

    if (fd == -1) {

        error_set(errp, QERR_FD_NOT_SUPPLIED);

        return;

    }



    if (qemu_isdigit(fdname[0])) {


        error_set(errp, QERR_INVALID_PARAMETER_VALUE, "fdname",

                  "a name not starting with a digit");

        return;

    }



    QLIST_FOREACH(monfd, &cur_mon->fds, next) {

        if (strcmp(monfd->name, fdname) != 0) {

            continue;

        }



        close(monfd->fd);

        monfd->fd = fd;

        return;

    }



    monfd = g_malloc0(sizeof(mon_fd_t));

    monfd->name = g_strdup(fdname);

    monfd->fd = fd;



    QLIST_INSERT_HEAD(&cur_mon->fds, monfd, next);

}
