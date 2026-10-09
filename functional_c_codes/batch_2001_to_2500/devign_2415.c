/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2415
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=75b0713e189a981e5bfd087d5f35705446bbb12a
 */

void nvdimm_build_acpi(GArray *table_offsets, GArray *table_data,

                       BIOSLinker *linker, GArray *dsm_dma_arrea,

                       uint32_t ram_slots)

{

    GSList *device_list;



    device_list = nvdimm_get_plugged_device_list();



    /* NVDIMM device is plugged. */

    if (device_list) {

        nvdimm_build_nfit(device_list, table_offsets, table_data, linker);

        g_slist_free(device_list);

    }



    /*

     * NVDIMM device is allowed to be plugged only if there is available

     * slot.

     */

    if (ram_slots) {

        nvdimm_build_ssdt(table_offsets, table_data, linker, dsm_dma_arrea,

                          ram_slots);

    }

}
