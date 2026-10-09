/* 
 * Benchmark Sample ID : devign_6830
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b7a8bddac52bd05dddb28afd4dff92739946d3b
 */

static void *circular_buffer_task_tx( void *_URLContext)

{

    URLContext *h = _URLContext;

    UDPContext *s = h->priv_data;

    int old_cancelstate;



    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancelstate);



    for(;;) {

        int len;

        uint8_t tmp[4];



        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_cancelstate);



        av_usleep(s->packet_gap);



        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancelstate);



        pthread_mutex_lock(&s->mutex);



        len=av_fifo_size(s->fifo);



        while (len<4) {

            if (pthread_cond_wait(&s->cond, &s->mutex) < 0) {

                goto end;

            }

            len=av_fifo_size(s->fifo);

        }



        av_fifo_generic_peek(s->fifo, tmp, 4, NULL);

        len=AV_RL32(tmp);



        if (len>0 && av_fifo_size(s->fifo)>=len+4) {

            av_fifo_drain(s->fifo, 4); /* skip packet length */

            av_fifo_generic_read(s->fifo, h, len, do_udp_write); /* use function for write from fifo buffer */

            if (s->circular_buffer_error == len) {

                /* all ok - reset error */

                s->circular_buffer_error=0;

            }

        }



        pthread_mutex_unlock(&s->mutex);

    }



end:

    pthread_mutex_unlock(&s->mutex);

    return NULL;

}
