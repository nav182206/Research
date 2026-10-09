/* 
 * Benchmark Sample ID : devign_7481
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a80bf99fa3dd829ecea88b9bfb4f7cf146208f07
 */

static void mux_chr_read(void *opaque, const uint8_t *buf, int size)

{

    CharDriverState *chr = opaque;

    MuxDriver *d = chr->opaque;

    int m = chr->focus;

    int i;



    mux_chr_accept_input (opaque);



    for(i = 0; i < size; i++)

        if (mux_proc_byte(chr, d, buf[i])) {

            if (d->prod == d->cons &&

                d->chr_can_read[m] &&

                d->chr_can_read[m](d->ext_opaque[m]))

                d->chr_read[m](d->ext_opaque[m], &buf[i], 1);

            else

                d->buffer[d->prod++ & MUX_BUFFER_MASK] = buf[i];

        }

}
