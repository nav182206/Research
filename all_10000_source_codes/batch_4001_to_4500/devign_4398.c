/* 
 * Benchmark Sample ID : devign_4398
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9888ffb1ce5e0a17f711b01933d504c72ea29d3b
 */

static int mov_read_stps(MOVContext *c, AVIOContext *pb, MOVAtom atom)

{

    AVStream *st;

    MOVStreamContext *sc;

    unsigned i, entries;



    if (c->fc->nb_streams < 1)

        return 0;

    st = c->fc->streams[c->fc->nb_streams-1];

    sc = st->priv_data;



    avio_rb32(pb); // version + flags



    entries = avio_rb32(pb);

    if (entries >= UINT_MAX / sizeof(*sc->stps_data))

        return AVERROR_INVALIDDATA;

    sc->stps_data = av_malloc(entries * sizeof(*sc->stps_data));

    if (!sc->stps_data)

        return AVERROR(ENOMEM);

    sc->stps_count = entries;



    for (i = 0; i < entries; i++) {

        sc->stps_data[i] = avio_rb32(pb);

        //av_dlog(c->fc, "stps %d\n", sc->stps_data[i]);

    }



    return 0;

}
