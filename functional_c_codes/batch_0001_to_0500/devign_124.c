/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_124
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a32354e206895400d17c3de9a8df1de96d3df289
 */

static uint32_t m5206_mbar_readb(void *opaque, target_phys_addr_t offset)

{

    m5206_mbar_state *s = (m5206_mbar_state *)opaque;

    offset &= 0x3ff;

    if (offset > 0x200) {

        hw_error("Bad MBAR read offset 0x%x", (int)offset);

    }

    if (m5206_mbar_width[offset >> 2] > 1) {

        uint16_t val;

        val = m5206_mbar_readw(opaque, offset & ~1);

        if ((offset & 1) == 0) {

            val >>= 8;

        }

        return val & 0xff;

    }

    return m5206_mbar_read(s, offset, 1);

}
