/* 
 * Benchmark Sample ID : devign_5643
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ec4a84dca603a24a8131297036dfe30eed33dd7
 */

static int get_video_frame(VideoState *is, AVFrame *frame)

{

    int got_picture;



    if ((got_picture = decoder_decode_frame(&is->viddec, frame)) < 0)

        return -1;



    if (got_picture) {

        double dpts = NAN;



        if (frame->pts != AV_NOPTS_VALUE)

            dpts = av_q2d(is->video_st->time_base) * frame->pts;



        frame->sample_aspect_ratio = av_guess_sample_aspect_ratio(is->ic, is->video_st, frame);



        if (framedrop>0 || (framedrop && get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER)) {

            if (frame->pts != AV_NOPTS_VALUE) {

                double diff = dpts - get_master_clock(is);

                if (!isnan(diff) && fabs(diff) < AV_NOSYNC_THRESHOLD &&

                    diff - is->frame_last_filter_delay < 0 &&

                    is->viddec.pkt_serial == is->vidclk.serial &&

                    is->videoq.nb_packets) {

                    is->frame_drops_early++;

                    av_frame_unref(frame);

                    got_picture = 0;

                }

            }

        }

    }



    return got_picture;

}
