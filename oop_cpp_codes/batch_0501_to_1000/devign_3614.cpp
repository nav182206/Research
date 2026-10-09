/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3614
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4d68e86bb10159099da0798f74e7512955f15eec
 */

static void __attribute__((destructor)) coroutine_pool_cleanup(void)

{

    Coroutine *co;

    Coroutine *tmp;



    QSLIST_FOREACH_SAFE(co, &pool, pool_next, tmp) {

        QSLIST_REMOVE_HEAD(&pool, pool_next);

        qemu_coroutine_delete(co);

    }



    qemu_mutex_destroy(&pool_lock);

}
