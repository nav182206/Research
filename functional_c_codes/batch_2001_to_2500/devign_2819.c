/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2819
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e70377dfa4bbc2e101066ca35675bed4129c5a8c
 */

S390PCIBusDevice *s390_pci_find_dev_by_fid(uint32_t fid)

{

    S390PCIBusDevice *pbdev;

    int i;

    S390pciState *s = s390_get_phb();



    for (i = 0; i < PCI_SLOT_MAX; i++) {

        pbdev = s->pbdev[i];

        if (pbdev && pbdev->fid == fid) {

            return pbdev;

        }

    }



    return NULL;

}
