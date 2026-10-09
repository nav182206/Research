/* 
 * Benchmark Sample ID : devign_444
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=67d5cd9722b230027d3d4267ae6069c5d8a65463
 */

void s390_pci_iommu_enable(S390PCIBusDevice *pbdev)

{

    memory_region_init_iommu(&pbdev->iommu_mr, OBJECT(&pbdev->mr),

                             &s390_iommu_ops, "iommu-s390", pbdev->pal + 1);

    memory_region_add_subregion(&pbdev->mr, 0, &pbdev->iommu_mr);

    pbdev->iommu_enabled = true;

}
