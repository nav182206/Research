/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7197
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2a176dfda32f5cf80703c2921a19fe75850c38c
 */

static void taihu_cpld_writel (void *opaque,

                               hwaddr addr, uint32_t value)

{

    taihu_cpld_writel(opaque, addr, (value >> 24) & 0xFF);

    taihu_cpld_writel(opaque, addr + 1, (value >> 16) & 0xFF);

    taihu_cpld_writel(opaque, addr + 2, (value >> 8) & 0xFF);

    taihu_cpld_writeb(opaque, addr + 3, value & 0xFF);

}
