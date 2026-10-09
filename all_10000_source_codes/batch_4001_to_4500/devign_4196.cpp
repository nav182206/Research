/* 
 * Benchmark Sample ID : devign_4196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d91ddd25e3a4e5008a2ac16127d51a34fd56bf1
 */

static void qemu_net_queue_append_iov(NetQueue *queue,

                                      NetClientState *sender,

                                      unsigned flags,

                                      const struct iovec *iov,

                                      int iovcnt,

                                      NetPacketSent *sent_cb)

{

    NetPacket *packet;

    size_t max_len = 0;

    int i;



    if (queue->nq_count >= queue->nq_maxlen && !sent_cb) {

        return; /* drop if queue full and no callback */

    }

    for (i = 0; i < iovcnt; i++) {

        max_len += iov[i].iov_len;

    }



    packet = g_malloc(sizeof(NetPacket) + max_len);

    packet->sender = sender;

    packet->sent_cb = sent_cb;

    packet->flags = flags;

    packet->size = 0;



    for (i = 0; i < iovcnt; i++) {

        size_t len = iov[i].iov_len;



        memcpy(packet->data + packet->size, iov[i].iov_base, len);

        packet->size += len;

    }




    QTAILQ_INSERT_TAIL(&queue->packets, packet, entry);

}
