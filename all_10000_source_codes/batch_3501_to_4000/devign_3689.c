/* 
 * Benchmark Sample ID : devign_3689
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=88affa1c77c9019f3450f851495997897bd14e40
 */

void st_print_trace(FILE *stream, int (*stream_printf)(FILE *stream, const char *fmt, ...))

{

    unsigned int i;



    for (i = 0; i < TRACE_BUF_LEN; i++) {

        TraceRecord record;



        if (!get_trace_record(i, &record)) {

            continue;

        }

        stream_printf(stream, "Event %" PRIu64 " : %" PRIx64 " %" PRIx64

                      " %" PRIx64 " %" PRIx64 " %" PRIx64 " %" PRIx64 "\n",

                      record.event, record.x1, record.x2,

                      record.x3, record.x4, record.x5,

                      record.x6);

    }

}
