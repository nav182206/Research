/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2272
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f186d64d8fda4bb22c15beb8e45b7814fbd8b51e
 */

void replay_read_next_clock(ReplayClockKind kind)

{

    unsigned int read_kind = replay_data_kind - EVENT_CLOCK;



    assert(read_kind == kind);



    int64_t clock = replay_get_qword();



    replay_check_error();

    replay_finish_event();



    replay_state.cached_clock[read_kind] = clock;

}
