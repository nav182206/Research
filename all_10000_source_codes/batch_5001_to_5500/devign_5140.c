/* 
 * Benchmark Sample ID : devign_5140
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=591b320ad046b2780c1b2841b836b50ba8192f02
 */

static uint64_t hb_count_between(HBitmap *hb, uint64_t start, uint64_t last)

{

    HBitmapIter hbi;

    uint64_t count = 0;

    uint64_t end = last + 1;

    unsigned long cur;

    size_t pos;



    hbitmap_iter_init(&hbi, hb, start << hb->granularity);

    for (;;) {

        pos = hbitmap_iter_next_word(&hbi, &cur);

        if (pos >= (end >> BITS_PER_LEVEL)) {

            break;

        }

        count += popcountl(cur);

    }



    if (pos == (end >> BITS_PER_LEVEL)) {

        /* Drop bits representing the END-th and subsequent items.  */

        int bit = end & (BITS_PER_LONG - 1);

        cur &= (1UL << bit) - 1;

        count += popcountl(cur);

    }



    return count;

}
