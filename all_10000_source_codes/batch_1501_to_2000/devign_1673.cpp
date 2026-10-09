/* 
 * Benchmark Sample ID : devign_1673
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=318347234d7069b62d38391dd27e269a3107d668
 */

static void spapr_phb_remove_pci_device(sPAPRDRConnector *drc,

                                        sPAPRPHBState *phb,

                                        PCIDevice *pdev,

                                        Error **errp)

{

    sPAPRDRConnectorClass *drck = SPAPR_DR_CONNECTOR_GET_CLASS(drc);



    drck->detach(drc, DEVICE(pdev), spapr_phb_remove_pci_device_cb, phb, errp);

}
