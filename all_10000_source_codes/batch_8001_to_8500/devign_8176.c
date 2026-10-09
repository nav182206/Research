/* 
 * Benchmark Sample ID : devign_8176
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af7e9e74c6a62a5bcd911726a9e88d28b61490e0
 */

static void openpic_irq_raise(OpenPICState *opp, int n_CPU, IRQ_src_t *src)

{

    int n_ci = IDR_CI0_SHIFT - n_CPU;



    if ((opp->flags & OPENPIC_FLAG_IDE_CRIT) && (src->ide & (1 << n_ci))) {

        qemu_irq_raise(opp->dst[n_CPU].irqs[OPENPIC_OUTPUT_CINT]);

    } else {

        qemu_irq_raise(opp->dst[n_CPU].irqs[OPENPIC_OUTPUT_INT]);

    }

}
