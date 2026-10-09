/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_356
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b7a8bddac52bd05dddb28afd4dff92739946d3b
 */

static int udp_close(URLContext *h)

{

    UDPContext *s = h->priv_data;



    if (s->is_multicast && (h->flags & AVIO_FLAG_READ))

        udp_leave_multicast_group(s->udp_fd, (struct sockaddr *)&s->dest_addr,(struct sockaddr *)&s->local_addr_storage);

    closesocket(s->udp_fd);

#if HAVE_PTHREAD_CANCEL

    if (s->thread_started) {

        int ret;

        pthread_cancel(s->circular_buffer_thread);

        ret = pthread_join(s->circular_buffer_thread, NULL);

        if (ret != 0)

            av_log(h, AV_LOG_ERROR, "pthread_join(): %s\n", strerror(ret));

        pthread_mutex_destroy(&s->mutex);

        pthread_cond_destroy(&s->cond);

    }

#endif

    av_fifo_freep(&s->fifo);

    return 0;

}
