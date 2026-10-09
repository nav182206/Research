/* 
 * Benchmark Sample ID : devign_3772
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b5538c300a56c3cfb33022840fe0b4968147e7a
 */

static void trace(TraceEventID event, uint64_t x1, uint64_t x2, uint64_t x3,

                  uint64_t x4, uint64_t x5, uint64_t x6)

{

    TraceRecord *rec = &trace_buf[trace_idx];



    if (!trace_list[event].state) {

        return;

    }



    rec->event = event;

    rec->timestamp_ns = get_clock();

    rec->x1 = x1;

    rec->x2 = x2;

    rec->x3 = x3;

    rec->x4 = x4;

    rec->x5 = x5;

    rec->x6 = x6;



    if (++trace_idx == TRACE_BUF_LEN) {

        st_flush_trace_buffer();

    }

}
