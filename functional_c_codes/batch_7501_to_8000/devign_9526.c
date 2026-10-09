/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9526
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c6bf8e0e0cf04b40a8a22426e00ebbd727331d8b
 */

static ram_addr_t ram_save_remaining(void)

{

    return ram_list.dirty_pages;

}
