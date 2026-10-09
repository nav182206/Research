/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9703
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=34e1c27bc3094ffe484d9855e07ad104bddf579f
 */

uint32 float32_to_uint32_round_to_zero( float32 a STATUS_PARAM )

{

    int64_t v;

    uint32 res;



    v = float32_to_int64_round_to_zero(a STATUS_VAR);

    if (v < 0) {

        res = 0;

        float_raise( float_flag_invalid STATUS_VAR);

    } else if (v > 0xffffffff) {

        res = 0xffffffff;

        float_raise( float_flag_invalid STATUS_VAR);

    } else {

        res = v;

    }

    return res;

}
