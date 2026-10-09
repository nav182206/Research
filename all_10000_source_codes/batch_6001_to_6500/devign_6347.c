/* 
 * Benchmark Sample ID : devign_6347
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=20c334a797bf46a4ee59a6e42be6d5e7c3cda585
 */

static inline int32_t mipsdsp_add_i32(int32_t a, int32_t b, CPUMIPSState *env)

{

    int32_t temp;



    temp = a + b;



    if (MIPSDSP_OVERFLOW(a, b, temp, 0x80000000)) {

        set_DSPControl_overflow_flag(1, 20, env);

    }



    return temp;

}
