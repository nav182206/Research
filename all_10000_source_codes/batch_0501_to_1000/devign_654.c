/* 
 * Benchmark Sample ID : devign_654
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

ThreadPool *thread_pool_new(AioContext *ctx)

{

    ThreadPool *pool = g_new(ThreadPool, 1);

    thread_pool_init_one(pool, ctx);

    return pool;

}
