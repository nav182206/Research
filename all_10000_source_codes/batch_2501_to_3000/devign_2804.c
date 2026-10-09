/* 
 * Benchmark Sample ID : devign_2804
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a32354e206895400d17c3de9a8df1de96d3df289
 */

static uint32_t m5206_mbar_readw(void *opaque, target_phys_addr_t offset)

{

    m5206_mbar_state *s = (m5206_mbar_state *)opaque;

    int width;

    offset &= 0x3ff;

    if (offset > 0x200) {

        hw_error("Bad MBAR read offset 0x%x", (int)offset);

    }

    width = m5206_mbar_width[offset >> 2];

    if (width > 2) {

        uint32_t val;

        val = m5206_mbar_readl(opaque, offset & ~3);

        if ((offset & 3) == 0)

            val >>= 16;

        return val & 0xffff;

    } else if (width < 2) {

        uint16_t val;

        val = m5206_mbar_readb(opaque, offset) << 8;

        val |= m5206_mbar_readb(opaque, offset + 1);

        return val;

    }

    return m5206_mbar_read(s, offset, 2);

}
