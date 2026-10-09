/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4976
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c720657c23afd798ae0db7c7362eb859a89ab3d
 */

static int mov_parse_stsd_data(MOVContext *c, AVIOContext *pb,

                                AVStream *st, MOVStreamContext *sc,

                                int size)

{

    if (st->codec->codec_tag == MKTAG('t','m','c','d')) {

        st->codec->extradata_size = size;

        st->codec->extradata = av_malloc(size + FF_INPUT_BUFFER_PADDING_SIZE);

        if (!st->codec->extradata)

            return AVERROR(ENOMEM);

        avio_read(pb, st->codec->extradata, size);

    } else {

        /* other codec type, just skip (rtp, mp4s ...) */

        avio_skip(pb, size);

    }

    return 0;

}
