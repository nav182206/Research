/* 
 * Benchmark Sample ID : devign_6528
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

const char *bdrv_get_node_name(const BlockDriverState *bs)

{

    return bs->node_name;

}
