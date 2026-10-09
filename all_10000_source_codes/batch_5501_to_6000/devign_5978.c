/* 
 * Benchmark Sample ID : devign_5978
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f5be7958e313f3f62505ea7f90007800e8e1dcb5
 */

static void qdm2_calculate_fft (QDM2Context *q, int channel, int sub_packet)

{

    const float gain = (q->channels == 1 && q->nb_channels == 2) ? 0.5f : 1.0f;

    int i;

    q->fft.complex[channel][0].re *= 2.0f;

    q->fft.complex[channel][0].im = 0.0f;

    q->rdft_ctx.rdft_calc(&q->rdft_ctx, (FFTSample *)q->fft.complex[channel]);

    /* add samples to output buffer */

    for (i = 0; i < ((q->fft_frame_size + 15) & ~15); i++)

        q->output_buffer[q->channels * i + channel] += ((float *) q->fft.complex[channel])[i] * gain;

}
