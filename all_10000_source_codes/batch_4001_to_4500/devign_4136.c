/* 
 * Benchmark Sample ID : devign_4136
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb5d4f5329df83ea15244b47f7fbca21adaae41b
 */

static void slirp_state_save(QEMUFile *f, void *opaque)

{

    Slirp *slirp = opaque;

    struct ex_list *ex_ptr;



    for (ex_ptr = slirp->exec_list; ex_ptr; ex_ptr = ex_ptr->ex_next)

        if (ex_ptr->ex_pty == 3) {

            struct socket *so;

            so = slirp_find_ctl_socket(slirp, ex_ptr->ex_addr,

                                       ntohs(ex_ptr->ex_fport));

            if (!so)

                continue;



            qemu_put_byte(f, 42);

            vmstate_save_state(f, &vmstate_slirp_socket, so, NULL);

        }

    qemu_put_byte(f, 0);



    qemu_put_be16(f, slirp->ip_id);



    slirp_bootp_save(f, slirp);

}
