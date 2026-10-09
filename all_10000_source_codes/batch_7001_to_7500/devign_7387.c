/* 
 * Benchmark Sample ID : devign_7387
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fa18f36a461984eae50ab957e47ec78dae3c14fc
 */

void qemu_input_event_send_key(QemuConsole *src, KeyValue *key, bool down)

{

    InputEvent *evt;

    evt = qemu_input_event_new_key(key, down);

    if (QTAILQ_EMPTY(&kbd_queue)) {

        qemu_input_event_send(src, evt);

        qemu_input_event_sync();

        qapi_free_InputEvent(evt);

    } else {

        qemu_input_queue_event(&kbd_queue, src, evt);

        qemu_input_queue_sync(&kbd_queue);

    }

}
