/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4232
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d32fcad366e5f45d33dab2ee4de0e5729439680b
 */

static void vde_to_qemu(void *opaque)

{

    VDEState *s = opaque;

    uint8_t buf[4096];

    int size;



    size = vde_recv(s->vde, (char *)buf, sizeof(buf), 0);

    if (size > 0) {

        qemu_send_packet(&s->nc, buf, size);

    }

}
