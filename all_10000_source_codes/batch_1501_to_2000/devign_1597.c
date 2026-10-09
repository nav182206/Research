/* 
 * Benchmark Sample ID : devign_1597
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b5538c300a56c3cfb33022840fe0b4968147e7a
 */

bool st_change_trace_event_state(const char *tname, bool tstate)

{

    TraceEvent *tp;



    tp = find_trace_event_by_name(tname);

    if (tp) {

        tp->state = tstate;

        return true;

    }

    return false;

}
