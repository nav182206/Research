/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f8a83245d9ec685bc6aa6173d6765fe03e20688f
 */

static void multiwrite_user_cb(MultiwriteCB *mcb)

{

    int i;



    for (i = 0; i < mcb->num_callbacks; i++) {

        mcb->callbacks[i].cb(mcb->callbacks[i].opaque, mcb->error);

        qemu_free(mcb->callbacks[i].free_qiov);

        qemu_free(mcb->callbacks[i].free_buf);

    }

}
