/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9899
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77b0359bf414ad666d1714dc9888f1017c08e283
 */

static void qemu_input_queue_process(void *opaque)

{

    struct QemuInputEventQueueHead *queue = opaque;

    QemuInputEventQueue *item;



    g_assert(!QTAILQ_EMPTY(queue));

    item = QTAILQ_FIRST(queue);

    g_assert(item->type == QEMU_INPUT_QUEUE_DELAY);

    QTAILQ_REMOVE(queue, item, node);


    g_free(item);



    while (!QTAILQ_EMPTY(queue)) {

        item = QTAILQ_FIRST(queue);

        switch (item->type) {

        case QEMU_INPUT_QUEUE_DELAY:

            timer_mod(item->timer, qemu_clock_get_ms(QEMU_CLOCK_VIRTUAL)

                      + item->delay_ms);

            return;

        case QEMU_INPUT_QUEUE_EVENT:

            qemu_input_event_send(item->src, item->evt);

            qapi_free_InputEvent(item->evt);

            break;

        case QEMU_INPUT_QUEUE_SYNC:

            qemu_input_event_sync();

            break;

        }

        QTAILQ_REMOVE(queue, item, node);


        g_free(item);

    }

}
