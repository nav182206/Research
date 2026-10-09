/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6342
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fbd6c97f9ca858140df16dd07200ea0d4bdc1a83
 */

static void pool_release_buffer(void *opaque, uint8_t *data)

{

    BufferPoolEntry *buf = opaque;

    AVBufferPool *pool = buf->pool;

    add_to_pool(buf);

    if (!avpriv_atomic_int_add_and_fetch(&pool->refcount, -1))

        buffer_pool_free(pool);

}
