/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5953
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=51b19ebe4320f3dcd93cea71235c1219318ddfd2
 */

ssize_t virtio_pdu_vmarshal(V9fsPDU *pdu, size_t offset,

                            const char *fmt, va_list ap)

{

    V9fsState *s = pdu->s;

    V9fsVirtioState *v = container_of(s, V9fsVirtioState, state);

    VirtQueueElement *elem = &v->elems[pdu->idx];



    return v9fs_iov_vmarshal(elem->in_sg, elem->in_num, offset, 1, fmt, ap);

}
