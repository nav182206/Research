/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7671
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b84c4586234b26ccc875595713f6f4491e5b3385
 */

static void __attribute__((destructor)) coroutine_cleanup(void)

{

    Coroutine *co;

    Coroutine *tmp;



    QSLIST_FOREACH_SAFE(co, &pool, pool_next, tmp) {

        QSLIST_REMOVE_HEAD(&pool, pool_next);

        qemu_coroutine_delete(co);

    }

}
