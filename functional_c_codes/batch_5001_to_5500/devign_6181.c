/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6181
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9da676de43d778d62efb1cfa75544d770736d67
 */

ogg_read_header (AVFormatContext * s, AVFormatParameters * ap)
{
    struct ogg *ogg = s->priv_data;
    ogg->curidx = -1;
    //linear headers seek from start
    if (ogg_get_headers (s) < 0){
        return -1;
    }
    //linear granulepos seek from end
    ogg_get_length (s);
    //fill the extradata in the per codec callbacks
    return 0;
}
