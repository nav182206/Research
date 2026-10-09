/* 
 * Benchmark Sample ID : devign_6635
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t cirrus_mmio_read(void *opaque, target_phys_addr_t addr,

                                 unsigned size)

{

    CirrusVGAState *s = opaque;



    if (addr >= 0x100) {

        return cirrus_mmio_blt_read(s, addr - 0x100);

    } else {

        return cirrus_vga_ioport_read(s, addr + 0x3c0);

    }

}
