/* 
 * Benchmark Sample ID : devign_737
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42bb9c9178ae7ac4c439172b1ae99cc29188a5c6
 */

static void stream_desc_load(struct Stream *s, hwaddr addr)

{

    struct SDesc *d = &s->desc;

    int i;



    cpu_physical_memory_read(addr, (void *) d, sizeof *d);



    /* Convert from LE into host endianness.  */

    d->buffer_address = le64_to_cpu(d->buffer_address);

    d->nxtdesc = le64_to_cpu(d->nxtdesc);

    d->control = le32_to_cpu(d->control);

    d->status = le32_to_cpu(d->status);

    for (i = 0; i < ARRAY_SIZE(d->app); i++) {

        d->app[i] = le32_to_cpu(d->app[i]);

    }

}
