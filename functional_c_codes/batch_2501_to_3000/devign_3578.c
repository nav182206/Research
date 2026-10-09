/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3578
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9f14b0add1dcdbfa2ee61051d068211fb0a1fcc9
 */

static void rng_egd_chr_read(void *opaque, const uint8_t *buf, int size)

{

    RngEgd *s = RNG_EGD(opaque);

    size_t buf_offset = 0;



    while (size > 0 && s->parent.requests) {

        RngRequest *req = s->parent.requests->data;

        int len = MIN(size, req->size - req->offset);



        memcpy(req->data + req->offset, buf + buf_offset, len);

        buf_offset += len;

        req->offset += len;

        size -= len;



        if (req->offset == req->size) {

            s->parent.requests = g_slist_remove_link(s->parent.requests,

                                                     s->parent.requests);



            req->receive_entropy(req->opaque, req->data, req->size);



            rng_egd_free_request(req);

        }

    }

}
