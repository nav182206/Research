/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1686
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static struct vm_area_struct *vma_first(const struct mm_struct *mm)

{

    return (TAILQ_FIRST(&mm->mm_mmap));

}
