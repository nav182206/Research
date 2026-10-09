/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2401
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void bonito_pciconf_writel(void *opaque, target_phys_addr_t addr,

                                  uint64_t val, unsigned size)

{

    PCIBonitoState *s = opaque;

    PCIDevice *d = PCI_DEVICE(s);



    DPRINTF("bonito_pciconf_writel "TARGET_FMT_plx" val %x\n", addr, val);

    d->config_write(d, addr, val, 4);

}
