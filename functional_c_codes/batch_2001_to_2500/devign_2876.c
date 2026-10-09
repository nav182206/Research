/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2876
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad196a9d0c14f681f010bb4b979030ec125ba976
 */

void slirp_init(int restricted, const char *special_ip)

{

    //    debug_init("/tmp/slirp.log", DEBUG_DEFAULT);



#ifdef _WIN32

    {

        WSADATA Data;

        WSAStartup(MAKEWORD(2,0), &Data);

	atexit(slirp_cleanup);

    }

#endif



    link_up = 1;

    slirp_restrict = restricted;



    if_init();

    ip_init();



    /* Initialise mbufs *after* setting the MTU */

    m_init();



    /* set default addresses */

    inet_aton("127.0.0.1", &loopback_addr);



    if (get_dns_addr(&dns_addr) < 0) {

        dns_addr = loopback_addr;

        fprintf (stderr, "Warning: No DNS servers found\n");

    }



    if (special_ip)

        slirp_special_ip = special_ip;



    inet_aton(slirp_special_ip, &special_addr);

    alias_addr.s_addr = special_addr.s_addr | htonl(CTL_ALIAS);

    getouraddr();

    register_savevm("slirp", 0, 1, slirp_state_save, slirp_state_load, NULL);

}
