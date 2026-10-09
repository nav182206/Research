/* 
 * Benchmark Sample ID : devign_9861
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=79218be42b835cbc7bd1b0fbd07d115add6e7605
 */

TraceEvent *trace_event_iter_next(TraceEventIter *iter)

{

    while (iter->event < TRACE_EVENT_COUNT) {

        TraceEvent *ev = &(trace_events[iter->event]);

        iter->event++;

        if (!iter->pattern ||

            pattern_glob(iter->pattern,

                         trace_event_get_name(ev))) {

            return ev;

        }

    }



    return NULL;

}
