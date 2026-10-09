/* 
 * Benchmark Sample ID : devign_2532
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4ab29b8214cc4b54e0c1a8270b610a340311470e
 */

static void fdt_add_gic_node(const VirtBoardInfo *vbi)

{

    uint32_t gic_phandle;



    gic_phandle = qemu_fdt_alloc_phandle(vbi->fdt);

    qemu_fdt_setprop_cell(vbi->fdt, "/", "interrupt-parent", gic_phandle);



    qemu_fdt_add_subnode(vbi->fdt, "/intc");

    /* 'cortex-a15-gic' means 'GIC v2' */

    qemu_fdt_setprop_string(vbi->fdt, "/intc", "compatible",

                            "arm,cortex-a15-gic");

    qemu_fdt_setprop_cell(vbi->fdt, "/intc", "#interrupt-cells", 3);

    qemu_fdt_setprop(vbi->fdt, "/intc", "interrupt-controller", NULL, 0);

    qemu_fdt_setprop_sized_cells(vbi->fdt, "/intc", "reg",

                                     2, vbi->memmap[VIRT_GIC_DIST].base,

                                     2, vbi->memmap[VIRT_GIC_DIST].size,

                                     2, vbi->memmap[VIRT_GIC_CPU].base,

                                     2, vbi->memmap[VIRT_GIC_CPU].size);

    qemu_fdt_setprop_cell(vbi->fdt, "/intc", "phandle", gic_phandle);

}
