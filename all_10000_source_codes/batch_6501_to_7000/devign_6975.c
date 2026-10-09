/* 
 * Benchmark Sample ID : devign_6975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf1d078e4ea094e516faab49678fbea3a34b7848
 */

size_t slirp_socket_can_recv(Slirp *slirp, struct in_addr guest_addr,

                             int guest_port)

{

	struct iovec iov[2];

	struct socket *so;



	so = slirp_find_ctl_socket(slirp, guest_addr, guest_port);



	if (!so || so->so_state & SS_NOFDREF)

		return 0;



	if (!CONN_CANFRCV(so) || so->so_snd.sb_cc >= (so->so_snd.sb_datalen/2))

		return 0;



	return sopreprbuf(so, iov, NULL);

}
