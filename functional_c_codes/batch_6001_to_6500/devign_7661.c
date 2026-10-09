/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7661
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1eb1f6f281eb6036d363e0317c1500be4a2708f2
 */

static void gain_scale(G723_1_Context *p, int16_t * buf, int energy)

{

    int num, denom, gain, bits1, bits2;

    int i;



    num   = energy;

    denom = 0;

    for (i = 0; i < SUBFRAME_LEN; i++) {

        int64_t temp = buf[i] >> 2;

        temp  = av_clipl_int32(MUL64(temp, temp) << 1);

        denom = av_clipl_int32(denom + temp);

    }



    if (num && denom) {

        bits1   = normalize_bits(num,   31);

        bits2   = normalize_bits(denom, 31);

        num     = num << bits1 >> 1;

        denom <<= bits2;



        bits2 = 5 + bits1 - bits2;

        bits2 = FFMAX(0, bits2);



        gain = (num >> 1) / (denom >> 16);

        gain = square_root(gain << 16 >> bits2);

    } else {

        gain = 1 << 12;

    }



    for (i = 0; i < SUBFRAME_LEN; i++) {

        p->pf_gain = (15 * p->pf_gain + gain + (1 << 3)) >> 4;

        buf[i]     = av_clip_int16((buf[i] * (p->pf_gain + (p->pf_gain >> 4)) +

                                   (1 << 10)) >> 11);

    }

}
