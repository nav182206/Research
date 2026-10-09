/* 
 * Benchmark Sample ID : devign_4290
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6737539e77e78fca9a04914d51996cfd1ccc55c
 */

static void intra_predict_vert_16x16_msa(uint8_t *src, uint8_t *dst,

                                         int32_t dst_stride)

{

    uint32_t row;

    v16u8 src0;



    src0 = LD_UB(src);



    for (row = 16; row--;) {

        ST_UB(src0, dst);

        dst += dst_stride;

    }

}
