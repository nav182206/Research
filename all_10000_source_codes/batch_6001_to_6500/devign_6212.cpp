/* 
 * Benchmark Sample ID : devign_6212
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d5a8ee60a0fbc20a2c2d02f3bda1bb1bd365f1ee
 */

BlockDeviceInfoList *bdrv_named_nodes_list(void)

{

    BlockDeviceInfoList *list, *entry;

    BlockDriverState *bs;



    list = NULL;

    QTAILQ_FOREACH(bs, &graph_bdrv_states, node_list) {

        entry = g_malloc0(sizeof(*entry));

        entry->value = bdrv_block_device_info(bs);

        entry->next = list;

        list = entry;

    }



    return list;

}
