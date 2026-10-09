/* 
 * Benchmark Sample ID : devign_9138
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cb6d3ca07b8f62b47ef30c6a92caa3e8bd71248b
 */

static void multiwrite_cb(void *opaque, int ret)

{

    MultiwriteCB *mcb = opaque;



    if (ret < 0) {

        mcb->error = ret;

        multiwrite_user_cb(mcb);

    }



    mcb->num_requests--;

    if (mcb->num_requests == 0) {

        if (mcb->error == 0) {

            multiwrite_user_cb(mcb);

        }

        qemu_free(mcb);

    }

}
