/* 
 * Benchmark Sample ID : devign_8977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f186d64d8fda4bb22c15beb8e45b7814fbd8b51e
 */

void replay_read_events(int checkpoint)

{

    while (replay_data_kind == EVENT_ASYNC) {

        Event *event = replay_read_event(checkpoint);

        if (!event) {

            break;

        }

        replay_mutex_unlock();

        replay_run_event(event);

        replay_mutex_lock();



        g_free(event);

        replay_finish_event();

        read_event_kind = -1;

    }

}
