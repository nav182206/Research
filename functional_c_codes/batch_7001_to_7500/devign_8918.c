/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8918
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8f171151f0f027abb06f72e48c44929616a84cb
 */

static int file_write(URLContext *h, const unsigned char *buf, int size)

{

    FileContext *c = h->priv_data;

    int r = write(c->fd, buf, size);

    return (-1 == r)?AVERROR(errno):r;

}
