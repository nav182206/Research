/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_935
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=445f0a8b666a34e6402f6ae96c6804c8bc024baa
 */

int avcodec_check_dimensions(void *av_log_ctx, unsigned int w, unsigned int h){

    if((int)w>0 && (int)h>0 && (w+128)*(uint64_t)(h+128) < INT_MAX/4)

        return 0;



    av_log(av_log_ctx, AV_LOG_ERROR, "picture size invalid (%ux%u)\n", w, h);

    return -1;

}
