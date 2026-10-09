/* 
 * Benchmark Sample ID : devign_6216
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6c77805fc84a63b74e5025b4d7eeea24c8138cf3
 */

unsigned int av_codec_get_tag(const AVCodecTag *tags[4], enum CodecID id)

{

    int i;

    for(i=0; i<4 && tags[i]; i++){

        int tag= codec_get_tag(tags[i], id);

        if(tag) return tag;

    }

    return 0;

}
