/* 
 * Benchmark Sample ID : devign_4989
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=802f045a5f61b781df55e4492d896b4d20503ba7
 */

void replay_shutdown_request(void)

{

    if (replay_mode == REPLAY_MODE_RECORD) {

        replay_mutex_lock();

        replay_put_event(EVENT_SHUTDOWN);

        replay_mutex_unlock();

    }

}
