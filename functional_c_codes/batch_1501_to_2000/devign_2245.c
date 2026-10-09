/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void multiwrite_cb(void *opaque, int ret)

{

    MultiwriteCB *mcb = opaque;



    trace_multiwrite_cb(mcb, ret);



    if (ret < 0 && !mcb->error) {

        mcb->error = ret;

    }



    mcb->num_requests--;

    if (mcb->num_requests == 0) {

        multiwrite_user_cb(mcb);

        g_free(mcb);

    }

}
