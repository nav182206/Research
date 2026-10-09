/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4060
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ba5e6bfa1aee29a8f72c5538c565dfb9889cf273
 */

static void vfio_unmap_bars(VFIOPCIDevice *vdev)

{

    int i;



    for (i = 0; i < PCI_ROM_SLOT; i++) {

        vfio_unmap_bar(vdev, i);

    }



    if (vdev->has_vga) {

        vfio_vga_quirk_teardown(vdev);

        pci_unregister_vga(&vdev->pdev);

    }

}
