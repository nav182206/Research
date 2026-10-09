/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_982
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=85e7386ae0d33ede4c575d4df4c1faae6c906338
 */

mlt_compensate_output(COOKContext *q, float *decode_buffer,

                      cook_gains *gains, float *previous_buffer,

                      int16_t *out, int chan)

{

    int j;



    cook_imlt(q, decode_buffer, q->mono_mdct_output);

    gain_compensate(q, gains, previous_buffer);



    /* Clip and convert floats to 16 bits.

     */

    for (j = 0; j < q->samples_per_channel; j++) {

        out[chan + q->nb_channels * j] =

          av_clip(lrintf(q->mono_mdct_output[j]), -32768, 32767);

    }

}
