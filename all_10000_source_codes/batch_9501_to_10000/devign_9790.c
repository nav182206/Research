/* 
 * Benchmark Sample ID : devign_9790
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9c8922acadb5187c274250d6cde653b7bad2559e
 */

static int tls_read(URLContext *h, uint8_t *buf, int size)

{

    TLSContext *c = h->priv_data;

    size_t processed = 0;

    int ret = SSLRead(c->ssl_context, buf, size, &processed);

    ret = map_ssl_error(ret, processed);

    if (ret > 0)

        return ret;

    if (ret == 0)

        return AVERROR_EOF;

    return print_tls_error(h, ret);

}
