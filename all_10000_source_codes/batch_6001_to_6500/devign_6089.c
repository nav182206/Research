/* 
 * Benchmark Sample ID : devign_6089
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

static void nbd_restart_write(void *opaque)

{

    NbdClientSession *s = opaque;



    qemu_coroutine_enter(s->send_coroutine, NULL);

}
