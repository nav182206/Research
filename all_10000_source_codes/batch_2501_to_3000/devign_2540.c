/* 
 * Benchmark Sample ID : devign_2540
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void nbd_restart_write(void *opaque)

{

    BlockDriverState *bs = opaque;



    qemu_coroutine_enter(nbd_get_client_session(bs)->send_coroutine, NULL);

}
