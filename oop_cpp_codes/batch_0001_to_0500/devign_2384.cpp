/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2384
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e7e2ebc942da8285931ceabf12823e165dced8b
 */

static void vnc_listen_read(void *opaque)

{

    VncDisplay *vs = opaque;

    struct sockaddr_in addr;

    socklen_t addrlen = sizeof(addr);



    /* Catch-up */

    vga_hw_update();



    int csock = qemu_accept(vs->lsock, (struct sockaddr *)&addr, &addrlen);

    if (csock != -1) {

        vnc_connect(vs, csock);

    }

}
