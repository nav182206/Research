/* 
 * Benchmark Sample ID : devign_3558
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=221f902f1dc167bdc0bfdff6b6af3214ae3cc1f4
 */

static void filter_edges_16bit(void *dst1, void *prev1, void *cur1, void *next1,

                               int w, int prefs, int mrefs, int parity, int mode)

{

    uint16_t *dst  = dst1;

    uint16_t *prev = prev1;

    uint16_t *cur  = cur1;

    uint16_t *next = next1;

    int x;

    uint16_t *prev2 = parity ? prev : cur ;

    uint16_t *next2 = parity ? cur  : next;

    mrefs /= 2;

    prefs /= 2;



    FILTER(0, 3, 0)



    dst   = (uint16_t*)dst1  + w - 3;

    prev  = (uint16_t*)prev1 + w - 3;

    cur   = (uint16_t*)cur1  + w - 3;

    next  = (uint16_t*)next1 + w - 3;

    prev2 = (uint16_t*)(parity ? prev : cur);

    next2 = (uint16_t*)(parity ? cur  : next);



    FILTER(w - 3, w, 0)

}
