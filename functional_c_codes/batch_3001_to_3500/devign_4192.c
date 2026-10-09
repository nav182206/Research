/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4192
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1509c018bd5b054a2354e20021ccbac9c934d213
 */

static int mpegts_probe(AVProbeData *p)

{

    const int size = p->buf_size;

    int score, fec_score, dvhs_score;

    int check_count = size / TS_FEC_PACKET_SIZE;

#define CHECK_COUNT 10



    if (check_count < CHECK_COUNT)

        return AVERROR_INVALIDDATA;



    score = analyze(p->buf, TS_PACKET_SIZE * check_count,

                    TS_PACKET_SIZE, NULL) * CHECK_COUNT / check_count;

    dvhs_score = analyze(p->buf, TS_DVHS_PACKET_SIZE * check_count,

                         TS_DVHS_PACKET_SIZE, NULL) * CHECK_COUNT / check_count;

    fec_score = analyze(p->buf, TS_FEC_PACKET_SIZE * check_count,

                        TS_FEC_PACKET_SIZE, NULL) * CHECK_COUNT / check_count;

    av_dlog(NULL, "score: %d, dvhs_score: %d, fec_score: %d \n",

            score, dvhs_score, fec_score);



    /* we need a clear definition for the returned score otherwise

     * things will become messy sooner or later */

    if (score > fec_score && score > dvhs_score && score > 6)

        return AVPROBE_SCORE_MAX + score - CHECK_COUNT;

    else if (dvhs_score > score && dvhs_score > fec_score && dvhs_score > 6)

        return AVPROBE_SCORE_MAX + dvhs_score - CHECK_COUNT;

    else if (fec_score > 6)

        return AVPROBE_SCORE_MAX + fec_score - CHECK_COUNT;

    else

        return AVERROR_INVALIDDATA;

}
