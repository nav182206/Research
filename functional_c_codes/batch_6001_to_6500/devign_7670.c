/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7670
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7102fa7073b2cefb33ab4012a11f15fbf297a74b
 */

static void pc_compat_1_6(MachineState *machine)

{

    pc_compat_1_7(machine);

    rom_file_has_mr = false;

    has_acpi_build = false;

}
