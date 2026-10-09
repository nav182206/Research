/* 
 * Benchmark Sample ID : devign_4709
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4edebb0e8e14a5b934114b5ff74cb86437bb2532
 */

static void sun4m_common_init(int ram_size, int boot_device, DisplayState *ds,

                              const char *kernel_filename, const char *kernel_cmdline,

                              const char *initrd_filename, const char *cpu_model,

                              unsigned int machine)

{

    sun4m_hw_init(&hwdefs[machine], ram_size, ds, cpu_model);



    sun4m_load_kernel(hwdefs[machine].vram_size, ram_size, boot_device,

                      kernel_filename, kernel_cmdline, initrd_filename,

                      hwdefs[machine].machine_id);

}
