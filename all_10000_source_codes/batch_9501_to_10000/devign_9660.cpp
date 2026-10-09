/* 
 * Benchmark Sample ID : devign_9660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37ad223c515da2fe9f1c679768cb5ccaa42e57e1
 */

build_tpm2(GArray *table_data, GArray *linker)

{

    Acpi20TPM2 *tpm2_ptr;



    tpm2_ptr = acpi_data_push(table_data, sizeof *tpm2_ptr);



    tpm2_ptr->platform_class = cpu_to_le16(TPM2_ACPI_CLASS_CLIENT);

    tpm2_ptr->control_area_address = cpu_to_le64(0);

    tpm2_ptr->start_method = cpu_to_le32(TPM2_START_METHOD_MMIO);



    build_header(linker, table_data,

                 (void *)tpm2_ptr, "TPM2", sizeof(*tpm2_ptr), 4, NULL);

}
