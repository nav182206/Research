/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8529
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=16a0d75c769a7df6f457b2200dbc9a7cc73798c6
 */

static int find_marker(const uint8_t **pbuf_ptr, const uint8_t *buf_end)

{

    const uint8_t *buf_ptr;

    unsigned int v, v2;

    int val;

    int skipped = 0;



    buf_ptr = *pbuf_ptr;

    while (buf_ptr < buf_end) {

        v  = *buf_ptr++;

        v2 = *buf_ptr;

        if ((v == 0xff) && (v2 >= 0xc0) && (v2 <= 0xfe) && buf_ptr < buf_end) {

            val = *buf_ptr++;

            goto found;

        }

        skipped++;

    }

    val = -1;

found:

    av_dlog(NULL, "find_marker skipped %d bytes\n", skipped);

    *pbuf_ptr = buf_ptr;

    return val;

}
