/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4669
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8cafeb8bca5d079041739dbd72ccec0ead138eaf
 */

static int mxf_timestamp_to_str(uint64_t timestamp, char **str)
{
    struct tm time = { 0 };
    time.tm_year = (timestamp >> 48) - 1900;
    time.tm_mon  = (timestamp >> 40 & 0xFF) - 1;
    time.tm_mday = (timestamp >> 32 & 0xFF);
    time.tm_hour = (timestamp >> 24 & 0xFF);
    time.tm_min  = (timestamp >> 16 & 0xFF);
    time.tm_sec  = (timestamp >> 8  & 0xFF);
    *str = av_mallocz(32);
    if (!*str)
        return AVERROR(ENOMEM);
    strftime(*str, 32, "%Y-%m-%d %H:%M:%S", &time);
    return 0;
}
