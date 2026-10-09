/* 
 * Benchmark Sample ID : devign_6882
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb5d4f5329df83ea15244b47f7fbca21adaae41b
 */

static void slirp_bootp_load(QEMUFile *f, Slirp *slirp)

{

    int i;



    for (i = 0; i < NB_BOOTP_CLIENTS; i++) {

        slirp->bootp_clients[i].allocated = qemu_get_be16(f);

        qemu_get_buffer(f, slirp->bootp_clients[i].macaddr, 6);

    }

}
