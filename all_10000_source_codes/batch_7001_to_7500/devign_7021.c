/* 
 * Benchmark Sample ID : devign_7021
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32f0c658283e2451add02a6ee5c719efa877a34c
 */

static void vc1_inv_trans_4x4_c(uint8_t *dest, int linesize, DCTELEM *block)

{

    int i;

    register int t1,t2,t3,t4;

    DCTELEM *src, *dst;

    const uint8_t *cm = ff_cropTbl + MAX_NEG_CROP;



    src = block;

    dst = block;

    for(i = 0; i < 4; i++){

        t1 = 17 * (src[0] + src[2]) + 4;

        t2 = 17 * (src[0] - src[2]) + 4;

        t3 = 22 * src[1] + 10 * src[3];

        t4 = 22 * src[3] - 10 * src[1];



        dst[0] = (t1 + t3) >> 3;

        dst[1] = (t2 - t4) >> 3;

        dst[2] = (t2 + t4) >> 3;

        dst[3] = (t1 - t3) >> 3;



        src += 8;

        dst += 8;

    }



    src = block;

    for(i = 0; i < 4; i++){

        t1 = 17 * (src[ 0] + src[16]) + 64;

        t2 = 17 * (src[ 0] - src[16]) + 64;

        t3 = 22 * src[ 8] + 10 * src[24];

        t4 = 22 * src[24] - 10 * src[ 8];



        dest[0*linesize] = cm[dest[0*linesize] + ((t1 + t3) >> 7)];

        dest[1*linesize] = cm[dest[1*linesize] + ((t2 - t4) >> 7)];

        dest[2*linesize] = cm[dest[2*linesize] + ((t2 + t4) >> 7)];

        dest[3*linesize] = cm[dest[3*linesize] + ((t1 - t3) >> 7)];



        src ++;

        dest++;

    }

}
