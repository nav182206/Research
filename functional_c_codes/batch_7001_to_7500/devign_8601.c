/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8601
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

BlockDriverState *bdrv_find_node(const char *node_name)

{

    BlockDriverState *bs;



    assert(node_name);



    QTAILQ_FOREACH(bs, &graph_bdrv_states, node_list) {

        if (!strcmp(node_name, bs->node_name)) {

            return bs;

        }

    }

    return NULL;

}
