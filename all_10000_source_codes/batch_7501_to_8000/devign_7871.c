/* 
 * Benchmark Sample ID : devign_7871
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1fdf257d52822695f5ace6c586e059aa17d4b79
 */

static ssize_t nbd_send_reply(QIOChannel *ioc, NBDReply *reply)

{

    uint8_t buf[NBD_REPLY_SIZE];



    reply->error = system_errno_to_nbd_errno(reply->error);



    TRACE("Sending response to client: { .error = %" PRId32

          ", handle = %" PRIu64 " }",

          reply->error, reply->handle);



    /* Reply

       [ 0 ..  3]    magic   (NBD_REPLY_MAGIC)

       [ 4 ..  7]    error   (0 == no error)

       [ 7 .. 15]    handle

     */

    stl_be_p(buf, NBD_REPLY_MAGIC);

    stl_be_p(buf + 4, reply->error);

    stq_be_p(buf + 8, reply->handle);



    return write_sync(ioc, buf, sizeof(buf), NULL);

}
