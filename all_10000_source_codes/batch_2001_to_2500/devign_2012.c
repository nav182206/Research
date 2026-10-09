/* 
 * Benchmark Sample ID : devign_2012
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=982263ce714ffcc4c7c41a7b255bd29e093912fe
 */

void replay_save_instructions(void)
{
    if (replay_file && replay_mode == REPLAY_MODE_RECORD) {
        replay_mutex_lock();
        int diff = (int)(replay_get_current_step() - replay_state.current_step);
        if (diff > 0) {
            replay_put_event(EVENT_INSTRUCTION);
            replay_put_dword(diff);
            replay_state.current_step += diff;
        }
        replay_mutex_unlock();
    }
}
