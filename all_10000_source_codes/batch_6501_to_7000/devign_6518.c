/* 
 * Benchmark Sample ID : devign_6518
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=edcc51fb8e15b704955d742559215697598927bb
 */

static int add_doubles_metadata(int count,

                                const char *name, const char *sep,

                                TiffContext *s)

{

    char *ap;

    int i;

    double *dp;



    if (count >= INT_MAX / sizeof(int64_t) || count <= 0)

        return AVERROR_INVALIDDATA;

    if (bytestream2_get_bytes_left(&s->gb) < count * sizeof(int64_t))

        return AVERROR_INVALIDDATA;



    dp = av_malloc(count * sizeof(double));

    if (!dp)

        return AVERROR(ENOMEM);



    for (i = 0; i < count; i++)

        dp[i] = tget_double(&s->gb, s->le);

    ap = doubles2str(dp, count, sep);

    av_freep(&dp);

    if (!ap)

        return AVERROR(ENOMEM);

    av_dict_set(avpriv_frame_get_metadatap(&s->picture), name, ap, AV_DICT_DONT_STRDUP_VAL);

    return 0;

}
