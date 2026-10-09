/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7624
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b5538c300a56c3cfb33022840fe0b4968147e7a
 */

static bool write_header(FILE *fp)

{

    static const TraceRecord header = {

        .event = HEADER_EVENT_ID,

        .timestamp_ns = HEADER_MAGIC,

        .x1 = HEADER_VERSION,

    };



    return fwrite(&header, sizeof header, 1, fp) == 1;

}
