/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3575
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b2bedb214469af55179d907a60cd67fed6b0779e
 */

static void bonito_pciconf_writel(void *opaque, target_phys_addr_t addr,

                                  uint32_t val)

{

    PCIBonitoState *s = opaque;



    DPRINTF("bonito_pciconf_writel "TARGET_FMT_plx" val %x \n", addr, val);

    s->dev.config_write(&s->dev, addr, val, 4);

}
