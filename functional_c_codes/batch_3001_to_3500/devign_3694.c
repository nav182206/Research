/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3694
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int qemu_rdma_close(void *opaque)

{

    DPRINTF("Shutting down connection.\n");

    QEMUFileRDMA *r = opaque;

    if (r->rdma) {

        qemu_rdma_cleanup(r->rdma);

        g_free(r->rdma);

    }

    g_free(r);

    return 0;

}
