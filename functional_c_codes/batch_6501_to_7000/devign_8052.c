/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c5619bf9e8935aeb972c0bd935549e9ee0a739f2
 */

int armv7m_nvic_acknowledge_irq(void *opaque)

{

    nvic_state *s = (nvic_state *)opaque;

    uint32_t irq;



    irq = gic_acknowledge_irq(&s->gic, 0);

    if (irq == 1023)

        hw_error("Interrupt but no vector\n");

    if (irq >= 32)

        irq -= 16;

    return irq;

}
