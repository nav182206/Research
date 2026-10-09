/* 
 * Benchmark Sample ID : devign_6908
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6c2a40742602c3cbe6a3905229dd539d7c311550
 */

void st_set_trace_file_enabled(bool enable)

{

    if (enable == !!trace_fp) {

        return; /* no change */

    }



    /* Halt trace writeout */

    flush_trace_file(true);

    trace_writeout_enabled = false;

    flush_trace_file(true);



    if (enable) {

        static const TraceRecord header = {

            .event = HEADER_EVENT_ID,

            .timestamp_ns = HEADER_MAGIC,

            .x1 = HEADER_VERSION,

        };



        trace_fp = fopen(trace_file_name, "w");

        if (!trace_fp) {

            return;

        }



        if (fwrite(&header, sizeof header, 1, trace_fp) != 1) {

            fclose(trace_fp);

            trace_fp = NULL;

            return;

        }



        /* Resume trace writeout */

        trace_writeout_enabled = true;

        flush_trace_file(false);

    } else {

        fclose(trace_fp);

        trace_fp = NULL;

    }

}
