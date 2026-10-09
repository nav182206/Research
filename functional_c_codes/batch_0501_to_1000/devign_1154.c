/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1154
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b926cc7834d5bc998775528097831c0fbcf3730a
 */

static void rac_normalise(RangeCoder *c)

{

    for (;;) {

        c->range <<= 8;

        c->low   <<= 8;

        if (c->src < c->src_end) {

            c->low |= *c->src++;

        } else if (!c->low) {

            c->got_error = 1;

            return;

        }

        if (c->range >= RAC_BOTTOM)

            return;

    }

}
