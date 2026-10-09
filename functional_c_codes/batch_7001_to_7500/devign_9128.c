/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9128
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=99684f3ae752fc8bfb44a2dd1482f8d7a3d8536d
 */

int avio_close(AVIOContext *s)

{

    AVIOInternal *internal;

    URLContext *h;



    if (!s)

        return 0;



    avio_flush(s);

    internal = s->opaque;

    h        = internal->h;



    av_opt_free(internal);



    av_freep(&internal->protocols);

    av_freep(&s->opaque);

    av_freep(&s->buffer);

    av_free(s);

    return ffurl_close(h);

}
