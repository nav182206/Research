/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2133
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

BlockDeviceInfoList *bdrv_named_nodes_list(Error **errp)

{

    BlockDeviceInfoList *list, *entry;

    BlockDriverState *bs;



    list = NULL;

    QTAILQ_FOREACH(bs, &graph_bdrv_states, node_list) {

        BlockDeviceInfo *info = bdrv_block_device_info(bs, errp);

        if (!info) {

            qapi_free_BlockDeviceInfoList(list);

            return NULL;

        }

        entry = g_malloc0(sizeof(*entry));

        entry->value = info;

        entry->next = list;

        list = entry;

    }



    return list;

}
