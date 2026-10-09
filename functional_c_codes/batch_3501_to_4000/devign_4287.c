/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4287
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bdfd065b1f75cacca21af0b8d4811c64cc48d04c
 */

void nvdimm_build_acpi(GArray *table_offsets, GArray *table_data,

                       BIOSLinker *linker, GArray *dsm_dma_arrea)

{

    GSList *device_list;



    /* no NVDIMM device is plugged. */

    device_list = nvdimm_get_plugged_device_list();

    if (!device_list) {

        return;

    }

    nvdimm_build_nfit(device_list, table_offsets, table_data, linker);

    nvdimm_build_ssdt(device_list, table_offsets, table_data, linker,

                      dsm_dma_arrea);

    g_slist_free(device_list);

}
