/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5610
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f72601d06378494b5026b919fcd3eb5eb22799a1
 */

static int txd_read_header(AVFormatContext *s, AVFormatParameters *ap) {
    AVStream *st;
    st = avformat_new_stream(s, NULL);
    if (!st)
        return AVERROR(ENOMEM);
    st->codec->codec_type = AVMEDIA_TYPE_VIDEO;
    st->codec->codec_id = CODEC_ID_TXD;
    st->codec->time_base.den = 5;
    st->codec->time_base.num = 1;
    /* the parameters will be extracted from the compressed bitstream */
    return 0;
}
