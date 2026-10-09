/* 
 * Benchmark Sample ID : devign_2793
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8e90c7285d1cbf62a9c9a5f9e6efda998dc0d454
 */

static int get_metadata(AVFormatContext *s,

                        const char *const tag,

                        const unsigned data_size)

{

    uint8_t *buf = ((data_size + 1) == 0) ? NULL : av_malloc(data_size + 1);



    if (!buf)

        return AVERROR(ENOMEM);



    if (avio_read(s->pb, buf, data_size) < 0) {

        av_free(buf);

        return AVERROR(EIO);

    }

    buf[data_size] = 0;

    av_dict_set(&s->metadata, tag, buf, AV_DICT_DONT_STRDUP_VAL);

    return 0;

}
