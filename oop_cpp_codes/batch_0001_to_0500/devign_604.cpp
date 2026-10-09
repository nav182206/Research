/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_604
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cea3a63ba3d89d8403eef008f7a7c54d645cff70
 */

static AVBufferRef *pool_alloc_buffer(AVBufferPool *pool)

{

    BufferPoolEntry *buf;

    AVBufferRef     *ret;



    ret = pool->alloc(pool->size);

    if (!ret)

        return NULL;



    buf = av_mallocz(sizeof(*buf));

    if (!buf) {

        av_buffer_unref(&ret);

        return NULL;

    }



    buf->data   = ret->buffer->data;

    buf->opaque = ret->buffer->opaque;

    buf->free   = ret->buffer->free;

    buf->pool   = pool;



    ret->buffer->opaque = buf;

    ret->buffer->free   = pool_release_buffer;



    avpriv_atomic_int_add_and_fetch(&pool->refcount, 1);




    return ret;

}
