/* 
 * Benchmark Sample ID : devign_8413
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b12e4d3bb8df994f042ff1216fb8de2b967aab9e
 */

int ffio_close_null_buf(AVIOContext *s)

{

    DynBuffer *d = s->opaque;

    int size;



    avio_flush(s);



    size = d->size;

    av_free(d);

    av_free(s);

    return size;

}
