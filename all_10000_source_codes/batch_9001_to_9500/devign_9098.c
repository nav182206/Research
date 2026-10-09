/* 
 * Benchmark Sample ID : devign_9098
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

Aml *init_aml_allocator(void)

{

    Aml *var;



    assert(!alloc_list);

    alloc_list = g_ptr_array_new();

    var = aml_alloc();

    return var;

}
