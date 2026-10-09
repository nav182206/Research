/* 
 * Benchmark Sample ID : devign_4441
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1851e1d05d06f6ef3436c667e4354da0f407b226
 */

static int rtp_write(URLContext *h, const uint8_t *buf, int size)
{
    RTPContext *s = h->priv_data;
    int ret;
    URLContext *hd;
    if (RTP_PT_IS_RTCP(buf[1])) {
        /* RTCP payload type */
        hd = s->rtcp_hd;
    } else {
        /* RTP payload type */
        hd = s->rtp_hd;
    }
    ret = ffurl_write(hd, buf, size);
    return ret;
}
