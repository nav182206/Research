/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_650
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9429b84af2302b6e28bec3c52710cf67eda3cee
 */

static void amdvi_mmio_trace(hwaddr addr, unsigned size)

{

    uint8_t index = (addr & ~0x2000) / 8;



    if ((addr & 0x2000)) {

        /* high table */

        index = index >= AMDVI_MMIO_REGS_HIGH ? AMDVI_MMIO_REGS_HIGH : index;

        trace_amdvi_mmio_read(amdvi_mmio_high[index], addr, size, addr & ~0x07);

    } else {

        index = index >= AMDVI_MMIO_REGS_LOW ? AMDVI_MMIO_REGS_LOW : index;

        trace_amdvi_mmio_read(amdvi_mmio_high[index], addr, size, addr & ~0x07);

    }

}
