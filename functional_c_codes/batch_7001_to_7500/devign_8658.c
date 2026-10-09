/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8658
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=568e18b15e2ddf494fd8926707d34ca08c8edce5
 */

static int mov_read_stss(MOVContext *c, ByteIOContext *pb, MOV_atom_t atom)

{

    AVStream *st = c->fc->streams[c->fc->nb_streams-1];

    MOVStreamContext *sc = (MOVStreamContext *)st->priv_data;

    int entries, i;



    print_atom("stss", atom);



    get_byte(pb); /* version */

    get_byte(pb); get_byte(pb); get_byte(pb); /* flags */



    entries = get_be32(pb);

    sc->keyframe_count = entries;

#ifdef DEBUG

    av_log(NULL, AV_LOG_DEBUG, "keyframe_count = %ld\n", sc->keyframe_count);

#endif

    sc->keyframes = (long*) av_malloc(entries * sizeof(long));

    if (!sc->keyframes)

        return -1;

    for(i=0; i<entries; i++) {

        sc->keyframes[i] = get_be32(pb);

#ifdef DEBUG

/*        av_log(NULL, AV_LOG_DEBUG, "keyframes[]=%ld\n", sc->keyframes[i]); */

#endif

    }

    return 0;

}
