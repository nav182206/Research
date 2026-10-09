/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2010
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f5ed36635d8fa73feb66fe12b3b9c2ed90a1adbe
 */

void virtqueue_fill(VirtQueue *vq, const VirtQueueElement *elem,
                    unsigned int len, unsigned int idx)
{
    VRingUsedElem uelem;
    trace_virtqueue_fill(vq, elem, len, idx);
    virtqueue_unmap_sg(vq, elem, len);
    idx = (idx + vq->used_idx) % vq->vring.num;
    uelem.id = elem->index;
    uelem.len = len;
    vring_used_write(vq, &uelem, idx);
