/* 
 * Benchmark Sample ID : devign_6859
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c6303f8d70c25dd6c6e6486c78bf99c9924e2b6b
 */

static void yop_next_macroblock(YopDecContext *s)

{

    // If we are advancing to the next row of macroblocks

    if (s->row_pos == s->frame.linesize[0] - 2) {

        s->dstptr  += s->frame.linesize[0];

        s->row_pos =  0;

    }else {

        s->row_pos += 2;

    }

    s->dstptr += 2;

}
