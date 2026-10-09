/* 
 * Benchmark Sample ID : devign_252
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8e9b0d24fb986d4241ae3b77752eca5dab4cb486
 */

static void vnc_listen_read(void *opaque, bool websocket)

{

    VncDisplay *vs = opaque;

    struct sockaddr_in addr;

    socklen_t addrlen = sizeof(addr);

    int csock;



    /* Catch-up */

    graphic_hw_update(vs->dcl.con);

#ifdef CONFIG_VNC_WS

    if (websocket) {

        csock = qemu_accept(vs->lwebsock, (struct sockaddr *)&addr, &addrlen);

    } else

#endif /* CONFIG_VNC_WS */

    {

        csock = qemu_accept(vs->lsock, (struct sockaddr *)&addr, &addrlen);

    }



    if (csock != -1) {

        socket_set_nodelay(csock);

        vnc_connect(vs, csock, false, websocket);

    }

}
