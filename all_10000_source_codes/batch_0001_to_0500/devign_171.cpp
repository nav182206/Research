/* 
 * Benchmark Sample ID : devign_171
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=26f6b8c571bcff7b325c7d6cc226c625dd465f8e
 */

int ffurl_read_complete(URLContext *h, unsigned char *buf, int size)

{

    if (h->flags & AVIO_FLAG_WRITE)

        return AVERROR(EIO);

    return retry_transfer_wrapper(h, buf, size, size, h->prot->url_read);

}
