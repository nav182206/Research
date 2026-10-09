/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6057
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=48bf7ea81aa848027bad24f7e7791b503dff727d
 */

void blk_io_limits_disable(BlockBackend *blk)

{

    assert(blk->public.throttle_group_member.throttle_state);

    bdrv_drained_begin(blk_bs(blk));

    throttle_group_unregister_tgm(&blk->public.throttle_group_member);

    bdrv_drained_end(blk_bs(blk));

}
