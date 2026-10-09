/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8313
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=df45892c1290c6c853010b83e5afebe8740cb9fa
 */

static ram_addr_t qxl_rom_size(void)

{

    uint32_t required_rom_size = sizeof(QXLRom) + sizeof(QXLModes) +

                                 sizeof(qxl_modes);

    uint32_t rom_size = 8192; /* two pages */



    QEMU_BUILD_BUG_ON(required_rom_size > rom_size);

    return rom_size;

}
