/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5148
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd7e2875fe99ca9621c02666e11389602b512f4b
 */

static void slavio_timer_get_out(SLAVIO_TIMERState *s)

{

    uint64_t count;



    count = s->limit - PERIODS_TO_LIMIT(ptimer_get_count(s->timer));

    DPRINTF("get_out: limit %" PRIx64 " count %x%08x\n", s->limit,

            s->counthigh, s->count);

    s->count = count & TIMER_COUNT_MASK32;

    s->counthigh = count >> 32;

}
