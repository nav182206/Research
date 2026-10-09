/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1455
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0ecca7a49f8e254c12a3a1de048d738bfbb614c6
 */

int get_partial_buffer(ByteIOContext *s, unsigned char *buf, int size)
{
    int len;
    len = s->buf_end - s->buf_ptr;
    if (len == 0) {
        fill_buffer(s);
        len = s->buf_end - s->buf_ptr;
    }
    if (len > size)
        len = size;
    memcpy(buf, s->buf_ptr, len);
    s->buf_ptr += len;
    return len;
}
