/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7774
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=51fc44768a5b71ad78fa40e609a58f71ed62775a
 */

void qmp_input_send_event(int64_t console, InputEventList *events,

                          Error **errp)

{

    InputEventList *e;

    QemuConsole *con;



    con = qemu_console_lookup_by_index(console);

    if (!con) {

        error_setg(errp, "console %" PRId64 " not found", console);

        return;

    }



    if (!runstate_is_running() && !runstate_check(RUN_STATE_SUSPENDED)) {

        error_setg(errp, "VM not running");

        return;

    }



    for (e = events; e != NULL; e = e->next) {

        InputEvent *event = e->value;



        if (!qemu_input_find_handler(1 << event->kind, con)) {

            error_setg(errp, "Input handler not found for "

                             "event type %s",

                            InputEventKind_lookup[event->kind]);

            return;

        }

    }



    for (e = events; e != NULL; e = e->next) {

        InputEvent *event = e->value;



        qemu_input_event_send(con, event);

    }



    qemu_input_event_sync();

}
