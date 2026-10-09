/* 
 * Benchmark Sample ID : devign_2044
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42bb9c9178ae7ac4c439172b1ae99cc29188a5c6
 */

static void stream_desc_store(struct Stream *s, hwaddr addr)

{

    struct SDesc *d = &s->desc;

    int i;



    /* Convert from host endianness into LE.  */

    d->buffer_address = cpu_to_le64(d->buffer_address);

    d->nxtdesc = cpu_to_le64(d->nxtdesc);

    d->control = cpu_to_le32(d->control);

    d->status = cpu_to_le32(d->status);

    for (i = 0; i < ARRAY_SIZE(d->app); i++) {

        d->app[i] = cpu_to_le32(d->app[i]);

    }

    cpu_physical_memory_write(addr, (void *) d, sizeof *d);

}
