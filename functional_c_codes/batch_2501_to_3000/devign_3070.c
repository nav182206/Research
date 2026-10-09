/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3070
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static void numa_stat_memory_devices(uint64_t node_mem[])

{

    MemoryDeviceInfoList *info_list = NULL;

    MemoryDeviceInfoList **prev = &info_list;

    MemoryDeviceInfoList *info;



    qmp_pc_dimm_device_list(qdev_get_machine(), &prev);

    for (info = info_list; info; info = info->next) {

        MemoryDeviceInfo *value = info->value;



        if (value) {

            switch (value->type) {

            case MEMORY_DEVICE_INFO_KIND_DIMM:

                node_mem[value->u.dimm->node] += value->u.dimm->size;

                break;

            default:

                break;

            }

        }

    }

    qapi_free_MemoryDeviceInfoList(info_list);

}
