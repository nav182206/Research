/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8688
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ef2b64f04c7269fe59dab0491784e06ade7892ca
 */

int avcodec_close(AVCodecContext *avctx)

{

    entangled_thread_counter++;

    if(entangled_thread_counter != 1){

        av_log(avctx, AV_LOG_ERROR, "insufficient thread locking around avcodec_open/close()\n");

        entangled_thread_counter--;

        return -1;

    }



    if (ENABLE_THREADS && avctx->thread_opaque)

        avcodec_thread_free(avctx);

    if (avctx->codec->close)

        avctx->codec->close(avctx);

    avcodec_default_free_buffers(avctx);

    av_freep(&avctx->priv_data);


    avctx->codec = NULL;

    entangled_thread_counter--;

    return 0;

}
