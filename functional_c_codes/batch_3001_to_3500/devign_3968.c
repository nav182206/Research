/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3968
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ca9567e23454ca94e3911710da4e953ad049b40f
 */

static void monitor_control_event(void *opaque, int event)

{

    if (event == CHR_EVENT_OPENED) {

        QObject *data;

        Monitor *mon = opaque;



        json_message_parser_init(&mon->mc->parser, handle_qmp_command);



        data = qobject_from_jsonf("{ 'QMP': { 'capabilities': [] } }");

        assert(data != NULL);



        monitor_json_emitter(mon, data);

        qobject_decref(data);

    }

}
