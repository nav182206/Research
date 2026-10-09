/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2507
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1a6245a5b0b4e8d822c739b403fc67c8a7bc8d12
 */

static int nbd_handle_list(NBDClient *client, uint32_t length)

{

    int csock;

    NBDExport *exp;



    csock = client->sock;

    if (length) {

        if (drop_sync(csock, length) != length) {

            return -EIO;

        }

        return nbd_send_rep(csock, NBD_REP_ERR_INVALID, NBD_OPT_LIST);

    }



    /* For each export, send a NBD_REP_SERVER reply. */

    QTAILQ_FOREACH(exp, &exports, next) {

        if (nbd_send_rep_list(csock, exp)) {

            return -EINVAL;

        }

    }

    /* Finish with a NBD_REP_ACK. */

    return nbd_send_rep(csock, NBD_REP_ACK, NBD_OPT_LIST);

}
