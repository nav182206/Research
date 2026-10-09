/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9e1c2ec8fd8d9a9ee299ea86c5f6c986fe25e838
 */

static void pc_q35_init_1_4(QEMUMachineInitArgs *args)

{

    pc_sysfw_flash_vs_rom_bug_compatible = true;

    has_pvpanic = false;

    x86_cpu_compat_set_features("n270", FEAT_1_ECX, 0, CPUID_EXT_MOVBE);

    pc_q35_init(args);

}
