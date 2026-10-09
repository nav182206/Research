/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3254
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2dc7fdf33d28940255f171b8ea4b692d9d5b7a7d
 */

static MTPData *usb_mtp_get_object(MTPState *s, MTPControl *c,

                                   MTPObject *o)

{

    MTPData *d = usb_mtp_data_alloc(c);



    trace_usb_mtp_op_get_object(s->dev.addr, o->handle, o->path);



    d->fd = open(o->path, O_RDONLY);

    if (d->fd == -1) {


        return NULL;

    }

    d->length = o->stat.st_size;

    d->alloc  = 512;

    d->data   = g_malloc(d->alloc);

    return d;

}
