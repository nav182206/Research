/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7750
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=26572b8a0e90ee0c77587173a78fa293a1d2beb6
 */

void vga_hw_invalidate(void)

{

    if (active_console->hw_invalidate)

        active_console->hw_invalidate(active_console->hw);

}
