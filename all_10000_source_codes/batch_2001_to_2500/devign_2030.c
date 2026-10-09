/* 
 * Benchmark Sample ID : devign_2030
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b854bc196f5c4b4e3299c0b0ee63cf828ece9e77
 */

int omap_validate_imif_addr(struct omap_mpu_state_s *s,

                target_phys_addr_t addr)

{

    return addr >= OMAP_IMIF_BASE && addr < OMAP_IMIF_BASE + s->sram_size;

}
