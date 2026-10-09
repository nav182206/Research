/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5776
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4ed66517c62c599701b3793fa2843d5a8530a4f4
 */

int ff_lock_avcodec(AVCodecContext *log_ctx, const AVCodec *codec)

{

    if (codec->caps_internal & FF_CODEC_CAP_INIT_THREADSAFE || !codec->init)

        return 0;



    if (ff_mutex_lock(&codec_mutex))

        return -1;



    if (atomic_fetch_add(&entangled_thread_counter, 1)) {

        av_log(log_ctx, AV_LOG_ERROR,

               "Insufficient thread locking. At least %d threads are "

               "calling avcodec_open2() at the same time right now.\n",

               atomic_load(&entangled_thread_counter));

        ff_avcodec_locked = 1;

        ff_unlock_avcodec(codec);

        return AVERROR(EINVAL);

    }

    av_assert0(!ff_avcodec_locked);

    ff_avcodec_locked = 1;

    return 0;

}
