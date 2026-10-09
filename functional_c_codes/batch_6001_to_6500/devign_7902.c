/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7902
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad5b88b1f198182642b6cbf3dacb4cade0c80fb9
 */

static void *acpi_add_rom_blob(AcpiBuildState *build_state, GArray *blob,

                               const char *name)

{

    return rom_add_blob(name, blob->data, acpi_data_len(blob), -1, name,

                        acpi_build_update, build_state);

}
