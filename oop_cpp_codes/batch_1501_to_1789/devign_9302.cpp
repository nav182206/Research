/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9302
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabbc64728c2fdb74f565aededec2ab023d20699
 */

static int mkv_write_tracks(AVFormatContext *s)

{

    MatroskaMuxContext *mkv = s->priv_data;

    AVIOContext *dyn_cp, *pb = s->pb;

    ebml_master tracks;

    int i, ret, default_stream_exists = 0;



    ret = mkv_add_seekhead_entry(mkv->main_seekhead, MATROSKA_ID_TRACKS, avio_tell(pb));

    if (ret < 0)

        return ret;



    ret = start_ebml_master_crc32(pb, &dyn_cp, &tracks, MATROSKA_ID_TRACKS, 0);

    if (ret < 0)

        return ret;



    for (i = 0; i < s->nb_streams; i++) {

        AVStream *st = s->streams[i];

        default_stream_exists |= st->disposition & AV_DISPOSITION_DEFAULT;

    }

    for (i = 0; i < s->nb_streams; i++) {

        ret = mkv_write_track(s, mkv, i, dyn_cp, default_stream_exists);

        if (ret < 0)

            return ret;

    }

    end_ebml_master_crc32(pb, &dyn_cp, mkv, tracks);

    return 0;

}
