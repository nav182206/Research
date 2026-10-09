/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1797
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ba5e6bfa1aee29a8f72c5538c565dfb9889cf273
 */

static void vfio_unmap_bar(VFIOPCIDevice *vdev, int nr)

{

    VFIOBAR *bar = &vdev->bars[nr];



    if (!bar->region.size) {

        return;

    }



    vfio_bar_quirk_teardown(vdev, nr);



    memory_region_del_subregion(&bar->region.mem, &bar->region.mmap_mem);

    munmap(bar->region.mmap, memory_region_size(&bar->region.mmap_mem));



    if (vdev->msix && vdev->msix->table_bar == nr) {

        memory_region_del_subregion(&bar->region.mem, &vdev->msix->mmap_mem);

        munmap(vdev->msix->mmap, memory_region_size(&vdev->msix->mmap_mem));

    }

}
