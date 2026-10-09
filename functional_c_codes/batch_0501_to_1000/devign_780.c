/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_780
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cb365646a942ed58aae053064b2048a415337ba2
 */

int64_t cpu_get_clock(void)

{

    int64_t ti;

    if (!timers_state.cpu_ticks_enabled) {

        return timers_state.cpu_clock_offset;

    } else {

        ti = get_clock();

        return ti + timers_state.cpu_clock_offset;

    }

}
