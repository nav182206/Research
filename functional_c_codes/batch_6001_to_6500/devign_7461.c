/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7461
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1945dbc15f0f1ffdc9a10526448e9eba7c599d98
 */

static void openpic_irq_raise(openpic_t *opp, int n_CPU, IRQ_src_t *src)

{

    int n_ci = IDR_CI0 - n_CPU;



    if ((opp->flags & OPENPIC_FLAG_IDE_CRIT) && test_bit(&src->ide, n_ci)) {

        qemu_irq_raise(opp->dst[n_CPU].irqs[OPENPIC_OUTPUT_CINT]);

    } else {

        qemu_irq_raise(opp->dst[n_CPU].irqs[OPENPIC_OUTPUT_INT]);

    }

}
