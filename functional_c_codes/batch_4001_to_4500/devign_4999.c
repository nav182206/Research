/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4999
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5b0ce5d4e3660fb0fc86779cbd027b47b1758c9f
 */

static PullupField *make_field_queue(PullupContext *s, int len)

{

    PullupField *head, *f;



    f = head = av_mallocz(sizeof(*head));

    if (!f)

        return NULL;



    if (alloc_metrics(s, f) < 0) {

        av_free(f);

        return NULL;

    }



    for (; len > 0; len--) {

        f->next = av_mallocz(sizeof(*f->next));

        if (!f->next) {

            free_field_queue(head, &f);

            return NULL;

        }



        f->next->prev = f;

        f = f->next;

        if (alloc_metrics(s, f) < 0) {

            free_field_queue(head, &f);

            return NULL;

        }

    }



    f->next = head;

    head->prev = f;



    return head;

}
