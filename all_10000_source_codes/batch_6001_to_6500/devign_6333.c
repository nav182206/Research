/* 
 * Benchmark Sample ID : devign_6333
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b2d1fe67d09d2b6c7da647fbcea6ca0148c206d3
 */

static void usbredir_put_bufpq(QEMUFile *f, void *priv, size_t unused)

{

    struct endp_data *endp = priv;

    USBRedirDevice *dev = endp->dev;

    struct buf_packet *bufp;

    int i = 0;



    qemu_put_be32(f, endp->bufpq_size);

    QTAILQ_FOREACH(bufp, &endp->bufpq, next) {

        DPRINTF("put_bufpq %d/%d len %d status %d\n", i + 1, endp->bufpq_size,

                bufp->len, bufp->status);

        qemu_put_be32(f, bufp->len);

        qemu_put_be32(f, bufp->status);

        qemu_put_buffer(f, bufp->data, bufp->len);

        i++;

    }

    assert(i == endp->bufpq_size);

}
