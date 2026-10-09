/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2508
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42d859001d180ea788aa2d34a7be021ac8c447f2
 */

static void acpi_build_update(void *build_opaque, uint32_t offset)

{

    AcpiBuildState *build_state = build_opaque;

    AcpiBuildTables tables;



    /* No state to update or already patched? Nothing to do. */

    if (!build_state || build_state->patched) {

        return;

    }

    build_state->patched = 1;



    acpi_build_tables_init(&tables);



    acpi_build(build_state->guest_info, &tables);



    assert(acpi_data_len(tables.table_data) == build_state->table_size);



    /* Make sure RAM size is correct - in case it got changed by migration */

    qemu_ram_resize(build_state->table_ram, build_state->table_size,

                    &error_abort);



    memcpy(qemu_get_ram_ptr(build_state->table_ram), tables.table_data->data,

           build_state->table_size);

    memcpy(build_state->rsdp, tables.rsdp->data, acpi_data_len(tables.rsdp));

    memcpy(qemu_get_ram_ptr(build_state->linker_ram), tables.linker->data,

           build_state->linker_size);



    cpu_physical_memory_set_dirty_range_nocode(build_state->table_ram,

                                               build_state->table_size);



    acpi_build_tables_cleanup(&tables, true);

}
