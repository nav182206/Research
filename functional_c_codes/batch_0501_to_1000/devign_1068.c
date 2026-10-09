/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1068
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d5a8ee60a0fbc20a2c2d02f3bda1bb1bd365f1ee
 */

BlockDeviceInfoList *qmp_query_named_block_nodes(Error **errp)

{

    return bdrv_named_nodes_list();

}
