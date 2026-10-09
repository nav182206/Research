/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_426
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ffacc5d3ddf2e3227aae2a8cc5c15627265f727
 */

static bool ga_open_pidfile(const char *pidfile)

{

    int pidfd;

    char pidstr[32];



    pidfd = open(pidfile, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

    if (pidfd == -1 || lockf(pidfd, F_TLOCK, 0)) {

        g_critical("Cannot lock pid file, %s", strerror(errno));

        if (pidfd != -1) {

            close(pidfd);

        }

        return false;

    }



    if (ftruncate(pidfd, 0) || lseek(pidfd, 0, SEEK_SET)) {

        g_critical("Failed to truncate pid file");

        goto fail;

    }

    snprintf(pidstr, sizeof(pidstr), "%d\n", getpid());

    if (write(pidfd, pidstr, strlen(pidstr)) != strlen(pidstr)) {

        g_critical("Failed to write pid file");

        goto fail;

    }



    return true;



fail:

    unlink(pidfile);

    return false;

}
