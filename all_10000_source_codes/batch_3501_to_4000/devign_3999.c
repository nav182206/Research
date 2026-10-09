/* 
 * Benchmark Sample ID : devign_3999
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1f7b4812eab992de46c98b3726745afb042a7f0
 */

static void virtio_rng_process(VirtIORNG *vrng)

{

    size_t size;



    if (!is_guest_ready(vrng)) {

        return;

    }



    size = get_request_size(vrng->vq);

    size = MIN(vrng->quota_remaining, size);

    if (size) {

        rng_backend_request_entropy(vrng->rng, size, chr_read, vrng);

    }

}
