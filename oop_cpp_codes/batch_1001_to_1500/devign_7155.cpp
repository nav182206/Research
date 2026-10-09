/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7155
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=06f4b1e37a08f3fd269ecbfeb0181129e5bfc86e
 */

static double compute_target_time(double frame_current_pts, VideoState *is)

{

    double delay, sync_threshold, diff;



    /* compute nominal delay */

    delay = frame_current_pts - is->frame_last_pts;

    if (delay <= 0 || delay >= 10.0) {

        /* if incorrect delay, use previous one */

        delay = is->frame_last_delay;

    } else {

        is->frame_last_delay = delay;

    }

    is->frame_last_pts = frame_current_pts;



    /* update delay to follow master synchronisation source */

    if (((is->av_sync_type == AV_SYNC_AUDIO_MASTER && is->audio_st) ||

         is->av_sync_type == AV_SYNC_EXTERNAL_CLOCK)) {

        /* if video is slave, we try to correct big delays by

           duplicating or deleting a frame */

        diff = get_video_clock(is) - get_master_clock(is);



        /* skip or repeat frame. We take into account the

           delay to compute the threshold. I still don't know

           if it is the best guess */

        sync_threshold = FFMAX(AV_SYNC_THRESHOLD, delay);

        if (fabs(diff) < AV_NOSYNC_THRESHOLD) {

            if (diff <= -sync_threshold)

                delay = 0;

            else if (diff >= sync_threshold)

                delay = 2 * delay;

        }

    }

    is->frame_timer += delay;



    av_log(NULL, AV_LOG_TRACE, "video: delay=%0.3f pts=%0.3f A-V=%f\n",

            delay, frame_current_pts, -diff);



    return is->frame_timer;

}
