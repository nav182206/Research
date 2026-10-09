/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9451
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void vma_delete(struct mm_struct *mm)

{

    struct vm_area_struct *vma;



    while ((vma = vma_first(mm)) != NULL) {

        TAILQ_REMOVE(&mm->mm_mmap, vma, vma_link);

        qemu_free(vma);

    }

    qemu_free(mm);

}
