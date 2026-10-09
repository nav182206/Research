/* 
 * Benchmark Sample ID : devign_9506
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=486637af8ef29ec215e0e0b7ecd3b5470f0e04e5
 */

static inline void mix_3f_2r_to_mono(AC3DecodeContext *ctx)

{

    int i;

    float (*output)[256] = ctx->audio_block.block_output;



    for (i = 0; i < 256; i++)

        output[1][i] += (output[2][i] + output[3][i] + output[4][i] + output[5][i]);

    memset(output[2], 0, sizeof(output[2]));

    memset(output[3], 0, sizeof(output[3]));

    memset(output[4], 0, sizeof(output[4]));

    memset(output[5], 0, sizeof(output[5]));

}
