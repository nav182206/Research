/* 
 * Benchmark Sample ID : devign_3338
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c933c51687db958d8045d25ed87848342e869f6
 */

static void svq3_add_idct_c(uint8_t *dst, int16_t *block,

                            int stride, int qp, int dc)

{

    const int qmul = svq3_dequant_coeff[qp];

    int i;



    if (dc) {

        dc       = 13 * 13 * (dc == 1 ? 1538U* block[0]

                                      : qmul * (block[0] >> 3) / 2);

        block[0] = 0;

    }



    for (i = 0; i < 4; i++) {

        const int z0 = 13 * (block[0 + 4 * i] +      block[2 + 4 * i]);

        const int z1 = 13 * (block[0 + 4 * i] -      block[2 + 4 * i]);

        const int z2 =  7 *  block[1 + 4 * i] - 17 * block[3 + 4 * i];

        const int z3 = 17 *  block[1 + 4 * i] +  7 * block[3 + 4 * i];



        block[0 + 4 * i] = z0 + z3;

        block[1 + 4 * i] = z1 + z2;

        block[2 + 4 * i] = z1 - z2;

        block[3 + 4 * i] = z0 - z3;

    }



    for (i = 0; i < 4; i++) {

        const unsigned z0 = 13 * (block[i + 4 * 0] +      block[i + 4 * 2]);

        const unsigned z1 = 13 * (block[i + 4 * 0] -      block[i + 4 * 2]);

        const unsigned z2 =  7 *  block[i + 4 * 1] - 17 * block[i + 4 * 3];

        const unsigned z3 = 17 *  block[i + 4 * 1] +  7 * block[i + 4 * 3];

        const int rr = (dc + 0x80000);



        dst[i + stride * 0] = av_clip_uint8(dst[i + stride * 0] + ((int)((z0 + z3) * qmul + rr) >> 20));

        dst[i + stride * 1] = av_clip_uint8(dst[i + stride * 1] + ((int)((z1 + z2) * qmul + rr) >> 20));

        dst[i + stride * 2] = av_clip_uint8(dst[i + stride * 2] + ((int)((z1 - z2) * qmul + rr) >> 20));

        dst[i + stride * 3] = av_clip_uint8(dst[i + stride * 3] + ((int)((z0 - z3) * qmul + rr) >> 20));

    }



    memset(block, 0, 16 * sizeof(int16_t));

}
