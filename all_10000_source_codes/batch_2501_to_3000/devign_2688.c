/* 
 * Benchmark Sample ID : devign_2688
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6bc03a695bc4c1ecd212263c4a3c9cf638d025e0
 */

static int dyn_buf_write(void *opaque, uint8_t *buf, int buf_size)

{

    DynBuffer *d = opaque;

    int new_size, new_allocated_size;



    /* reallocate buffer if needed */

    new_size = d->pos + buf_size;

    new_allocated_size = d->allocated_size;

    if(new_size < d->pos || new_size > INT_MAX/2)

        return -1;

    while (new_size > new_allocated_size) {

        if (!new_allocated_size)

            new_allocated_size = new_size;

        else

            new_allocated_size += new_allocated_size / 2 + 1;

    }



    if (new_allocated_size > d->allocated_size) {

        d->buffer = av_realloc(d->buffer, new_allocated_size);

        if(d->buffer == NULL)

             return -1234;

        d->allocated_size = new_allocated_size;

    }

    memcpy(d->buffer + d->pos, buf, buf_size);

    d->pos = new_size;

    if (d->pos > d->size)

        d->size = d->pos;

    return buf_size;

}
