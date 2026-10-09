/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4321
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bdcc3a28b7f6ed6b90ad8b8af7b5d17e0d3f1f06
 */

void qemu_input_event_send(QemuConsole *src, InputEvent *evt)

{

    QemuInputHandlerState *s;



    if (!runstate_is_running() && !runstate_check(RUN_STATE_SUSPENDED)) {





    qemu_input_event_trace(src, evt);



    /* pre processing */

    if (graphic_rotate && (evt->kind == INPUT_EVENT_KIND_ABS)) {

            qemu_input_transform_abs_rotate(evt);




    /* send event */

    s = qemu_input_find_handler(1 << evt->kind);




    s->handler->event(s->dev, src, evt);

    s->events++;
