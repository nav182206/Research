/* 
 * Benchmark Sample ID : devign_8001
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee7f2609a0dcac4008759f20ab9558a68d759821
 */

static void reanalyze(MpegTSContext *ts) {

    AVIOContext *pb = ts->stream->pb;

    int64_t pos = avio_tell(pb);

    if(pos < 0)

        return;

    pos += ts->raw_packet_size - ts->pos47_full;

    if (pos == TS_PACKET_SIZE) {

        ts->size_stat[0] ++;

    } else if (pos == TS_DVHS_PACKET_SIZE) {

        ts->size_stat[1] ++;

    } else if (pos == TS_FEC_PACKET_SIZE) {

        ts->size_stat[2] ++;

    }



    ts->size_stat_count ++;

    if(ts->size_stat_count > SIZE_STAT_THRESHOLD) {

        int newsize = 0;

        if (ts->size_stat[0] > SIZE_STAT_THRESHOLD) {

            newsize = TS_PACKET_SIZE;

        } else if (ts->size_stat[1] > SIZE_STAT_THRESHOLD) {

            newsize = TS_DVHS_PACKET_SIZE;

        } else if (ts->size_stat[2] > SIZE_STAT_THRESHOLD) {

            newsize = TS_FEC_PACKET_SIZE;

        }

        if (newsize) {

            av_log(ts->stream, AV_LOG_WARNING, "changing packet size to %d\n", newsize);

            ts->raw_packet_size = newsize;

        }

        ts->size_stat_count = 0;

        memset(ts->size_stat, 0, sizeof(ts->size_stat));

    }

}
