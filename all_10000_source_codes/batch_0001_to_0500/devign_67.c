/* 
 * Benchmark Sample ID : devign_67
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2bd3bce8efebe86b031beab5c0e3b9bbaec0b502
 */

void bdrv_error_action(BlockDriverState *bs, BlockErrorAction action,

                       bool is_read, int error)

{

    assert(error >= 0);

    bdrv_emit_qmp_error_event(bs, QEVENT_BLOCK_IO_ERROR, action, is_read);

    if (action == BDRV_ACTION_STOP) {

        vm_stop(RUN_STATE_IO_ERROR);

        bdrv_iostatus_set_err(bs, error);

    }

}
