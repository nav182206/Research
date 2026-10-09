/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5489
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=29851ee7c8bd3fb8542e21cd0270c73132590350
 */

static inline uint16_t mipsdsp_lshift16(uint16_t a, uint8_t s,

                                        CPUMIPSState *env)

{

    uint8_t  sign;

    uint16_t discard;



    if (s == 0) {

        return a;

    } else {

        sign = (a >> 15) & 0x01;

        if (sign != 0) {

            discard = (((0x01 << (16 - s)) - 1) << s) |

                      ((a >> (14 - (s - 1))) & ((0x01 << s) - 1));

        } else {

            discard = a >> (14 - (s - 1));

        }



        if ((discard != 0x0000) && (discard != 0xFFFF)) {

            set_DSPControl_overflow_flag(1, 22, env);

        }

        return a << s;

    }

}
