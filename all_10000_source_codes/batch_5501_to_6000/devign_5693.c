/* 
 * Benchmark Sample ID : devign_5693
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a354bd935a800dd2d98ac8f30707e2912c80ae6
 */

static void replay_save_event(Event *event, int checkpoint)

{

    if (replay_mode != REPLAY_MODE_PLAY) {

        /* put the event into the file */

        replay_put_event(EVENT_ASYNC);

        replay_put_byte(checkpoint);

        replay_put_byte(event->event_kind);



        /* save event-specific data */

        switch (event->event_kind) {

        default:

            error_report("Unknown ID %d of replay event", read_event_kind);

            exit(1);

            break;

        }

    }

}
