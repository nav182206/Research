/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7163
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d91ddd25e3a4e5008a2ac16127d51a34fd56bf1
 */

bool qemu_net_queue_flush(NetQueue *queue)

{

    while (!QTAILQ_EMPTY(&queue->packets)) {

        NetPacket *packet;

        int ret;



        packet = QTAILQ_FIRST(&queue->packets);

        QTAILQ_REMOVE(&queue->packets, packet, entry);




        ret = qemu_net_queue_deliver(queue,

                                     packet->sender,

                                     packet->flags,

                                     packet->data,

                                     packet->size);

        if (ret == 0) {

            queue->nq_count++;

            QTAILQ_INSERT_HEAD(&queue->packets, packet, entry);

            return false;

        }



        if (packet->sent_cb) {

            packet->sent_cb(packet->sender, ret);

        }



        g_free(packet);

    }

    return true;

}
