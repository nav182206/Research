/* 
 * Benchmark Sample ID : devign_8988
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0379f474ddebfc69f42fa8231d86687cf29d997b
 */

static int nbd_handle_list(NBDClient *client, uint32_t length)

{

    int csock;

    NBDExport *exp;



    csock = client->sock;

    if (length) {




        return nbd_send_rep(csock, NBD_REP_ERR_INVALID, NBD_OPT_LIST);




    /* For each export, send a NBD_REP_SERVER reply. */

    QTAILQ_FOREACH(exp, &exports, next) {

        if (nbd_send_rep_list(csock, exp)) {

            return -EINVAL;



    /* Finish with a NBD_REP_ACK. */

    return nbd_send_rep(csock, NBD_REP_ACK, NBD_OPT_LIST);
