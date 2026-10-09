/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5246
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void do_srad (void)

{

    int64_t ret;



    if (likely(!(T1 & 0x40UL))) {

        if (likely((uint64_t)T1 != 0)) {

            ret = (int64_t)T0 >> (T1 & 0x3FUL);

            if (likely(ret >= 0 || ((int64_t)T0 & ((1 << T1) - 1)) == 0)) {

                xer_ca = 0;

            } else {

                xer_ca = 1;

            }

        } else {

            ret = T0;

            xer_ca = 0;

        }

    } else {

        ret = (-1) * ((uint64_t)T0 >> 63);

        if (likely(ret >= 0 || ((uint64_t)T0 & ~0x8000000000000000ULL) == 0)) {

            xer_ca = 0;

        } else {

            xer_ca = 1;

        }

    }

    T0 = ret;

}
