/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3733
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8ef98855d25e457094468e2e1a79d9b10d6445b2
 */

static int ff_sctp_send(int s, const void *msg, size_t len,

                        const struct sctp_sndrcvinfo *sinfo, int flags)

{

    struct msghdr outmsg;

    struct iovec iov;



    outmsg.msg_name       = NULL;

    outmsg.msg_namelen    = 0;

    outmsg.msg_iov        = &iov;

    iov.iov_base          = msg;

    iov.iov_len           = len;

    outmsg.msg_iovlen     = 1;

    outmsg.msg_controllen = 0;



    if (sinfo) {

        char outcmsg[CMSG_SPACE(sizeof(struct sctp_sndrcvinfo))];

        struct cmsghdr *cmsg;



        outmsg.msg_control    = outcmsg;

        outmsg.msg_controllen = sizeof(outcmsg);

        outmsg.msg_flags      = 0;



        cmsg             = CMSG_FIRSTHDR(&outmsg);

        cmsg->cmsg_level = IPPROTO_SCTP;

        cmsg->cmsg_type  = SCTP_SNDRCV;

        cmsg->cmsg_len   = CMSG_LEN(sizeof(struct sctp_sndrcvinfo));



        outmsg.msg_controllen = cmsg->cmsg_len;

        memcpy(CMSG_DATA(cmsg), sinfo, sizeof(struct sctp_sndrcvinfo));

    }



    return sendmsg(s, &outmsg, flags | MSG_NOSIGNAL);

}
