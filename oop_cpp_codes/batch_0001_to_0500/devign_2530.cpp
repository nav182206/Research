/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2530
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98f343395e937fa1db3a28dfb4f303f97cfddd6c
 */

static void packet_id_queue_add(struct PacketIdQueue *q, uint64_t id)

{

    USBRedirDevice *dev = q->dev;

    struct PacketIdQueueEntry *e;



    DPRINTF("adding packet id %"PRIu64" to %s queue\n", id, q->name);



    e = g_malloc0(sizeof(struct PacketIdQueueEntry));

    e->id = id;

    QTAILQ_INSERT_TAIL(&q->head, e, next);

    q->size++;

}
