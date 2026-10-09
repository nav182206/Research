/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8578
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01ecb7172b684f1c4b3e748f95c5a9a494ca36ec
 */

static float get_band_cost_ZERO_mips(struct AACEncContext *s,

                                     PutBitContext *pb, const float *in,

                                     const float *scaled, int size, int scale_idx,

                                     int cb, const float lambda, const float uplim,

                                     int *bits)

{

    int i;

    float cost = 0;



    for (i = 0; i < size; i += 4) {

        cost += in[i  ] * in[i  ];

        cost += in[i+1] * in[i+1];

        cost += in[i+2] * in[i+2];

        cost += in[i+3] * in[i+3];

    }

    if (bits)

        *bits = 0;

    return cost * lambda;

}
