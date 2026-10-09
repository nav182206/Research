/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=242acf3af4605adce933906bdc053b2414181ec7
 */

int udp_output(struct socket *so, struct mbuf *m,

               struct sockaddr_in *addr)



{

    struct sockaddr_in saddr, daddr;



    saddr = *addr;

    if ((so->so_faddr.s_addr & htonl(0xffffff00)) == special_addr.s_addr) {

        if ((so->so_faddr.s_addr & htonl(0x000000ff)) == htonl(0xff))

            saddr.sin_addr.s_addr = alias_addr.s_addr;

        else if (addr->sin_addr.s_addr == loopback_addr.s_addr ||

                 ((so->so_faddr.s_addr & htonl(CTL_DNS)) == htonl(CTL_DNS)))

            saddr.sin_addr.s_addr = so->so_faddr.s_addr;

    }

    daddr.sin_addr = so->so_laddr;

    daddr.sin_port = so->so_lport;



    return udp_output2(so, m, &saddr, &daddr, so->so_iptos);

}
