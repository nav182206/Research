/* 
 * Benchmark Sample ID : devign_3345
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=134d42d614768b2803e551621f6654dab1fdc2d2
 */

static unsigned acpi_data_len(GArray *table)

{

#if GLIB_CHECK_VERSION(2, 14, 0)

    assert(g_array_get_element_size(table) == 1);

#endif

    return table->len;

}
