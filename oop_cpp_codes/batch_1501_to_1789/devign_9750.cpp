/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9750
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void blkreplay_bh_cb(void *opaque)

{

    Request *req = opaque;

    qemu_coroutine_enter(req->co, NULL);

    qemu_bh_delete(req->bh);

    g_free(req);

}
