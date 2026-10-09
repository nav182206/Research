/* 
 * Benchmark Sample ID : devign_5174
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=635ac8e1be91e941908f85642e4bbb609e48193f
 */

static int handle_ping(URLContext *s, RTMPPacket *pkt)

{

    RTMPContext *rt = s->priv_data;

    int t, ret;



    if (pkt->data_size < 2) {

        av_log(s, AV_LOG_ERROR, "Too short ping packet (%d)\n",

               pkt->data_size);

        return AVERROR_INVALIDDATA;




    t = AV_RB16(pkt->data);

    if (t == 6) {

        if ((ret = gen_pong(s, rt, pkt)) < 0)












    return 0;
