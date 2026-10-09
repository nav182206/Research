/* 
 * Benchmark Sample ID : devign_6335
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=20c334a797bf46a4ee59a6e42be6d5e7c3cda585
 */

static inline int16_t mipsdsp_sat_add_i16(int16_t a, int16_t b,

                                          CPUMIPSState *env)

{

    int16_t tempS;



    tempS = a + b;



    if (MIPSDSP_OVERFLOW(a, b, tempS, 0x8000)) {

        if (a > 0) {

            tempS = 0x7FFF;

        } else {

            tempS = 0x8000;

        }

        set_DSPControl_overflow_flag(1, 20, env);

    }



    return tempS;

}
