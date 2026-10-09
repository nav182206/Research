/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8422
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=904d6f588063fb5ad2b61998acdf1e73fb465067
 */

static void chr_read(void *opaque, const void *buf, size_t size)

{

    VirtIORNG *vrng = opaque;

    size_t len;

    int offset;



    if (!is_guest_ready(vrng)) {

        return;

    }



    offset = 0;

    while (offset < size) {

        if (!pop_an_elem(vrng)) {

            break;

        }

        len = iov_from_buf(vrng->elem.in_sg, vrng->elem.in_num,

                           0, buf + offset, size - offset);

        offset += len;



        virtqueue_push(vrng->vq, &vrng->elem, len);

        vrng->popped = false;

    }

    virtio_notify(&vrng->vdev, vrng->vq);



    /*

     * Lastly, if we had multiple elems queued by the guest, and we

     * didn't have enough data to fill them all, indicate we want more

     * data.

     */

    len = pop_an_elem(vrng);

    if (len) {

        rng_backend_request_entropy(vrng->rng, size, chr_read, vrng);

    }

}
