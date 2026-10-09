/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2890
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dd44d9e316c17f473eff9f4a5a94ad0d7adb157e
 */

static int adts_write_header(AVFormatContext *s)

{

    ADTSContext *adts = s->priv_data;

    AVCodecContext *avc = s->streams[0]->codec;



    if(avc->extradata_size > 0)

        decode_extradata(adts, avc->extradata, avc->extradata_size);



    return 0;

}
