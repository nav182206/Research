/* 
 * Benchmark Sample ID : devign_7497
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4d68e86bb10159099da0798f74e7512955f15eec
 */

static void coroutine_delete(Coroutine *co)

{

    if (CONFIG_COROUTINE_POOL) {

        qemu_mutex_lock(&pool_lock);

        if (pool_size < pool_max_size) {

            QSLIST_INSERT_HEAD(&pool, co, pool_next);

            co->caller = NULL;

            pool_size++;

            qemu_mutex_unlock(&pool_lock);

            return;

        }

        qemu_mutex_unlock(&pool_lock);

    }



    qemu_coroutine_delete(co);

}
