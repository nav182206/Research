/* 
 * Benchmark Sample ID : devign_8136
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a307d59434ba78b97544b42b8cfd24a1b62e39a6
 */

qemu_irq xics_assign_irq(struct icp_state *icp, int irq,

                         enum xics_irq_type type)

{

    if ((irq < icp->ics->offset)

        || (irq >= (icp->ics->offset + icp->ics->nr_irqs))) {

        return NULL;

    }



    assert((type == XICS_MSI) || (type == XICS_LSI));



    icp->ics->irqs[irq - icp->ics->offset].type = type;

    return icp->ics->qirqs[irq - icp->ics->offset];

}
