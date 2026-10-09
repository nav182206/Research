/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8334
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a307d59434ba78b97544b42b8cfd24a1b62e39a6
 */

static void vty_receive(void *opaque, const uint8_t *buf, int size)

{

    VIOsPAPRVTYDevice *dev = (VIOsPAPRVTYDevice *)opaque;

    int i;



    if ((dev->in == dev->out) && size) {

        /* toggle line to simulate edge interrupt */

        qemu_irq_pulse(dev->sdev.qirq);

    }

    for (i = 0; i < size; i++) {

        assert((dev->in - dev->out) < VTERM_BUFSIZE);

        dev->buf[dev->in++ % VTERM_BUFSIZE] = buf[i];

    }

}
