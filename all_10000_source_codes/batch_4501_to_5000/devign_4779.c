/* 
 * Benchmark Sample ID : devign_4779
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f0317cfc8da620cdb38cb5cfec5f82b8dd05403
 */

static BlockJob *test_block_job_start(unsigned int iterations,

                                      bool use_timer,

                                      int rc, int *result)

{

    BlockDriverState *bs;

    TestBlockJob *s;

    TestBlockJobCBData *data;



    data = g_new0(TestBlockJobCBData, 1);

    bs = bdrv_new();

    s = block_job_create(&test_block_job_driver, bs, 0, test_block_job_cb,

                         data, &error_abort);

    s->iterations = iterations;

    s->use_timer = use_timer;

    s->rc = rc;

    s->result = result;

    s->common.co = qemu_coroutine_create(test_block_job_run);

    data->job = s;

    data->result = result;

    qemu_coroutine_enter(s->common.co, s);

    return &s->common;

}
