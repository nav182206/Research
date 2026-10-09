/* 
 * Benchmark Sample ID : devign_3506
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6ba5cbc699e77cae66bb719354fa142114b64eab
 */

int rtp_set_remote_url(URLContext *h, const char *uri)

{

    RTPContext *s = h->priv_data;

    char hostname[256];

    int port;



    char buf[1024];

    char path[1024];

    

    url_split(NULL, 0, hostname, sizeof(hostname), &port, 

              path, sizeof(path), uri);



    snprintf(buf, sizeof(buf), "udp://%s:%d%s", hostname, port, path);

    udp_set_remote_url(s->rtp_hd, buf);



    snprintf(buf, sizeof(buf), "udp://%s:%d%s", hostname, port + 1, path);

    udp_set_remote_url(s->rtcp_hd, buf);

    return 0;

}
