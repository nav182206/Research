/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6137
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1831274ff1ef69d4b730993e03283430775e2eca
 */

static int process_video_header_vp6(AVFormatContext *s)

{

    EaDemuxContext *ea = s->priv_data;

    AVIOContext *pb = s->pb;



    avio_skip(pb, 8);

    ea->nb_frames = avio_rl32(pb);

    avio_skip(pb, 4);

    ea->time_base.den = avio_rl32(pb);

    ea->time_base.num = avio_rl32(pb);





    ea->video_codec = AV_CODEC_ID_VP6;



    return 1;
