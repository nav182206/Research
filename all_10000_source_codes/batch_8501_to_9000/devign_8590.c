/* 
 * Benchmark Sample ID : devign_8590
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6fb2fd895e858ab93f46e656a322778ee181c307
 */

void avfilter_unref_buffer(AVFilterBufferRef *ref)

{

    if (!ref)

        return;

    av_assert0(ref->buf->refcount > 0);

    if (!(--ref->buf->refcount)) {

        if (!ref->buf->free) {

            store_in_pool(ref);

            return;

        }

        ref->buf->free(ref->buf);

    }

    if (ref->extended_data != ref->data)

        av_freep(&ref->extended_data);

    if (ref->video)

        av_freep(&ref->video->qp_table);

    av_freep(&ref->video);

    av_freep(&ref->audio);


    av_free(ref);

}
