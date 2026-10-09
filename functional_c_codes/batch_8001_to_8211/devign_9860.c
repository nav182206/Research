/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9860
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5839e53bbc0fec56021d758aab7610df421ed8c8
 */

void bdrv_op_block(BlockDriverState *bs, BlockOpType op, Error *reason)

{

    BdrvOpBlocker *blocker;

    assert((int) op >= 0 && op < BLOCK_OP_TYPE_MAX);



    blocker = g_malloc0(sizeof(BdrvOpBlocker));

    blocker->reason = reason;

    QLIST_INSERT_HEAD(&bs->op_blockers[op], blocker, list);

}
