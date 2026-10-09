/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=40ff6d7e8dceca227e7f8a3e8e0d58b2c66d19b4
 */

static void vnc_listen_read(void *opaque)

{

    VncDisplay *vs = opaque;

    struct sockaddr_in addr;

    socklen_t addrlen = sizeof(addr);



    /* Catch-up */

    vga_hw_update();



    int csock = accept(vs->lsock, (struct sockaddr *)&addr, &addrlen);

    if (csock != -1) {

        vnc_connect(vs, csock);

    }

}
