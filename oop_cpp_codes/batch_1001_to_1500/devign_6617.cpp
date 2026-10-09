/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6617
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b84c4586234b26ccc875595713f6f4491e5b3385
 */

Coroutine *qemu_coroutine_create(CoroutineEntry *entry)

{

    Coroutine *co;



    co = QSLIST_FIRST(&pool);

    if (co) {

        QSLIST_REMOVE_HEAD(&pool, pool_next);

        pool_size--;

    } else {

        co = qemu_coroutine_new();

    }



    co->entry = entry;

    return co;

}
