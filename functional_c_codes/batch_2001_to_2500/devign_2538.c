/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2538
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a821ce59338c79bb72dc844dd44ea53701965b2b
 */

static int virtqueue_num_heads(VirtQueue *vq, unsigned int idx)

{

    uint16_t num_heads = vring_avail_idx(vq) - idx;



    /* Check it isn't doing very strange things with descriptor numbers. */

    if (num_heads > vq->vring.num) {

        error_report("Guest moved used index from %u to %u",

                     idx, vring_avail_idx(vq));

        exit(1);









    return num_heads;
