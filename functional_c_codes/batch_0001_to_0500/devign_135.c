/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b938c7262e403f5467110609cb20ef1ae6e9df2
 */

static void unix_process_msgfd(CharDriverState *chr, struct msghdr *msg)
{
    TCPCharDriver *s = chr->opaque;
    struct cmsghdr *cmsg;
    for (cmsg = CMSG_FIRSTHDR(msg); cmsg; cmsg = CMSG_NXTHDR(msg, cmsg)) {
        int fd;
        if (cmsg->cmsg_len != CMSG_LEN(sizeof(int)) ||
            cmsg->cmsg_level != SOL_SOCKET ||
            cmsg->cmsg_type != SCM_RIGHTS)
            continue;
        fd = *((int *)CMSG_DATA(cmsg));
        if (fd < 0)
            continue;
#ifndef MSG_CMSG_CLOEXEC
        qemu_set_cloexec(fd);
#endif
        if (s->msgfd != -1)
            close(s->msgfd);
        s->msgfd = fd;
    }
}
