/* 
 * Benchmark Sample ID : devign_8466
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2f21b8d431030bcb7478ee9521bdfd3d0ef3901d
 */

static int trap_msix(S390PCIBusDevice *pbdev, uint64_t offset, uint8_t pcias)

{

    if (pbdev->msix.available && pbdev->msix.table_bar == pcias &&

        offset >= pbdev->msix.table_offset &&

        offset <= pbdev->msix.table_offset +

                  (pbdev->msix.entries - 1) * PCI_MSIX_ENTRY_SIZE) {

        return 1;

    } else {

        return 0;

    }

}
