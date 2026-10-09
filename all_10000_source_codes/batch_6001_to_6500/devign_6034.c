/* 
 * Benchmark Sample ID : devign_6034
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e9b9edae7bebfd31fdbead4ccbbce03876a7edd
 */

build_facs(GArray *table_data, GArray *linker)

{

    AcpiFacsDescriptorRev1 *facs = acpi_data_push(table_data, sizeof *facs);

    memcpy(&facs->signature, "FACS", 4);

    facs->length = cpu_to_le32(sizeof(*facs));

}
