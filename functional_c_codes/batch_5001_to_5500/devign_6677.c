/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6677
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77bc507f6f001b9f5fa75c664106261bd8f2c971
 */

static int mov_get_h264_codec_tag(AVFormatContext *s, MOVTrack *track)

{

    int tag = track->par->codec_tag;

    int interlaced = track->par->field_order > AV_FIELD_PROGRESSIVE;

    AVStream *st = track->st;

    int rate = av_q2d(find_fps(s, st));



    if (!tag)

        tag = MKTAG('a', 'v', 'c', 'i'); //fallback tag



    if (track->par->format == AV_PIX_FMT_YUV420P10) {

        if (track->par->width == 960 && track->par->height == 720) {

            if (!interlaced) {

                if      (rate == 24) tag = MKTAG('a','i','5','p');

                else if (rate == 25) tag = MKTAG('a','i','5','q');

                else if (rate == 30) tag = MKTAG('a','i','5','p');

                else if (rate == 50) tag = MKTAG('a','i','5','q');

                else if (rate == 60) tag = MKTAG('a','i','5','p');

            }

        } else if (track->par->width == 1440 && track->par->height == 1080) {

            if (!interlaced) {

                if      (rate == 24) tag = MKTAG('a','i','5','3');

                else if (rate == 25) tag = MKTAG('a','i','5','2');

                else if (rate == 30) tag = MKTAG('a','i','5','3');

            } else {

                if      (rate == 50) tag = MKTAG('a','i','5','5');

                else if (rate == 60) tag = MKTAG('a','i','5','6');

            }

        }

    } else if (track->par->format == AV_PIX_FMT_YUV422P10) {

        if (track->par->width == 1280 && track->par->height == 720) {

            if (!interlaced) {

                if      (rate == 24) tag = MKTAG('a','i','1','p');

                else if (rate == 25) tag = MKTAG('a','i','1','q');

                else if (rate == 30) tag = MKTAG('a','i','1','p');

                else if (rate == 50) tag = MKTAG('a','i','1','q');

                else if (rate == 60) tag = MKTAG('a','i','1','p');

            }

        } else if (track->par->width == 1920 && track->par->height == 1080) {

            if (!interlaced) {

                if      (rate == 24) tag = MKTAG('a','i','1','3');

                else if (rate == 25) tag = MKTAG('a','i','1','2');

                else if (rate == 30) tag = MKTAG('a','i','1','3');

            } else {

                if      (rate == 25) tag = MKTAG('a','i','1','5');

                else if (rate == 50) tag = MKTAG('a','i','1','5');

                else if (rate == 60) tag = MKTAG('a','i','1','6');

            }

        } else if (   track->par->width == 4096 && track->par->height == 2160

                   || track->par->width == 3840 && track->par->height == 2160

                   || track->par->width == 2048 && track->par->height == 1080) {

            tag = MKTAG('a','i','v','x');

        }

    }



    return tag;

}
