/* 
 * Benchmark Sample ID : devign_8286
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=45eb768c706d3a5fbe55224c589e8b4e252781d9
 */

void pcie_port_init_reg(PCIDevice *d)

{

    /* Unlike pci bridge,

       66MHz and fast back to back don't apply to pci express port. */

    pci_set_word(d->config + PCI_STATUS, 0);

    pci_set_word(d->config + PCI_SEC_STATUS, 0);



    /* Unlike conventional pci bridge, some bits are hardwired to 0. */

#define  PCI_BRIDGE_CTL_VGA_16BIT       0x10    /* VGA 16-bit decode */

    pci_set_word(d->wmask + PCI_BRIDGE_CONTROL,

                 PCI_BRIDGE_CTL_PARITY |

                 PCI_BRIDGE_CTL_ISA |

                 PCI_BRIDGE_CTL_VGA |

                 PCI_BRIDGE_CTL_VGA_16BIT | /* Req, but no alias support yet */

                 PCI_BRIDGE_CTL_SERR |

                 PCI_BRIDGE_CTL_BUS_RESET);

}
