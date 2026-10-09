/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_571
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=947cbeca16c7a30322e02feea440e1e67801ab9a
 */

static void choose_sample_rate(AVStream *st, AVCodec *codec)

{

    if(codec && codec->supported_samplerates){

        const int *p= codec->supported_samplerates;

        int best;

        int best_dist=INT_MAX;

        for(; *p; p++){

            int dist= abs(st->codec->sample_rate - *p);

            if(dist < best_dist){

                best_dist= dist;

                best= *p;

            }

        }

        if(best_dist){

            av_log(st->codec, AV_LOG_WARNING, "Requested sampling rate unsupported using closest supported (%d)\n", best);

        }

        st->codec->sample_rate= best;

    }

}
