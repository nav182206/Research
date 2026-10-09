/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4121
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=88266f5aa70fa71fd5cc20aa4dbeb7a7bd8d2e92
 */

void bdrv_io_limits_enable(BlockDriverState *bs)

{

    qemu_co_queue_init(&bs->throttled_reqs);

    bs->block_timer = qemu_new_timer_ns(vm_clock, bdrv_block_timer, bs);

    bs->io_limits_enabled = true;

}
