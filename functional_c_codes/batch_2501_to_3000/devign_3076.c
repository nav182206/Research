/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3076
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2e2aa31674444b61e79536a90d63a90572e695c8
 */

static void mptsas_update_interrupt(MPTSASState *s)

{

    PCIDevice *pci = (PCIDevice *) s;

    uint32_t state = s->intr_status & ~(s->intr_mask | MPI_HIS_IOP_DOORBELL_STATUS);



    if (s->msi_in_use && msi_enabled(pci)) {

        if (state) {

            trace_mptsas_irq_msi(s);

            msi_notify(pci, 0);

        }

    }



    trace_mptsas_irq_intx(s, !!state);

    pci_set_irq(pci, !!state);

}
