/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1809
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=20c334a797bf46a4ee59a6e42be6d5e7c3cda585
 */

static inline uint32_t mipsdsp_sat32_sub(int32_t a, int32_t b,

                                         CPUMIPSState *env)

{

    int32_t  temp;



    temp = a - b;

    if (MIPSDSP_OVERFLOW(a, -b, temp, 0x80000000)) {

        if (a > 0) {

            temp = 0x7FFFFFFF;

        } else {

            temp = 0x80000000;

        }

        set_DSPControl_overflow_flag(1, 20, env);

    }



    return temp & 0xFFFFFFFFull;

}
