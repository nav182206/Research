/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8797
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

static AioContext *thread_pool_get_aio_context(BlockAIOCB *acb)

{

    ThreadPoolElement *elem = (ThreadPoolElement *)acb;

    ThreadPool *pool = elem->pool;

    return pool->ctx;

}
