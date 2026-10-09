/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7667
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6bdc21c050a2a7b92cbbd0b2a1f8934e9b5f896f
 */

void virtqueue_map(VirtIODevice *vdev, VirtQueueElement *elem)

{

    virtqueue_map_iovec(vdev, elem->in_sg, elem->in_addr, &elem->in_num,

                        MIN(ARRAY_SIZE(elem->in_sg), ARRAY_SIZE(elem->in_addr)),

                        1);

    virtqueue_map_iovec(vdev, elem->out_sg, elem->out_addr, &elem->out_num,

                        MIN(ARRAY_SIZE(elem->out_sg),

                        ARRAY_SIZE(elem->out_addr)),

                        0);

}
