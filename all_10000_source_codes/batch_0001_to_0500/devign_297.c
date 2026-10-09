/* 
 * Benchmark Sample ID : devign_297
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=58a83c61496eeb0d31571a07a51bc1947e3379ac
 */

void virtqueue_discard(VirtQueue *vq, const VirtQueueElement *elem,

                       unsigned int len)

{

    vq->last_avail_idx--;


    virtqueue_unmap_sg(vq, elem, len);

}
