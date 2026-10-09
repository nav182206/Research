/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8077
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4ffdb337e74f9a4dae97ea0396d4e1a3dbb13723
 */

static bool enforce_config_section(void)

{

    MachineState *machine = MACHINE(qdev_get_machine());

    return machine->enforce_config_section;

}
