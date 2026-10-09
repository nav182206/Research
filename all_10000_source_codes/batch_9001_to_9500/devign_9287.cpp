/* 
 * Benchmark Sample ID : devign_9287
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ed3d807b0a577c4f825b25f3281fe54ce89202db
 */

static bool cuda_cmd_set_time(CUDAState *s,

                              const uint8_t *in_data, int in_len,

                              uint8_t *out_data, int *out_len)

{

    uint32_t ti;



    if (in_len != 4) {

        return false;

    }



    ti = (((uint32_t)in_data[1]) << 24) + (((uint32_t)in_data[2]) << 16)

         + (((uint32_t)in_data[3]) << 8) + in_data[4];

    s->tick_offset = ti - (qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL)

                           / NANOSECONDS_PER_SECOND);

    return true;

}
