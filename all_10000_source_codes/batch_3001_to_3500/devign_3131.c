/* 
 * Benchmark Sample ID : devign_3131
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1fdf257d52822695f5ace6c586e059aa17d4b79
 */

ssize_t nbd_send_request(QIOChannel *ioc, NBDRequest *request)

{

    uint8_t buf[NBD_REQUEST_SIZE];



    TRACE("Sending request to server: "

          "{ .from = %" PRIu64", .len = %" PRIu32 ", .handle = %" PRIu64

          ", .flags = %" PRIx16 ", .type = %" PRIu16 " }",

          request->from, request->len, request->handle,

          request->flags, request->type);



    stl_be_p(buf, NBD_REQUEST_MAGIC);

    stw_be_p(buf + 4, request->flags);

    stw_be_p(buf + 6, request->type);

    stq_be_p(buf + 8, request->handle);

    stq_be_p(buf + 16, request->from);

    stl_be_p(buf + 24, request->len);



    return write_sync(ioc, buf, sizeof(buf), NULL);

}
