/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3337
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=34c52005605d68f7cd1957b169b6732c7d2447d9
 */

static void move_audio(vorbis_enc_context *venc, float **audio, int *samples, int sf_size)

{

    AVFrame *cur = NULL;

    int frame_size = 1 << (venc->log2_blocksize[1] - 1);

    int subframes = frame_size / sf_size;



    for (int sf = 0; sf < subframes; sf++) {

        cur = ff_bufqueue_get(&venc->bufqueue);

        *samples += cur->nb_samples;



        for (int ch = 0; ch < venc->channels; ch++) {

            const float *input = (float *) cur->extended_data[ch];

            const size_t len  = cur->nb_samples * sizeof(float);

            memcpy(&audio[ch][sf*sf_size], input, len);

        }

        av_frame_free(&cur);

    }

}
