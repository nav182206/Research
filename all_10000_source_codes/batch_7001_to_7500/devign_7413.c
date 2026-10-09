/* 
 * Benchmark Sample ID : devign_7413
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e9b9edae7bebfd31fdbead4ccbbce03876a7edd
 */

void nvdimm_build_acpi(GArray *table_offsets, GArray *table_data,

                       GArray *linker)

{

    GSList *device_list;



    /* no NVDIMM device is plugged. */

    device_list = nvdimm_get_plugged_device_list();

    if (!device_list) {

        return;

    }

    nvdimm_build_nfit(device_list, table_offsets, table_data, linker);

    nvdimm_build_ssdt(device_list, table_offsets, table_data, linker);

    g_slist_free(device_list);

}
