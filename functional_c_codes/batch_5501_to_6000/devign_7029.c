/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7029
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=465e1dadbef7596a3eb87089a66bb4ecdc26d3c4
 */

static int bytes_left(ByteIOContext *bc)

{

    return bc->buf_end - bc->buf_ptr;

}
