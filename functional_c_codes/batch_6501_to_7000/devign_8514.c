/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8514
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1dc19729e92a96620000e09eba8e58cb458c9486
 */

static void asfrtp_close_context(PayloadContext *asf)

{

    ffio_free_dyn_buf(&asf->pktbuf);

    av_freep(&asf->buf);

    av_free(asf);

}
