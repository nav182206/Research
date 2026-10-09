/* 
 * Benchmark Sample ID : devign_8729
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac43fa508cc1cfe6d6f67c8eb99dc012e52c164e
 */

static uint64_t pci_host_data_read(void *opaque,

                                   hwaddr addr, unsigned len)

{

    PCIHostState *s = opaque;

    uint32_t val;

    if (!(s->config_reg & (1 << 31)))

        return 0xffffffff;

    val = pci_data_read(s->bus, s->config_reg | (addr & 3), len);

    PCI_DPRINTF("read addr " TARGET_FMT_plx " len %d val %x\n",

                addr, len, val);

    return val;

}
