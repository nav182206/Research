/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9023
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e4f910c8d490a1490409a7e381dbbb229f9d272
 */

static uint32_t ehci_mem_readl(void *ptr, target_phys_addr_t addr)

{

    EHCIState *s = ptr;

    uint32_t val;



    val = s->mmio[addr] | (s->mmio[addr+1] << 8) |

          (s->mmio[addr+2] << 16) | (s->mmio[addr+3] << 24);



    trace_usb_ehci_mmio_readl(addr, addr2str(addr), val);

    return val;

}
