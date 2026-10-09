/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2047
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8607f5c3072caeebbe0217df28651fffd3a79fd9
 */

void virtqueue_map(VirtQueueElement *elem)

{

    virtqueue_map_iovec(elem->in_sg, elem->in_addr, &elem->in_num,

                        VIRTQUEUE_MAX_SIZE, 1);

    virtqueue_map_iovec(elem->out_sg, elem->out_addr, &elem->out_num,

                        VIRTQUEUE_MAX_SIZE, 0);

}
