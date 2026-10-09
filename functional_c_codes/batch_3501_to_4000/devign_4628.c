/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4628
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d36c231f4b7386bd8230aa17d362b925aa419b2f
 */

static inline uint16_t mipsdsp_trunc16_sat16_round(int32_t a,

                                                   CPUMIPSState *env)

{

    int64_t temp;



    temp = (int32_t)a + 0x00008000;



    if (a > (int)0x7fff8000) {

        temp = 0x7FFFFFFF;

        set_DSPControl_overflow_flag(1, 22, env);

    }



    return (temp >> 16) & 0xFFFF;

}
