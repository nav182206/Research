/* 
 * Benchmark Sample ID : devign_5594
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e305a16510afa74eec20390479e349402e55ef4c
 */

void ide_init_ioport(IDEBus *bus, ISADevice *dev, int iobase, int iobase2)

{

    /* ??? Assume only ISA and PCI configurations, and that the PCI-ISA

       bridge has been setup properly to always register with ISA.  */

    isa_register_portio_list(dev, iobase, ide_portio_list, bus, "ide");



    if (iobase2) {

        isa_register_portio_list(dev, iobase2, ide_portio2_list, bus, "ide");

    }

}
