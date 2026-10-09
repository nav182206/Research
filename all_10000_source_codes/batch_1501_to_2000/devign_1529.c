/* 
 * Benchmark Sample ID : devign_1529
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=220b24c7c97dc033ceab1510549f66d0e7b52ef1
 */

void *ff_schro_queue_pop(FFSchroQueue *queue)

{

    FFSchroQueueElement *top = queue->p_head;



    if (top) {

        void *data = top->data;

        queue->p_head = queue->p_head->next;

        --queue->size;

        av_freep(&top);

        return data;

    }



    return NULL;

}
