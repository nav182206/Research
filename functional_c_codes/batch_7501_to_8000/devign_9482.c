/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9482
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=03cef34aa66662e2ab3681d290e7c5a6634f4058
 */

static void qsv_uninit(AVCodecContext *s)

{

    InputStream *ist = s->opaque;

    QSVContext  *qsv = ist->hwaccel_ctx;



    av_freep(&qsv->ost->enc_ctx->hwaccel_context);

    av_freep(&s->hwaccel_context);



    av_buffer_unref(&qsv->opaque_surfaces_buf);

    av_freep(&qsv->surface_used);

    av_freep(&qsv->surface_ptrs);



    av_freep(&qsv);

}
