/* 
 * Benchmark Sample ID : devign_7028
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8542f9c4f17125d483c40c0c5723842f1c982f81
 */

static int replaygain_export(AVStream *st,

                             const uint8_t *track_gain, const uint8_t *track_peak,

                             const uint8_t *album_gain, const uint8_t *album_peak)

{

    AVPacketSideData *sd, *tmp;

    AVReplayGain *replaygain;

    uint8_t *data;

    int32_t tg, ag;

    uint32_t tp, ap;



    tg = parse_gain(track_gain);

    ag = parse_gain(album_gain);

    tp = parse_peak(track_peak);

    ap = parse_peak(album_peak);



    if (tg == INT32_MIN && ag == INT32_MIN)

        return 0;



    replaygain = av_mallocz(sizeof(*replaygain));

    if (!replaygain)

        return AVERROR(ENOMEM);



    tmp = av_realloc_array(st->side_data, st->nb_side_data + 1, sizeof(*tmp));

    if (!tmp) {

        av_freep(&replaygain);

        return AVERROR(ENOMEM);

    }

    st->side_data = tmp;

    st->nb_side_data++;



    sd = &st->side_data[st->nb_side_data - 1];

    sd->type = AV_PKT_DATA_REPLAYGAIN;

    sd->data = (uint8_t*)replaygain;

    sd->size = sizeof(*replaygain);



    replaygain->track_gain = tg;

    replaygain->track_peak = tp;

    replaygain->album_gain = ag;

    replaygain->album_peak = ap;



    return 0;

}
