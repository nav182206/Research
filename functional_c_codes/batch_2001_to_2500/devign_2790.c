/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2790
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f20921deec135a68f78cb327472ea6cf28644a5
 */

static int applehttp_read_seek(AVFormatContext *s, int stream_index,

                               int64_t timestamp, int flags)

{

    AppleHTTPContext *c = s->priv_data;

    int i, j, ret;



    if ((flags & AVSEEK_FLAG_BYTE) || !c->variants[0]->finished)

        return AVERROR(ENOSYS);



    timestamp = av_rescale_rnd(timestamp, 1, stream_index >= 0 ?

                               s->streams[stream_index]->time_base.den :

                               AV_TIME_BASE, flags & AVSEEK_FLAG_BACKWARD ?

                               AV_ROUND_DOWN : AV_ROUND_UP);

    ret = AVERROR(EIO);

    for (i = 0; i < c->n_variants; i++) {

        /* Reset reading */

        struct variant *var = c->variants[i];

        int64_t pos = 0;

        if (var->input) {

            ffurl_close(var->input);

            var->input = NULL;

        }

        av_free_packet(&var->pkt);

        reset_packet(&var->pkt);

        var->pb.eof_reached = 0;



        /* Locate the segment that contains the target timestamp */

        for (j = 0; j < var->n_segments; j++) {

            if (timestamp >= pos &&

                timestamp < pos + var->segments[j]->duration) {

                var->cur_seq_no = var->start_seq_no + j;

                ret = 0;

                break;

            }

            pos += var->segments[j]->duration;

        }

    }

    return ret;

}
