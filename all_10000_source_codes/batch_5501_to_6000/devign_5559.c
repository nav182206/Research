/* 
 * Benchmark Sample ID : devign_5559
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a4d70941cd4a82f7db9fbaa2148d60ce550e7611
 */

AVStream *add_av_stream1(FFStream *stream, AVCodecContext *codec)

{

    AVStream *fst;



    fst = av_mallocz(sizeof(AVStream));

    if (!fst)

        return NULL;

    fst->priv_data = av_mallocz(sizeof(FeedData));

    memcpy(&fst->codec, codec, sizeof(AVCodecContext));


    stream->streams[stream->nb_streams++] = fst;

    return fst;

}
