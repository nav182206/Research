/* 
 * Benchmark Sample ID : devign_6725
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=edcc5f9dc39309d32f4b3737e6b750ae967f5bbd
 */

static inline abi_long do_msgsnd(int msqid, abi_long msgp,

                                 unsigned int msgsz, int msgflg)

{

    struct target_msgbuf *target_mb;

    struct msgbuf *host_mb;

    abi_long ret = 0;



    if (!lock_user_struct(VERIFY_READ, target_mb, msgp, 0))

        return -TARGET_EFAULT;

    host_mb = malloc(msgsz+sizeof(long));

    host_mb->mtype = (abi_long) tswapal(target_mb->mtype);

    memcpy(host_mb->mtext, target_mb->mtext, msgsz);

    ret = get_errno(msgsnd(msqid, host_mb, msgsz, msgflg));

    free(host_mb);

    unlock_user_struct(target_mb, msgp, 0);



    return ret;

}
