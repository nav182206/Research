/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2374
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e84c2498f0ff3999937d18d1e9abaa030400000
 */

static inline void load_seg_cache_raw_dt(SegmentCache *sc, uint32_t e1, uint32_t e2)

{

    sc->base = get_seg_base(e1, e2);

    sc->limit = get_seg_limit(e1, e2);

    sc->flags = e2;

}
