/* 
 * Benchmark Sample ID : devign_2654
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ccbcfedd17fd2d13521fcee66810d0df464ec1cc
 */

int qemu_devtree_setprop_cell(void *fdt, const char *node_path,

                              const char *property, uint32_t val)

{

    int offset;



    offset = fdt_path_offset(fdt, node_path);

    if (offset < 0)

        return offset;



    return fdt_setprop_cell(fdt, offset, property, val);

}
