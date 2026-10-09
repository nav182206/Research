/* 
 * Benchmark Sample ID : devign_5872
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=001bcd29556b32c1afd686c03f6bdd65dd0e9a36
 */

static int modify_current_stream(HTTPContext *c, char *rates)
{
    int i;
    FFStream *req = c->stream;
    int action_required = 0;
    for (i = 0; i < req->nb_streams; i++) {
        AVCodecContext *codec = &req->streams[i]->codec;
        switch(rates[i]) {
            case 0:
                c->switch_feed_streams[i] = req->feed_streams[i];
                break;
            case 1:
                c->switch_feed_streams[i] = find_stream_in_feed(req->feed, codec, codec->bit_rate / 2);
                break;
            case 2:
                /* Wants off or slow */
                c->switch_feed_streams[i] = find_stream_in_feed(req->feed, codec, codec->bit_rate / 4);
#ifdef WANTS_OFF
                /* This doesn't work well when it turns off the only stream! */
                c->switch_feed_streams[i] = -2;
                c->feed_streams[i] = -2;
#endif
                break;
        }
        if (c->switch_feed_streams[i] >= 0 && c->switch_feed_streams[i] != c->feed_streams[i])
            action_required = 1;
    }
    return action_required;
}
