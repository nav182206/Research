/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_774
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5b0ce5d4e3660fb0fc86779cbd027b47b1758c9f
 */

static void free_field_queue(PullupField *head, PullupField **last)

{

    PullupField *f = head;

    while (f) {

        av_free(f->diffs);

        av_free(f->combs);

        av_free(f->vars);

        if (f == *last) {

            av_freep(last);

            break;

        }

        f = f->next;

        av_freep(&f->prev);

    };

}
