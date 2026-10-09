/* 
 * Benchmark Sample ID : devign_4818
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void nfs_co_generic_bh_cb(void *opaque)

{

    NFSRPC *task = opaque;

    task->complete = 1;

    qemu_bh_delete(task->bh);

    qemu_coroutine_enter(task->co, NULL);

}
