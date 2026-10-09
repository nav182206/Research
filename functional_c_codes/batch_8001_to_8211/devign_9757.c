/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9757
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac369a77967d5dd984a5430505eaf24a380af1c0
 */

static inline void acpi_build_tables_cleanup(AcpiBuildTables *tables, bool mfre)

{

    void *linker_data = bios_linker_loader_cleanup(tables->linker);

    if (mfre) {

        g_free(linker_data);

    }

    g_array_free(tables->rsdp, mfre);

    g_array_free(tables->table_data, mfre);

    g_array_free(tables->tcpalog, mfre);

}
