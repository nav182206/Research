/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_904
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37ad223c515da2fe9f1c679768cb5ccaa42e57e1
 */

build_fadt(GArray *table_data, GArray *linker, AcpiPmInfo *pm,

           unsigned facs, unsigned dsdt)

{

    AcpiFadtDescriptorRev1 *fadt = acpi_data_push(table_data, sizeof(*fadt));



    fadt->firmware_ctrl = cpu_to_le32(facs);

    /* FACS address to be filled by Guest linker */

    bios_linker_loader_add_pointer(linker, ACPI_BUILD_TABLE_FILE,

                                   ACPI_BUILD_TABLE_FILE,

                                   table_data, &fadt->firmware_ctrl,

                                   sizeof fadt->firmware_ctrl);



    fadt->dsdt = cpu_to_le32(dsdt);

    /* DSDT address to be filled by Guest linker */

    bios_linker_loader_add_pointer(linker, ACPI_BUILD_TABLE_FILE,

                                   ACPI_BUILD_TABLE_FILE,

                                   table_data, &fadt->dsdt,

                                   sizeof fadt->dsdt);



    fadt_setup(fadt, pm);



    build_header(linker, table_data,

                 (void *)fadt, "FACP", sizeof(*fadt), 1, NULL);

}
