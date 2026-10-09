/* 
 * Benchmark Sample ID : devign_6514
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=640601c7cb1b6b41d3e1a435b986266c2b71e9bc
 */

vu_queue_fill(VuDev *dev, VuVirtq *vq,

              const VuVirtqElement *elem,

              unsigned int len, unsigned int idx)

{

    struct vring_used_elem uelem;



    if (unlikely(dev->broken)) {

        return;

    }



    vu_log_queue_fill(dev, vq, elem, len);



    idx = (idx + vq->used_idx) % vq->vring.num;



    uelem.id = elem->index;

    uelem.len = len;

    vring_used_write(dev, vq, &uelem, idx);

}
