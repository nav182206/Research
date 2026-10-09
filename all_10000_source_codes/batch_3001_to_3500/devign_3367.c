/* 
 * Benchmark Sample ID : devign_3367
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a83000f5e3fac30a7f213af1ba6a8f827622854d
 */

static void spapr_phb_reset(DeviceState *qdev)

{

    SysBusDevice *s = SYS_BUS_DEVICE(qdev);

    sPAPRPHBState *sphb = SPAPR_PCI_HOST_BRIDGE(s);



    /* Reset the IOMMU state */

    spapr_tce_reset(sphb->tcet);

}
