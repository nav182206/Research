/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1614
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=635db18f68ded6abec11cd4cf64ebc15c1c6b190
 */

static void monitor_qmp_event(void *opaque, int event)

{

    QObject *data;

    Monitor *mon = opaque;



    switch (event) {

    case CHR_EVENT_OPENED:

        mon->qmp.in_command_mode = false;

        data = get_qmp_greeting();

        monitor_json_emitter(mon, data);

        qobject_decref(data);

        mon_refcount++;

        break;

    case CHR_EVENT_CLOSED:

        json_message_parser_destroy(&mon->qmp.parser);

        json_message_parser_init(&mon->qmp.parser, handle_qmp_command);

        mon_refcount--;

        monitor_fdsets_cleanup();

        break;

    }

}
