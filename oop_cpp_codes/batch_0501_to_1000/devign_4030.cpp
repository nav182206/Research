/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4030
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fced4d00e68e7559c73746d963265f7fd0b6abf9
 */

static void gen_rp_realize(DeviceState *dev, Error **errp)

{

    PCIDevice *d = PCI_DEVICE(dev);

    GenPCIERootPort *grp = GEN_PCIE_ROOT_PORT(d);

    PCIERootPortClass *rpc = PCIE_ROOT_PORT_GET_CLASS(d);



    rpc->parent_realize(dev, errp);



    int rc = pci_bridge_qemu_reserve_cap_init(d, 0, grp->bus_reserve,

            grp->io_reserve, grp->mem_reserve, grp->pref32_reserve,

            grp->pref64_reserve, errp);



    if (rc < 0) {

        rpc->parent_class.exit(d);

        return;

    }



    if (!grp->io_reserve) {

        pci_word_test_and_clear_mask(d->wmask + PCI_COMMAND,

                                     PCI_COMMAND_IO);

        d->wmask[PCI_IO_BASE] = 0;

        d->wmask[PCI_IO_LIMIT] = 0;

    }

}
