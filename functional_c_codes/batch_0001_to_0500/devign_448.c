/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_448
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4207117c93357347500235952ce7891688089cb1
 */

static void akita_init(int ram_size, int vga_ram_size, int boot_device,

                DisplayState *ds, const char **fd_filename, int snapshot,

                const char *kernel_filename, const char *kernel_cmdline,

                const char *initrd_filename, const char *cpu_model)

{

    spitz_common_init(ram_size, vga_ram_size, ds, kernel_filename,

                kernel_cmdline, initrd_filename, akita, 0x2e8);

}
