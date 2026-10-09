/* 
 * Benchmark Sample ID : devign_1361
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c720657c23afd798ae0db7c7362eb859a89ab3d
 */

static int mov_read_dvc1(MOVContext *c, AVIOContext *pb, MOVAtom atom)

{

    AVStream *st;

    uint8_t profile_level;



    if (c->fc->nb_streams < 1)

        return 0;

    st = c->fc->streams[c->fc->nb_streams-1];



    if (atom.size >= (1<<28) || atom.size < 7)

        return AVERROR_INVALIDDATA;



    profile_level = avio_r8(pb);

    if ((profile_level & 0xf0) != 0xc0)

        return 0;



    av_free(st->codec->extradata);

    st->codec->extradata = av_mallocz(atom.size - 7 + FF_INPUT_BUFFER_PADDING_SIZE);

    if (!st->codec->extradata)

        return AVERROR(ENOMEM);

    st->codec->extradata_size = atom.size - 7;

    avio_seek(pb, 6, SEEK_CUR);

    avio_read(pb, st->codec->extradata, st->codec->extradata_size);

    return 0;

}
