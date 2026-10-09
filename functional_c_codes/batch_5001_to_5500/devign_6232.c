/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6232
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=863714ba6cdc09d1a84069815dc67c8da66b0a29
 */

static void fdt_add_psci_node(const VirtBoardInfo *vbi)

{

    void *fdt = vbi->fdt;

    ARMCPU *armcpu = ARM_CPU(qemu_get_cpu(0));



    /* No PSCI for TCG yet */

    if (kvm_enabled()) {

        qemu_fdt_add_subnode(fdt, "/psci");

        if (armcpu->psci_version == 2) {

            const char comp[] = "arm,psci-0.2\0arm,psci";

            qemu_fdt_setprop(fdt, "/psci", "compatible", comp, sizeof(comp));

        } else {

            qemu_fdt_setprop_string(fdt, "/psci", "compatible", "arm,psci");

        }



        qemu_fdt_setprop_string(fdt, "/psci", "method", "hvc");

        qemu_fdt_setprop_cell(fdt, "/psci", "cpu_suspend",

                                  QEMU_PSCI_0_1_FN_CPU_SUSPEND);

        qemu_fdt_setprop_cell(fdt, "/psci", "cpu_off", QEMU_PSCI_0_1_FN_CPU_OFF);

        qemu_fdt_setprop_cell(fdt, "/psci", "cpu_on", QEMU_PSCI_0_1_FN_CPU_ON);

        qemu_fdt_setprop_cell(fdt, "/psci", "migrate", QEMU_PSCI_0_1_FN_MIGRATE);

    }

}
