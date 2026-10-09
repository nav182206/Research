/* 
 * Benchmark Sample ID : devign_3642
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=967b75230b9720ea2b3ae49f38f8287026125f9f
 */

static void powernv_populate_chip(PnvChip *chip, void *fdt)
{
    PnvChipClass *pcc = PNV_CHIP_GET_CLASS(chip);
    char *typename = pnv_core_typename(pcc->cpu_model);
    size_t typesize = object_type_get_instance_size(typename);
    int i;
    for (i = 0; i < chip->nr_cores; i++) {
        PnvCore *pnv_core = PNV_CORE(chip->cores + i * typesize);
        powernv_create_core_node(chip, pnv_core, fdt);
    }
    if (chip->ram_size) {
        powernv_populate_memory_node(fdt, chip->chip_id, chip->ram_start,
                                     chip->ram_size);
    }
    g_free(typename);
}
