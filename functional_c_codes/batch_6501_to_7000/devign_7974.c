/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7974
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f448e415f364d0ec4c5556993e44ca183e31c5c
 */

static void unin_data_write(void *opaque, hwaddr addr,

                            uint64_t val, unsigned len)

{

    UNINState *s = opaque;

    PCIHostState *phb = PCI_HOST_BRIDGE(s);

    UNIN_DPRINTF("write addr %" TARGET_FMT_plx " len %d val %"PRIx64"\n",

                 addr, len, val);

    pci_data_write(phb->bus,

                   unin_get_config_reg(phb->config_reg, addr),

                   val, len);

}
