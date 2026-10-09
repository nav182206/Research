/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7312
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void do_sraw (void)

{

    int32_t ret;



    if (likely(!(T1 & 0x20UL))) {

        if (likely((uint32_t)T1 != 0)) {

            ret = (int32_t)T0 >> (T1 & 0x1fUL);

            if (likely(ret >= 0 || ((int32_t)T0 & ((1 << T1) - 1)) == 0)) {

                xer_ca = 0;

            } else {

                xer_ca = 1;

            }

        } else {

            ret = T0;

            xer_ca = 0;

        }

    } else {

        ret = (-1) * ((uint32_t)T0 >> 31);

        if (likely(ret >= 0 || ((uint32_t)T0 & ~0x80000000UL) == 0)) {

            xer_ca = 0;

        } else {

            xer_ca = 1;

        }

    }

    T0 = ret;

}
