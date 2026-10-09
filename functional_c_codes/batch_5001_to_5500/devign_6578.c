/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6578
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=502d6c0a234b10f65acb0a203aedf14de70dc555
 */

static int wav_read_header(AVFormatContext *s,

                           AVFormatParameters *ap)

{

    int size;

    unsigned int tag;

    ByteIOContext *pb = s->pb;

    AVStream *st;

    WAVContext *wav = s->priv_data;



    /* check RIFF header */

    tag = get_le32(pb);



    if (tag != MKTAG('R', 'I', 'F', 'F'))

        return -1;

    get_le32(pb); /* file size */

    tag = get_le32(pb);

    if (tag != MKTAG('W', 'A', 'V', 'E'))

        return -1;



    /* parse fmt header */

    size = find_tag(pb, MKTAG('f', 'm', 't', ' '));

    if (size < 0)

        return -1;

    st = av_new_stream(s, 0);

    if (!st)

        return AVERROR(ENOMEM);



    get_wav_header(pb, st->codec, size);

    st->need_parsing = AVSTREAM_PARSE_FULL;



    av_set_pts_info(st, 64, 1, st->codec->sample_rate);



    size = find_tag(pb, MKTAG('d', 'a', 't', 'a'));

    if (size < 0)

        return -1;

    wav->data_end= url_ftell(pb) + size;

    return 0;

}
