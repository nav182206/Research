/* 
 * Benchmark Sample ID : devign_592
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=edcc51fb8e15b704955d742559215697598927bb
 */

static int add_string_metadata(int count, const char *name,

                               TiffContext *s)

{

    char *value;



    if (bytestream2_get_bytes_left(&s->gb) < count || count < 0)

        return AVERROR_INVALIDDATA;



    value = av_malloc(count + 1);

    if (!value)

        return AVERROR(ENOMEM);



    bytestream2_get_bufferu(&s->gb, value, count);

    value[count] = 0;



    av_dict_set(avpriv_frame_get_metadatap(&s->picture), name, value, AV_DICT_DONT_STRDUP_VAL);

    return 0;

}
