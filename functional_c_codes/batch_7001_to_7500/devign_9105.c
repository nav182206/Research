/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9105
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e58c05bb3c8b7bd3b93d264facbf290aeae4c483
 */

static int xiph_parse_sdp_line(AVFormatContext *s, int st_index,

                                 PayloadContext *data, const char *line)

{

    const char *p;

    char *value;

    char attr[25];

    int value_size = strlen(line), attr_size = sizeof(attr), res = 0;

    AVCodecContext* codec = s->streams[st_index]->codec;



    assert(codec->id == CODEC_ID_THEORA);

    assert(data);



    if (!(value = av_malloc(value_size))) {

        av_log(codec, AV_LOG_ERROR, "Out of memory\n");

        return AVERROR(ENOMEM);

    }



    if (av_strstart(line, "fmtp:", &p)) {

        // remove protocol identifier

        while (*p && *p == ' ') p++; // strip spaces

        while (*p && *p != ' ') p++; // eat protocol identifier

        while (*p && *p == ' ') p++; // strip trailing spaces



        while (ff_rtsp_next_attr_and_value(&p,

                                           attr, attr_size,

                                           value, value_size)) {

            res = xiph_parse_fmtp_pair(codec, data, attr, value);

            if (res < 0 && res != AVERROR_PATCHWELCOME)

                return res;

        }

    }



    av_free(value);

    return 0;

}
