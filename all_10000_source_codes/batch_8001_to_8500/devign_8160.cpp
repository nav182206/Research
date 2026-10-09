/* 
 * Benchmark Sample ID : devign_8160
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b6267901c466c482b2f1af3578b0a6d88265d144
 */

static int mp3_seek(AVFormatContext *s, int stream_index, int64_t timestamp,

                    int flags)

{

    MP3Context *mp3 = s->priv_data;

    AVIndexEntry *ie;

    AVStream *st = s->streams[0];

    int64_t ret  = av_index_search_timestamp(st, timestamp, flags);

    uint32_t header = 0;



    if (!mp3->xing_toc) {

        st->skip_samples = timestamp <= 0 ? mp3->start_pad + 528 + 1 : 0;



        return -1;

    }



    if (ret < 0)

        return ret;



    ie = &st->index_entries[ret];

    ret = avio_seek(s->pb, ie->pos, SEEK_SET);

    if (ret < 0)

        return ret;



    while (!s->pb->eof_reached) {

        header = (header << 8) + avio_r8(s->pb);

        if (ff_mpa_check_header(header) >= 0) {

            ff_update_cur_dts(s, st, ie->timestamp);

            ret = avio_seek(s->pb, -4, SEEK_CUR);



            st->skip_samples = ie->timestamp <= 0 ? mp3->start_pad + 528 + 1 : 0;



            return (ret >= 0) ? 0 : ret;

        }

    }



    return AVERROR_EOF;

}
