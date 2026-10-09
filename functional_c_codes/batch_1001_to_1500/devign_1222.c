/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1222
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5861a33898bbddfd1a80c2e202cb9352e3b1ba62
 */

static void mpic_irq_raise(openpic_t *mpp, int n_CPU, IRQ_src_t *src)

{

    int n_ci = IDR_CI0 - n_CPU;



    if(test_bit(&src->ide, n_ci)) {

        qemu_irq_raise(mpp->dst[n_CPU].irqs[OPENPIC_OUTPUT_CINT]);

    }

    else {

        qemu_irq_raise(mpp->dst[n_CPU].irqs[OPENPIC_OUTPUT_INT]);

    }

}
