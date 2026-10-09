/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2934
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=72b6ffc76653214b69a94a7b1643ff80df134486
 */

static void nbd_co_receive_reply(NBDClientSession *s,

                                 NBDRequest *request,

                                 NBDReply *reply,

                                 QEMUIOVector *qiov)

{

    int ret;



    /* Wait until we're woken up by nbd_read_reply_entry.  */

    qemu_coroutine_yield();

    *reply = s->reply;

    if (reply->handle != request->handle ||

        !s->ioc) {

        reply->error = EIO;

    } else {

        if (qiov && reply->error == 0) {

            ret = nbd_rwv(s->ioc, qiov->iov, qiov->niov, request->len, true,

                          NULL);

            if (ret != request->len) {

                reply->error = EIO;

            }

        }



        /* Tell the read handler to read another header.  */

        s->reply.handle = 0;

    }

}
