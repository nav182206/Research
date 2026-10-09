/* 
 * Benchmark Sample ID : devign_9175
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf7c0ff521b0710079aa28f21937fb7dbb3f5224
 */

static NVDIMMDevice *nvdimm_get_device_by_handle(uint32_t handle)

{

    NVDIMMDevice *nvdimm = NULL;

    GSList *list, *device_list = nvdimm_get_plugged_device_list();



    for (list = device_list; list; list = list->next) {

        NVDIMMDevice *nvd = list->data;

        int slot = object_property_get_int(OBJECT(nvd), PC_DIMM_SLOT_PROP,

                                           NULL);



        if (nvdimm_slot_to_handle(slot) == handle) {

            nvdimm = nvd;

            break;

        }

    }



    g_slist_free(device_list);

    return nvdimm;

}
