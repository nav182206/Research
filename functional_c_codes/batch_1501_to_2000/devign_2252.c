/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2252
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b6dcbe086c77ec683f5ff0b693593cda1d61f3a1
 */

static void sdram_set_bcr (uint32_t *bcrp, uint32_t bcr, int enabled)

{

    if (*bcrp & 0x00000001) {

        /* Unmap RAM */

#ifdef DEBUG_SDRAM

        printf("%s: unmap RAM area " TARGET_FMT_plx " " TARGET_FMT_lx "\n",

               __func__, sdram_base(*bcrp), sdram_size(*bcrp));

#endif

        cpu_register_physical_memory(sdram_base(*bcrp), sdram_size(*bcrp),

                                     IO_MEM_UNASSIGNED);

    }

    *bcrp = bcr & 0xFFDEE001;

    if (enabled && (bcr & 0x00000001)) {

#ifdef DEBUG_SDRAM

        printf("%s: Map RAM area " TARGET_FMT_plx " " TARGET_FMT_lx "\n",

               __func__, sdram_base(bcr), sdram_size(bcr));

#endif

        cpu_register_physical_memory(sdram_base(bcr), sdram_size(bcr),

                                     sdram_base(bcr) | IO_MEM_RAM);

    }

}
