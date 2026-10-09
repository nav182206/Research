/* 
 * Benchmark Sample ID : devign_3396
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=70df51112ccc8d281cdb96141f20b3fd8a5b11f8
 */

static void cqueue_free(cqueue *q)

{

    av_free(q->elements);

    av_free(q);

}
