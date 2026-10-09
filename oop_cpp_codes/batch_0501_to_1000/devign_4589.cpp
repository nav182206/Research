/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4589
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static ssize_t qemu_enqueue_packet_iov(VLANClientState *sender,

                                       const struct iovec *iov, int iovcnt,

                                       NetPacketSent *sent_cb)

{

    VLANPacket *packet;

    size_t max_len = 0;

    int i;



    max_len = calc_iov_length(iov, iovcnt);



    packet = qemu_malloc(sizeof(VLANPacket) + max_len);

    packet->sender = sender;

    packet->sent_cb = sent_cb;

    packet->size = 0;



    for (i = 0; i < iovcnt; i++) {

        size_t len = iov[i].iov_len;



        memcpy(packet->data + packet->size, iov[i].iov_base, len);

        packet->size += len;

    }



    TAILQ_INSERT_TAIL(&sender->vlan->send_queue, packet, entry);



    return packet->size;

}
