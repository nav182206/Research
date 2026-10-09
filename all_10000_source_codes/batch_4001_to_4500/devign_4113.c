/* 
 * Benchmark Sample ID : devign_4113
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=85e7386ae0d33ede4c575d4df4c1faae6c906338
 */

static void cook_imlt(COOKContext *q, float* inbuffer, float* outbuffer)

{

    int i;



    q->mdct_ctx.fft.imdct_calc(&q->mdct_ctx, outbuffer, inbuffer, q->mdct_tmp);



    for(i = 0; i < q->samples_per_channel; i++){

        float tmp = outbuffer[i];



        outbuffer[i] = q->mlt_window[i] * outbuffer[q->samples_per_channel + i];

        outbuffer[q->samples_per_channel + i] = q->mlt_window[q->samples_per_channel - 1 - i] * -tmp;

    }

}
