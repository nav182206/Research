/* 
 * Benchmark Sample ID : devign_9647
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=26c208cf0ff59efd7786528884a64d35fc42e9bf
 */

static double compute_target_delay(double delay, VideoState *is)

{

    double sync_threshold, diff;



    /* update delay to follow master synchronisation source */

    if (get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER) {

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



    av_dlog(NULL, "video: delay=%0.3f A-V=%f\n",

            delay, -diff);



    return delay;

}
