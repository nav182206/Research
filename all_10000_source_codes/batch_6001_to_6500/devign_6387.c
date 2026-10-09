/* 
 * Benchmark Sample ID : devign_6387
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=baab248c499a7689aefb5f2e9c004338deb08d74
 */

int ff_socket(int af, int type, int proto)

{

    int fd;



#ifdef SOCK_CLOEXEC

    fd = socket(af, type | SOCK_CLOEXEC, proto);

    if (fd == -1 && errno == EINVAL)

#endif

    {

        fd = socket(af, type, proto);

#if HAVE_FCNTL

        if (fd != -1)

            fcntl(fd, F_SETFD, FD_CLOEXEC);

#endif

    }

    return fd;

}
