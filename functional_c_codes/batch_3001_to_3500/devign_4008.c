/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4008
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cdb3081269347fd9271fd1b7a9df312e2953bdd9
 */

void memory_region_unregister_iommu_notifier(MemoryRegion *mr, Notifier *n)

{

    notifier_remove(n);

    if (mr->iommu_ops->notify_stopped &&

        QLIST_EMPTY(&mr->iommu_notify.notifiers)) {

        mr->iommu_ops->notify_stopped(mr);

    }

}
