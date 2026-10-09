/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2149
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ccbcfedd17fd2d13521fcee66810d0df464ec1cc
 */

int qemu_devtree_nop_node(void *fdt, const char *node_path)

{

    int offset;



    offset = fdt_path_offset(fdt, node_path);

    if (offset < 0)

        return offset;



    return fdt_nop_node(fdt, offset);

}
