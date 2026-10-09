/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9092
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aa7f9966dfdff500bbbf1956d9e115b1fa8987a6
 */

static inline void ne2000_mem_writel(NE2000State *s, uint32_t addr,

                                     uint32_t val)

{

    addr &= ~1; /* XXX: check exact behaviour if not even */

    if (addr < 32 ||

        (addr >= NE2000_PMEM_START && addr < NE2000_MEM_SIZE)) {

        stl_le_p(s->mem + addr, val);

    }

}
