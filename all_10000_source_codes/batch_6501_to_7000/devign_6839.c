/* 
 * Benchmark Sample ID : devign_6839
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b54f3c0878a3acaa9142e4f24942e762d97e350
 */

static void GLZWDecodeInit(GifState * s, int csize)

{

    /* read buffer */

    s->eob_reached = 0;

    s->pbuf = s->buf;

    s->ebuf = s->buf;

    s->bbuf = 0;

    s->bbits = 0;



    /* decoder */

    s->codesize = csize;

    s->cursize = s->codesize + 1;

    s->curmask = mask[s->cursize];

    s->top_slot = 1 << s->cursize;

    s->clear_code = 1 << s->codesize;

    s->end_code = s->clear_code + 1;

    s->slot = s->newcodes = s->clear_code + 2;

    s->oc = s->fc = 0;

    s->sp = s->stack;

}
