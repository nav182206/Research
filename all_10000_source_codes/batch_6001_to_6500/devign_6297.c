/* 
 * Benchmark Sample ID : devign_6297
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

BlockDriverState *bdrv_next_node(BlockDriverState *bs)

{

    if (!bs) {

        return QTAILQ_FIRST(&graph_bdrv_states);

    }

    return QTAILQ_NEXT(bs, node_list);

}
