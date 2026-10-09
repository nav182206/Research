/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2131
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=384acbf46b70edf0d2c1648aa1a92a90bcf7057d
 */

int qed_read_l1_table_sync(BDRVQEDState *s)

{

    int ret = -EINPROGRESS;



    async_context_push();



    qed_read_table(s, s->header.l1_table_offset,

                   s->l1_table, qed_sync_cb, &ret);

    while (ret == -EINPROGRESS) {

        qemu_aio_wait();

    }



    async_context_pop();



    return ret;

}
